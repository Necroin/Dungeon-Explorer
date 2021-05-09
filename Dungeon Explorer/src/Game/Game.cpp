#include "Game.h"
#include <Windows.h>


Game::Game(int game_FPS) :
	CGEGame(*this, game_FPS),
	_map(_renderer)
{
	_renderer.get_camera().move_to(_map.get_x_centre(), _map.get_y_centre());
	_map.draw();

	_player = std::make_unique<Player>(_map, _renderer, _map.get_x_centre(), _map.get_y_centre(), 10);


	_in_play_buttons = std::make_unique<CGE::UI::HorizontalLayout>(_renderer, 0, 0, 1, CGE::UI::HorizontalLayout::Model::centre);
	decltype(auto) characteristics_button = _in_play_buttons->add_object<CGE::UI::PushButton>(_renderer, "Characteristics", CGE::Color::White, _in_play_buttons.get());
	decltype(auto) inventory_button = _in_play_buttons->add_object<CGE::UI::PushButton>(_renderer, "Inventory", CGE::Color::White, _in_play_buttons.get());

	_characteristics_layout_frame = std::make_unique<CGE::UI::Frame<CGE::UI::HorizontalLayout>>(
		_renderer,
		_in_play_buttons->position().x,
		_in_play_buttons->position().y + _in_play_buttons->position().height,
		CGE::Color::White);

	decltype(auto) characteristics_layout = _characteristics_layout_frame->add_object(
		_renderer,
		_characteristics_layout_frame.get(),
		1,
		CGE::UI::HorizontalLayout::Model::centre);

	decltype(auto) characteristics_name_layout = characteristics_layout.add_object<CGE::UI::VerticalLayout>(
		_renderer, 
		&characteristics_layout,
		1,
		CGE::UI::VerticalLayout::Model::left
		);

	decltype(auto) characteristics_value_layout = characteristics_layout.add_object<CGE::UI::VerticalLayout>(
		_renderer,
		&characteristics_layout,
		1,
		CGE::UI::VerticalLayout::Model::left
		);

	characteristics_name_layout.add_object<CGE::UI::Text>(_renderer,"Health", CGE::Color::White, &characteristics_name_layout);

	characteristics_value_layout.add_object<CGE::UI::Text>(_renderer, "10", CGE::Color::White, &characteristics_name_layout);

	characteristics_name_layout.add_object<CGE::UI::Text>(_renderer, "Attack", CGE::Color::White, &characteristics_name_layout);

	characteristics_value_layout.add_object<CGE::UI::Text>(_renderer, "1", CGE::Color::White, &characteristics_name_layout);


	characteristics_button.pressed_event() += CGE::EventSystem::createFunctorEventHandler([
			&characteristics_layout_frame = _characteristics_layout_frame
	]() {
			if (characteristics_layout_frame->is_hidden()) {
				characteristics_layout_frame->show();
			}
			else {
				characteristics_layout_frame->hide();
			}
		});

	_in_play_buttons->show();
}

void Game::event()
{
	static auto mouse_pressed = []() -> bool
	{
		static bool pressed = false;
		static bool was_pressed = false;
		pressed = (GetKeyState(VK_LBUTTON) & 0x8000);
		if (pressed && !was_pressed) {
			was_pressed = true;
			return true;
		}
		was_pressed = pressed;
		return false;
	};

	if (mouse_pressed()) {
		auto coords = _renderer.GetCursorWindowPosition();
		_in_play_buttons->event(CGE::UI::UIMouseEvent(coords.X, coords.Y));
	}
}

void Game::action()
{
	_player->action(_objects);
	for (auto&& entity : _objects) {
		entity->action(_objects);
	}
}

void Game::update()
{
	_player->update();
	for (auto&& entity : _objects) {
		entity->update();
	}
}

void Game::render()
{
	_map.draw();
	for (auto&& entity : _objects) {
		entity->render();
	}
	_player->render();
	_in_play_buttons->render();
	_characteristics_layout_frame->render();
}
