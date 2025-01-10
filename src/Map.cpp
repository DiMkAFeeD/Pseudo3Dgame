#include <Map.h>

void Map::addWall(sf::FloatRect rect)
{
	objects.push_back(std::make_unique<Wall>(rect));
}

std::vector<sf::Vector2f> Map::getCollisions(const sf::Vector2f& A, const sf::Vector2f& B) {
	std::vector<sf::Vector2f> result;

	for (auto& object : objects) {
		std::vector<sf::Vector2f> collisions = object->getCollisions(A, B);
		result.insert(result.end(), collisions.begin(), collisions.end());
	}

	return result;
}

void Map::draw(sf::RenderWindow& window)
{
	for (auto& object : objects) {
		object->draw(window);
	}
}
