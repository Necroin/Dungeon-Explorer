#include "PushButton.h"

namespace CGE::UI {
	PushButton::PushButton(Renderer& renderer, const char* text, int color, UIObject* parent) :
		UIObject(renderer, parent, GameRect{ 0, 0, static_cast<int>(std::string_view(text).size()) + 2 , 3 }),
		_text(text),
		_color(color)
	{}

	PushButton::PushButton(Renderer& renderer, const std::string& text, int color, UIObject* parent) :
		UIObject(renderer, parent, GameRect{ 0, 0, static_cast<int>(text.size()) + 2, 3 }),
		_text(text),
		_color(color)
	{}

	PushButton::PushButton(Renderer& renderer, int x, int y, const char* text, int color) :
		UIObject(renderer, nullptr, GameRect{ x, y, static_cast<int>(std::string_view(text).size()) + 2 , 3 }),
		_text(text),
		_color(color)
	{}

	PushButton::PushButton(Renderer& renderer, int x, int y, const std::string& text, int color) :
		UIObject(renderer, nullptr, GameRect{ x, y, static_cast<int>(text.size()) + 2, 3 }),
		_text(text),
		_color(color)
	{}

	void PushButton::show() const
	{
		_renderer.draw_symbol_absolute(218, _position.x, _position.y, _color);
		_renderer.draw_symbol_absolute(191, _position.x + _position.width - 1, _position.y, _color);
		_renderer.draw_symbol_absolute(192, _position.x, _position.y + _position.height - 1, _color);
		_renderer.draw_symbol_absolute(217, _position.x + _position.width - 1, _position.y + _position.height - 1, _color);

		_renderer.draw_symbol_absolute(196, _position.x + 1, _position.y, _color, _text.size());
		_renderer.draw_symbol_absolute(196, _position.x + 1, _position.y + _position.height - 1, _color, _text.size());

		for (size_t i = 1; i < _position.height - 1; ++i) {
			_renderer.draw_symbol_absolute(179, _position.x, _position.y + i, _color);
			_renderer.draw_symbol_absolute(179, _position.x + _text.size() + 1, _position.y + i, _color);
		}
		_renderer.draw_string_absolute(_text.c_str(), _text.size(), _position.x + 1, _position.y + 1, _color);
	}

	void PushButton::hide() const
	{
		for (size_t i = 0; i < _position.height; i++) {
			_renderer.draw_symbol_absolute(' ', _position.x, _position.y + i, _color, _position.width);
		}
	}

	void PushButton::event(UIEvent& event)
	{
		if (auto mouse_event = event.as<UIMouseEvent>()) {
			if (mouse_event->get_x() >= _position.x && mouse_event->get_x() < _position.x + _position.width &&
				mouse_event->get_y() >= _position.y && mouse_event->get_y() < _position.y + _position.height)
			{
				_pressed();
			}
		}
	}

	void PushButton::set_text(const std::string& text)
	{
		_text = text;
	}

	EventSystem::IEvent<>& PushButton::pressed_event()
	{
		return _pressed;
	}
}