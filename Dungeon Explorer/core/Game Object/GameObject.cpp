#include "GameObject.h"
#include <Windows.h>


void GameObject::draw_symbol(char symbol, int x, int y, int color, size_t count)
{
	DWORD written;
	decltype(auto) handle = GetStdHandle(STD_OUTPUT_HANDLE);
	FillConsoleOutputAttribute(handle, (WORD)color, count, COORD{ static_cast<SHORT>(x), static_cast<SHORT>(y) }, &written);
	FillConsoleOutputCharacterA(handle, static_cast<CHAR>(symbol), count, COORD{ static_cast<SHORT>(x), static_cast<SHORT>(y) }, &written);
}

GameObject::GameObject(GameRect position) :
	_position(position)
{}

GameRect::GameRect(int x, int y, int width, int height) :
	x(x), y(y), width(width), height(height)
{}
