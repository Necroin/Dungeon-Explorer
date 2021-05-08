#include "Text.h"

namespace CGE::UI {
	Text::Text(Renderer& renderer, const char* text, int color, UIObject* parent) :
		UIObject(renderer, parent, GameRect{ 0, 0, static_cast<int>(std::string_view(text).size()), 1 }),
		_text(text),
		_color(color)
	{}

	Text::Text(Renderer& renderer, const std::string& text, int color, UIObject* parent) :
		UIObject(renderer, parent, GameRect{ 0, 0, static_cast<int>(text.size()), 1 }),
		_text(text),
		_color(color)
	{}

	Text::Text(Renderer& renderer, int x, int y, const char* text, int color) :
		UIObject(renderer, nullptr, GameRect{ x, y, static_cast<int>(std::string_view(text).size()), 1 }),
		_text(text),
		_color(color)
	{}

	Text::Text(Renderer& renderer, int x, int y, const std::string& text, int color) :
		UIObject(renderer, nullptr, GameRect{ x, y, static_cast<int>(text.size()), 1 }),
		_text(text),
		_color(color)
	{}

	const std::string& Text::text()
	{
		return _text;
	}

	void Text::set_text(const std::string& text)
	{
		std::size_t prev_width = _position.width;
		_text = text;
		_position.width = _text.size();
		if (prev_width != _position.width) {
			decltype(auto) root_update_position = &Text::UIObject::update_position;
			(root()->*root_update_position)();
			if (!_hidden) {
				root()->hide();
				root()->show();
			}
		}
	}

	void Text::set_text(const char* text)
	{
		std::size_t prev_width = _position.width;
		_text = text;
		_position.width = _text.size();
		if (prev_width != _position.width) {
			decltype(auto) root_update_position = &Text::UIObject::update_position;
			(root()->*root_update_position)();
			if (!_hidden) {
				root()->hide();
				root()->show();
			}
		}
	}

	void Text::render()
	{
		if(!_hidden) _renderer.draw_string_absolute(_text.c_str(), _position.width, _position.x, _position.y, _color);
	}
}