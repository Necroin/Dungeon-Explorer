#include "Game/Game.h"
#include <chrono>
#include <thread>

int main() {
	constexpr int FPS = 30;
	std::chrono::milliseconds frame_delay{ 1000 / FPS };
	Game game;
	while (game.is_active()) {
		decltype(auto) frame_start = std::chrono::steady_clock::now();
		game.run();
		decltype(auto) frame_time = std::chrono::steady_clock::now() - frame_start;
		if (frame_delay > frame_time) {
			std::this_thread::sleep_for(std::chrono::duration_cast<std::chrono::milliseconds>(frame_delay - frame_time));
		}
	}
	return 0;
}