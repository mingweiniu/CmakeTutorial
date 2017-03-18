#ifndef YPSCENEHANDLE_HPP
#define YPSCENEHANDLE_HPP

#include <iostream>
#include <string>
#include <fbxsdk.h>


class ypSceneHandle {
public:
	ypSceneHandle(FbxManager* Manager);
	~ypSceneHandle();
	FbxScene* getScene();
	void addNode(FbxNode* Node);
	bool Save(std::string PATH);
private:
	FbxScene* Scene;
	FbxNode* Root;
	FbxManager* Manager;
};


ypSceneHandle::ypSceneHandle(FbxManager* Manager) :Manager(Manager)
{
	//Create an FBX scene. This object holds most objects imported/exported from/to files.
	Scene = FbxScene::Create(Manager, "My Scene");
	if (!Scene) FBXSDK_printf("Error: Unable to create FBX scene!\n");

	Root = Scene->GetRootNode();


	// create scene info
	auto sceneInfo = FbxDocumentInfo::Create(Manager, "SceneInfo");
	sceneInfo->mTitle = "Example scene";
	sceneInfo->mSubject = "Illustrates the creation and animation of a deformed cylinder.";
	sceneInfo->mAuthor = "ExportScene01.exe sample program.";
	sceneInfo->mRevision = "rev. 1.0";
	sceneInfo->mKeywords = "deformed cylinder";
	sceneInfo->mComment = "no particular comments required.";
	// that function is asking the scene for the sceneInfo.
	Scene->SetSceneInfo(sceneInfo);

}


ypSceneHandle::~ypSceneHandle()
{
	//do nothing
}


inline FbxScene * ypSceneHandle::getScene()
{
	return Scene;
}


void ypSceneHandle::addNode(FbxNode* Node)
{
	Root->AddChild(Node);
}


bool ypSceneHandle::Save(std::string PATH)
{
	std::cout << "Saving Scene to : " << PATH << '\n';
	int FileFormat = 0;
	// Create an exporter.
	auto lExporter = FbxExporter::Create(Manager, "");

	if (FileFormat < 0 || FileFormat >= Manager->GetIOPluginRegistry()->GetWriterFormatCount())
	{
		// Write in fall back format in less no ASCII format found
		FileFormat = Manager->GetIOPluginRegistry()->GetNativeWriterFormat();

		//Try to export in ASCII if possible
		auto lFormatCount = Manager->GetIOPluginRegistry()->GetWriterFormatCount();

		for (int lFormatIndex = 0; lFormatIndex<lFormatCount; lFormatIndex++)
		{
			if (Manager->GetIOPluginRegistry()->WriterIsFBX(lFormatIndex))
			{
				FbxString lDesc = Manager->GetIOPluginRegistry()->GetWriterFormatDescription(lFormatIndex);
				const char *lASCII = "ascii";
				if (lDesc.Find(lASCII) >= 0)
				{
					FileFormat = lFormatIndex;
					break;
				}
			}
		}
	}


	// Initialize the exporter by providing a filename.
	auto res = lExporter->Initialize(PATH.c_str(), FileFormat, Manager->GetIOSettings());
	if (res == false)
	{
		FBXSDK_printf("Call to FbxExporter::Initialize() failed.\n");
		FBXSDK_printf("Error returned: %s\n\n", lExporter->GetStatus().GetErrorString());
		return false;
	}

	int lMajor, lMinor, lRevision;
	FbxManager::GetFileFormatVersion(lMajor, lMinor, lRevision);
	FBXSDK_printf("FBX file format version %d.%d.%d\n\n", lMajor, lMinor, lRevision);

	// Export the scene.
	auto lStatus = lExporter->Export(Scene);

	// Destroy the exporter.
	lExporter->Destroy();
	return lStatus;
}

#endif // !YPSCENEHANDLE_HPP