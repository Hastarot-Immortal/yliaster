#include "GameContext.hpp"

int main()
{
    sf::Vector2u windowSize = {1024, 768};
    GameContext context(windowSize, "assets\\images", "assets\\fonts");
    context.run();
}