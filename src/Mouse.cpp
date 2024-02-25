#include "Mouse.h"
#include "Cheese.h"
#include "Door.h"
#include "Key.h"
#include "Gift.h"

Mouse::Mouse(): m_cookieCounter(0), m_score(0), m_life(3), m_numberKeys(0), m_isArrested(false)
{
	m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(MOUSE)));
	m_sprite.setOrigin(getCenter(m_sprite.getPosition()));
	SetPosition(m_sprite.getOrigin());
}

void Mouse::setDirection(sf::Keyboard::Key direction) {
	switch (direction)
	{
	case sf::Keyboard::Left:
		m_newDirection = LEFT;
		break;
	case sf::Keyboard::Right:
		m_newDirection = RIGHT;
		break;
	case sf::Keyboard::Up:
		m_newDirection = UP;
		break;
	case sf::Keyboard::Down:
		m_newDirection = DOWN;
		break;
	}
}

void Mouse::move(float passedTime, sf::Vector2f boardSize)
{
	m_previousPostion = m_sprite.getPosition();
	float moveDistance = REGULAR_SPEED * passedTime;

	if (isCentered(m_sprite.getPosition(), getCenter(m_sprite.getPosition())))
		m_direction = m_newDirection;

	moveDirection(moveDistance);

	if (outOfBoard(boardSize))
		m_sprite.setPosition(m_previousPostion);
	m_position = m_sprite.getPosition();
}





bool Mouse::getMouseState() const
{
	return m_isArrested;
}

void Mouse::setMouseState()
{
	m_isArrested = false;
}

int Mouse::getScore() const
{
	return m_score;
}

void Mouse::setScore(const int& score)
{
	m_score += score;
}

int Mouse::getLife() const
{
	return m_life;
}

void Mouse::setLife(const int& Life)
{
	m_life = Life;
}

int Mouse::getKeysNumber() const
{
	return m_numberKeys;
}

void Mouse::setKeysNumber(const int& number)
{
	m_numberKeys = number;
}

void Mouse::collide(Cat* object)
{
	m_life--;
	m_isArrested = true;
	//sound catch
}

void Mouse::collide(Cheese* object)
{
	sf::Vector2f objectPosition;
	objectPosition.x = object->getPosition().x * P_SIZE + P_SIZE / 2;
	objectPosition.y = object->getPosition().y * P_SIZE + P_SIZE / 2;

	if (abs(m_sprite.getPosition().x - objectPosition.x) < P_SIZE / 2 &&
		abs(m_sprite.getPosition().y - objectPosition.y) < P_SIZE / 2 &&
		object->getStatus()) {

		setScore(SCORE_CHEESE);
		object->setStatus(false);
		// sound eat
	}
}

void Mouse::collide(Wall* object)
{
	m_sprite.setPosition(getCenter(m_previousPostion));
	//sound ouch
}

void Mouse::collide(Door* object)
{
	if (m_numberKeys > 0) {
		setScore(SCORE_OREN_DOOR);
		object->setStatus(false);
			//m_level.clearBoard(m_level.getNumberOfLevel(), 'D');//to cler from the bord
	}
	if (object->getStatus())
		m_sprite.setPosition(getCenter(m_previousPostion));
}

void Mouse::collide(Key* object)
{
	sf::Vector2f objectPosition;
	objectPosition.x = object->getPosition().x * P_SIZE + P_SIZE / 2;
	objectPosition.y = object->getPosition().y * P_SIZE + P_SIZE / 2;

	if (abs(m_sprite.getPosition().x - objectPosition.x) < P_SIZE / 2 &&
		abs(m_sprite.getPosition().y - objectPosition.y) < P_SIZE / 2 &&
		object->getStatus()) {

		object->setStatus(false);
		//m_level.clearBoard(m_level.getNumberOfLevel(), '%');//to cler from the bord
	}
}

void Mouse::collide(Gift* object)
{
	sf::Vector2f objectPosition;
	objectPosition.x = object->getPosition().x * P_SIZE + P_SIZE / 2;
	objectPosition.y = object->getPosition().y * P_SIZE + P_SIZE / 2;
	//object->getType();
	if (abs(m_sprite.getPosition().x - objectPosition.x) < P_SIZE / 2 &&
		abs(m_sprite.getPosition().y - objectPosition.y) < P_SIZE / 2 &&
		object->getStatus()) {

		setScore(SCORE_GIFT);
		object->setStatus(false);
	}
}
