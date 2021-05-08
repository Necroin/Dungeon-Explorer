#include "GameObject.h"

namespace CGE {

	const GameRect& GameObject::get_position() const
	{
		return _position;
	}

	tag_t GameObject::get_tag() const
	{
		return _tag;
	}

	GameObject::GameObject(GameRect position, tag_t tag) :
		_position(position),
		_tag(tag)
	{}

	GameRect::GameRect(int x, int y, int width, int height) :
		x(x), y(y), width(width), height(height)
	{}

	GameRect::GameRect(int x, int y) :
		x(x), y(y), width(0), height(0)
	{}
};