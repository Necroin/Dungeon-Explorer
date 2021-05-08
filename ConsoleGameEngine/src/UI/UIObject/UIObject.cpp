#include "UIObject.h"

namespace CGE::UI {
	void UIObject::update_position() {}

	void UIObject::update_width(int width)
	{
		if (width > _position.width) {
			_position.width = width;
			if (_parent) _parent->update_width(width);
		}
	}

	void UIObject::update_height(int height)
	{
		if (height > _position.height) {
			_position.height = height;
			if (_parent) _parent->update_height(height);
		}
	}

	UIObject* UIObject::root()
	{
		UIObject* root = this;
		while (root->_parent) {
			root = root->_parent;
		}
		return root;
	}

	UIObject::UIObject(Renderer& renderer, UIObject* parent, const GameRect& position) :
		_parent(parent),
		_position(position),
		_renderer(renderer)
	{}

	UIObject::~UIObject() {}

	void UIObject::show() const
	{
		_hidden = false;
	}

	void UIObject::hide() const
	{
		_hidden = true;
	}

	const bool& UIObject::is_hidden() const
	{
		return _hidden;
	}

	void UIObject::event(const UIEvent& event) {}

	int UIObject::x() const noexcept
	{
		return _position.x;
	}

	int UIObject::y() const noexcept
	{
		return _position.y;
	}

	int UIObject::width() const noexcept
	{
		return _position.width;
	}

	int UIObject::height() const noexcept
	{
		return _position.height;
	}

	const GameRect& UIObject::position() const noexcept
	{
		return _position;
	}
}