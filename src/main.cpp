#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>

#include <Player.h>
#include <Map.h>

void mapInit(Player& player, const std::string& mapInString, Map& map) {
    float tileSize = 15;
    float x = 0, y = 0;

    for (char tile : mapInString) {
        if (tile == 'P') {
            player.setPosition(sf::Vector2f(x * tileSize, y * tileSize));
        }
        else if (tile == '#') {
            map.addWall(sf::FloatRect({ x * tileSize, y * tileSize }, { tileSize, tileSize }));
        }

        if (tile == '\n') {
            x = 0;
            y++;
        }
        else {
            x++;
        }
    }
}

int main() {
    sf::RenderWindow window(sf::VideoMode({ 1280, 720 }), "Window");
    window.setVerticalSyncEnabled(true);

    Player player;
    Map map;

    player.getCamera().setNumRay(window.getSize().x);

    std::string mapInString =
        "###############\n"
        "#.......####..#\n"
        "#.............#\n"
        "#...###.......#\n"
        "#.............#\n"
        "#......P......#\n"
        "#.............#\n"
        "####..........#\n"
        "#..#..........#\n"
        "#..#.....######\n"
        "#.##..........#\n"
        "#.......##....#\n"
        "#.......##....#\n"
        "#.......##....#\n"
        "###############\n";

    mapInit(player, mapInString, map);

    sf::View view;
    view.setSize(sf::Vector2f(window.getSize()));
    view.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));

    sf::Clock clock;

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (event->is<sf::Event::Resized>()) {
                player.getCamera().setNumRay(window.getSize().x);
                view.setSize(sf::Vector2f(window.getSize()));
                view.setCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
            }

            player.eventProcessing(event);
        }

        float deltaTime = clock.restart().asSeconds();

        if (window.hasFocus()) {
            player.Move(deltaTime);
            player.Update(window, map);
        }

        window.clear();
        window.setView(view);

        map.draw(window);
        player.getCamera().render(window);

        player.draw(window);

        window.display();
    }
}