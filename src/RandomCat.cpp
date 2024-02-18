#include "RandomCat.h"

void RandomCat::move(float passedTime, sf::Vector2f boardSize, const std::vector<std::vector<sf::Vector3i>>& Tree)
{
    m_previousPostion = m_sprite.getPosition();
    float moveDistance = CAT_SPEED * passedTime;
    int randomSwitch = (rand() % 10);

    if ((passedTime > randomSwitch || m_wallCollision) &&
        isCentered(m_sprite.getPosition(), getCenter(m_sprite.getPosition())))
    {
        m_wallCollision = false;
        m_moving = true;
        m_direction = getRandomDirection();
    }

    moveDirection(moveDistance);

    if (outOfBoard(boardSize))
        m_sprite.setPosition(m_previousPostion);
    m_position = m_sprite.getPosition();
}


Direction RandomCat::getRandomDirection()
{
	Direction arrayOfDirection[] = { LEFT,RIGHT,UP,DOWN };
	return arrayOfDirection[rand() % 4];
}
