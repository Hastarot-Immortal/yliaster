#pragma once
#include "GameState.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include "../UI.hpp"

class StartState : public GameState
{
public:
    StartState(GameContext* context);

    void handleEvent(std::optional<sf::Event> event) override;

    void update() override;
    
    void draw() const override;
private:
    VContainer menu_;
};

