#pragma once
#ifndef _ROOMOBJECT_H_
#define _ROOMOBJECT_H_
#include "../../../Game Object/GameObject.h"

class RoomObject;
typedef void (RoomObject::* RoomObjectFunctions) ();

class RoomObject : public GameObject {
public:
	inline static const char empty_place_symbol = 249;
	inline static const char empty_place_color = Color::DarkGray;
	inline static const char room_border_basic = '#';

	inline static const char double_line_corner_left_up = 201;
	inline static const char double_line_corner_right_up = 187;
	inline static const char double_line_corner_left_down = 200;
	inline static const char double_line_corner_right_down = 188;
	inline static const char center_filled_square = 254;
	inline static const char horizontal_line = 196;
	inline static const char vertical_line = 179;

	enum ObjectTypes : int {
		BORDER,
		BOMB,
		TABLE
	};

private:
	int _room_object_id;

public:
	RoomObject(int room_object_id, GameRect position);

	void fill_room_empty(char filling_symbol, int x, int y, int w, int h);

	void draw_rect_borders();
	void draw_strange_bomb();

	void draw_room_border_symbol(int x, int y, int color, size_t count);
	void draw_specific_symbol(char symbol, int x, int y, int color);

	void draw();
	RoomObjectFunctions drawFunctions[2] =
	{
		&RoomObject::draw_rect_borders,
		&RoomObject::draw_strange_bomb
	};


	virtual void update() {}
};

#endif