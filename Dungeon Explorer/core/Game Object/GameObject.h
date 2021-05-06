#pragma once
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_


struct GameRect {
	GameRect(int x, int y, int width, int height);
	int x;
	int y;
	int width;
	int height;
};

class GameObject {
protected:
	GameRect _position;

	static void draw_symbol(char symbol, int x, int y, int color, size_t count = 1);
public:
	GameObject(GameRect position);
	virtual void update() = 0;
	virtual ~GameObject() {}

	enum Color : int {
		Black = 0,
		Blue = 1,
		Green = 2,
		Cyan = 3,
		Red = 4,
		Magenta = 5,
		Brown = 6,
		LightGray = 7,
		DarkGray = 8,
		LightBlue = 9,
		LightGreen = 10,
		LightCyan = 11,
		LightRed = 12,
		LightMagenta = 13,
		Yellow = 14,
		White = 15
	};
};
#endif