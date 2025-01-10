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

	std::vector<sf::Vector2f> getCollisions(const sf::Vector2f& A, const sf::Vector2f& B);

	void draw(sf::RenderWindow& window);
};