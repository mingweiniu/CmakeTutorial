#ifndef YPGEOMETRY_HPP
#define YPGEOMETRY_HPP

#include "ManagerHandle.hpp"
#include "SceneHandle.hpp"
#include "Cube.hpp"
#include "Cylinder.hpp"
#include "Sphere.hpp"

namespace yp {
	void demo_geometry_fbx() {

		// initialize environment
		yp::ManagerHandle Manager1("Manager1");
		yp::SceneHandle MyScene1(Manager1.getManager());

		// draw a cylinder
		yp::Cylinder cylinder_1(MyScene1.getScene(), "cylinder_1");
		cylinder_1.trans(100, 0, 0);
		MyScene1.addNode(cylinder_1.getNode());

		// draw a cube
		yp::Cube cube_1(MyScene1.getScene(), "cube_1");
		cube_1.rotate(25, 45, 90);
		cube_1.scale(0.5, 0.5, 0.5);
		MyScene1.addNode(cube_1.getNode());

		// draw another cube
		yp::Cube cube_2(MyScene1.getScene(), "cube_2");
		cube_2.trans(200, 0, 0);
		MyScene1.addNode(cube_2.getNode());

		// draw a ball
		yp::Sphere ball_1(MyScene1.getScene(), "ball_1");
		ball_1.trans(-200, 0, 0);
		ball_1.scale(2, 2, 2);
		MyScene1.addNode(ball_1.getNode());

		// save it
		std::string save_path("./");
		std::string save_name("yp_demo_geometry_fbx.fbx");

		std::string save_place = save_path + save_name;
		MyScene1.Save(save_place);

	}
}
#endif // !YPGEOMETRY_HPP