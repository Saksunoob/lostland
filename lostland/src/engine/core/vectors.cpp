#include "vectors.h"

using namespace Engine;

IVec2::IVec2() : x(0), y(0) {};
IVec2::IVec2(int x, int y) : x(x), y(y) {}
IVec2::IVec2(int num) : x(num), y(num) {}

IVec2 IVec2::operator*(int num) { return IVec2(x * num, y * num); }
IVec2 IVec2::operator/(int num) { return IVec2(x / num, y / num); }
IVec2 IVec2::operator%(int num) { return IVec2(x % num, y % num); }
IVec2 IVec2::operator+(IVec2 other) { return IVec2(x + other.x, y + other.y); }
IVec2 IVec2::operator-(IVec2 other) { return IVec2(x - other.x, y - other.y); }
bool IVec2::operator==(const IVec2& other) const { return x == other.x && y == other.y; }
bool IVec2::operator!=(const IVec2& other) const { return x != other.x && y != other.y; }

Vec2::Vec2() : x(0), y(0) {};
Vec2::Vec2(double x, double y) : x(x), y(y) {}
Vec2::Vec2(double num) : x(num), y(num) {}
Vec2::Vec2(IVec2 pos) : x(pos.x), y(pos.y) {}

IVec2 Vec2::to_IVec2() { return IVec2(x, y); };

Vec2 Vec2::operator*(double num) { return Vec2(x * num, y * num); }
Vec2 Vec2::operator/(double num) { return Vec2(x / num, y / num); }
Vec2 Vec2::operator+(Vec2 other) { return Vec2(x + other.x, y + other.y); }
Vec2 Vec2::operator-(Vec2 other) { return Vec2(x - other.x, y - other.y); }