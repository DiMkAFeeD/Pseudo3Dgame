#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <optional>

class Object {
protected:
    sf::VertexArray points;

public:

    virtual std::vector<sf::Vector2f> getCollisions(const sf::Vector2f& A, const sf::Vector2f& B);

    void setFillColor(sf::Color color);

    void draw(sf::RenderWindow& window) {
        window.draw(points);
    }

private:
    std::optional<sf::Vector2f> getIntersection(const sf::Vector2f& p1, const sf::Vector2f& p2,
        const sf::Vector2f& q1, const sf::Vector2f& q2);
};
