#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "CGE.h"
#include "../Map/Map.h"

class Player : public CGE::GameObject {
private:
	Map& _map;
	CGE::Renderer& _renderer;
	char _symbol;
	int _health;
public:
	Player(Map& map, CGE::Renderer& renderer, char symbol, int x, int y, int health);
	virtual void action(std::list<std::unique_ptr<GameObject>>& entities) override;
	virtual void update() override;
	virtual void render() override;
};
#endif