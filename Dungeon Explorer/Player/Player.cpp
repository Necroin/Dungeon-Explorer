#include "Player.h"
#include <Windows.h>


void Player::shift_console_up()
{
	decltype(auto) hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	CHAR_INFO ci;

	CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
	GetConsoleScreenBufferInfo(hOutput, &consoleInfo);
	int width = consoleInfo.srWindow.Right - consoleInfo.srWindow.Left + 1;
	int height = consoleInfo.srWindow.Bottom - consoleInfo.srWindow.Top + 1;
}

Player::Player(Map& map, char symbol, int x, int y, int health) :
	Entity(map, symbol, Color::Green, x, y, health, EntityTag::Player)
{}

void Player::action(std::list<std::unique_ptr<Entity>>& entities)
{
	Entity::hide();
	if (GetAsyncKeyState(0x57) ) {
		_position.y -= 1;
		shift_console_up();
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
	Entity::show();
}

void Player::update()
{
}
