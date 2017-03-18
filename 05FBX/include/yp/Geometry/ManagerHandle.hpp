#ifndef YPMANAGERHANDLE_HPP
#define YPMANAGERHANDLE_HPP

#include <fbxsdk.h>
#include <string>
#include <utility>
namespace yp {
	class ManagerHandle {
	public:
		ManagerHandle(std::string Name);
		~ManagerHandle();
		FbxManager* getManager();
		std::string getName();
	private:
		std::string Name;
		FbxManager* Manager{};
	};
}
#endif // !YPMANAGERHANDLE_HPP