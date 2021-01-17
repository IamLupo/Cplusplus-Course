@echo off

:: Mingw-w64 compiler directory
set mingw64_dir=C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin
::----------------------------------------------------------------------------------------

::--- Generated variables ----------------------------------------------------------------
set PATH=%PATH%;%mingw64_dir%
::----------------------------------------------------------------------------------------

echo Compiling math
g++ -c src/math.cpp -o src/math.o -I "./include" --std=c++17

echo Compiling lib
ar rcs lib/libmycustomlib.a src/math.o

pause
