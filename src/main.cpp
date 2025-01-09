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

    while (window.isOpen()) {
        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            player.eventProcessing(event);
        }

        if (window.hasFocus()) {
            player.Move(1);
        }

        window.clear();

        map.draw(window);
        player.draw(window);

        window.display();
    }
}