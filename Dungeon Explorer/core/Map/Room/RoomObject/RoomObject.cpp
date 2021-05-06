#include "RoomObject.h"

RoomObject::RoomObject(int room_object_id, GameRect position) :
	GameObject(position),
	_room_object_id(room_object_id)
{}


void  RoomObject::fill_room_empty(char filling_symbol, int x, int y, int w, int h)
{
	for (int i = 0; i < h; ++i) {
		draw_symbol(filling_symbol, x, y + i, empty_place_color, w);
	}
}


void RoomObject::draw_room_border_symbol(int x, int y, int color, size_t count)
{
	draw_symbol(room_border_basic, x, y, color, count);
}

void RoomObject::draw_specific_symbol(char symbol, int x, int y, int color)
{
	draw_symbol(symbol, x, y, color, 1);
}

void RoomObject::draw_strange_bomb() {

	int& x = _position.x;
	int& y = _position.y;
	int& w = _position.width;
	int& h = _position.height;

	draw_specific_symbol(double_line_corner_left_up, x, y, GameObject::Color::White);
	draw_specific_symbol(vertical_line, x + 1, y, GameObject::Color::White);
	draw_specific_symbol(double_line_corner_right_up, x + 2, y, GameObject::Color::White);

	draw_specific_symbol(horizontal_line, x, y + 1, GameObject::Color::White);
	draw_specific_symbol(center_filled_square, x + 1, y + 1, GameObject::Color::White);
	draw_specific_symbol(horizontal_line, x + 2, y + 1, GameObject::Color::White);

	draw_specific_symbol(double_line_corner_left_down, x, y + 2, GameObject::Color::White);
	draw_specific_symbol(vertical_line, x + 1, y + 2, GameObject::Color::White);
	draw_specific_symbol(double_line_corner_right_down, x + 2, y + 2, GameObject::Color::White);
}

void RoomObject::draw_rect_borders() 
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

void RoomObject::draw()
{
	(this->*drawFunctions[_room_object_id])();
}
