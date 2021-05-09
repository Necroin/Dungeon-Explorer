#pragma once
#ifndef _FRAME_H_
#define _FRAME_H_
#include "../UIObject/UIObject.h"

namespace CGE::UI {
	template<class _UIObject>
	class Frame : public UIObject
	{
	private:
		std::unique_ptr<_UIObject> _framed_object;
		int _color;

		virtual void update_position() override {
			_position.width = 2;
			_position.height = 2;
			decltype(auto) object = _framed_object.get();
			decltype(auto) object_position = &Frame<_UIObject>::_position;

			if (_framed_object) {
				(*object.*object_position).x = _position.x + 1;
				(*object.*object_position).y = _position.y + 1;
			}

			decltype(auto) parent_update_width = &Frame<_UIObject>::UIObject::update_width;
			if (_parent) (_parent->*parent_update_width)(_position.width);

			decltype(auto) parent_update_height = &Frame<_UIObject>::UIObject::update_height;
			if (_parent) (_parent->*parent_update_height)(_position.height);

			if (_framed_object) {
				decltype(auto) object_update_positiion = &Frame::UIObject::update_position;
				((*object).*object_update_positiion)();
				_position.width += (*object.*object_position).width;
				_position.height += (*object.*object_position).height;
			}
		}
		virtual void update_width(int width) override {
			if (width > _position.width - 2) {
				_position.width = width + 2;
				decltype(auto) parent_update_width = &Frame<_UIObject>::UIObject::update_width;
				if (_parent) (_parent->*parent_update_width)(width);
			}
		}
		virtual void update_height(int height) override {
			if (height > _position.height - 2) {
				_position.height = height + 2;
				decltype(auto) parent_update_height = &Frame<_UIObject>::UIObject::update_height;
				if (_parent) (_parent->*parent_update_height)(height);
			}
		}
	public:
		Frame(Renderer& renderer, int x, int y, int color) :
			UIObject(renderer, nullptr, { x, y, 2, 2 }),
			_color(color)
		{}

		Frame(Renderer& renderer, UIObject* parent, int x, int y, int color) :
			UIObject(renderer, parent, { x, y, 2, 2 }),
			_color(color)
		{}
	public:
		virtual void show() const {
			_hidden = false;
			_framed_object->show();
		}
		virtual void hide() const {
			_hidden = true;
			_framed_object->hide();
		}

		virtual void render() override {
			if (!_hidden) {
				_renderer.draw_symbol_absolute(218, _position.x, _position.y, _color);
				_renderer.draw_symbol_absolute(191, _position.x + _position.width - 1, _position.y, _color);
				_renderer.draw_symbol_absolute(192, _position.x, _position.y + _position.height - 1, _color);
				_renderer.draw_symbol_absolute(217, _position.x + _position.width - 1, _position.y + _position.height - 1, _color);

				_renderer.draw_symbol_absolute(196, _position.x + 1, _position.y, _color, _position.width - 2);
				_renderer.draw_symbol_absolute(196, _position.x + 1, _position.y + _position.height - 1, _color, _position.width - 2);

				for (size_t i = 1; i < _position.height - 1; ++i) {
					_renderer.draw_symbol_absolute(179, _position.x, _position.y + i, _color);
					_renderer.draw_symbol_absolute(179, _position.x + _position.width - 1, _position.y + i, _color);
				}
				
				if (_framed_object) _framed_object->render();
			}
		}
		virtual void event(const UIEvent& event) override {
			if (_framed_object) _framed_object->event(event);
		}

		template<class... Args>
		_UIObject& add_object(Args&&... args) {
			_framed_object = std::make_unique<_UIObject>(std::forward<Args>(args)...);

			decltype(auto) object = _framed_object.get();
			decltype(auto) object_position = &Frame::_position;
			(*object.*object_position).x = _position.x + 1;
			(*object.*object_position).y = _position.y + 1;
			_position.width = (*object.*object_position).width + 2;
			_position.height = (*object.*object_position).height + 2;

			decltype(auto) parent_update_width = &Frame<_UIObject>::UIObject::update_width;
			if (_parent) (_parent->*parent_update_width)(_position.width);

			decltype(auto) parent_update_height = &Frame<_UIObject>::UIObject::update_height;
			if (_parent) (_parent->*parent_update_height)(_position.height);

			decltype(auto) root_update_position = &Frame<_UIObject>::UIObject::update_position;
			(root()->*root_update_position)();

			return *_framed_object;
		}

		_UIObject& get_object() {
			return *_framed_object;
		}
	};
}
#endif