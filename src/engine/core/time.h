#pragma once
#include <glad/glad.h>
#include <chrono>

using namespace std::chrono;

namespace Engine {
	namespace Time {
		extern const system_clock::time_point time_start;
		extern double delta_time;
		extern long long elapsed;

		void update_time();
	}
}