#ifndef ELBOW45_HPP
#define ELBOW45_HPP

#include <cmath>

#include <iostream>
#include <boost/geometry.hpp>
#include <boost/geometry/arithmetic/arithmetic.hpp>
#include <boost/geometry/geometries/register/point.hpp>
#include <boost/geometry/arithmetic/cross_product.hpp>

#include "GeomertyBase.hpp"

namespace yp {
	class Elbow45 : public GeomertyBase<FbxPatch> {
	public:

		Elbow45(FbxScene* Scene, std::string Name)
		{
			namespace geo = boost::geometry;

			using vec3 = geo::model::point<double, 3, geo::cs::cartesian>;

			double R1 = 20.0;

			// center 1
			vec3 C1{ 40, 0, 0 };

			// center 2
			vec3 C2{ 0, 40, 0 };

			// Cross point
			vec3 Cp{ 0, 0, 0 };

			vec3 U{ C1 };
			geo::subtract_point(U, Cp);
			vec3 V{ C2 };
			geo::subtract_point(V, Cp);

			double fRadius = len(U);

			vec3 W{ geo::cross_product(U, V) };
			geo::divide_value(W, len(W));
			geo::multiply_value(W, R1);

			vec3 H{ U };
			geo::add_point(H, V); // H = U + V

			vec3 C0{ Cp };
			geo::add_point(C0, H); // C0 is circle center now


			geo::divide_value(H, len(H));


			geo::multiply_value(H, -len(V));


			std::cout << "print_vec3(H) :  \n";
			print_vec3(H);
			std::vector<vec3> VK(5, H);

			VK[0] = V;
			geo::multiply_value(VK[0], -1);
			VK[4] = U;
			geo::multiply_value(VK[4], -1);

			geo::add_point(VK[1], VK[0]);
			geo::add_point(VK[3], VK[4]);


			// control point set
			std::vector<std::vector<vec3>> cpSet;

			for (auto& i : VK) {
				geo::divide_value(i, len(i));
				geo::multiply_value(i, fRadius);

				std::vector<vec3> control_points;

				// near
				geo::multiply_value(i, (fRadius - R1) / fRadius);
				control_points.push_back(i);
				geo::divide_value(i, (fRadius - R1) / fRadius);

				// up
				geo::add_point(i, W); // up
				control_points.push_back(i); // up
				geo::subtract_point(i, W);

				// far
				geo::multiply_value(i, (fRadius + R1) / fRadius);
				control_points.push_back(i);
				geo::divide_value(i, (fRadius + R1) / fRadius);

				// down
				geo::subtract_point(i, W); // up
				control_points.push_back(i); // up
				geo::add_point(i, W);

				cpSet.push_back(control_points);
			}


			init_scene_name_obj(Scene, Name);

			const int segments = 5;

			// Set patch properties.
			Obj->InitControlPoints(4, FbxPatch::eBSpline, segments, FbxPatch::eBSpline);
			Obj->SetStep(4, 4);
			Obj->SetClosed(true, false);

			FbxVector4* CylinderVector4 = Obj->GetControlPoints();


			for (int i = 0; i < segments; ++i) {
				std::cout << '\n';
				for (int j = 0; j < 4; ++j) {
					std::cout << "( i , j ) = " << i << ',' << j << '\n';
					print_vec3(cpSet[i][j]);
					CylinderVector4[4 * i + j].Set(cpSet[i][j].get<0>(), cpSet[i][j].get<1>(), cpSet[i][j].get<2>());
				}
			}

		}
	
	


	private:
		void print_vec3(boost::geometry::model::point<double, 3, boost::geometry::cs::cartesian> vec3) {
			decltype(vec3) zero{ 0,0,0 };
			auto x = vec3.get<0>();
			auto y = vec3.get<1>();
			auto z = vec3.get<2>();
			std::cout << '\t' << x << "," << y << ',' << z << '\t' << boost::geometry::distance(vec3, zero) << '\n';
		}

		double len(boost::geometry::model::point<double, 3, boost::geometry::cs::cartesian> vec3) {
			decltype(vec3) zero{ 0,0,0 };
			return boost::geometry::distance(vec3, zero);
		}
	};
}


#endif // !ELBOW45_HPP