using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NUnit.Framework;
using VeristandPythonInterop;
using System.IO;
using System.Diagnostics;

namespace VeristandPythonInteropTest
{
    [TestFixture]
    public class VeristandPythonInteropLaunchCloseTest
    {
        VeriStandInterop VeriStandInterop { get; set; }

        [SetUp]
        public void SetUp()
        {
            this.VeriStandInterop = new VeriStandInterop();
        }

        [Ignore]
        [Test]
        public void VeriStandOpen()
        {
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

        [Test]
        public void VeriStandNotLaunchedShouldBeTrueByDefault()
        {
            Assert.IsTrue(this.VeriStandInterop.VeristandIsNotLaunched);
        }

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
            this.VeriStandInterop.LaunchVeriStand();

            Assert.IsTrue(this.IsProcessOpen("NI VeriStand"), "The Veristand process failed to start");
            Assert.IsNotNull(this.VeriStandInterop.Factory);
        }

        [Test]
        public void LaunchVeriStandShouldProvideErrorMessageOnTimeout()
        {
            Exception e = Assert.Throws<InvalidOperationException>(() =>
                {
                    this.VeriStandInterop.MaxVeriStandLaunchTimeout = 0;
                    this.VeriStandInterop.LaunchVeriStand();
                });

            Assert.AreEqual(ErrorMessages.ErrorMessageVeriStandLaunch, e.Message);
        }

        [Test]
        public void OpenProjectShouldThrownExceptionWhenVeriStandIsNotLaunched()
        {
            Exception e = Assert.Throws<InvalidOperationException>(() =>
            {
                this.VeriStandInterop.OpenProject(@"");
            });

            Assert.AreEqual(ErrorMessages.ErrorMessageVeriStandIsNotLaunched, e.Message);
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

            this.VeriStandInterop.OpenProject(@"C:\Users\Public\Documents\National Instruments\NI VeriStand 2011\Examples\Stimulus Profile\Engine Demo\Engine Demo.nivsproj");

            this.VeriStandInterop.CloseVeristand();
        }

        [Test]
        public void ShouldCloseVeriStand()
        {
            Console.WriteLine(this.VeriStandInterop.MaxVeriStandCloseTimeout);

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
