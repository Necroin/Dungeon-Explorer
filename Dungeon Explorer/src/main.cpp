#include "Game/Game.h"
#include <chrono>
#include <thread>

int main() {
	constexpr int FPS = 30;
	Game(FPS).execute();
	return 0;
}