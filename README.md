# cmake_test_boost

on unix, you will fail if just 
$ g++ main.cpp

you need 
$ mkdir build && cd build && cmake .. && make

on windows, need BOOST_ROOT in path
then you could use cmake gui.
