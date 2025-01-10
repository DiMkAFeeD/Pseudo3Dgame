#include <Camera.h>

Camera::Camera(const float& maxLenght) : maxRayLenght(maxLenght)
{
	miniMapView.setPrimitiveType(sf::PrimitiveType::Lines);
	viewInCamera.setPrimitiveType(sf::PrimitiveType::Lines);
}

void Camera::setNumRay(float rayNums)
{
	numRays = rayNums;
}

void Camera::castRay(const sf::Vector2f& rayStart, const sf::Vector2f& rayEnd, sf::Angle& rayDir, Map& map)
{
	miniMapView.append(sf::Vertex({ rayStart }));
	std::vector<sf::Vector2f> points = map.getCollisions(rayStart, rayEnd);
	if (!points.empty()) {
		float minDistance = maxRayLenght;

		for (auto& point : points) {
			float distance = std::sqrt(std::pow(point.x - rayStart.x, 2) + std::pow(point.y - rayStart.y, 2));
			if (distance < minDistance) minDistance = distance;
		}
		miniMapView.append(sf::Vertex({ rayStart + sf::Vector2f(cos(rayDir.asRadians()) * minDistance, sin(rayDir.asRadians()) * minDistance) }));


	}
	else {
		miniMapView.append(sf::Vertex({ rayEnd }));
	}
}

void Camera::Update(const sf::Vector2f& position, sf::RenderWindow& window, sf::Angle& angle, Map& map)
{
	miniMapView.clear();
	viewInCamera.clear();
	for (int i = -numRays / 2; i < numRays / 2; ++i) {

		sf::Angle rayDir = angle - (FOV/2) + (FOV / numRays) * i;	
		sf::Vector2f rayEnd = { cos(rayDir.asRadians()) * maxRayLenght, sin(rayDir.asRadians()) * maxRayLenght };
		castRay(position, position + rayEnd, rayDir, map);
	}
}

void Camera::render(sf::RenderWindow& window)
{
	window.draw(miniMapView);
	window.draw(viewInCamera);
}
