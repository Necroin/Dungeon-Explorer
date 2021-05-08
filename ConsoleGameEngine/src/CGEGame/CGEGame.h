#pragma once
#ifndef _CGE_GAME_H_
#define _CGE_GAME_H_
#include "../Renderer/Renderer.h"
namespace CGE {
	template<class _DerivedGameClass>
	class CGEGame {
	private:
		_DerivedGameClass& _game;
	protected:
		int _FPS;
		bool _is_active = true;
		Renderer _renderer;
	public:
		CGEGame(_DerivedGameClass& game, int game_FPS) :
			_FPS(game_FPS),
			_game(game)
		{}

		virtual void event() {}
		virtual void action() {}
		virtual void update() {}
		virtual void render() {}
	private:
		void do_frame_interation() {
			_renderer.swap_surfaces();
			_game.event();
			_game.action();
			_game.update();
			_game.render();
			_renderer.render();
		}
	public:
		void execute() {
			std::chrono::milliseconds frame_delay{ 1000 / _FPS };
			while (_is_active) {
				decltype(auto) frame_start = std::chrono::steady_clock::now();
				do_frame_interation();
				decltype(auto) frame_time = std::chrono::steady_clock::now() - frame_start;
				if (frame_delay > frame_time) {
					std::this_thread::sleep_for(std::chrono::duration_cast<std::chrono::milliseconds>(frame_delay - frame_time));
				}
			}
		}
	};
};
#endif