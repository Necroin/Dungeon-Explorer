#include "Map.h"

Map::Map(Renderer& renderer, int x_centre, int y_centre) :
	_x_centre(x_centre),
	_y_centre(y_centre),
	_renderer(renderer)
{
	generate_rooms_in_map(_x_centre, _y_centre);
}

void Map::generate_rooms_in_map(int x, int y){
	int room_w = 20;
	int room_h = 20;
	GameRect rect = GameRect(x - room_w/2, y - room_h/2, room_w, room_h);
	Room room = Room(_renderer, 0, rect);
	_rooms.push_back(room);
}

void Map::draw()
{
	for (auto&& room: _rooms){
		room.draw();
	}
}

int Map::get_x_centre() const
{
	return _x_centre;
}

int Map::get_y_centre() const
{
	return _y_centre;
}
