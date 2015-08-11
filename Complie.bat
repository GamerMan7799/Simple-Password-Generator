@echo off
:: A few quick notes about this. 
:: %~dp0 is the directory the batch file is in, and it ends with a '\' so don't add it
:: The Batch file has to stay in the main to work as it is written right now

::Delete the old .exe if it exists
IF EXIST Password-Generator.exe del /F Password-Generator.exe
::Delete Stackdump if it exists (so as to not confuse me later)
IF EXIST Password-Generator.exe.stackdump del /F Password-Generator.exe.stackdump

cd %~dp0res
::Complie the resource files of the icon and boilerplate
windres my_icon.rc -O coff my_icon.res
windres boilerplate.rc -O coff boilerplate.res

cd %~dp0

gcc -g -Wall -o Password-Generator.exe %~dp0src\main.c %~dp0Res\boilerplate.res %~dp0Res\my_icon.res

IF EXIST %~dp0Res\boilerplate.res del /F %~dp0Res\boilerplate.res
IF EXIST %~dp0Res\my_icon.res del /F %~dp0Res\my_icon.res
pause
