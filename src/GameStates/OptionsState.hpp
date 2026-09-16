#pragma once
#include "GameState.hpp"
#include "../UI.hpp"

class OptionsState : public GameState
{
public:
    OptionsState(GameContext* context);

    void handleEvent(std::optional<sf::Event> event) override;

    void update() override;
    
    void draw() const override;

private:
    TextButton returnToStartBtn_;
    VContainer menu_;    
};