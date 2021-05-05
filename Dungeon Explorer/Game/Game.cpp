#include "Game.h"
#include <Windows.h>

void Game::set_console_parameters()
{
	set_console_font(10);
	set_fullscreen();
}

void Game::set_console_font(int font_size)
{
	decltype(auto) hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_FONT_INFOEX fontInfo;
	fontInfo.cbSize = sizeof(fontInfo);

	GetCurrentConsoleFontEx(hOutput, TRUE, &fontInfo);
	fontInfo.dwFontSize.X = font_size;
	fontInfo.dwFontSize.Y = font_size;
	fontInfo.FontFamily = FF_DONTCARE;
	fontInfo.FontWeight = FW_NORMAL;
	SetCurrentConsoleFontEx(hOutput, TRUE, &fontInfo);
}

void Game::set_fullscreen()
{
	decltype(auto) hInput = GetStdHandle(STD_INPUT_HANDLE);
	decltype(auto) hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;
	SetConsoleDisplayMode(hOutput, CONSOLE_FULLSCREEN_MODE, &coord);

	DWORD console_prev_mode;
	GetConsoleMode(hInput, &console_prev_mode);
	SetConsoleMode(hInput, console_prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}

Game::Game() :
	_map(20,20)
{
	set_console_parameters();
	_map.draw();

	_entities.emplace_back(std::make_unique<Player>(_map, '@', _map.get_x_centre(), _map.get_y_centre(), 10));
}

bool Game::is_active() const
{
	return _is_active;
}

void Game::run()
{
	for (auto&& entity : _entities) {
		entity->action(_entities);
	}

	for (auto&& entity : _entities) {
		entity->update();
	}
}
