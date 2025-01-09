#include <Map.h>

void Map::addWall(sf::FloatRect rect)
{
	objects.push_back(std::make_unique<Wall>(rect));
}

void Map::draw(sf::RenderWindow& window)
{
	for (auto& object : objects) {
		object->draw(window);
	}
}
