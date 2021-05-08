#pragma once
#ifndef _PLAYER_H_
#define _PLAYER_H_
#include "CGE.h"
#include "../Map/Map.h"

class Player : public CGE::GameObject {
private:
	Map& _map;
	CGE::Renderer& _renderer;
	int _health;

	enum class PlayerActions {
		stay,
		move_left,
		move_right,
		move_down,
		move_up
	};
	CGE::FSM::FSM<PlayerActions> _player_fsm;
public:
	Player(Map& map, CGE::Renderer& renderer, int x, int y, int health);
	virtual void action(std::list<std::unique_ptr<GameObject>>& entities) override;
	virtual void update() override;
	virtual void render() override;
};
#endif