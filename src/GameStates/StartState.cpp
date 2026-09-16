#include "StartState.hpp"
#include "../GameContext.hpp"

VContainer createStartMenu(GameContext* context)
{
    VContainer menu({
        std::make_shared<Label>(context->fonts.get("simple-pixel"), "Yliaster"),
        std::make_shared<TextButton>(
            [context]()
            {
                context->switchState(GameContext::State::Options);
            },
            context->fonts.get("simple-pixel"), 
            "Options"
        ),
        std::make_shared<TextButton>(
            [context]()
            {
                context->window.close();
            },
            context->fonts.get("simple-pixel"),
            "Exit"
        )
    });
    return menu;
}


StartState::StartState(GameContext* context)
: GameState(context), menu_(createStartMenu(context))
{
    auto windowSize = context->window.getSize();
    menu_.setOrigin({menu_.getSize().x / 2, menu_.getSize().y / 2});
    menu_.setPosition({windowSize.x / 2.f, windowSize.y / 2.f});
}

void StartState::handleEvent(std::optional<sf::Event> event)
{
    if (event->is<sf::Event::MouseMoved>()
    || event->is<sf::Event::MouseButtonPressed>())
    {
        if (const auto* mouse = event->getIf<sf::Event::MouseMoved>())
        {
            auto e = MouseEvent(mouse);
            menu_.handle(e);
        } 
        else if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
        {
            auto e = MouseEvent(mouse);
            menu_.handle(e);
        }
    }
}

void StartState::update() {}
    
void StartState::draw() const
{
    context_->window.clear(sf::Color::White);
    context_->window.draw(menu_);
    context_->window.display();

}                       