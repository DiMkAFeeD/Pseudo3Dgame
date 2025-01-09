#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

class Player {
private:
	float radius = 10;
	float speed = 5;
	float sensity = .1f;

	sf::Angle angle = sf::degrees(-90);
	sf::Vector2f position;

	sf::Vector2i lastMousePos;
	sf::CircleShape playerCircle;
public:

	void setPosition(const sf::Vector2f& newPos);
	void eventProcessing(const std::optional<sf::Event>& event);
	void Move(const float& deltaTime);
	void draw(sf::RenderWindow& window);
};