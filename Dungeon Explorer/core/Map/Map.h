#pragma once
#ifndef _MAP_H_
#define _MAP_H_
#include <vector>
#include "../Game Object/GameObject.h"
#include "../Renderer/Renderer.h"
#include "Room/Room.h"

class Map {
private:
	std::vector<Room> _rooms;

	int _x_centre;
	int _y_centre;

	Renderer& _renderer;
public:
	Map(Renderer& renderer, int x_centre, int y_centre);

	
	void generate_rooms_in_map(int x, int y);

	void draw();


	int get_x_centre() const;
	int get_y_centre() const;
};
#endif