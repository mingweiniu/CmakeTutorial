#ifndef YPREADDIRECTORY_HPP
#define YPREADDIRECTORY_HPP


#include "ypDirectory.hpp"
#include "ypFileContent.hpp"

void yp_demo_read_file() {

	std::vector<ypFileContent> read_files;

	ypDirectory dir_testDate("./testData/");
	for (auto i : dir_testDate.files_path) {
		ypFileContent temp(i);
		read_files.push_back(std::move(temp));
		std::cout << "read_files.push_back(" << i << ")\n";
	}

	for (auto file : read_files) {
		std::cout << file.getPath() << '\n';
		for (auto component : file.Objects) {
			auto is_in = false;
			for (auto line : component) {
				if (line.find("ReadBusinessDataAndGraphics") < line.size()) is_in = true;
				if (line.find("ReadGraphicsAndRelatedData") < line.size()) is_in = false;
				if (is_in)
					std::cout << line << '\n';
			}
		}
	}
}

#endif // !YPREADDIRECTORY_HPP
