#ifndef YPCONE_HPP
#define YPCONE_HPP

#include "GeomertyBase.hpp"

namespace yp {
	class Cone : public GeomertyBase<FbxPatch> {
	public:
		Cone(FbxScene* Scene, std::string Name)
		{
			init_scene_name_obj(Scene, Name);
			const int segment = 7;
			// Set patch properties.
			Obj->InitControlPoints(4, FbxPatch::eBSpline, segment, FbxPatch::eBSpline);
			Obj->SetStep(4, 4);
			Obj->SetClosed(true, false);

			FbxVector4* CylinderVector4 = Obj->GetControlPoints();
			double lSegmentLength = 10.0;
			double lRadius = 15.0;
			for (int i = 0; i < segment; i++)
			{
				auto Radius = lRadius * i / 7;
				CylinderVector4[4 * i + 0].Set(Radius, 0.0, (i - 3)*lSegmentLength);
				CylinderVector4[4 * i + 1].Set(0.0, -Radius, (i - 3)*lSegmentLength);
				CylinderVector4[4 * i + 2].Set(-Radius, 0.0, (i - 3)*lSegmentLength);
				CylinderVector4[4 * i + 3].Set(0.0, Radius, (i - 3)*lSegmentLength);
			}

		}

	};
}
#endif // !YPCONE_HPP