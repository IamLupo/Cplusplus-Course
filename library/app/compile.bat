@echo off

:: Mingw-w64 compiler directory
set mingw64_dir=C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin
::----------------------------------------------------------------------------------------

::--- Generated variables ----------------------------------------------------------------
set PATH=%PATH%;%mingw64_dir%
::----------------------------------------------------------------------------------------

echo Compiling main
g++ main.cpp -o main.exe -I "../my_custom_lib/include" -L "../my_custom_lib/lib" -lmycustomlib -static -std=c++11 -s

pause

main.exe

pause
