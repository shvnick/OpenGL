/*
 * Roof2.cc
 *
 *  Created on: 28 мар. 2021 г.
 *      Author: Никита
 */

#include "Roof2.h"

static const std::vector<Roof2::Vertex> s_roof2_vertices {
	{ -0.0,  3.0, 4.5 },
	{ -0.0,  2.5,  4.5 },
	{ -0.5,   2.5,  4.5 },
	{ -0.5,   3.0, 4.5 },
	{ -0.0,  3.0, 3.0 },
	{ -0.0,  2.5,  3.0 },
	{ -0.5,   2.5,  3.0 },
	{ -0.5,   3.0, 3.0 },
};

static const std::vector<Roof2::Vertex> s_roof2_faces {
	{  4., 1., 0., 4., 5. },
	{  4., 3., 2., 6., 7. },
	{  4., 2., 3., 0., 1. },
	{  4., 7., 6., 5., 4. },
	{  4., 0., 3., 7., 4. },
	{  4., 2., 1., 5., 6. },
};

static const std::vector<Roof2::Color> s_roof2_colors {
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
};

static const std::vector<Roof2::Normal> s_roof2_normals {
	{  1.0,  0.0,  0.0 },
	{ -1.0,  0.0,  0.0 },
	{  0.0,  0.0,  1.0 },
	{  0.0,  0.0, -1.0 },
	{  0.0,  1.0,  0.0 },
	{  0.0, -1.0,  0.0 },
};

static const std::vector<std::vector<Roof2::Vertex>> s_roof2_tex_coords {
	{ { 0.00, 0.00 }, { 0.25, 0.00 }, { 0.25, 0.50 }, { 0.00, 0.50 } },
	{ { 0.25, 0.00 }, { 0.50, 0.00 }, { 0.50, 0.50 }, { 0.25, 0.50 } },
	{ { 0.50, 0.00 }, { 0.75, 0.00 }, { 0.75, 0.50 }, { 0.50, 0.50 } },
	{ { 0.00, 0.50 }, { 0.25, 0.50 }, { 0.25, 1.00 }, { 0.00, 1.00 } },
	{ { 0.25, 0.50 }, { 0.50, 0.50 }, { 0.50, 1.00 }, { 0.25, 1.00 } },
	{ { 0.50, 0.50 }, { 0.75, 0.50 }, { 0.75, 1.00 }, { 0.50, 1.00 } },
};

Roof2::Roof2(
		const std::vector<Vertex> &vertices,
		const std::vector<Face> &faces,
		const std::vector<Color> &colors,
		const std::vector<Normal> &normals,
		const std::vector<Texture> &tex_coords
		)
: _vertices(vertices),
  _faces(faces),
  _colors(colors),
  _normals(normals),
  _tex_coords(tex_coords)
{
}

void Roof2::draw() {
	for (unsigned face_idx = 0; face_idx < _faces.size(); ++face_idx) {
		int vertices = _faces[face_idx][0];

		if (vertices == 3) glBegin(GL_TRIANGLES);
		else if (vertices == 4) glBegin(GL_QUADS);
		else glBegin(GL_POLYGON);

		glColor3fv(&_colors[face_idx][0]);
		glNormal3dv(&_normals[face_idx][0]);
		glMaterialfv(GL_FRONT_AND_BACK, GL_DIFFUSE, &_colors[face_idx][0]);

		for (int i = 0; i < vertices; ++i) {
			glTexCoord2dv(&_tex_coords[face_idx][i][0]);
			glVertex3dv(&_vertices[_faces[face_idx][i+1]][0]);
		}

		glEnd();
	}
}

Roof2 Roof2::create_roof2() {
	return Roof2(
			s_roof2_vertices,
			s_roof2_faces,
			s_roof2_colors,
			s_roof2_normals,
			s_roof2_tex_coords
			);
}

