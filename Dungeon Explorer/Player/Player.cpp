#include "Player.h"

Player::Player(Map& map, Renderer& renderer, char symbol, int x, int y, int health) :
	Entity(map, renderer, symbol, Color::Green, x, y, health, get_class_tag<Player>())
{}

void Player::action(std::list<std::unique_ptr<Entity>>& entities)
{
	if (GetAsyncKeyState(0x57) ) {
		_position.y -= 1;
		_renderer.get_camera().move_up();
	}
	if (GetAsyncKeyState(0x53)) {
		_position.y += 1;
		_renderer.get_camera().move_down();
	}
	if (GetAsyncKeyState(0x41)) {
		_position.x -= 1;
		_renderer.get_camera().move_left();
	}
	if (GetAsyncKeyState(0x44)) {
		_position.x += 1;
		_renderer.get_camera().move_right();
	}
}

void Player::update()
{
}
