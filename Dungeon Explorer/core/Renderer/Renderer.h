#pragma once
#ifndef _RENDERER_H_
#define _RENDERER_H_
#include "../std_includes.h"
#include "../Camera/Camera.h"

class Renderer {
private:
	inline static constexpr int _surfaces_count = 2;
	std::array<HANDLE, _surfaces_count> _surfaces;
	HANDLE _current_surface;
	int _current_surface_index;
	Camera& _camera;
private:
	void clear_surface(HANDLE surface);
public:
	Renderer(Camera& camera);
	~Renderer();
public:
	void draw_symbol(char symbol, int x, int y, int color, size_t count = 1);
	void swap_surfaces();
	void render();
public:
	Camera& get_camera() const;
	COORD get_screen_size();
};
#endif