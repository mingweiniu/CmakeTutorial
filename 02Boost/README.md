# 02Boost

on unix, you will fail if just
$ g++ main.cpp

you need 
$ mkdir build && cd build && cmake .. && make


on windows, 
you need BOOST_ROOT in $Env:Path, 
then you could use cmake gui.
