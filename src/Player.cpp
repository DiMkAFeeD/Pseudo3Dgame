#include "Player.h"

void Player::setPosition(const sf::Vector2f& newPos)
{
	position = newPos;
}

Camera& Player::getCamera()
{
	return camera;
}

void Player::eventProcessing(const std::optional<sf::Event>& event)
{
	if (event->is<sf::Event::MouseButtonPressed>()) {
		if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
			sf::Mouse::setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().size.x / 2, sf::VideoMode::getDesktopMode().size.y / 2));
			lastMousePos = sf::Mouse::getPosition();
		}
	}
}

#define PI 3.14159265358979323846

void Player::Move(const float& deltaTime)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Right)) {
		angle += sf::degrees((sf::Mouse::getPosition().x - lastMousePos.x) * sensity);
		sf::Mouse::setPosition(sf::Vector2i(sf::VideoMode::getDesktopMode().size.x / 2, sf::VideoMode::getDesktopMode().size.y / 2));
		lastMousePos = sf::Mouse::getPosition();
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
		position.x += cos(angle.asRadians()) * speed * deltaTime;
		position.y += sin(angle.asRadians()) * speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		position.x -= cos(angle.asRadians()) * speed * deltaTime;
		position.y -= sin(angle.asRadians()) * speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		position.x += cos(angle.asRadians() + (PI / 2 )) * speed * deltaTime;
		position.y += sin(angle.asRadians() + (PI / 2)) * speed * deltaTime;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		position.x -= cos(angle.asRadians() + (PI / 2)) * speed * deltaTime;
		position.y -= sin(angle.asRadians() + (PI / 2)) * speed * deltaTime;
	}

	playerCircle.setPosition(position - sf::Vector2f(radius, radius));
}

void Player::Update(sf::RenderWindow& window, Map& map)
{
	camera.Update(position, window, angle, map);
}

void Player::draw(sf::RenderWindow& window)
{
	playerCircle.setFillColor(sf::Color::Red);
	playerCircle.setRadius(radius);
	playerCircle.setPointCount(100);
	window.draw(playerCircle);
}