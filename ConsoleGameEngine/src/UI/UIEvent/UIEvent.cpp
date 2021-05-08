#include "UIEvent.h"

namespace CGE::UI {
	tag_t UIEvent::get_tag()
	{
		return _tag;
	}

	UIEvent::UIEvent(tag_t tag) :
		_tag(tag)
	{}

	int UIMouseEvent::get_x()
	{
		return _x;
	}

	int UIMouseEvent::get_y()
	{
		return _y;
	}

	UIMouseEvent::UIMouseEvent(int x, int y) :
		UIEvent(get_class_tag<UIMouseEvent>()),
		_x(x),
		_y(y)
	{}
};