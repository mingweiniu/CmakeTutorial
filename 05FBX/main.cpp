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

#include <yp/Geometry/demo_draw_fbx.hpp>
#include <yp/File/ReadDirectory.hpp>
#include <yp/demo_read_generate_fbx.hpp>


int main(int argc, char** argv)
{
	std::vector<std::string> inputs;
	inputs.reserve(argc);
	for (int i = 0; i < argc; ++i) {
		inputs.push_back(argv[i]);
	}
	std::cout << "argvs are : \n";
	for(auto argv : inputs){
		std::cout << '\t' << argv << '\n';
	}
	
	yp::demo_draw_fbx();
	//yp::demo_read_file();
	//yp::demo_read_generate_fbx(inputs[1]);




	system("PAUSE");
}
#endif // !MAIN_CPP
