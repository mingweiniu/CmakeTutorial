#ifndef YOREADGENFBX_HPP
#define YOREADGENFBX_HPP

#ifdef _MSC_VER
#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif //!_CRT_SECURE_NO_WARNINGS
#endif //_MSC_VER

#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>

#include "./Geometry/ypGeometry.hpp"
#include "./File/ypReadDirectory.hpp"


void yp_demo_read_generate_fbx(){
	// just draw someting from txt to fbx to files
	std::string read_path(".\\testData\\");
	std::vector<ypFileContent> read_files;
	ypDirectory dir_testDate(read_path.c_str());
	for (auto i : dir_testDate.files_path) {
		ypFileContent temp(i);
		read_files.push_back(std::move(temp));
		std::cout << "read_files.push_back(" << i << ")\n";
	}

	for (auto file : read_files) {
		ypManagerHandle<> Manager1(file.getPath());
		ypSceneHandle<> MyScene1(Manager1.getManager());
		std::cout << "searching : " << file.getPath() << '\n';

		for (auto component : file.Objects) {
			std::string model{}, element{};
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
			}
			auto component_name{ std::move(model) };
			component_name += '?';
			component_name += std::move(element);
			std::cout << "creating : " << component_name << "\n";

			auto type = std::rand() % 3;
			if (type == 0) {
				// draw a cylinder
				ypCylinder cylinder_1(MyScene1.getScene(), component_name.c_str());
				cylinder_1.trans(std::rand() % 1000, std::rand() % 1000, std::rand() % 1000);
				cylinder_1.rotate(std::rand() % 90, std::rand() % 90, std::rand() % 90);
				cylinder_1.scale((std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f);
				MyScene1.addNode(cylinder_1.getNode());
			}
			if (type == 1) {
				// draw a cube
				ypCube cube_1(MyScene1.getScene(), component_name.c_str());
				cube_1.trans(std::rand() % 1000, std::rand() % 1000, std::rand() % 1000);
				cube_1.rotate(std::rand() % 90, std::rand() % 90, std::rand() % 90);
				cube_1.scale((std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f);
				MyScene1.addNode(cube_1.getNode());
			}
			if (type == 2) {
				// draw a ball
				ypSphere ball_1(MyScene1.getScene(), component_name.c_str());
				ball_1.trans(std::rand() % 1000, std::rand() % 1000, std::rand() % 1000);
				ball_1.rotate(std::rand() % 90, std::rand() % 90, std::rand() % 90);
				ball_1.scale((std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f);
				MyScene1.addNode(ball_1.getNode());
			}

		}

		// save it
		auto save_path{ file.getPath() };
		save_path += ".fbx";
		MyScene1.Save(save_path);
	}

}


#endif // !YOREADGENFBX_HPP