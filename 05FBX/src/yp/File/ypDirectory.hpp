#ifndef YPDIRECTORY_HPP
#define YPDIRECTORY_HPP

#include <iostream>
#include <vector>
#include <string>
/*
#include <boost/filesystem.hpp>
#include <boost/range/iterator_range.hpp>
*/


class ypDirectory {
public:
	ypDirectory(std::string directory_path);
	std::vector<std::string> files_path;

private:

};

ypDirectory::ypDirectory(std::string directory_path) {
	//enum all file in this dir
	/*
	boost::filesystem::path dir_path(directory_path.c_str());
	auto is_path = boost::filesystem::is_directory(dir_path);
	std::string temp_chars;
	for (auto& entry : boost::make_iterator_range(boost::filesystem::directory_iterator(dir_path), {})) {
		auto temp_path = entry.path();
		files_path.push_back(temp_path.string());
	}
	*/
}




#endif // !YPDIRECTORY_HPP