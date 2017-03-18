#ifndef YPGEOMETRY_HPP
#define YPGEOMETRY_HPP

#include "ManagerHandle.hpp"
#include "SceneHandle.hpp"
#include "Cone.hpp"

namespace yp {
	void demo_draw_fbx() {

		// initialize environment
		yp::ManagerHandle Manager1("Manager1");
		yp::SceneHandle MyScene1(Manager1.getManager());

		// draw a Half Sphere


		// draw a Cone
		yp::Cone Cone_1(MyScene1.getScene(), "Cone_1");
		Cone_1.trans(100, 0, 0);
		MyScene1.addNode(Cone_1.getNode());


		// draw an Elbow with 45 degree


		// draw an Elbow with 90 degree


		


		// save it
		std::string save_path("./");
		std::string save_name("yp_demo_geometry_fbx.fbx");

		std::string save_place = save_path + save_name;
		MyScene1.Save(save_place);

	}
}
#endif // !YPGEOMETRY_HPP