#include "Player.h"

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
		position.x += cos(angle.asRadians()) * speed;
		position.y += sin(angle.asRadians()) * speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
		position.x -= cos(angle.asRadians()) * speed;
		position.y -= sin(angle.asRadians()) * speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
		position.x += cos(angle.asRadians() + (PI / 2 )) * speed;
		position.y += sin(angle.asRadians() + (PI / 2)) * speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
		position.x -= cos(angle.asRadians() + (PI / 2)) * speed;
		position.y -= sin(angle.asRadians() + (PI / 2)) * speed;
	}

	playerCircle.setPosition(position - sf::Vector2f(radius, radius));
}
