#ifndef YPCUBE_HPP
#define YPCUBE_HPP

#include "GeomertyBase.hpp"
#include <vector>

namespace yp {
	class Cube : public GeomertyBase<FbxMesh> {
	public:
		Cube(FbxScene* Scene, std::string Name)
		{
			init_scene_name_obj(Scene, Name);

			const int cube_size = 50;
			// draw a cube
			// L: leftside ; R: rightside
			// D: downside ; U: Upperside
			// F: frontside ; B: backside
			FbxVector4 LDF(-cube_size, -cube_size, cube_size);
			FbxVector4 RDF(cube_size, -cube_size, cube_size);
			FbxVector4 RUF(cube_size, cube_size, cube_size);
			FbxVector4 LUF(-cube_size, cube_size, cube_size);
			FbxVector4 LDB(-cube_size, -cube_size, -cube_size);
			FbxVector4 RDB(cube_size, -cube_size, -cube_size);
			FbxVector4 RUB(cube_size, cube_size, -cube_size);
			FbxVector4 LUB(-cube_size, cube_size, -cube_size);

			// Create control points.
			Obj->InitControlPoints(24);
			FbxVector4* ControlPoints = Obj->GetControlPoints();

			ControlPoints[0] = LDF;
			ControlPoints[1] = RDF;
			ControlPoints[2] = RUF;
			ControlPoints[3] = LUF;

			ControlPoints[4] = RDF;
			ControlPoints[5] = RDB;
			ControlPoints[6] = RUB;
			ControlPoints[7] = RUF;

			ControlPoints[8] = RDB;
			ControlPoints[9] = LDB;
			ControlPoints[10] = LUB;
			ControlPoints[11] = RUB;

			ControlPoints[12] = LDB;
			ControlPoints[13] = LDF;
			ControlPoints[14] = LUF;
			ControlPoints[15] = LUB;

			ControlPoints[16] = LUF;
			ControlPoints[17] = RUF;
			ControlPoints[18] = RUB;
			ControlPoints[19] = LUB;

			ControlPoints[20] = RDF;
			ControlPoints[21] = LDF;
			ControlPoints[22] = LDB;
			ControlPoints[23] = RDB;



			std::vector<FbxVector4> Normals;
			Normals.reserve(6);

			FbxVector4 lNormalZPos(0, 0, 1);
			FbxVector4 lNormalXPos(1, 0, 0);
			FbxVector4 lNormalZNeg(0, 0, -1);
			FbxVector4 lNormalXNeg(-1, 0, 0);
			FbxVector4 lNormalYPos(0, 1, 0);
			FbxVector4 lNormalYNeg(0, -1, 0);

			Normals.push_back(std::move(lNormalZPos));
			Normals.push_back(std::move(lNormalXPos));
			Normals.push_back(std::move(lNormalZNeg));
			Normals.push_back(std::move(lNormalXNeg));
			Normals.push_back(std::move(lNormalYPos));
			Normals.push_back(std::move(lNormalYNeg));

			// We want to have one normal for each vertex (or control point),
			// so we set the mapping mode to eByControlPoint.
			FbxGeometryElementNormal* lGeometryElementNormal = Obj->CreateElementNormal();

			lGeometryElementNormal->SetMappingMode(FbxGeometryElement::eByControlPoint);

			// Set the normal values for every control point.
			lGeometryElementNormal->SetReferenceMode(FbxGeometryElement::eDirect);


			for (auto normal : Normals) {
				for (auto i = 0;i < 4;++i) {
					lGeometryElementNormal->GetDirectArray().Add(normal);
				}
			}

			// Array of polygon vertices.
			int lPolygonVertices[] = {
				0, 1, 2, 3,
				4, 5, 6, 7,
				8, 9, 10, 11,
				12, 13, 14, 15,
				16, 17, 18, 19,
				20, 21, 22, 23
			};

			// Create UV for Diffuse channel.
			FbxGeometryElementUV* lUVDiffuseElement = Obj->CreateElementUV("DiffuseUV");
			FBX_ASSERT(lUVDiffuseElement != NULL);
			lUVDiffuseElement->SetMappingMode(FbxGeometryElement::eByPolygonVertex);
			lUVDiffuseElement->SetReferenceMode(FbxGeometryElement::eIndexToDirect);

			std::vector<FbxVector2> lVectors{ {0,0},{1,0},{1,1},{0,1} };
			for (auto i : lVectors) lUVDiffuseElement->GetDirectArray().Add(i);


			//Now we have set the UVs as eIndexToDirect reference and in eByPolygonVertex  mapping mode
			//we must update the size of the index array.
			lUVDiffuseElement->GetIndexArray().SetCount(24);

			// Create polygons. Assign texture and texture UV indices.
			for (int i = 0; i < 6; ++i)
			{
				// all faces of the cube have the same texture
				Obj->BeginPolygon(-1, -1, -1, false);

				for (int j = 0; j < 4; ++j)
				{
					// Control point index
					Obj->AddPolygon(lPolygonVertices[i * 4 + j]);

					// update the index array of the UVs that map the texture to the face
					lUVDiffuseElement->GetIndexArray().SetAt(i * 4 + j, j);
				}
				Obj->EndPolygon();
			}

		}
	};
}
#endif // !YPCUBE_HPP