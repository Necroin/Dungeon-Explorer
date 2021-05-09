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
		mutable bool _hidden = true;
	protected:
		virtual void update_position();
		virtual void update_width(int width);
		virtual void update_height(int height);
		UIObject* root();
	public:
		UIObject(Renderer& renderer, UIObject* parent, const GameRect& position);
		virtual ~UIObject();
	public:
		virtual void show() const;
		virtual void hide() const;
		const bool& is_hidden() const;
		virtual void render() = 0;
		virtual void event(const UIEvent& event);
		int x() const noexcept;
		int y() const noexcept;
		int width() const noexcept;
		int height() const noexcept;
		const GameRect& position() const noexcept;
	};
}
#endif