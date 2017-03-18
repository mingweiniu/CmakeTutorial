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
			double R = 30.0;
			double lSegmentLength = R / segments;
			for (int i = 0; i < segments; i++)
			{
				auto length = static_cast<double>(i);
				auto degree = std::acos(length / segments);
				std::cout << " degree is " << degree << '\n';
				auto Radius = std::sin(degree) * R;
				if (Radius < 1e-8) Radius = 0.001;
				std::cout << " Radius is " << Radius << '\n';
				CylinderVector4[4 * i + 0].Set(Radius, 0.0, (i)*lSegmentLength);
				CylinderVector4[4 * i + 1].Set(0.0, -Radius, (i)*lSegmentLength);
				CylinderVector4[4 * i + 2].Set(-Radius, 0.0, (i)*lSegmentLength);
				CylinderVector4[4 * i + 3].Set(0.0, Radius, (i)*lSegmentLength);
			}

		}
	};
}
#endif // !HEMISPHERE_HPP