#pragma once
#include <SFML/Window/Event.hpp>
#include <optional>

class GameContext;

class GameState
{
protected:
    GameContext* context_;
public:
    GameState(GameContext* context)
    : context_(context) {}
    virtual void handleEvent(std::optional<sf::Event> event) = 0;
    virtual void update() = 0;
    virtual void draw() const = 0;
};