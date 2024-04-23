#include "time.h"

using namespace Engine;

const system_clock::time_point Time::time_start = high_resolution_clock::now();
double Time::delta_time = 0.0;
long long Time::elapsed = 0;

void Time::update_time() {
	long long last_frame = Time::elapsed;
	Time::elapsed = duration_cast<microseconds>(high_resolution_clock::now() - Time::time_start).count();
	delta_time = (double)(Time::elapsed - last_frame) / 1e6;
}