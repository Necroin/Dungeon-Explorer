#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include <memory>

#include "../core/Map/Map.h"
#include "../Player/Player.h"

class Game {
private:
	bool _is_active = true;
	Map _map;
	std::list<std::unique_ptr<Entity>> _entities;
private:
	void set_console_parameters();
	void set_console_font(int font_size);
	void set_fullscreen();
public:
	Game();
	bool is_active() const;
	void run();
};
#endif