#include <Object.h>

std::optional<sf::Vector2f> Object::getIntersection(const sf::Vector2f& p1, const sf::Vector2f& p2,
    const sf::Vector2f& q1, const sf::Vector2f& q2) {

    float epsilon = 0.00001f;  // ����������� ��� ���������� � ��������� ������

    float A1 = p2.y - p1.y;
    float B1 = p1.x - p2.x;
    float C1 = A1 * p1.x + B1 * p1.y;

    float A2 = q2.y - q1.y;
    float B2 = q1.x - q2.x;
    float C2 = A2 * q1.x + B2 * q1.y;

    float determinant = A1 * B2 - A2 * B1;

    // ���� ����������� ����� ����, ������� �����������, ����������� ���
    if (std::abs(determinant) < epsilon) {
        return std::nullopt;
    }

    float x = (B2 * C1 - B1 * C2) / determinant;
    float y = (A1 * C2 - A2 * C1) / determinant;

    if ((std::min(p1.x, p2.x) - epsilon <= x && x <= std::max(p1.x, p2.x) + epsilon) &&
        (std::min(p1.y, p2.y) - epsilon <= y && y <= std::max(p1.y, p2.y) + epsilon) &&
        (std::min(q1.x, q2.x) - epsilon <= x && x <= std::max(q1.x, q2.x) + epsilon) &&
        (std::min(q1.y, q2.y) - epsilon <= y && y <= std::max(q1.y, q2.y) + epsilon)) {
        return sf::Vector2f(x, y);
    }

    return std::nullopt;
}

std::vector<sf::Vector2f> Object::getCollisions(const sf::Vector2f& A, const sf::Vector2f& B) {
    std::vector<sf::Vector2f> collisions;

    for (size_t i = 0; i < points.getVertexCount(); ++i) {
        sf::Vector2f p1 = points[i].position;
        sf::Vector2f p2 = points[(i + 1) % points.getVertexCount()].position;

        auto intersection = getIntersection(p1, p2, A, B);
        if (intersection) {
            collisions.push_back(intersection.value());
        }
    }
    
    

    return collisions;
}

void Object::setFillColor(sf::Color color)
{
    for (size_t i = 0; i < points.getVertexCount(); ++i) {
        points[i].color = color;
    }
}
