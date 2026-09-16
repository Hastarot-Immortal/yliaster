#include "GameContext.hpp"

GameContext::GameContext(
    sf::Vector2u windowSize,
    const fs::path& texturesPath,
    const fs::path& fontsPath,
    State initState
)
    : window({sf::VideoMode(windowSize), "Yliaster"}),
    textures(texturesPath),
    fonts(fontsPath),
    currentState_(nullptr),
    states_({})
{
    states_ = {
        std::make_shared<StartState>(this),
        std::make_shared<OptionsState>(this)
    };
    switchState(initState);
}

void GameContext::run()
{
    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
            this->currentState_->handleEvent(event);
        }
        this->currentState_->update();
        this->currentState_->draw();
    }
}

void GameContext::switchState(GameContext::State newState)
{
    currentState_ = states_.at((size_t)newState).get();
}