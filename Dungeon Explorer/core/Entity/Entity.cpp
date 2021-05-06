#include "Entity.h"

void Entity::show()
{
	_renderer.draw_symbol(_symbol, _position.x, _position.y, _color);
}

void Entity::hide()
{
	_renderer.draw_symbol(Room::empty_place_symbol, _position.x, _position.y, Room::empty_place_color);
}

Entity::Entity(Map& map, Renderer& renderer, char symbol, int color, int x, int y, int health, tag_t tag) :
	GameObject({ x, y, 0, 0 }, tag),
	_map(map),
	_renderer(renderer),
	_symbol(symbol),
	_color(color),
	_health(health)
{
	show();
}

void Entity::render()
{
	show();
}
