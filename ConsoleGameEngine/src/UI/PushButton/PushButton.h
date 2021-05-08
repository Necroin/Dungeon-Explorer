#pragma once
#ifndef _PUSHBUTTON_H_
#define _PUSHBUTTON_H_
#include "../UIObject/UIObject.h"
#include "../../Event System/EventSystem.h"

namespace CGE::UI {
	class PushButton : public UIObject
	{
	private:
		std::string _text;
		EventSystem::Event<> _pressed;
		int _color;
	public:
		PushButton(Renderer& renderer, const char* text, int color, UIObject* parent = nullptr);
		PushButton(Renderer& renderer, const std::string& text, int color, UIObject* parent = nullptr);
		PushButton(Renderer& renderer, int x, int y, const char* text, int color);
		PushButton(Renderer& renderer, int x, int y, const std::string& text, int color);
		virtual void show() const override;
		virtual void hide() const override;
		virtual void event(UIEvent& event) override;
		void set_text(const std::string& text);
		EventSystem::IEvent<>& pressed_event();
	};
}
#endif