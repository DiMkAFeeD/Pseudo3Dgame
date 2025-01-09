#include <SFML/Graphics.hpp>


#include <Player.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Window");
    window.setVerticalSyncEnabled(true);

    Player player;

    while (window.isOpen())
    {
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();

            player.eventProcessing(event);
        }

        if (window.hasFocus()) {
            player.Move(1);
        }

        window.clear();

        player.draw(window);

        window.display();
    }
}