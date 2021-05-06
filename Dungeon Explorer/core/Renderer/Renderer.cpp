#include "Renderer.h"

Renderer::Renderer() :
	_current_surface_index(0)
{
	for (auto&& surface : _surfaces) {
		surface = CreateConsoleScreenBuffer(GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	}
	if (_surfaces[0] == INVALID_HANDLE_VALUE ||
		_surfaces[1] == INVALID_HANDLE_VALUE)
	{
		throw std::exception("CreateConsoleScreenBuffer failed - (%d)");
	}

	/*for (auto&& surface : _surfaces) {
		COORD coord;
		SetConsoleDisplayMode(surface, CONSOLE_FULLSCREEN_MODE, &coord);

		DWORD console_prev_mode;
		GetConsoleMode(hInput, &console_prev_mode);
		SetConsoleMode(hInput, console_prev_mode & ~ENABLE_QUICK_EDIT_MODE);
	}*/
	_current_surface = _surfaces[_current_surface_index];
	SetConsoleActiveScreenBuffer(_current_surface);
}

void Renderer::clear_surface(HANDLE surface)
{
	DWORD written;
	CONSOLE_SCREEN_BUFFER_INFO buf_info;
	GetConsoleScreenBufferInfo(surface, &buf_info);
	int cell_count = buf_info.dwSize.X * buf_info.dwSize.Y;
	FillConsoleOutputCharacterA(surface, ' ', cell_count, COORD{ 0,0 }, &written);
}

void Renderer::draw_symbol(char symbol, int x, int y, int color, size_t count)
{
	DWORD written;
	FillConsoleOutputAttribute(_current_surface, (WORD)color, count, COORD{ static_cast<SHORT>(x), static_cast<SHORT>(y) }, &written);
	FillConsoleOutputCharacterA(_current_surface, static_cast<CHAR>(symbol), count, COORD{ static_cast<SHORT>(x), static_cast<SHORT>(y) }, &written);
}

void Renderer::swap_surfaces()
{
	++_current_surface_index %= _surfaces_count;
	_current_surface = _surfaces[_current_surface_index];
}

void Renderer::render()
{
	SetConsoleActiveScreenBuffer(_current_surface);
	clear_surface(_surfaces[(_current_surface_index + 1) % _surfaces_count]);
}

void Renderer::set_fullscreen()
{
	decltype(auto) hInput = GetStdHandle(STD_INPUT_HANDLE);
	decltype(auto) hOutput = GetStdHandle(STD_OUTPUT_HANDLE);

	COORD coord;
	SetConsoleDisplayMode(hOutput, CONSOLE_FULLSCREEN_MODE, &coord);

	DWORD console_prev_mode;
	GetConsoleMode(hInput, &console_prev_mode);
	SetConsoleMode(hInput, console_prev_mode & ~ENABLE_QUICK_EDIT_MODE);
}
