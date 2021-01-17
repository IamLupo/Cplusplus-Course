@echo off

:: Mingw-w64 compiler directory
set mingw64_dir=C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin
::----------------------------------------------------------------------------------------

::--- Generated variables ----------------------------------------------------------------
set PATH=%PATH%;%mingw64_dir%
::----------------------------------------------------------------------------------------

echo Compiling cfunctions
gcc -c cfunctions.c -o cfunctions.o

echo Compiling main
g++ main.cpp cfunctions.o -o main.exe -static -std=c++11 -O2


pause

main.exe

pause
