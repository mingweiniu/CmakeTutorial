#ifndef YPTEST_HPP
#define YPTEST_HPP

#include <cmath>

#include "ypGeomertyBase.hpp"

class ypTest : public ypGeomertyBase<FbxPatch> {
public:
	ypTest(FbxScene* Scene, std::string Name)
	{
		init_scene_name_obj(Scene, Name);

		const int control_sets_num = 15;

		// Set patch properties.
		Obj->InitControlPoints(4, FbxPatch::eBSpline, control_sets_num, FbxPatch::eBSpline);
		Obj->SetStep(4, 4);
		Obj->SetClosed(true, false);

		FbxVector4* CylinderVector4 = Obj->GetControlPoints();
		double lRadius = 15.0;
		double lSegmentLength = 10.0;
		for (int i = 0; i < 7; i++)
		{
			CylinderVector4[4 * i + 0].Set(lRadius, 0.0, (i - 3)*lSegmentLength);
			CylinderVector4[4 * i + 1].Set(0.0, -lRadius, (i - 3)*lSegmentLength);
			CylinderVector4[4 * i + 2].Set(-lRadius, 0.0, (i - 3)*lSegmentLength);
			CylinderVector4[4 * i + 3].Set(0.0, lRadius, (i - 3)*lSegmentLength);
		}
		
		CylinderVector4[28 + 0].Set(lRadius/std::pow(2,0.5), 0.0, (7 - 3)*lSegmentLength + lRadius * std::pow(2, 0.5));
		CylinderVector4[28 + 1].Set(0.0, -lRadius, (7 - 3)*lSegmentLength + lRadius / std::pow(2, 0.5));
		CylinderVector4[28 + 2].Set(-lRadius, 0.0, (7 - 3)*lSegmentLength);
		CylinderVector4[28 + 3].Set(0.0, lRadius, (7 - 3)*lSegmentLength + lRadius / std::pow(2, 0.5));

		for (int i = 0; i < 7; i++)
		{
			CylinderVector4[4 * i + 0].Set(lRadius - 3* lSegmentLength, 0.0, (7 - 3)*lSegmentLength + lRadius);
			CylinderVector4[4 * i + 1].Set(-3 * lSegmentLength, -lRadius, (7 - 3)*lSegmentLength + lRadius / 2);
			CylinderVector4[4 * i + 2].Set(-lRadius - 3 * lSegmentLength, 0.0, (7 - 3)*lSegmentLength);
			CylinderVector4[4 * i + 3].Set(-3 * lSegmentLength, lRadius, (7 - 3)*lSegmentLength + lRadius / 2);
		}
		
	}
};
#endif // !YPTEST_HPP