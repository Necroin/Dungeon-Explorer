#include "Entity.h"

void Entity::show()
{
	draw_symbol(_symbol, _position.x, _position.y, _color);
}

void Entity::hide()
{
	draw_symbol(Room::empty_place_symbol, _position.x, _position.y, Room::empty_place_color);
}

Entity::Entity(Map& map, char symbol, int color, int x, int y, int health, EntityTag tag) :
	GameObject({ x, y, 0, 0 }),
	_symbol(symbol),
	_health(health),
	_tag(tag),
	_color(color),
	_map(map)
{
	show();
}