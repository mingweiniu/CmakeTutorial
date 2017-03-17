#ifndef YPMANAGERHANDLE_HPP
#define YPMANAGERHANDLE_HPP

#include <fbxsdk.h>
#include <string>
#include <utility>

template<typename...Ts>
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

template<typename ...Ts>
ypManagerHandle<Ts...>::ypManagerHandle(std::string Name) : Name(std::move(Name))
{
	//The first thing to do is to create the FBX Manager which is the object allocator for almost all the classes in the SDK	Manager = FbxManager::Create();
	Manager = FbxManager::Create();
	if(! Manager) FBXSDK_printf("Error: Unable to create FBX Manager!\n");
	else FBXSDK_printf("Autodesk FBX SDK version %s\n", Manager->GetVersion());

	//Create an IOSettings object. This object holds all import/export settings.
	auto ios = FbxIOSettings::Create(Manager, IOSROOT);
	Manager->SetIOSettings(std::move(ios));

	//Load plugins from the executable directory (optional)
	auto Path = FbxGetApplicationDirectory();
	Manager->LoadPluginsDirectory(Path.Buffer());
}

template<typename ...Ts>
ypManagerHandle<Ts...>::~ypManagerHandle()
{
	//Delete the FBX Manager. All the objects that have been allocated using the FBX Manager and that haven't been explicitly destroyed are also automatically destroyed.
	Manager->Destroy();
}

template<typename ...Ts>
FbxManager * ypManagerHandle<Ts...>::getManager()
{
	return Manager;
}

template<typename ...Ts>
std::string ypManagerHandle<Ts...>::getName()
{
	return Name;
}

#endif // !YPMANAGERHANDLE_HPP