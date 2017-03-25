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

#include <yp/demo_draw_fbx.hpp>
#include <yp/File/ReadDirectory.hpp>
#include <yp/demo_read_generate_fbx.hpp>

#define DEBUG_VS14

int main(int argc, char** argv)
{
#if !defined(DEBUG_VS14)
	std::vector<std::string> inputs;
	inputs.reserve(argc);
	for (int i = 0; i < argc; ++i) {
		inputs.push_back(argv[i]);
	}
	std::cout << "argvs are : \n";
	for (auto argv : inputs) {
		std::cout << '\t' << argv << '\n';
	}

	auto read_path{ inputs[1] };
#else
	std::string path{ ".\\testData\\" };
#endif


	//yp::demo_draw_fbx();
	//yp::demo_read_file();
	//yp::demo_read_generate_fbx(read_path);

	std::vector<yp::FileContent> read_files;
	auto paths = yp::files_path(path.c_str());
	for (auto path : paths) {
		yp::FileContent temp(path);
		std::cout << "read_files.push_back(" << path << ")\n";
		read_files.push_back(std::move(temp));

	}

	for (auto file : read_files) {
		std::cout << "path is : " << file.getPath() << '\n';
		yp::ManagerHandle Manager1(file.getPath());
		yp::SceneHandle MyScene1(Manager1.getManager());
		std::cout << "searching : " << file.getPath() << '\n';
		for (auto component : file.Objects) {
			std::string model{}, element{};
			std::string RangeLow{}, RangeHigh{};
			for (auto line : component) {
				auto length = line.size();
				auto find_Model = line.find("Model =");
				auto find_element = line.find("ElementID =");
				if (find_Model < length) {
					decltype(line) temp(line, find_Model + 7, length - find_Model - 7);
					model += temp;
				}
				if (find_element < length) {
					decltype(line) temp(line, find_element + 11, length - find_element - 11);
					element += temp;
				}
				auto find_low = line.find("RangeLow = <DPoint3d xyz=\"");
				auto find_high = line.find("RangeHigh = <DPoint3d xyz=\"");
				if (find_low < length){
					decltype(line) temp(line, find_low + 26);
					RangeLow += temp;
				}
				if (find_high < length) {
					decltype(line) temp(line, find_high + 27);
					RangeHigh += temp;
				}
			}
			std::cout << "(low, high)" << RangeLow << ", " << RangeHigh << '\n';

			std::vector<long long> RangeLxyzHxyz;

			while (RangeLow.find(",") < RangeLow.size()) {
				std::string number(RangeLow, 0, RangeLow.find(","));
				RangeLxyzHxyz.push_back(std::stoll(number));
				RangeLow.erase(RangeLow.begin(), RangeLow.begin() + RangeLow.find(",") + 1);
			}
			if (RangeLow.find("\"") < RangeLow.size()) {
				RangeLow.erase(RangeLow.find("\""));
				RangeLxyzHxyz.push_back(std::stoll(RangeLow));
			}


			while (RangeHigh.find(",") < RangeHigh.size()) {
				std::string number(RangeHigh, 0, RangeHigh.find(","));
				RangeLxyzHxyz.push_back(std::stoll(number));
				RangeHigh.erase(RangeHigh.begin(), RangeHigh.begin() + RangeHigh.find(",") + 1);
			}
			if (RangeHigh.find("\"") < RangeHigh.size()) {
				RangeHigh.erase(RangeHigh.find("\""));
				RangeLxyzHxyz.push_back(std::stoll(RangeHigh));
			}

			
			for (auto i : RangeLxyzHxyz) {
				std::cout << i << '\n';
			}


			auto component_name{ std::move(model) };
			component_name += '?';
			component_name += std::move(element);
			std::cout << "creating : " << component_name << "\n";

		}
	}
	system("PAUSE");
}
#endif // !MAIN_CPP
