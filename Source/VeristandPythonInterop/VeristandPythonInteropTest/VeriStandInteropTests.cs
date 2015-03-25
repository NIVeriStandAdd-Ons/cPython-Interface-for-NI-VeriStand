using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using NUnit.Framework;
using VeristandPythonInterop;
using NationalInstruments.VeriStand;

namespace VeristandPythonInteropTest
{
    [TestFixture]
    public class VeriStandInteropTests
    {
        VeriStandInterop VeriStandInterop { get; set; }

        private static string ExampleVeriStandProjectPath = @"C:\Users\Public\Documents\National Instruments\NI VeriStand 2011\Projects\Example\Sinewave Delay.nivsproj";

        [TestFixtureSetUp]
        public void SetupFixture()
        {
            this.VeriStandInterop = new VeriStandInterop();
            this.VeriStandInterop.LaunchVeriStand();
        }

        [TestFixtureTearDown]
        public void TearDownFixture()
        {
            this.VeriStandInterop.CloseVeristand();
        }

        [Test]
        public void OpenProjectShouldThrowExceptionIfProjectIsInvalid()
        {
            Assert.Throws<VeriStandException>(() =>
            {
                this.VeriStandInterop.OpenProject(@"this is an invalid project path");
            });
        }

        [Test]
        public void ShouldOpenProject()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropTests.ExampleVeriStandProjectPath);

            Assert.IsNotNull(this.VeriStandInterop.Project);
        }

        [Test]
        public void OpenShouldClosePreviouslyOpenedProject()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropTests.ExampleVeriStandProjectPath);
            this.VeriStandInterop.OpenProject(VeriStandInteropTests.ExampleVeriStandProjectPath);
        }

        [Test]
        public void ShowProjectWindowShouldShowWindow()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropTests.ExampleVeriStandProjectPath);
            this.VeriStandInterop.ShowProjectWindow();

            Assert.IsTrue(this.VeriStandInterop.Project.Visible);
        }

        /*
        [Test]
        public void HideProjectWindowShouldHideWindow()
        {
            this.VeriStandInterop.OpenProject(VeriStandInteropTests.ExampleVeriStandProjectPath);

            this.VeriStandInterop.ShowProjectWindow();
 
            this.VeriStandInterop.HideProjectWindow();

            Assert.IsFalse(this.VeriStandInterop.Project.Visible);
        }*/

        [Test]
        public void ShowProjectShouldThrowExceptionIfProjectNotOpened()
        {
            this.VeriStandInterop.CloseVeristand();
            this.VeriStandInterop.LaunchVeriStand();

            Exception e = Assert.Throws<InvalidOperationException>(() =>
            {
                this.VeriStandInterop.ShowProjectWindow();
            });

            Assert.AreEqual(ErrorMessages.ErrorMessageShowHide, e.Message);
        }

        /*
        [Test]
        public void HideProjectShouldThrowExceptionIfProjectNotOpened()
        {
            this.VeriStandInterop.CloseVeristand();
            this.VeriStandInterop.LaunchVeriStand();

            Exception e = Assert.Throws<InvalidOperationException>(() =>
            {
                this.VeriStandInterop.HideProjectWindow();
            });

            Assert.AreEqual(ErrorMessages.ErrorMessageShowHide, e.Message);
        }
        */
    }
}
