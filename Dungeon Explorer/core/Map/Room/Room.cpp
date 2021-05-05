#include "Room.h"

Room::Room(int room_id, GameRect position):
	GameObject(position),
	_room_id(room_id)
{}

void Room::draw_room_border_symbol(int x, int y, int color, size_t count)
{
	draw_symbol(room_border_basic, x, y, color, count);
}

void  Room::fill_room_empty(char filling_symbol, int x, int y, int w, int h)
{
	for (int i = 0; i < h; ++i) {
		draw_symbol(filling_symbol, x, y + i, empty_place_color, w);
	}
}

/* Draw basic room 4 x 5 with border and empty inside*/
void Room::draw_basic_room()
{
	int& x = _position.x;
	int& y = _position.y;
	int& w = _position.width;
	int& h = _position.height;

	fill_room_empty(empty_place_symbol, x, y, w, h);
	draw_room_border_symbol(x, y, GameObject::Color::White, w);

	for (int i = 1; i < h - 1; ++i) {
		draw_room_border_symbol(x, y + i, GameObject::Color::White, 1);
		draw_room_border_symbol(x + w - 1, y + i, GameObject::Color::White, 1);
	}

	draw_room_border_symbol(x, y + h - 1, GameObject::Color::White, w);


}

void Room::draw()
{
	draw_basic_room();
	//(this->*draw_room_functions[_room_id])();
}
