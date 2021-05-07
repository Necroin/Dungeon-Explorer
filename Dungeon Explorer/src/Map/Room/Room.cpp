#include "Room.h"
using namespace CGE;

Room::Room(Renderer& renderer, int room_id, GameRect position) :
	GameObject(position, get_class_tag<Room>()),
	_room_id(room_id),
	_renderer(renderer)
{
	generate_room();
}

/* Draw basic room 4 x 5 with border and empty inside*/
void Room::draw_basic_room()
{
	for (auto&& object : room_objects) {
		object.draw();
	}

}

void Room::generate_basic_room() {
	try {
		RoomObject border = RoomObject(_renderer, RoomObject::ObjectTypes::BORDER, _position);
		room_objects.push_back(border);
		_position.x += _position.width;
		RoomObject bomb = RoomObject(_renderer, RoomObject::ObjectTypes::BOMB, _position);
		room_objects.push_back(bomb);
	}
	catch(std::exception e){

	}
}


void Room::generate_room() {
	(this->*generateFunctions[_room_id])();
}


void Room::draw()
{
	(this->*drawFunctions[_room_id])();
}

