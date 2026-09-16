#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include "Factory/ResourceFactory.hpp"
#include <memory>
#include "GameStates.hpp"

class GameContext
{
public:
    enum class State : size_t
    {
        Start,
        Options
    };

    sf::RenderWindow window;
    TextureFactory textures;
    FontFactory fonts;

    GameContext(
        sf::Vector2u windowSize,
        const fs::path& texturesPath,
        const fs::path& fontsPath,
        State initState = State::Start
    );

    void run();

    void switchState(GameContext::State newState);
private:
    GameState* currentState_;
    std::vector<std::shared_ptr<GameState>> states_;
};