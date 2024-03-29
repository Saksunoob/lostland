#include "engine/game_objects/game_object.h"
#include "engine/game_objects/transform.h"
#include "engine/core/input.h"
#include "engine/core/time.h"

using namespace Engine::GameObjects;
using namespace Engine;

class Player : public Component {
	const double SPEED = 100.0;

public:

	void update();
};

