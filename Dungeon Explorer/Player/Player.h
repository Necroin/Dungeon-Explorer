#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "../core/Entity/Entity.h"

class Player : public Entity {
private:
public:
	Player(Map& map, Renderer& renderer, char symbol, int x, int y, int health);

	virtual void action(std::list<std::unique_ptr<Entity>>& entities) override;
	virtual void update() override;
};
#endif