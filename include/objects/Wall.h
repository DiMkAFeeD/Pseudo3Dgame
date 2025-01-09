#pragma once

#include <Object.h>
#include <SFML/Graphics.hpp>

class Wall : public Object {
public:
	Wall(sf::FloatRect rect);
};