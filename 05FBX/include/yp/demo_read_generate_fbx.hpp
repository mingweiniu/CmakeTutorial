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
#include <utility>

#include "File/ReadDirectory.hpp"
#include "Geometry/ManagerHandle.hpp"
#include "Geometry/SceneHandle.hpp"
#include "Geometry/Cube.hpp"
#include "Geometry/Cylinder.hpp"
#include "Geometry/Sphere.hpp"

namespace yp {
	void demo_read_generate_fbx(std::string path) {

		std::vector<yp::FileContent> read_files;
		auto paths = files_path(path.c_str());
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
					yp::Cylinder cylinder_1(MyScene1.getScene(), component_name.c_str());
					cylinder_1.trans(std::rand() % 1000, std::rand() % 1000, std::rand() % 1000);
					cylinder_1.rotate(std::rand() % 90, std::rand() % 90, std::rand() % 90);
					cylinder_1.scale((std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f);
					MyScene1.addNode(cylinder_1.getNode());
				}
				if (type == 1) {
					// draw a cube
					yp::Cube cube_1(MyScene1.getScene(), component_name.c_str());
					cube_1.trans(std::rand() % 1000, std::rand() % 1000, std::rand() % 1000);
					cube_1.rotate(std::rand() % 90, std::rand() % 90, std::rand() % 90);
					cube_1.scale((std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f, (std::rand() % 50) / 25.0f);
					MyScene1.addNode(cube_1.getNode());
				}
				if (type == 2) {
					// draw a ball
					yp::Sphere ball_1(MyScene1.getScene(), component_name.c_str());
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
}

#endif // !YOREADGENFBX_HPP