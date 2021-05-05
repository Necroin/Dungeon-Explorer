#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "../Game Object/GameObject.h"
#include <vector>
#include <list>

#include "../Map/Map.h"

class Entity : public GameObject{
protected:
	char _symbol;
	int _health;

	enum class EntityTag{
		Player,
		Enemy
	};
	EntityTag _tag;

	int _color;

	Map& _map;
protected:
	void show();
	void hide();
public:
	Entity(Map& map, char symbol, int color, int x, int y, int health, EntityTag tag);
	virtual ~Entity() {}
	virtual void action(std::list<std::unique_ptr<Entity>>& entities) = 0;
	//bool apply_damage(Damage damage); Damage - ?
};
#endif