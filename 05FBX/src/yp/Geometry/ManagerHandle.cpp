#ifndef YPMANAGERHANDLE_CPP
#define YPMANAGERHANDLE_CPP

#include <fbxsdk.h>
#include <string>
#include <utility>
#include <yp\Geometry\ManagerHandle.hpp>

namespace yp {
	ManagerHandle::ManagerHandle(std::string Name)
	{
		//The first thing to do is to create the FBX Manager which is the object allocator for almost all the classes in the SDK	Manager = FbxManager::Create();
		Manager = FbxManager::Create();
		if (!Manager) FBXSDK_printf("Error: Unable to create FBX Manager!\n");
		else FBXSDK_printf("Autodesk FBX SDK version %s\n", Manager->GetVersion());

		//Create an IOSettings object. This object holds all import/export settings.
		auto ios = FbxIOSettings::Create(Manager, IOSROOT);
		Manager->SetIOSettings(std::move(ios));

		//Load plugins from the executable directory (optional)
		auto Path = FbxGetApplicationDirectory();
		Manager->LoadPluginsDirectory(Path.Buffer());
	}

	ManagerHandle::~ManagerHandle()
	{
		//Delete the FBX Manager. All the objects that have been allocated using the FBX Manager and that haven't been explicitly destroyed are also automatically destroyed.
		Manager->Destroy();
	}

	FbxManager * ManagerHandle::getManager()
	{
		return Manager;;
	}

	std::string ManagerHandle::getName()
	{
		return Name;
	}
}
#endif // !YPMANAGERHANDLE_CPP