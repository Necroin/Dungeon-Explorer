#include "RoomObject.h"
using namespace CGE;

RoomObject::RoomObject(Renderer& renderer, int room_object_id, GameRect position) :
	GameObject(position, get_class_tag<RoomObject>()),
	_room_object_id(room_object_id),
	_renderer(renderer)
{}


void  RoomObject::fill_room_empty(char filling_symbol, int x, int y, int w, int h)
{
	for (int i = 0; i < h; ++i) {
		_renderer.draw_symbol(filling_symbol, x, y + i, AsciiSymbols::empty_place_color, w);
	}
}


void RoomObject::draw_room_border_symbol(int x, int y, int color, size_t count)
{
	_renderer.draw_symbol(AsciiSymbols::room_border_basic, x, y, color, count);
}

void RoomObject::draw_specific_symbol(char symbol, int x, int y, int color)
{
	_renderer.draw_symbol(symbol, x, y, color, 1);
}

void RoomObject::draw_strange_bomb() {

	int& x = _position.x;
	int& y = _position.y;
	int& w = _position.width;
	int& h = _position.height;

	draw_specific_symbol(AsciiSymbols::double_line_corner_left_up, x, y, CGE::Color::White);
	draw_specific_symbol(AsciiSymbols::vertical_line, x + 1, y, CGE::Color::White);
	draw_specific_symbol(AsciiSymbols::double_line_corner_right_up, x + 2, y, CGE::Color::White);

	draw_specific_symbol(AsciiSymbols::horizontal_line, x, y + 1, CGE::Color::White);
	draw_specific_symbol(AsciiSymbols::center_filled_square, x + 1, y + 1, CGE::Color::White);
	draw_specific_symbol(AsciiSymbols::horizontal_line, x + 2, y + 1, CGE::Color::White);

	draw_specific_symbol(AsciiSymbols::double_line_corner_left_down, x, y + 2, CGE::Color::White);
	draw_specific_symbol(AsciiSymbols::vertical_line, x + 1, y + 2, CGE::Color::White);
	draw_specific_symbol(AsciiSymbols::double_line_corner_right_down, x + 2, y + 2, CGE::Color::White);
}

void RoomObject::draw_rect_borders() 
{
		int& x = _position.x;
		int& y = _position.y;
		int& w = _position.width;
		int& h = _position.height;

		fill_room_empty(AsciiSymbols::empty_place_symbol, x, y, w, h);
		draw_room_border_symbol(x, y, CGE::Color::White, w);

		for (int i = 1; i < h - 1; ++i) {
			draw_room_border_symbol(x, y + i, CGE::Color::White, 1);
			draw_room_border_symbol(x + w - 1, y + i, CGE::Color::White, 1);
		}

		draw_room_border_symbol(x, y + h - 1, CGE::Color::White, w);

}

void RoomObject::draw()
{
	(this->*drawFunctions[_room_object_id])();
}
