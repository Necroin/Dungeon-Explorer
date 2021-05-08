#include "Player.h"

Player::Player(Map& map, CGE::Renderer& renderer, int x, int y, int health) :
	CGE::GameObject({ x, y, 0,0 }, CGE::get_class_tag<Player>()),
	_map(map),
	_renderer(renderer),
	_health(health)
{
	decltype(auto) stay_state = _player_fsm.add_state([
		&renderer = _renderer,
		&x = _position.x,
		&y = _position.y
	]() {
		renderer.draw_symbol('O', x, y - 1, CGE::Color::Green);
		renderer.draw_symbol('#', x, y, CGE::Color::Green);
		renderer.draw_symbol('/', x - 1, y, CGE::Color::Green);
		renderer.draw_symbol('\\', x + 1, y, CGE::Color::Green);
		renderer.draw_symbol('/', x - 1, y + 1, CGE::Color::Green);
		renderer.draw_symbol('\\', x + 1, y + 1, CGE::Color::Green);
		});

	decltype(auto) move_left_state = _player_fsm.add_state([
		&renderer = _renderer,
			&x = _position.x,
			&y = _position.y
	]() {
			static int step = 0;
			static const int del = 10;
			if (step / del == 0) {
				renderer.draw_symbol('O', x, y - 1, CGE::Color::Green); // head
				renderer.draw_symbol('#', x, y, CGE::Color::Green); // body
				renderer.draw_symbol('/', x - 1, y, CGE::Color::Green); // left hand
				renderer.draw_symbol(46, x + 1, y, CGE::Color::Green); // right hand
				renderer.draw_symbol('<', x, y + 1, CGE::Color::Green); // left leg
				renderer.draw_symbol('\\', x + 1, y + 1, CGE::Color::Green); // right leg
			}
			if (step / del == 1) {
				renderer.draw_symbol('O', x, y - 1, CGE::Color::Green); // head
				renderer.draw_symbol('#', x, y, CGE::Color::Green); // body
				renderer.draw_symbol(46, x - 1, y, CGE::Color::Green); // left hand
				renderer.draw_symbol('>', x + 1, y, CGE::Color::Green); // right hand
				renderer.draw_symbol('|', x, y + 1, CGE::Color::Green); // left leg
				renderer.draw_symbol('-', x + 1, y + 1, CGE::Color::Green); // right leg
			}
			++step %= (del * 2);
		});

	decltype(auto) move_right_state = _player_fsm.add_state([
		&renderer = _renderer,
			&x = _position.x,
			&y = _position.y
	]() {
			static int step = 0;
			static const int del = 10;
			if (step / del == 0) {
				renderer.draw_symbol('O', x, y - 1, CGE::Color::Green); // head
				renderer.draw_symbol('#', x, y, CGE::Color::Green); // body
				renderer.draw_symbol(46, x - 1, y, CGE::Color::Green); // left hand
				renderer.draw_symbol('\\', x + 1, y, CGE::Color::Green); // right hand
				renderer.draw_symbol('/', x - 1, y + 1, CGE::Color::Green); // left leg
				renderer.draw_symbol('>', x, y + 1, CGE::Color::Green); // right leg
			}
			if (step / del == 1) {
				renderer.draw_symbol('O', x, y - 1, CGE::Color::Green); // head
				renderer.draw_symbol('#', x, y, CGE::Color::Green); // body
				renderer.draw_symbol('<', x - 1, y, CGE::Color::Green); // left hand
				renderer.draw_symbol(46, x + 1, y, CGE::Color::Green); // right hand
				renderer.draw_symbol('-', x - 1, y + 1, CGE::Color::Green); // left leg
				renderer.draw_symbol('|', x, y + 1, CGE::Color::Green); // right leg
			}
			++step %= (del * 2);
		});

	stay_state.add_transition([
			move_left_state = &move_left_state,
			move_right_state = &move_right_state
	](PlayerActions action) -> decltype(&stay_state) {
			if (action == PlayerActions::move_left) return move_left_state;
			if (action == PlayerActions::move_right) return move_right_state;

			else return nullptr;
		});

	move_left_state.add_transition([stay_state = &stay_state](PlayerActions action) -> decltype(&move_left_state) {
			if (action == PlayerActions::stay) return stay_state;
			else return nullptr;
		});

	move_right_state.add_transition([stay_state = &stay_state](PlayerActions action) -> decltype(&move_right_state) {
		if (action == PlayerActions::stay) return stay_state;
		else return nullptr;
		});

	_player_fsm.set_current_state(stay_state);
}

void Player::action(std::list<std::unique_ptr<GameObject>>& entities)
{
	if (GetAsyncKeyState(0x57) ) {
		_position.y -= 1;
		_renderer.get_camera().move_up();
		_player_fsm.handle(PlayerActions::move_up);
	}
	else if (GetAsyncKeyState(0x53)) {
		_position.y += 1;
		_renderer.get_camera().move_down();
		_player_fsm.handle(PlayerActions::move_down);
	}
	else if (GetAsyncKeyState(0x41)) {
		_position.x -= 1;
		_renderer.get_camera().move_left();
		_player_fsm.handle(PlayerActions::move_left);
	}
	else if (GetAsyncKeyState(0x44)) {
		_position.x += 1;
		_renderer.get_camera().move_right();
		_player_fsm.handle(PlayerActions::move_right);
	}
	else {
		_player_fsm.handle(PlayerActions::stay);
	}
}

void Player::update()
{
}

void Player::render()
{
	_player_fsm.execute();
}
