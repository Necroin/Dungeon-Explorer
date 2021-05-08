#pragma once
#ifndef _GAMERECT_H_
#define _GAMERECT_H_

namespace CGE {
	struct GameRect {
		GameRect(int x, int y, int width, int height);
		GameRect(int x, int y);
		int x;
		int y;
		int width;
		int height;
	};
};
#endif