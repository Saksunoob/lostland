#include "lostland.h"

int main(void)
{
    Engine::initialize(800, 600, "LostLand");
    if (!Engine::run())
        return -1;
    return 0;
}