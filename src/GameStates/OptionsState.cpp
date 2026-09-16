#include "OptionsState.hpp"
#include "../GameContext.hpp"

VContainer createOptionsMenu(GameContext* context)
{
    VContainer menu({
        std::make_shared<Label>(context->fonts.get("simple-pixel"), "Options menu")
    });
    return menu;
}

OptionsState::OptionsState(GameContext* context)
    : GameState(context), 
    returnToStartBtn_(TextButton(
        [context]()
        {
            context->switchState(GameContext::State::Start);
        },
        context->fonts.get("simple-pixel"),
        "Return"
    )),
    menu_(createOptionsMenu(context))
{   
    returnToStartBtn_.move({10.f, 10.f});
    auto windowSize = context->window.getSize();
    menu_.setOrigin({menu_.getSize().x / 2, menu_.getSize().y / 2});
    menu_.setPosition({windowSize.x / 2.f, windowSize.y / 2.f});
}

void OptionsState::handleEvent(std::optional<sf::Event> event)
{
    if (event->is<sf::Event::MouseMoved>()
    || event->is<sf::Event::MouseButtonPressed>())
    {
        if (const auto* mouse = event->getIf<sf::Event::MouseMoved>())
        {
            auto e = MouseEvent(mouse);
            returnToStartBtn_.handle(e);
            menu_.handle(e);
        } 
        else if (const auto* mouse = event->getIf<sf::Event::MouseButtonPressed>())
        {
            auto e = MouseEvent(mouse);
            returnToStartBtn_.handle(e);
            menu_.handle(e);
        }
    }
}

void OptionsState::update()
{

}
    
void OptionsState::draw() const
{
    context_->window.clear(sf::Color::White);
    context_->window.draw(returnToStartBtn_);
    context_->window.draw(menu_);
    context_->window.display();
}