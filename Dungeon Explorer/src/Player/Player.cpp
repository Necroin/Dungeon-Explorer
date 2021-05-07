#include "Player.h"

Player::Player(Map& map, CGE::Renderer& renderer, char symbol, int x, int y, int health) :
	CGE::GameObject({ x, y, 0,0 }, CGE::get_class_tag<Player>()),
	_map(map),
	_renderer(renderer),
	_symbol(symbol),
	_health(health)
{}

void Player::action(std::list<std::unique_ptr<GameObject>>& entities)
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

void Player::render()
{
	_renderer.draw_symbol(_symbol, _position.x, _position.y, Color::Green);
}
