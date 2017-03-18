#ifndef YPFILECONTENT_HPP
#define YPFILECONTENT_HPP

#include <string>
#include <iostream>
#include <vector>


namespace yp {
	class FileContent {
	public:
		FileContent(std::string file_path);
		std::vector<std::vector<std::string>> Objects;
		auto getPath() { return Path; }
	private:
		std::string Path;
	};
	
}
#endif // !YPFILECONTENT_HPP
