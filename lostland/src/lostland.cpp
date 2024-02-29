#include "lostland.h"

int main(void)
{
    Engine engine(800, 600, "LostLand");
    if (!engine.run())
        return -1;
    return 0;
}