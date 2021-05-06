#include "Renderer.h"

Renderer::Renderer() :
	_current_surface_index(0)
{
	for (auto&& surface : _surfaces) {
		surface = CreateConsoleScreenBuffer(GENERIC_WRITE | GENERIC_READ, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	}
	if (_surfaces[0] == INVALID_HANDLE_VALUE ||
		_surfaces[1] == INVALID_HANDLE_VALUE)
	{
		throw std::exception("CreateConsoleScreenBuffer failed - (%d)");
	}

	int font_size = 10;
	for (auto&& surface : _surfaces) {
		COORD new_font_size{ font_size, font_size };
		SetConsoleActiveScreenBuffer(surface);
		CONSOLE_FONT_INFOEX font_info;
		font_info.cbSize = sizeof(font_info);
		
		GetCurrentConsoleFontEx(surface, TRUE, &font_info);
		font_info.dwFontSize = new_font_size;
		font_info.FontFamily = FF_DONTCARE;
		font_info.FontWeight = FW_NORMAL;
		SetCurrentConsoleFontEx(surface, TRUE, &font_info);

		COORD largest_size = GetLargestConsoleWindowSize(surface);
		SMALL_RECT windowSize = { 0, 0, largest_size.X - 1, largest_size.Y - 1 };
		SetConsoleScreenBufferSize(surface, largest_size);
		SetConsoleWindowInfo(surface, TRUE, &windowSize);
		SetConsoleDisplayMode(surface, CONSOLE_FULLSCREEN_MODE, &largest_size);

		GetCurrentConsoleFontEx(surface, TRUE, &font_info);
		font_info.dwFontSize = new_font_size;
		font_info.FontFamily = FF_DONTCARE;
		font_info.FontWeight = FW_NORMAL;
		SetCurrentConsoleFontEx(surface, TRUE, &font_info);
	}

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

Renderer::~Renderer()
{
	for (auto&& surface : _surfaces) {
		CloseHandle(surface);
	}
}

void Renderer::render()
{
	SetConsoleActiveScreenBuffer(_current_surface);
	clear_surface(_surfaces[(_current_surface_index + 1) % _surfaces_count]);
}
