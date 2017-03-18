#ifndef HEMISPHERE_HPP
#define HEMISPHERE_HPP

#include <cmath>

#include "GeomertyBase.hpp"

namespace yp {
	class Hemisphere : public GeomertyBase<FbxPatch> {
	public:
		Hemisphere(FbxScene* Scene, std::string Name)
		{
			init_scene_name_obj(Scene, Name);

			const int segments = 15;

			// Set patch properties.
			Obj->InitControlPoints(4, FbxPatch::eBSpline, segments, FbxPatch::eBSpline);
			Obj->SetStep(4, 4);
			Obj->SetClosed(true, false);

			FbxVector4* CylinderVector4 = Obj->GetControlPoints();
			double R = 40.0;
			double lSegmentLength = R / (segments + 1);

			for (int i = 0; i < (segments - 1); i++)
			{
				auto length = static_cast<double>(i + 1);
				auto degree = std::acos(length / (segments - 1));
				auto Radius = std::sin(degree) * R;
				std::cout << " degree is " << degree << " Radius is " << Radius << '\n';
				CylinderVector4[4 * i + 0].Set(Radius, 0.0, (i)*lSegmentLength);
				CylinderVector4[4 * i + 1].Set(0.0, -Radius, (i)*lSegmentLength);
				CylinderVector4[4 * i + 2].Set(-Radius, 0.0, (i)*lSegmentLength);
				CylinderVector4[4 * i + 3].Set(0.0, Radius, (i)*lSegmentLength);
			}
			int i = segments - 1;
			auto Radius = 0.0f;
			CylinderVector4[4 * i + 0].Set(Radius, 0.0, (i-1)*lSegmentLength);
			CylinderVector4[4 * i + 1].Set(0.0, -Radius, (i-1)*lSegmentLength);
			CylinderVector4[4 * i + 2].Set(-Radius, 0.0, (i-1)*lSegmentLength);
			CylinderVector4[4 * i + 3].Set(0.0, Radius, (i-1)*lSegmentLength);

		}
	};
}
#endif // !HEMISPHERE_HPP