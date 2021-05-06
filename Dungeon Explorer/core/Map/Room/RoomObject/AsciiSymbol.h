#pragma once
#ifndef _ASCIISYMBOL_H_
#define _ASCIISYMBOL_H_
#include "../../../Game Object/GameObject.h"

class AsciiSymbols{

public:
	inline static const char empty_place_symbol = 249;
	inline static const char empty_place_color = GameObject::Color::DarkGray;
	inline static const char room_border_basic = '#';
	
	inline static const char double_line_corner_left_up = 201;
	inline static const char double_line_corner_right_up = 187;
	inline static const char double_line_corner_left_down = 200;
	inline static const char double_line_corner_right_down = 188;
	inline static const char center_filled_square = 254;
	inline static const char horizontal_line = 196;
	inline static const char vertical_line = 179;

public:
	AsciiSymbols() {};

};


#endif