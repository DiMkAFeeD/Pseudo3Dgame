#pragma once

#include <SFML/Graphics.hpp>
#include <Map.h>
#include <math.h>

class Camera {
private:
	sf::VertexArray viewInCamera;
	sf::VertexArray miniMapView;

	sf::Angle FOV = sf::degrees(60);

	float maxRayLenght = 150;
	float numRays = 100;

	float objectHeight = 10;

	int i = 0;

	void castRay(const sf::Vector2f& rayStart, const sf::Vector2f& rayEnd, sf::Angle& rayDir, sf::RenderWindow& window, Map& map);

public:
	Camera(const float& maxLenght = 150);

	void setNumRay(float rayNums);

	void Update(const sf::Vector2f& position, sf::RenderWindow& window, sf::Angle& angle, Map& map);

	void render(sf::RenderWindow& window);
};