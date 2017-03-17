#ifndef YPGEOMETRY_HPP
#define YPGEOMETRY_HPP

#include "ypManagerHandle.hpp"
#include "ypSceneHandle.hpp"
#include "ypCube.hpp"
#include "ypCylinder.hpp"
#include "ypSphere.hpp"

void yp_demo_geometry_fbx() {
	
	// initialize environment
	ypManagerHandle<> Manager1("Manager1");
	ypSceneHandle<> MyScene1(Manager1.getManager());
	
	// draw a cylinder
	ypCylinder cylinder_1(MyScene1.getScene(), "cylinder_1");
	cylinder_1.trans(100, 0, 0);
	MyScene1.addNode(cylinder_1.getNode());
	
	// draw a cube
	ypCube cube_1(MyScene1.getScene(), "cube_1");
	cube_1.rotate(25, 45, 90);
	cube_1.scale(0.5, 0.5, 0.5);
	MyScene1.addNode(cube_1.getNode());

	// draw another cube
	ypCube cube_2(MyScene1.getScene(), "cube_2");
	cube_2.trans(200, 0, 0);
	MyScene1.addNode(cube_2.getNode());
	
	// draw a ball
	ypSphere ball_1(MyScene1.getScene(), "ball_1");
	ball_1.trans(-200, 0, 0);
	ball_1.scale(2, 2, 2);
	MyScene1.addNode(ball_1.getNode());

	// save it
	std::string save_path("./");
	std::string save_name("yp_demo_geometry_fbx.fbx");

	std::string save_place = save_path + save_name;
	MyScene1.Save(save_place);	
}
#endif // !YPGEOMETRY_HPP