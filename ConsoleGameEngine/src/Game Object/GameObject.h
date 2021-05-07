#pragma once
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include "../std_includes.h"

namespace CGE {
	using tag_t = size_t;

	tag_t get_class_tag();

	template<class _Type>
	size_t get_class_tag() {
		static tag_t value = get_class_tag();
		return value;
	}

	struct GameRect {
		GameRect(int x, int y, int width, int height);
		GameRect(int x, int y);
		int x;
		int y;
		int width;
		int height;
	};

	class GameObject {
	protected:
		GameRect _position;
		tag_t _tag;
	public:
		const GameRect& get_position() const;
		tag_t get_tag() const;
	public:
		GameObject(GameRect position, tag_t tag);
		virtual void action(std::list<std::unique_ptr<GameObject>>& _objects) {}
		virtual void update() {}
		virtual void render() {}
		virtual ~GameObject() {}

		enum Color : int {
			Black = 0,
			Blue = 1,
			Green = 2,
			Cyan = 3,
			Red = 4,
			Magenta = 5,
			Brown = 6,
			LightGray = 7,
			DarkGray = 8,
			LightBlue = 9,
			LightGreen = 10,
			LightCyan = 11,
			LightRed = 12,
			LightMagenta = 13,
			Yellow = 14,
			White = 15
		};
	};
};
#endif