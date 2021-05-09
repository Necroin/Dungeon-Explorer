#pragma once
#ifndef _UIEVENT_H_
#define _UIEVENT_H_
#include "../../Bases/Bases_include.h"

namespace CGE::UI {
	class UIEvent {
	protected:
		tag_t _tag;
	public:
		tag_t get_tag();

		template<class DerivedEvent>
		DerivedEvent* as() {
			if (_tag == get_class_tag<DerivedEvent>()) {
				return static_cast<DerivedEvent*>(this);
			}
			return nullptr;
		}

		template<class DerivedEvent>
		const DerivedEvent* const as() const {
			if (_tag == get_class_tag<DerivedEvent>()) {
				return static_cast<const DerivedEvent*>(this);
			}
			return nullptr;
		}
	public:
		UIEvent(tag_t tag);
	};

	class UIMouseEvent : public UIEvent 
	{
	private:
		int _x;
		int _y;
	public:
		int get_x() const;
		int get_y() const;
	public:
		UIMouseEvent(int x, int y);
	};
};
#endif