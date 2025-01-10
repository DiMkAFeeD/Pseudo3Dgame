#pragma once

#include <SFML/Graphics.hpp>
#include <Camera.h>
#include <math.h>

class Player {
private:
	float radius = 5;
	float speed = 35;
	float sensity = .1f;

	sf::Angle angle = sf::degrees(-90);
	sf::Vector2f position;

	sf::Vector2i lastMousePos;
	sf::CircleShape playerCircle;

	Camera camera;

public:
	void setPosition(const sf::Vector2f& newPos);
	Camera &getCamera();
	void eventProcessing(const std::optional<sf::Event>& event);
	void Move(const float& deltaTime);
	void Update(sf::RenderWindow& window, Map& map);
	void draw(sf::RenderWindow& window);
};