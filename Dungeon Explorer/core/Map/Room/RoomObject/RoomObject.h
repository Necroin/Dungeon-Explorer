#pragma once
#ifndef _ROOMOBJECT_H_
#define _ROOMOBJECT_H_
#include "../../../Game Object/GameObject.h"
#include "AsciiSymbol.h"

class RoomObject;
typedef void (RoomObject::* RoomObjectFunctions) ();

class RoomObject : public GameObject {
public:
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