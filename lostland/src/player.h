#include "engine/core.h"
#include "engine/game_objects/transform.h"

using namespace Engine::GameObjects;
using namespace Engine;

class Player : public Component {
	const double SPEED = 100.0;

public:

	void update();
};

