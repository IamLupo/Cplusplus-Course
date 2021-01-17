@echo off

:: Mingw-w64 compiler directory
set mingw64_dir=C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin
::----------------------------------------------------------------------------------------

::--- Generated variables ----------------------------------------------------------------
set PATH=%PATH%;%mingw64_dir%
::----------------------------------------------------------------------------------------

echo Compiling runner
g++ runner.cpp -o runner.exe -static -std=c++11 -s

echo Compiling injector
g++ injector.cpp -o injector.exe -static -std=c++11 -lPsapi -s

echo Compiling simple_dll
g++ simple_dll.cpp -o simple_dll.dll -shared -static-libgcc -static-libstdc++ -static --std=c++17 -s

echo Compiling patch_run_dll
g++ patch_run_dll.cpp -o patch_run_dll.dll -shared -static-libgcc -static-libstdc++ -static --std=c++17 -s

pause

run.bat
