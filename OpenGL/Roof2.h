/*
 * Roof2.h
 *
 *  Created on: 28 мар. 2021 г.
 *      Author: Никита
 */

#ifndef Roof2_H_
#define Roof2_H_

#include <vector>
#include <GL/gl.h>

class Roof2 {
public:
	using Vertex = std::vector<GLdouble>;
	using Normal = std::vector<GLdouble>;
	using Color = std::vector<GLfloat>;
	// [0] - колво вершин; остальное - индексы
	using Face = std::vector<GLdouble>;
	using Texture = std::vector<Vertex>;

protected:
	std::vector<Vertex> _vertices;
	std::vector<Face> _faces;
	std::vector<Color> _colors;
	std::vector<Normal> _normals;
	std::vector<std::vector<Vertex>> _tex_coords;
public:
	Roof2(
			const std::vector<Vertex> &vertices,
			const std::vector<Face> &faces,
			const std::vector<Color> &colors,
			const std::vector<Normal> &normals,
			const std::vector<Texture> &tex_coords
			);
	virtual ~Roof2() = default;

	void draw();

	static Roof2 create_roof2();
};

#endif /* Roof2_H_ */
