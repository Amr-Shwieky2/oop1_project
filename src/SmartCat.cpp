#include "SmartCat.h"



void SmartCat::move(float passedTime, sf::Vector2f boardSize, const std::vector<std::vector<sf::Vector3i>>& Tree)
{
    //std::vector<std::vector<sf::Vector3i>> Tree = getBfsTree();

	sf::Vector2i start = sf::Vector2i((int)(m_sprite.getPosition().x / P_SIZE),
									  (int)(m_sprite.getPosition().y / P_SIZE));

	m_previousPostion = m_sprite.getPosition();
	float moveDistance = CAT_SPEED * passedTime;

	//if (isCentered(m_sprite.getPosition(), getCenter(m_sprite.getPosition()))) {
		m_direction = getBfsMove(start,
			sf::Vector2i(Tree[start.y][start.x].y, Tree[start.y][start.x].z));
	//}

	moveDirection(moveDistance);

	if (outOfBoard(boardSize)) {
		m_sprite.setPosition(m_previousPostion);
	}
	else 
	m_position = m_sprite.getPosition();
}

Direction SmartCat::getBfsMove(const sf::Vector2i& start, const sf::Vector2i& destination)
{
	if (start.x > destination.x)
		return LEFT;

	if (start.x < destination.x)
		return RIGHT;

	if (start.y > destination.y)
		return UP;

	if (start.y < destination.y)
		return DOWN;

	return UP;
}

