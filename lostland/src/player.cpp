#include "player.h"


void Player::update() {
	Transform* transform = object->get_component<Transform>();

	if (Input::get_key_pressed(Input::KEY_D)) {
		transform->position.x += SPEED * Time::delta_time;
	}
	if (Input::get_key_pressed(Input::KEY_A)) {
		transform->position.x -= SPEED * Time::delta_time;
	}
	if (Input::get_key_pressed(Input::KEY_W)) {
		transform->position.y += SPEED * Time::delta_time;
	}
	if (Input::get_key_pressed(Input::KEY_S)) {
		transform->position.y -= SPEED * Time::delta_time;
	}

}