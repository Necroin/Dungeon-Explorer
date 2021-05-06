#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_
#include <Windows.h>
#include <array>
#include <exception>

class Renderer {
private:
	inline static constexpr int _surfaces_count = 2;
	std::array<HANDLE, _surfaces_count> _surfaces;
	HANDLE _current_surface;
	int _current_surface_index;
private:
	void clear_surface(HANDLE surface);
public:
	Renderer();
public:
	void draw_symbol(char symbol, int x, int y, int color, size_t count = 1);
	void swap_surfaces();
	void render();
	void set_fullscreen();
};
#endif