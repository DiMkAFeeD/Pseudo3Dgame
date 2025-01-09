#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <Object.h>
#include <objects/Wall.h>
#include <memory>

class Map {
private:
	std::vector<std::unique_ptr<Object>> objects;

public:
	void addWall(sf::FloatRect rect);

	void draw(sf::RenderWindow& window);
};