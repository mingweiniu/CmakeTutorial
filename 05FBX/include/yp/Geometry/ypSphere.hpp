#ifndef YPSPHERE_HPP
#define YPSPHERE_HPP

#include "ypGeomertyBase.hpp"

class ypSphere: public ypGeomertyBase<FbxNurbs>{
public:
	ypSphere(FbxScene* Scene, std::string Name)
	{
		init_scene_name_obj(Scene, Name);

		// Set nurbs properties.
		Obj->SetOrder(4, 4);
		Obj->SetStep(2, 2);
		Obj->InitControlPoints(8, FbxNurbs::ePeriodic, 7, FbxNurbs::eOpen);

		double lUKnotVector[] = { -3.0, -2.0, -1.0, 0.0, 1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0 };
		memcpy(Obj->GetUKnotVector(), lUKnotVector, Obj->GetUKnotCount() * sizeof(double));

		double lVKnotVector[] = { 0.0, 0.0, 0.0, 0.0, 1.0, 2.0, 3.0, 4.0, 4.0, 4.0, 4.0 };
		memcpy(Obj->GetVKnotVector(), lVKnotVector, Obj->GetVKnotCount() * sizeof(double));

		FbxVector4* lVector4 = Obj->GetControlPoints();
		int i, j;
		double lScale = 20.0;
		double lPi = 3.14159;
		double lYAngle[] = { 90.0, 90.0, 52.0, 0.0, -52.0, -90.0, -90.0 };
		double lRadius[] = { 0.0, 0.283, 0.872, 1.226, 0.872, 0.283, 0.0 };

		for (i = 0; i < 7; i++)
		{
			for (j = 0; j < 8; j++)
			{
				double lX = lScale * lRadius[i] * cos(lPi / 4 * j);
				double lY = lScale * sin(2 * lPi / 360 * lYAngle[i]);
				double lZ = lScale * lRadius[i] * sin(lPi / 4 * j);
				double lWeight = 1.0;

				lVector4[8 * i + j].Set(lX, lY, lZ, lWeight);
			}
		}
	
	}

};
#endif // !YPSPHERE_HPP