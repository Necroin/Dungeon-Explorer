#include "Game.h"
#include <Windows.h>


Game::Game() :
	_map(_renderer, 20, 20)
{
	set_console_parameters();
	_map.draw();

	_entities.emplace_back(std::make_unique<Player>(_map, _renderer, '@', _map.get_x_centre(), _map.get_y_centre(), 10));
}

bool Game::is_active() const
{
	return _is_active;
}

void Game::run()
{
	_renderer.swap_surfaces();
	action();
	update();
	render();
}

void Game::action()
{
	for (auto&& entity : _entities) {
		entity->action(_entities);
	}
}

void Game::update()
{
	for (auto&& entity : _entities) {
		entity->update();
	}
}

void Game::render()
{
	_map.draw();
	for (auto&& entity : _entities) {
		entity->render();
	}
	_renderer.render();
}
