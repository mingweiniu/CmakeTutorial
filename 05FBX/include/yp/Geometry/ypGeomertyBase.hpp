#ifndef YPGEOMETRYBASE_HPP
#define YPGEOMETRYBASE_HPP

#include <fbxsdk.h>
#include <string>

struct vec4 {
	double x, y, z, w;
};

// fbxType relys on which basic shape for the model
template<typename fbx_Type>
class ypGeomertyBase {
public:
	auto getNode() {
		Node = FbxNode::Create(Scene, Name.c_str());
		Node->LclRotation.Set(Rotation);
		Node->LclTranslation.Set(Translation);
		FbxVector4 Scale(Scale_vec.x, Scale_vec.y, Scale_vec.z);
		Node->LclScaling.Set(Scale);
		Node->SetNodeAttribute(Obj);
		return Node;
	}
	void rotate(double x_axis, double y_axis, double z_axis) {
		FbxVector4 temp(x_axis, y_axis, z_axis);
		Rotation += temp;
	}
	void trans(double x, double y, double z) {
		FbxVector4 temp(x, y, z);
		Translation += temp;
	}
	void scale(double x, double y, double z) {
		Scale_vec.x *= x;
		Scale_vec.y *= y;
		Scale_vec.z *= z;
	}
protected:
	FbxScene* Scene;
	std::string Name{};
	fbx_Type* Obj;
	void init_scene_name_obj(FbxScene* Scene, std::string Name) {
		this->Scene = Scene;
		this->Name += Name;
		std::string ObjName = Name + "Mesh";
		Obj = fbx_Type::Create(Scene, ObjName.c_str());
	}
	FbxNode* Node;
	FbxVector4 Rotation{ 0.0, 0.0, 0.0 };
	FbxVector4 Translation{ 0.0, 0.0, 0.0 };
	vec4 Scale_vec{ 1.0, 1.0, 1.0, 1.0 };
};
#endif // !YPGEOMETRYBASE_HPP