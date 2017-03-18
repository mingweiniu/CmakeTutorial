#ifndef YPREADDIRECTORY_HPP
#define YPREADDIRECTORY_HPP


#include "Directory.hpp"
#include "FileContent.hpp"

namespace yp {
	void demo_read_file() {

		std::vector<yp::FileContent> read_files;

		auto dir_testDate = files_path("./testData/");

		for (auto i : dir_testDate) {
			yp::FileContent temp(i);
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
}
#endif // !YPREADDIRECTORY_HPP
