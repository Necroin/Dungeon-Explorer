#include "Player.h"
#include <Windows.h>

Player::Player(Map& map, Renderer& renderer, char symbol, int x, int y, int health) :
	Entity(map, renderer, symbol, Color::Green, x, y, health, get_class_tag<Player>())
{}

void Player::action(std::list<std::unique_ptr<Entity>>& entities)
{
	if (GetAsyncKeyState(0x57) ) {
		_position.y -= 1;
	}
	if (GetAsyncKeyState(0x53)) {
		_position.y += 1;
	}
	if (GetAsyncKeyState(0x41)) {
		_position.x -= 1;
	}
	if (GetAsyncKeyState(0x44)) {
		_position.x += 1;
	}
}

void Player::update()
{
}
