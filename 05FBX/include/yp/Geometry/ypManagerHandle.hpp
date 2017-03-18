#ifndef YPMANAGERHANDLE_HPP
#define YPMANAGERHANDLE_HPP

#include <fbxsdk.h>
#include <string>
#include <utility>

class ypManagerHandle {
public:
	ypManagerHandle(std::string Name);
	~ypManagerHandle();
	FbxManager* getManager();
	std::string getName();
private:
	std::string Name;
	FbxManager* Manager{};
};
#endif // !YPMANAGERHANDLE_HPP