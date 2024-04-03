#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "game_object.h"
#include "camera.h"

namespace Engine {
	namespace GameObjects {
		struct IVec2 {
			int x, y;
			IVec2(int x, int y) : x(x), y(y) {}
			IVec2(int num) : x(num), y(num) {}

			IVec2 operator*(int num) { return IVec2(x * num, y * num); }
			IVec2 operator/(int num) { return IVec2(x / num, y / num); }
			IVec2 operator%(int num) { return IVec2(x % num, y % num); }
			IVec2 operator+(IVec2 other) { return IVec2(x + other.x, y + other.y); }
			IVec2 operator-(IVec2 other) { return IVec2(x - other.x, y - other.y); }
			bool operator==(const IVec2 &other) const { return x == other.x && y == other.y; }
			bool operator!=(const IVec2 &other) const { return x != other.x && y != other.y; }
		};

		struct Vec2 {
			double x, y;
			Vec2(double x, double y) : x(x), y(y) {}
			Vec2(double num) : x(num), y(num) {}
			Vec2(IVec2 pos) : x(pos.x), y(pos.y) {}

			IVec2 to_IVec2() { return IVec2(x, y); };

			IVec2 operator*(double num) { return IVec2(x * num, y * num); }
			IVec2 operator/(double num) { return IVec2(x / num, y / num); }
			IVec2 operator+(IVec2 other) { return IVec2(x + other.x, y + other.y); }
			IVec2 operator-(IVec2 other) { return IVec2(x - other.x, y - other.y); }
		};
		class Transform : public Component {
		public:
			Vec2 position, scale;
			double rotation;
			int z_index;
			Transform()
				: position(0.0, 0.0),
				rotation(0.0),
				scale(1.0, 1.0),
				z_index(0) {}

			glm::mat4 matrix();
		};
	}
}

template<> struct std::hash<Engine::GameObjects::IVec2> {
	std::size_t operator()(const Engine::GameObjects::IVec2& v) const noexcept {
		std::size_t h1 = std::hash<int>{}(v.x);
		std::size_t h2 = std::hash<int>{}(v.y);
		return h1 ^ (h2 << 1);
	}
};

