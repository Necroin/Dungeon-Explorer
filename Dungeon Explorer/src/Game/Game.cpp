#include "Game.h"
#include <Windows.h>


Game::Game(int game_FPS) :
	CGEGame(*this, game_FPS),
	_map(_renderer)
{
	_renderer.get_camera().move_to(_map.get_x_centre(), _map.get_y_centre());
	_map.draw();

	_objects.emplace_back(std::make_unique<Player>(_map, _renderer, '@', _map.get_x_centre(), _map.get_y_centre(), 10));
}

void Game::action()
{
	for (auto&& entity : _objects) {
		entity->action(_objects);
	}
}

void Game::update()
{
	for (auto&& entity : _objects) {
		entity->update();
	}
}

void Game::render()
{
	_map.draw();
	for (auto&& entity : _objects) {
		entity->render();
	}
}
