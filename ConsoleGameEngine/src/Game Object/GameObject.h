#pragma once
#ifndef _GAMEOBJECT_H_
#define _GAMEOBJECT_H_
#include "../std_includes.h"
#include "../Bases/Bases_include.h"

namespace CGE {
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
	};
};
#endif