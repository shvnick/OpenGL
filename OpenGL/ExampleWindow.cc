/*
 * ExampleWindow.cc
 *
 *  Created on: 22 мар. 2021 г.
 *      Author: Никита
 */

#include "ExampleWindow.h"

#include <cmath>

static constexpr double Pi = acos(-1.);

//Snowman coordinates
double x1=4.5, x2=4, x3=3.5, x4=3, x5=-0.2;
double y1=1, y2=0, y3=-1, y4=-2, y5=2.7;
double z1=0, z2=0, z3=0, z4=0, z5=4.8;
#include "Primitives.h"

ExampleWindow::ExampleWindow(int width, int height)
:Window(width, height),
 _crate_texture("crate_tex_house.png"),
 _carrot("carrot.png"),
 _leaf("leaf.png"),
 tex_roof("roof.png"),
 tex_roof2("roof2.png"),
 _snow("snow.png"),
 _snowfloor("snowfloor.png"),
 _wood("wood.png")
{

}

void ExampleWindow::setup() {
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	float ambient[4] = {1, 1, 1, 1};
	glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambient);
	glEnable(GL_TEXTURE);

	glClearColor(0.2f, 0.35f, 0.45f, 1.0f);

	glMatrixMode(GL_PROJECTION);
	gluPerspective(45.,
			double(width())/double(height()),
					0.1, 60.0);
	glMatrixMode(GL_MODELVIEW);
}

void ExampleWindow::render() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();

	gluLookAt(
			15., 15., _camera_z,
			0.0, 0.0, 0.0,
			0., 0., 1.);

	glRotated(_angle, 0., 0., 1.);

	_snowfloor.bind();
	glEnable(GL_TEXTURE_2D);
	_ground.draw();
	glDisable(GL_TEXTURE_2D);

	_crate_texture.bind();
	glEnable(GL_TEXTURE_2D);
	_house.draw();
	glDisable(GL_TEXTURE_2D);

	tex_roof.bind();
	glEnable(GL_TEXTURE_2D);
	_roof.draw();
	glDisable(GL_TEXTURE_2D);

	tex_roof2.bind();
	glEnable(GL_TEXTURE_2D);
	_roof2.draw();
	glDisable(GL_TEXTURE_2D);

	_wood.bind();
	glEnable(GL_TEXTURE_2D);
	draw_cone(16, 3., 3., 4.4, 0, 0.5);
	draw_cone(16, -3., -3., 4.4, 0, 0.5);
	glDisable(GL_TEXTURE_2D);

	_leaf.bind();
	glEnable(GL_TEXTURE_2D);
	draw_cone(16, 3., 3., 1.4, 1.0, 1.3);
	draw_cone(16, 3., 3., 1.8, 1.4, 1.2);
	draw_cone(16, 3., 3., 2.3, 1.8, 1.1);
	draw_cone(16, 3., 3., 2.7, 2.3, 1.0);
	draw_cone(16, 3., 3., 3.0, 2.7, 0.9);
	draw_cone(16, 3., 3., 3.5, 3.0, 0.8);
	draw_cone(16, 3., 3., 4.0, 3.5, 0.7);
	draw_cone(16, 3., 3., 4.5, 4.0, 0.6);

	draw_cone(16, -3., -3., 1.4, 1.0, 1.3);
	draw_cone(16, -3., -3., 1.8, 1.4, 1.2);
	draw_cone(16, -3., -3., 2.3, 1.8, 1.1);
	draw_cone(16, -3., -3., 2.7, 2.3, 1.0);
	draw_cone(16, -3., -3., 3.0, 2.7, 0.9);
	draw_cone(16, -3., -3., 3.5, 3.0, 0.8);
	draw_cone(16, -3., -3., 4.0, 3.5, 0.7);
	draw_cone(16, -3., -3., 4.5, 4.0, 0.6);
	glDisable(GL_TEXTURE_2D);

	//First snowman
	_snow.bind();
	glEnable(GL_TEXTURE_2D);
	draw_sphere(16, 16, x1, y1, z1, 0.5);
	draw_sphere(16, 16, x1, y1, 0.7+z1, 0.4);
	draw_sphere(16, 16, x1, y1, 1.25+z1, 0.25);
	glDisable(GL_TEXTURE_2D);
	_carrot.bind();
	glEnable(GL_TEXTURE_2D);
	draw_cylinder(5, 1.25+z1, y1, x1+0.5, x1+0.1, 0.1);
	glDisable(GL_TEXTURE_2D);

	//Second snowman
	_snow.bind();
	glEnable(GL_TEXTURE_2D);
	draw_sphere(16, 16, x2, y2, z2, 0.5);
	draw_sphere(16, 16, x2, y2, 0.7+z2, 0.4);
	draw_sphere(16, 16, x2, y2, 1.25+z2, 0.25);
	glDisable(GL_TEXTURE_2D);
	_carrot.bind();
	glEnable(GL_TEXTURE_2D);
	draw_cylinder(5, 1.25+z2, y2, x2+0.5, x2+0.1, 0.1);
	glDisable(GL_TEXTURE_2D);

	//Third snowman
	_snow.bind();
	glEnable(GL_TEXTURE_2D);
	draw_sphere(16, 16, x3, y3, z3, 0.5);
	draw_sphere(16, 16, x3, y3, 0.7+z3, 0.4);
	draw_sphere(16, 16, x3, y3, 1.25+z3, 0.25);
	glDisable(GL_TEXTURE_2D);
	_carrot.bind();
	glEnable(GL_TEXTURE_2D);
	draw_cylinder(5, 1.25+z3, y3, x3+0.5, x3+0.1, 0.1);
	glDisable(GL_TEXTURE_2D);

	//Fourth snowman
	_snow.bind();
	glEnable(GL_TEXTURE_2D);
	draw_sphere(16, 16, x4, y4, z4, 0.5);
	draw_sphere(16, 16, x4, y4, 0.7+z4, 0.4);
	draw_sphere(16, 16, x4, y4, 1.25+z4, 0.25);
	glDisable(GL_TEXTURE_2D);
	_carrot.bind();
	glEnable(GL_TEXTURE_2D);
	draw_cylinder(5, 1.25+z4, y4, x4+0.5, x4+0.1, 0.1);
	glDisable(GL_TEXTURE_2D);

	//Fifth snowman
	_snow.bind();
	glEnable(GL_TEXTURE_2D);
	draw_sphere(16, 16, x5, y5, z5, 0.3);
	draw_sphere(16, 16, x5, y5, 0.4+z5, 0.2);
	draw_sphere(16, 16, x5, y5, 0.7+z5, 0.15);
	glDisable(GL_TEXTURE_2D);
	_carrot.bind();
	glEnable(GL_TEXTURE_2D);
	draw_cylinder(5, 0.65+z5, y5, x5+0.2, x5+0.05, 0.05);
	glDisable(GL_TEXTURE_2D);

}

void ExampleWindow::do_logic() {
	_angle += 1.;
	if (_angle >= 360.)
		_angle -= 360.;

	x1 += sin(_angle / 180. * Pi) * 0.05;
	x2 += sin(_angle / 180. * Pi) * 0.06;
	x3 += sin(_angle / 180. * Pi) * 0.07;
	x4 += sin(_angle / 180. * Pi) * 0.08;

	_camera_z = 13. + sin(_angle / 180. * Pi) * 5.;
}
