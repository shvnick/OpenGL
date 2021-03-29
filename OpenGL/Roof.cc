/*
 * Roof.cc
 *
 *  Created on: 28 мар. 2021 г.
 *      Author: Никита
 */

#include "Roof.h"

static const std::vector<Roof::Vertex> s_roof_vertices {
	{  2.0,   -4,  3.0 },
	{  2.0,   4,  3.0 },
	{ -2.0,   4,  3.0 },
	{ -2.0,  -4,  3.0 },
	{  2.0,   0,  5.0 },
	{ -2.0,   0,  5.0 },
};

static const std::vector<Roof::Vertex> s_roof_faces {
	{ 4,  0,  1,  2,  3 },
	{ 4,  1,  4,  5,  2 },
	{ 4,  0,  3,  5,  4 },
	{ 3,  0,  4,  1 },
	{ 3,  2,  5,  3 },
};

static const std::vector<Roof::Color> s_roof_colors {
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
	{ 1.0f, 1.0f, 1.0f },
};

static const std::vector<Roof::Normal> s_roof_normals {
	{  0.0,  0.0, -1.0 },
	{  0.0,  1.0,  1.0 },
	{  0.0, -1.0,  1.0 },
	{  1.0,  0.0,  0.0 },
	{ -1.0,  0.0,  0.0 },
};

static const std::vector<std::vector<Roof::Vertex>> s_roof_tex_coords {
	{ { 0.00, 0.00 }, { 0.25, 0.00 }, { 0.25, 0.50 }, { 0.00, 0.50 } },
	{ { 0.25, 0.00 }, { 0.50, 0.00 }, { 0.50, 0.50 }, { 0.25, 0.50 } },
	{ { 0.50, 0.00 }, { 0.75, 0.00 }, { 0.75, 0.50 }, { 0.50, 0.50 } },
	{ { 0.00, 0.50 }, { 0.25, 0.50 }, { 0.25, 1.00 }, { 0.00, 1.00 } },
	{ { 0.25, 0.50 }, { 0.50, 0.50 }, { 0.50, 1.00 }, { 0.25, 1.00 } },
	{ { 0.50, 0.50 }, { 0.75, 0.50 }, { 0.75, 1.00 }, { 0.50, 1.00 } },
};

Roof::Roof(
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

void Roof::draw() {
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

Roof Roof::create_roof() {
	return Roof(
			s_roof_vertices,
			s_roof_faces,
			s_roof_colors,
			s_roof_normals,
			s_roof_tex_coords
			);
}

