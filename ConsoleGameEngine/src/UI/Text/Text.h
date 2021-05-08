#pragma once
#ifndef _TEXT_H_
#define _TEXT_H_
#include "../UIObject/UIObject.h"

namespace CGE::UI {
	class Text :
		public UIObject
	{
	private:
		std::string _text;
		mutable bool _hiden = true;
		int _color;
	public:
		Text(Renderer& renderer, const char* text, int color, UIObject* parent = nullptr);
		Text(Renderer& renderer, const std::string& text, int color, UIObject* parent = nullptr);
		Text(Renderer& renderer, int x, int y, const char* text, int color);
		Text(Renderer& renderer, int x, int y, const std::string& text, int color);
	public:
		const std::string& text();
		void set_text(const std::string& text);
		void set_text(const char* text);
		virtual void show() const override;
		virtual void hide() const override;
	};
}
#endif
