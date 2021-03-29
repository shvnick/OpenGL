/*
 * ExampleWindow.h
 *
 *  Created on: 22 мар. 2021 г.
 *      Author: Никита
 */

#ifndef EXAMPLEWINDOW_H_
#define EXAMPLEWINDOW_H_

#pragma once
#include "Window.h"
#include <GL/gl.h>
#include <GL/glu.h>

#include "House.h"
#include "Roof.h"
#include "Roof2.h"
#include "Ground.h"
#include "Texture.h"

class ExampleWindow: public Window {
protected:
	double _angle { 0. };
	double _camera_x { 0. };
	double _camera_y { 0. };
	double _camera_z { 0. };

	House _house = House::create_house();
	Roof _roof = Roof::create_roof();
	Roof2 _roof2 = Roof2::create_roof2();
	Ground _ground = Ground::create_ground();
	Texture _crate_texture, _carrot, _leaf, tex_roof, tex_roof2, _snow, _snowfloor, _wood;
public:
	ExampleWindow(  int width = DEFAULT_WIDTH,
					int height = DEFAULT_HEIGHT);
	virtual ~ExampleWindow() = default;

	virtual void setup() override;
	virtual void render() override;
	virtual void do_logic() override;
};

#endif /* EXAMPLEWINDOW_H_ */
