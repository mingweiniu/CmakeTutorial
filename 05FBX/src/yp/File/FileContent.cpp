
#include <fstream>
#include <sstream>
#include <utility>
#include <yp\File\FileContent.hpp>

yp::FileContent::FileContent(std::string file_path)
{
	std::ifstream File_test;
	Path = file_path;
	File_test.open(file_path.c_str());

	std::stringstream read_streams;
	read_streams << File_test.rdbuf();
	File_test.close();

	std::vector<std::string> content;
	auto buffer_chars = read_streams.str();
	std::string temp_chars;
	for (auto i : buffer_chars) {
		if (i == '\n')
			content.push_back(std::move(temp_chars));
		else
			temp_chars += i;
	}

	std::vector<std::string> temp_strings;
	for (auto i : content) {
		temp_strings.push_back(i);
		auto find_palce = i.find("Outputing element: Bentley.IModel.Core.IModelElement");
		if (find_palce < i.size())
			Objects.push_back(std::move(temp_strings));
	}
	Objects.push_back(std::move(temp_strings));
}