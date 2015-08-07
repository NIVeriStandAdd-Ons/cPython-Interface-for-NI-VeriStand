@echo "c:\program files (x86)\national instruments\cvi2013\sdk\bin\rc.exe" /d _CVI_ /i "c:\program files (x86)\national instruments\cvi2013\sdk\include" /fo %2 %1
@"c:\program files (x86)\national instruments\cvi2013\sdk\bin\rc.exe" /d _CVI_ /i "c:\program files (x86)\national instruments\cvi2013\sdk\include" /fo %2 %1 > Rc.out 2>&1
@if errorlevel 1 goto err
@echo RC complete
@exit 0
:err
@echo RC failed
@exit 1
