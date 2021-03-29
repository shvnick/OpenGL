/*
 * Primitives.h
 *
 *  Created on: 22 мар. 2021 г.
 *      Author: Никита
 */

#ifndef PRIMITIVES_H_
#define PRIMITIVES_H_

#include <GL/gl.h>
#include <GL/glu.h>
#include <cmath>

void cart2cyl(
		double x, double y, double z,
		double &r, double &phi, double &cz);

void cyl2cart(
		double r, double phi, double cz,
		double &x, double &y, double &z,
		double Coordinates);


void cart2sph(
		double x, double y, double z,
		double &r, double &phi, double &theta);

void sph2cart(
		double r, double phi, double theta,
		double &x, double &y, double &z,
		double Coordinates);


void draw_cylinder (int sides,
					double PositionX, double PositionY,
					double PositionZ1, double PositionZ2,
					double Width);
void draw_cone     (int sides,
					double PositionX, double PositionY,
					double PositionZ1, double PositionZ2,
					double Width);
void draw_sphere   (int rows, int cols,
					double PositionX, double PositionY, double PositionZ,
					double Radius);

#endif /* PRIMITIVES_H_ */




