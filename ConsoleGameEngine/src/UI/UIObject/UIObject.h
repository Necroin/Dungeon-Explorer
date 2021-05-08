#pragma once
#ifndef _UIOBJECT_H_
#define _UIOBJECT_H_
#include "../../Bases/Bases_include.h"
#include "../../Renderer/Renderer.h"
#include "../UIEvent/UIEvent.h"

namespace CGE::UI {
	class UIObject {
	protected:
		GameRect _position;
		UIObject* _parent;
		Renderer& _renderer;
	protected:
		virtual void update_position();
		void update_width(int width);
		void update_height(int height);
		UIObject* root();
	public:
		UIObject(Renderer& renderer, UIObject* parent, const GameRect& position);
		virtual ~UIObject();
	public:
		virtual void show() const = 0;
		virtual void hide() const = 0;
		virtual void event(UIEvent& event);
		int x() const noexcept;
		int y() const noexcept;
		int width() const noexcept;
		int height() const noexcept;
		const GameRect& position() const noexcept;
	};
}
#endif