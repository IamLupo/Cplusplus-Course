@echo off

:: Mingw-w64 compiler directory
set mingw64_dir=C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin
::----------------------------------------------------------------------------------------

::--- Generated variables ----------------------------------------------------------------
set PATH=%PATH%;%mingw64_dir%
::----------------------------------------------------------------------------------------

echo Compiling myclass
g++ -c myclass.cpp -o myclass.o -static -std=c++11

echo Compiling main
g++ main.cpp myclass.o -o main.exe -static -std=c++11 -s

pause

main.exe

pause
