#include "Camera.h"

Camera::Camera() :
	GameObject({ 0,0,0,0 }, get_class_tag<Camera>())
{}

int Camera::translate_x_coordinate(int x)
{
	return x - _position.x;
}

int Camera::translate_y_coordinate(int y)
{
	return y - _position.y;
}

GameRect Camera::translate_coordinates(int x, int y)
{
	return { x - _position.x, y - _position.y };
}

GameRect Camera::translate_coordinates(GameRect position)
{
	position.x -= _position.x;
	position.y -= _position.y;
	return position;
}

void Camera::move_left()
{
	if (_position.x > 0) {
		--_position.x;
	}
}

void Camera::move_right()
{
	++_position.x;
}

void Camera::move_up()
{
	if (_position.y > 0) {
		--_position.y;
	}
}

void Camera::move_down()
{
	++_position.y;
}

void Camera::move_to(int x, int y)
{
	_position.x = x;
	_position.y = y;
}
