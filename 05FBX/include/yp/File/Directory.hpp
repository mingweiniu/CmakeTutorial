#ifndef YPDIRECTORY_HPP
#define YPDIRECTORY_HPP

#include <iostream>
#include <vector>
#include <string>

#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>

namespace yp {
	decltype(auto) files_path(std::string directory_path) {

		std::vector<std::string> files_path;

		boost::filesystem::path dir_path(directory_path.c_str());
		auto is_path = boost::filesystem::is_directory(dir_path);
		if (!is_path) {
			std::cout << directory_path << " is not a path\n";
		}
		else {
			std::string temp_chars;
			for (auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(dir_path), {})) {
				auto temp_path = entry.path();
				files_path.push_back(temp_path.string());
			}
		}
		return files_path;
	}
}
#endif // !YPDIRECTORY_HPP