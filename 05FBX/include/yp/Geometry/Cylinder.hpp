#ifndef YPCYLINDER_HPP
#define YPCYLINDER_HPP

#include "GeomertyBase.hpp"

namespace yp {
	class Cylinder : public GeomertyBase<FbxPatch> {
	public:
		Cylinder(FbxScene* Scene, std::string Name)
		{
			init_scene_name_obj(Scene, Name);

			// Set patch properties.
			Obj->InitControlPoints(4, FbxPatch::eBSpline, 7, FbxPatch::eBSpline);
			Obj->SetStep(4, 4);
			Obj->SetClosed(true, false);

			FbxVector4* CylinderVector4 = Obj->GetControlPoints();
			for (int i = 0; i < 7; i++)
			{
				double lRadius = 15.0;
				double lSegmentLength = 10.0;
				CylinderVector4[4 * i + 0].Set(lRadius, 0.0, (i - 3)*lSegmentLength);
				CylinderVector4[4 * i + 1].Set(0.0, -lRadius, (i - 3)*lSegmentLength);
				CylinderVector4[4 * i + 2].Set(-lRadius, 0.0, (i - 3)*lSegmentLength);
				CylinderVector4[4 * i + 3].Set(0.0, lRadius, (i - 3)*lSegmentLength);
			}
		}

	};
}
#endif // !YPCYLINDER_HPP