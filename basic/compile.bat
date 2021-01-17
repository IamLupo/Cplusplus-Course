@echo off

:: Mingw-w64 compiler directory
set mingw64_dir=C:\Program Files\mingw-w64\x86_64-8.1.0-win32-seh-rt_v6-rev0\mingw64\bin
::----------------------------------------------------------------------------------------

::--- Generated variables ----------------------------------------------------------------
set PATH=%PATH%;%mingw64_dir%
::----------------------------------------------------------------------------------------

echo Compiling Console
g++ console.cpp -o console.exe -static -std=c++17 -s

echo Compiling String
g++ string.cpp -o string.exe -static -std=c++17 -s

echo Compiling Vector
g++ vector.cpp -o vector.exe -static -std=c++17 -s

echo Compiling TryCatch
g++ trycatch.cpp -o trycatch.exe -static -std=c++17 -s

echo Compiling MyClass
g++ -c myclass.cpp -o myclass.o -static -std=c++17

echo Compiling Class
g++ class.cpp myclass.o -o class.exe -static -std=c++17 -s

echo Compiling Pointers
g++ pointers.cpp -o pointers.exe -static -std=c++17 -s

pause
