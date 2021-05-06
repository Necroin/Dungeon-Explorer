#pragma once
#ifndef _ROOM_H_
#define _ROOM_H_
#include <vector>
#include <functional>
#include "../../Game Object/GameObject.h"
#include "RoomObject/RoomObject.h"

class Room;
typedef void (Room::* RoomFunctions) ();

class Room : public GameObject {
public:
	inline static const char empty_place_symbol = 249;
	inline static const char empty_place_color = Color::DarkGray;
	inline static const char room_border_basic = '#';
private:
	int _room_id;
	std::vector<RoomObject> room_objects;
	Renderer& _renderer;
public:
	Room(Renderer& renderer, int room_id, GameRect position);
	
	/* Types of room */
	void generate_basic_room();
	void draw_basic_room();

	/* Draw room */
	void generate_room();
	RoomFunctions generateFunctions[2] =
	{
		&Room::generate_basic_room,
		&Room::generate_basic_room
	};

	void draw();
	RoomFunctions drawFunctions[2] =
	{
		&Room::draw_basic_room, 
		&Room::draw_basic_room
	};

	virtual void update() {}
};
#endif
