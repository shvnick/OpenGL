/*
 * main.cc
 *
 *  Created on: 22 ���. 2021 �.
 *      Author: ������
 */

#include <iostream>
#include <stdexcept>
#include <SDL2/SDL.h>

#include "ExampleWindow.h"

#include <SDL2/SDL_main.h>

int main(int, char ** )
{
	SDL_Init(SDL_INIT_EVERYTHING);

	try {
		ExampleWindow w;

		w.main_loop();

	} catch (const std::exception &e) {
		std::cerr << "��� ���������� ��������� ��������� ����������� ������!"
				<< std::endl;
		return 1;
	} catch (...) {

	}
	return 0;
}


