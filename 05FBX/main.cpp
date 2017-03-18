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

#include <yp/Geometry/ypGeometry.hpp>
#include <yp/File/ypReadDirectory.hpp>



int main(int argc, char** argv)
{
	yp_demo_geometry_fbx();
	yp_demo_read_file();
	system("PAUSE");
}
#endif // !MAIN_CPP
