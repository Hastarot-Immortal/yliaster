#include "GameContext.hpp"

GameContext::GameContext(
<<<<<<< HEAD
    sf::Vector2u windowSize,
    const fs::path& texturesPath,
    const fs::path& fontsPath,
    State initState
=======
        sf::Vector2u windowSize,
        const fs::path& texturesPath,
        const fs::path& fontsPath,
        State initState
>>>>>>> 07eb2d0ecde9d4899f0d4bd339f307a5a21bf89a
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