#pragma once
#ifndef _ROOM_H_
#define _ROOM_H_
#include <vector>
#include <functional>
#include "../../Game Object/GameObject.h"

class Room : public GameObject {
public:
	inline static const char empty_place_symbol = 249;
	inline static const char empty_place_color = Color::DarkGray;
	inline static const char room_border_basic = '#';
private:
	int _room_id;
public:
	Room(int room_id, GameRect position);
	
	/* Draw room */
	void draw();

	void fill_room_empty(char filling_symbol, int x, int y, int w, int h);
	
	/* Types of room */
	void draw_basic_room();
	
	/*std::vector<decltype(draw_basic_room)> draw_room_functions =  { 
		&draw_basic_room,
		&draw_basic_room };*/

	/*std::vector<std::function<void()>> draw_room_functions = {
		std::function(&draw_basic_room)
	};*/
	
	/* Types of symbols */
	void draw_room_border_symbol(int x, int y, int color, size_t count);

	virtual void update() {}
};
#endif
