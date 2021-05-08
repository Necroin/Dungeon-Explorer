#pragma once
#ifndef _GAME_H_
#define _GAME_H_
#include "CGE.h"
#include "../Map/Map.h"
#include "../Player/Player.h"

class Game : public CGE::CGEGame<Game> {
private:
	bool _is_active = true;

	Map _map;

	std::list<std::unique_ptr<CGE::GameObject>> _objects;

	std::unique_ptr<Player> _player;

	std::unique_ptr<CGE::UI::HorizontalLayout> _in_play_buttons;
	std::unique_ptr<CGE::UI::HorizontalLayout> _characteristics_layout;

public:
	Game(int game_FPS);
	virtual void event() override;
	virtual void action() override;
	virtual void update() override;
	virtual void render() override;
};
#endif