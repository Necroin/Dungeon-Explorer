#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_
#include "../Game Object/GameObject.h"
#include "../Renderer/Renderer.h"
#include <vector>
#include <list>

#include "../Map/Map.h"

class Entity : public GameObject{
protected:
	char _symbol;
	int _color;
	
	int _health;

	Map& _map;
	Renderer& _renderer;
protected:
	void show();
	void hide();
public:
	Entity(Map& map, Renderer& renderer, char symbol, int color, int x, int y, int health, tag_t tag);
	virtual ~Entity() {}
	virtual void action(std::list<std::unique_ptr<Entity>>& entities) {};
	virtual void render() override;
	//bool apply_damage(Damage damage); Damage - ?
};
#endif