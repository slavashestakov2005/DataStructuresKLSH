set FileName=%1
if not exist build_cpp mkdir build_cpp
if not exist build_cpp\\obj mkdir build_cpp\\obj

make run -f .vscode\\Makefile
build_cpp\\run.exe
