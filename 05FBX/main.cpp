#ifndef MAIN_CPP
#define MAIN_CPP

#ifdef _MSC_VER
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif //!_CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

#include <yp/Geometry/Geometry.hpp>
#include <yp/File/ReadDirectory.hpp>
#include <yp/ReadGenFBX.hpp>


int main(int argc, char** argv)
{
	yp::demo_geometry_fbx();
	yp::demo_read_file();
	yp::demo_read_generate_fbx();
	system("PAUSE");
}
#endif // !MAIN_CPP
