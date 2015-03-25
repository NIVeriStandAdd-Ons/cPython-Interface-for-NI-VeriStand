from ctypes import *
import datetime
import traceback
import sys

from time import sleep
                
veristandInterOp = cdll.LoadLibrary("VeriStandCviDll.dll")
print veristandInterOp

print "InitPlatform"

status = veristandInterOp.LaunchVeriStand()

if status != 0:
    print "Failed To Launch VeriStand"
    
print "DownloadProject"
veristandInterOp.OpenProject("C:\Users\Public\Documents\National Instruments\NI VeriStand 2011\Projects\Example\Sinewave Delay.nivsproj")

print "Run"
veristandInterOp.RunProject()

sleep(10)
start = datetime.datetime.now()

print datetime.datetime.now()

h_value = c_double(0.0)

for i in range(0,1999):
    veristandInterOp.GetChannelValue("Aliases/SineWave", byref(h_value))
#    print "value is: "
#    print h_value

end = datetime.datetime.now()
print datetime.datetime.now()
diff = end - start
print diff

print "DeinitPlatform"
veristandInterOp.CloseVeristand()
print "Exit"
