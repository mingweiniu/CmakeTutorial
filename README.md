# cmake_test_boost

on unix, you will fail if just \n 
$ g++ main.cpp

you need 
$ mkdir build && cd build && cmake .. && make

on windows, need BOOST_ROOT in $Env:Path
then you could use cmake gui.
