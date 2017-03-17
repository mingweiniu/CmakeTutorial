#ifndef MAIN_CPP
#define MAIN_CPP
/*
 * extract all *.7z in ../libs/vs2015
 * Windows and x64 Release mode only. :D
 */
/*
 * FBX tutorial : 
 * http://help.autodesk.com/view/FBX/2017/ENU/?guid=__cpp_ref_index_html
 */

#ifdef _MSC_VER
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif //!_CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
/*
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
*/

#include <yp/Geometry/ypGeometry.hpp>

int main(int argc, char** argv)
{
	yp_demo_geometry_fbx();
	system("PAUSE");
}
#endif // !MAIN_CPP
