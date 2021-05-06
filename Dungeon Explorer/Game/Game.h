#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include "../Player/Player.h"
#include "../core/Renderer/Renderer.h"

class Game {
private:
	bool _is_active = true;

	Camera _camera;
	Renderer _renderer;
	Map _map;

	std::list<std::unique_ptr<Entity>> _entities;
public:
	Game();
	bool is_active() const;
	void run();

	void action();
	void update();
	void render();
};
#endif