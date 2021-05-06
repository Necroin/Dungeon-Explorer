#pragma once
#ifndef _CAMERA_H_
#define _CAMERA_H_
#include"../Game Object/GameObject.h"

class Camera : GameObject {
private:

public:
	Camera();
public:
	int translate_x_coordinate(int x);
	int translate_y_coordinate(int y);
	GameRect translate_coordinates(int x, int y);
	GameRect translate_coordinates(GameRect position);
public:
	void move_left();
	void move_right();
	void move_up();
	void move_down();
	void move_to(int x, int y);
};
#endif