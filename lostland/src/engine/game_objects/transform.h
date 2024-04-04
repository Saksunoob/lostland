#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "game_object.h"

namespace Engine {
	namespace GameObjects {
		struct IVec2 {
			int x, y;
			IVec2(int x, int y);
			IVec2(int num);

			IVec2 operator*(int num);
			IVec2 operator/(int num);
			IVec2 operator%(int num);
			IVec2 operator+(IVec2 other);
			IVec2 operator-(IVec2 other);
			bool operator==(const IVec2& other) const;
			bool operator!=(const IVec2& other) const;
		};

		struct Vec2 {
			double x, y;
			Vec2(double x, double y);
			Vec2(double num);
			Vec2(IVec2 pos);

			IVec2 to_IVec2();

			IVec2 operator*(double num);
			IVec2 operator/(double num);
			IVec2 operator+(IVec2 other);
			IVec2 operator-(IVec2 other);
		};
		class Transform : public Component {
		public:
			Vec2 position, scale;
			double rotation;
			int z_index;
			Transform();

			void update();

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

