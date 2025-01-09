#include <objects/Wall.h>

Wall::Wall(sf::FloatRect rect)
{
	points.append(sf::Vertex{ rect.position });
	points.append(sf::Vertex{ rect.position + sf::Vector2f(0, rect.size.y) });
	points.append(sf::Vertex{ rect.position + sf::Vector2f(rect.size.x, 0) });
	points.append(sf::Vertex{ rect.position + sf::Vector2f(rect.size.x, rect.size.y) });

	points.setPrimitiveType(sf::PrimitiveType::TriangleStrip);

	setFillColor(sf::Color::Green);
}
