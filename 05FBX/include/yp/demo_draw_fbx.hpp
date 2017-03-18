#ifndef YPGEOMETRY_HPP
#define YPGEOMETRY_HPP


#include "Geometry/ManagerHandle.hpp"
#include "Geometry/SceneHandle.hpp"
#include "Geometry/Cone.hpp"
#include "Geometry/Hemisphere.hpp"
#include "Geometry/Elbow90.hpp"
#include "Geometry/Elbow45.hpp"

#include "Geometry/Cylinder.hpp"

namespace yp {
	void demo_draw_fbx() {

		// initialize environment
		yp::ManagerHandle Manager1("Manager1");
		yp::SceneHandle MyScene1(Manager1.getManager());

		
		// draw a Cylinder
		yp::Cylinder Cylinder_1(MyScene1.getScene(), "Cylinder_1");
		Cylinder_1.trans(-100, 0, 0);
		MyScene1.addNode(Cylinder_1.getNode());


		// draw a Cone
		yp::Cone Cone_1(MyScene1.getScene(), "Cone_1");
		Cone_1.trans(100, 0, 0);
		MyScene1.addNode(Cone_1.getNode());
		


		// draw a Hemisphere
		yp::Hemisphere Hemisphere_1(MyScene1.getScene(), "Hemisphere_1");
		Hemisphere_1.trans(200, 100, -100);
		MyScene1.addNode(Hemisphere_1.getNode());
		
		// draw an Elbow with 90 degree
		yp::Elbow90 Elbow90_1(MyScene1.getScene(), "Elbow90_1");
		Elbow90_1.trans(0, 0, 0);
		MyScene1.addNode(Elbow90_1.getNode());


		// draw an Elbow with 45 degree
		//yp::Elbow45 Elbow45_1(MyScene1.getScene(), "Elbow45_1");
		//Elbow45_1.trans(100, 0, 0);
		//MyScene1.addNode(Elbow45_1.getNode());
		


		// save it
		std::string save_path("./");
		std::string save_name("demo_geometry_fbx.fbx");

		std::string save_place = save_path + save_name;
		MyScene1.Save(save_place);

	}
}
#endif // !YPGEOMETRY_HPP