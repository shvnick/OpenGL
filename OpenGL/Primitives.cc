/*
 * Primitives.cc
 *
 *  Created on: 22 мар. 2021 г.
 *      Author: Никита
 */

#include "Primitives.h"

static constexpr double Pi = acos(-1.);


void cart2cyl(
		double x, double y, double cz,
		double &r, double &phi, double &z)
{
	r = hypot(y, x);
	phi = atan2(y, x);
	cz = z;
}

void cyl2cart(
		double r, double phi, double cz,
		double &x, double &y, double &z,
		double PositionX, double PositionY)
{
	x = r * cos(phi) + PositionX;
	y = r * sin(phi) + PositionY;
	z = cz;
}

void cart2sph(
		double x, double y, double z,
		double &r, double &phi, double &theta)
{
	r = sqrt(x*x + y*y + z*z);
	phi = atan2(y, x);
	theta = atan2(hypot(x, y), z);
}

void sph2cart(
		double r, double phi, double theta,
		double &x, double &y, double &z,
		double PositionX, double PositionY, double PositionZ)
{
	x = r * sin(theta) * cos(phi) + PositionX;
	y = r * sin(theta) * sin(phi) + PositionY;
	z = r * cos(theta) + PositionZ;
}


void draw_cylinder(int sides, double PositionX, double PositionY, double PositionZ1, double PositionZ2, double Width)
{
	double phi_step = 2. * Pi / sides;
	for (int side = 0; side < sides; side++){
		double  phi1 = phi_step * side,
				phi2 = phi_step * (side + 1),
				phin = (phi1 + phi2) / 2.;
		double x1, x2, y1, y2, z1, z2, xn, yn, zn;
		double xn1, xn2, yn1, yn2, zn1, zn2;
		cyl2cart(Width, phi1, 0., x1, y1, z1, PositionX, PositionY);
		cyl2cart(Width, phi2, 1., x2, y2, z2, PositionX, PositionY);
		sph2cart(1., phin, Pi/4., xn, yn, zn, 0, 0, 0);
		sph2cart(1., phi1, Pi/4., xn1, yn1, zn1, 0, 0, 0);
		sph2cart(1., phi2, Pi/4., xn2, yn2, zn2, 0, 0, 0);
		glBegin(GL_TRIANGLES);
		{
			glNormal3d(zn, yn, xn);
			glVertex3d(PositionZ1, PositionY, PositionX);
			glNormal3d(zn1, yn1, xn1);
			glVertex3d(PositionZ2, y1, x1);
			glNormal3d(zn2, yn2, xn2);
			glVertex3d(PositionZ2, y2, x2);
			glNormal3d(-1., 0., 0.);
			glVertex3d(PositionZ2, PositionY, PositionX);
			glVertex3d(PositionZ2, y2, x2);
			glVertex3d(PositionZ2, y1, x1);
		}
		glEnd();
	}
}

void draw_cone(int sides, double PositionX, double PositionY, double PositionZ1, double PositionZ2, double Width)
{
	double phi_step = 2. * Pi / sides;
	for (int side = 0; side < sides; side++){
		double  phi1 = phi_step * side,
				phi2 = phi_step * (side + 1),
				phin = (phi1 + phi2) / 2.;
		double x1, x2, y1, y2, z1, z2, xn, yn, zn;
		double xn1, xn2, yn1, yn2, zn1, zn2;
		cyl2cart(Width, phi1, 0., x1, y1, z1, PositionX, PositionY);
		cyl2cart(Width, phi2, 1., x2, y2, z2, PositionX, PositionY);
		sph2cart(1., phin, Pi/4., xn, yn, zn, 0, 0, 0);
		sph2cart(1., phi1, Pi/4., xn1, yn1, zn1, 0, 0, 0);
		sph2cart(1., phi2, Pi/4., xn2, yn2, zn2, 0, 0, 0);
		glBegin(GL_TRIANGLES);
		{
			glNormal3d(xn, yn, zn);
			glVertex3d(PositionX, PositionY, PositionZ1);
			glNormal3d(xn1, yn1, zn1);
			glVertex3d(x1, y1, PositionZ2);
			glNormal3d(xn2, yn2, zn2);
			glVertex3d(x2, y2, PositionZ2);
			glNormal3d(0., 0., -1.);
			glVertex3d(PositionX, PositionY, PositionZ2);
			glVertex3d(x2, y2, PositionZ2);
			glVertex3d(x1, y1, PositionZ2);
		}
		glEnd();
	}
}

void draw_sphere(int rows, int cols, double PositionX, double PositionY, double PositionZ, double Radius)
{
	double  phi_step = 2. * Pi / cols,
			theta_step = Pi / rows;
	glBegin(GL_QUADS);
	for (int row = 0; row < rows; ++row){
		for (int col = 0; col < cols; ++col){
			double  phi1 = phi_step * col,
					phi2 = phi_step * (col + 1),
					theta1 = theta_step * row,
					theta2 = theta_step * (row + 1),
					phin = (phi1 + phi2) / 2.,
					thetan = (theta1 + theta2) / 2.;

			double  x11, x12, x21, x22,
					y11, y12, y21, y22,
					z11, z12, z21, z22,
					nx, ny, nz;

			sph2cart(Radius, phi1, theta1, x11, y11, z11, PositionX, PositionY, PositionZ);
			sph2cart(Radius, phi1, theta2, x12, y12, z12, PositionX, PositionY, PositionZ);
			sph2cart(Radius, phi2, theta1, x21, y21, z21, PositionX, PositionY, PositionZ);
			sph2cart(Radius, phi2, theta2, x22, y22, z22, PositionX, PositionY, PositionZ);
			sph2cart(Radius, phin, thetan, nx, ny, nz, PositionX, PositionY, PositionZ);

			glNormal3d(x11, y11, z11);
			glVertex3d(x11, y11, z11);
			glNormal3d(x12, y12, z12);
			glVertex3d(x12, y12, z12);
			glNormal3d(x22, y22, z22);
			glVertex3d(x22, y22, z22);
			glNormal3d(x21, y21, z21);
			glVertex3d(x21, y21, z21);
		}
	}
	glEnd();
}




