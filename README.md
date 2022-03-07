Example of cross platform C++ CMake build with google tests

# CMake Build and Run in WSL

## Open WSL command prompt
```
wsl
```

## Go to the source file directory
```
cd /mnt/c/code/c++/github.com/335is/hello_test
```

## Create a build directory, generate makefiles, build all outputs.
```rm -r build
mkdir build
cd build
cmake -S ../ -B .
make
```

## Run the tests, display return value
```
./hello_test
echo $?
```

# CMake Build and Run in Windows

## Open developer command prompt for Visual Studio
```
%comspec% /k "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat"
```

## Go to the source file directory
```
cd C:\github.com\335is\hello_test
```

## Build with CMake in Windows
```
rd /s /q build
md build
cd build
cmake -S ../ -B .
cmake --build . --config Debug
cmake --build . --config Release
```

## Run the tests, display return value
```
.\Debug\hello_test.exe
.\Release\hello_test.exe
echo %ERRORLEVEL%
```
