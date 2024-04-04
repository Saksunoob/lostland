#include "transform.h"

using namespace Engine::GameObjects;

IVec2::IVec2(int x, int y) : x(x), y(y) {}
IVec2::IVec2(int num) : x(num), y(num) {}

IVec2 IVec2::operator*(int num) { return IVec2(x * num, y * num); }
IVec2 IVec2::operator/(int num) { return IVec2(x / num, y / num); }
IVec2 IVec2::operator%(int num) { return IVec2(x % num, y % num); }
IVec2 IVec2::operator+(IVec2 other) { return IVec2(x + other.x, y + other.y); }
IVec2 IVec2::operator-(IVec2 other) { return IVec2(x - other.x, y - other.y); }
bool IVec2::operator==(const IVec2& other) const { return x == other.x && y == other.y; }
bool IVec2::operator!=(const IVec2& other) const { return x != other.x && y != other.y; }

Vec2::Vec2(double x, double y) : x(x), y(y) {}
Vec2::Vec2(double num) : x(num), y(num) {}
Vec2::Vec2(IVec2 pos) : x(pos.x), y(pos.y) {}

IVec2 Vec2::to_IVec2() { return IVec2(x, y); };

IVec2 Vec2::operator*(double num) { return IVec2(x * num, y * num); }
IVec2 Vec2::operator/(double num) { return IVec2(x / num, y / num); }
IVec2 Vec2::operator+(IVec2 other) { return IVec2(x + other.x, y + other.y); }
IVec2 Vec2::operator-(IVec2 other) { return IVec2(x - other.x, y - other.y); }

Transform::Transform() : 
	position(0.0, 0.0),
	rotation(0.0),
	scale(1.0, 1.0),
	z_index(0) 
{}

glm::mat4 Transform::matrix() {
	glm::mat4 trans = glm::mat4(1.0f);

	trans = glm::translate(trans, glm::vec3(position.x, position.y, 0.));

	trans = glm::rotate(trans, (float)rotation, glm::vec3(0.0, 0.0, -1.0));

	trans = glm::scale(trans, glm::vec3(scale.x, scale.y, 1.0));

	return trans;
}