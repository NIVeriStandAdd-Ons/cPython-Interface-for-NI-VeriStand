using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NUnit.Framework;
using VeristandPythonInterop;
using System.IO;
using System.Diagnostics;
using System.Linq.Expressions;
using System.Threading;

namespace VeristandPythonInteropTest
{
    [TestFixture]
    public class VeristandPythonInteropLaunchCloseTest
    {
        VeriStandInterop VeriStandInterop { get; set; }

        [SetUp]
        public void SetUp()
        {
            //Console.WriteLine("Setup launch");
            this.VeriStandInterop = new VeriStandInterop();
            this.VeriStandInterop.LaunchVeriStand(false);

        }

        [TearDown]
        public void TearDown()
        {
            //Console.WriteLine("Tear close");
            this.VeriStandInterop.MaxVeriStandCloseTimeout = 2;
            this.VeriStandInterop.CloseVeristand();           
        }

        [Test]
        public void CloseShouldNotThrowExceptionWhenVeriStandIsNotLaunched()
        {
            this.VeriStandInterop.CloseVeristand();
        }

        [Test]
        public void ShouldProvideDefaultTimeouts()
        {
            Assert.AreEqual(2, this.VeriStandInterop.MaxVeriStandLaunchTimeout);
            Assert.AreEqual(2, this.VeriStandInterop.MaxVeriStandCloseTimeout);
        }        

        /*[Test]
        public void VeriStandNotLaunchedShouldBeTrueByDefault()
        {
            Assert.IsTrue(this.VeriStandInterop.VeristandIsNotLaunched);
        }*/

        [Test]
        public void ShouldReadVeristandLocationFromRegistry()
        {
            string vsPath = this.VeriStandInterop.ReadVeriStandLocationFromRegistry();
            
            Assert.IsNotNull(vsPath);

            Assert.AreEqual("NI VeriStand.exe", Path.GetFileName(vsPath));

            Assert.IsTrue(File.Exists(vsPath));
        }

        [Test]
        public void ShouldLaunchVeriStand()
        {
            this.VeriStandInterop.LaunchVeriStand(false);

            Assert.IsTrue(this.IsProcessOpen("NI VeriStand"), "The Veristand process failed to start");
            Assert.IsNotNull(this.VeriStandInterop.Factory);
        }

        [Test]
        public void ShouldLaunchVeriStandRunAs()
        {
            this.VeriStandInterop.LaunchVeriStand(true);

            Assert.IsTrue(this.IsProcessOpen("NI VeriStand"), "The Veristand process failed to start");
            Assert.IsNotNull(this.VeriStandInterop.Factory);
        }

        [Test]
        public void SetMultipleChannelValuesShouldThrowExceptionWhenArgumentsAreNotCorrect()
        {
            Exception e = Assert.Throws<ArgumentException>(() => {
                this.VeriStandInterop.SetMultipleChannelValues(new string[2], new double[5]);
            });

            Assert.AreEqual(ErrorMessages.ErrorMessageArraySizeDoesNotEqual, e.Message);
        }

        [Test]
        public void SetMultipleChannelValuesShouldThrowExceptionWhenArgumentIsNull()
        {
            Assert.Throws<ArgumentNullException>(() =>
            {
                this.VeriStandInterop.SetMultipleChannelValues(null, null);
            });

            Assert.Throws<ArgumentNullException>(() =>
            {
                this.VeriStandInterop.SetMultipleChannelValues(null, new double[3]);
            });

            Assert.Throws<ArgumentNullException>(() =>
            {
                this.VeriStandInterop.SetMultipleChannelValues(null, new double[3]);
            });
        }
      

        [Test]
        public void LaunchVeriStandShouldProvideErrorMessageOnTimeout()
        {
            Exception e = Assert.Throws<InvalidOperationException>(() =>
                {
                    this.VeriStandInterop.MaxVeriStandLaunchTimeout = 0;
                    this.VeriStandInterop.LaunchVeriStand(false);
                    //Thread.Sleep(1000);
                });

            Assert.AreEqual(ErrorMessages.ErrorMessageVeriStandLaunch, e.Message);
        }

        private void EnsureThrowsExceptionIfVeriStandNotLaunched(TestDelegate code)
        {
            Exception exception = AssertTestDelegateThrowsInvalidOperationException(code);

            Assert.AreEqual(ErrorMessages.ErrorMessageVeriStandIsNotLaunched, exception.Message);
        }

        internal static Exception AssertTestDelegateThrowsInvalidOperationException(TestDelegate code)
        {
            Exception exception = Assert.Throws<InvalidOperationException>(() =>
            {
                code.Invoke();
            });
            return exception;
        }

        [Test]
        public void MethodsShouldThrownExceptionWhenVeriStandIsNotLaunched()
        {
            this.VeriStandInterop.CloseVeristand();            
            EnsureThrowsExceptionIfVeriStandNotLaunched(() =>
            {
                this.VeriStandInterop.OpenProject(@"");
            });

            EnsureThrowsExceptionIfVeriStandNotLaunched(() =>
            {
                this.VeriStandInterop.SetChannelValue("", double.NaN);
            });

            EnsureThrowsExceptionIfVeriStandNotLaunched(() =>
            {
                this.VeriStandInterop.RunProject();
            });

            EnsureThrowsExceptionIfVeriStandNotLaunched(() =>
            {
                this.VeriStandInterop.SetChannelValue("123", 123);
            });

            EnsureThrowsExceptionIfVeriStandNotLaunched(() =>
            {
                this.VeriStandInterop.GetChannelValue("1243");
            });

            EnsureThrowsExceptionIfVeriStandNotLaunched(() =>
            {
                this.VeriStandInterop.SetMultipleChannelValues(new string [5] , new double [5]);
            });

            EnsureThrowsExceptionIfVeriStandNotLaunched(() =>
            {
                this.VeriStandInterop.GetMultipleChannelValues(new string[5]);
            });


        }

        [Test]
        public void ShowProjectWindowShouldThrownExceptionWhenVeriStandIsNotLaunched()
        {
            this.VeriStandInterop.CloseVeristand();
            EnsureThrowsExceptionIfVeriStandNotLaunched(() =>
            {
                this.VeriStandInterop.ShowProjectWindow();
            });
        }

        [Test]
        public void DeployProjectShouldThrownExceptionWhenVeriStandIsNotLaunched()
        {
            this.VeriStandInterop.CloseVeristand();
            EnsureThrowsExceptionIfVeriStandNotLaunched(() =>
            {
                this.VeriStandInterop.DeployProject();
            });
        }

        [Test]
        public void CloseVeriStandShouldProvideErrorMessageOnTimeout()
        {
            this.VeriStandInterop.LaunchVeriStand();

            Exception e = Assert.Throws<InvalidOperationException>(() =>
            {
                this.VeriStandInterop.MaxVeriStandCloseTimeout = 0;
                this.VeriStandInterop.CloseVeristand();
            });         
                        
            Assert.AreEqual(ErrorMessages.ErrorMessageVeriStandClose, e.Message);
        }

        [Test]
        public void CloseShouldCloseVeriStandWhenAProjectIsOpen()
        {
            this.VeriStandInterop.LaunchVeriStand();

            string pathPublic = System.Environment.GetFolderPath(Environment.SpecialFolder.CommonDocuments);
            string exampleProjectPath = pathPublic + @"\National Instruments\NI VeriStand 2013\Examples\Stimulus Profile\Engine Demo\Engine Demo.nivsproj";
            this.VeriStandInterop.OpenProject(exampleProjectPath);            

            this.VeriStandInterop.CloseVeristand();
        }

        [Test]
        public void MethodsShouldThrowExceptionIfProjectNotOpened()
        {
            this.VeriStandInterop.CloseVeristand();
            //Console.WriteLine("Close Methods^");
            this.VeriStandInterop.LaunchVeriStand();

            EnsureThrowsExceptionIfProjectIsNotOpened(() =>
            {
                this.VeriStandInterop.DeployProject();
            });

            EnsureThrowsExceptionIfProjectIsNotOpened(() =>
            {
                this.VeriStandInterop.RunProject();
            });

            EnsureThrowsExceptionIfProjectIsNotOpened(() =>
            {
                this.VeriStandInterop.ShowProjectWindow();
            });
            //Console.WriteLine("End Methods^");
        }

        private void EnsureThrowsExceptionIfProjectIsNotOpened(TestDelegate code)
        {
            Exception exception = VeristandPythonInteropLaunchCloseTest.AssertTestDelegateThrowsInvalidOperationException(code);

            Assert.AreEqual(ErrorMessages.ErrorMessageShowHide, exception.Message);
        }

        [Test]
        public void ShouldCloseVeriStand()
        {
            //Console.WriteLine(this.VeriStandInterop.MaxVeriStandCloseTimeout);

            this.VeriStandInterop.LaunchVeriStand();

            Assert.IsTrue(this.IsProcessOpen("NI VeriStand"), "The Veristand process failed to start");

            this.VeriStandInterop.CloseVeristand();

            Assert.IsTrue(this.VeriStandInterop.VeriStandProcess.HasExited, "The Veristand process failed to close");
            Assert.IsFalse(this.IsProcessOpen("NI VeriStand"), "The Veristand process failed to close");
        }

        private bool IsProcessOpen(string name)
        {
	        foreach (Process clsProcess in Process.GetProcesses()) 
            {
		        if (clsProcess.ProcessName.Contains(name))
		        {
			        return true;
		        }
	        }
	        return false;
        }

        
    }
}
