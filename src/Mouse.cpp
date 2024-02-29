#include "Mouse.h"
#include "Cheese.h"
#include "Door.h"
#include "Key.h"
#include "Gift.h"

Mouse::Mouse()
{
	m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(MOUSE)));
	m_sprite.setOrigin(m_sprite.getPosition());
	m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
		((float)P_SIZE / m_sprite.getGlobalBounds().height)));
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

	if (m_timerCatsStop > 0)
		m_timerCatsStop -= int(passedTime);

	float moveDistance = (REGULAR_SPEED * passedTime);

	if (isCentered(m_sprite.getPosition(), getCenter(m_sprite.getPosition())))
		m_direction = m_newDirection;
	/*else
		m_sprite.setPosition(getCenter(m_position));*/
		//std::cout << moveDistance << "\n"; in 3 - 6 in range
		moveDirection(moveDistance);
	

	if (!outOfBoard(boardSize))
		m_sprite.setPosition(getCenter(m_previousPostion));

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

int Mouse::getMoreTime() const
{
	return m_moreTime;
}

int Mouse::getTimerCatsStop() const
{
	return m_timerCatsStop;
}

int Mouse::getCheeseCounter() const
{
	return m_countCheese;
}

void Mouse::setStoppingPower(const bool& s)
{
	m_stoppingPower = s;
}

bool Mouse::getStoppingPower() const
{
	return m_stoppingPower;
}

void Mouse::collide(Cat*)
{
	m_life--;
	m_isArrested = true;
	m_position = m_startPosition;
	//sound catch
}

void Mouse::collide(Cheese* object)
{
	if (object->getStatus()) {
		setScore(SCORE_CHEESE);
		object->setStatus(false);
		m_countCheese++;
		// sound eat
	}
}

void Mouse::collide(Wall*)  
{
	m_sprite.setPosition(m_previousPostion); 
	
	//sound ouch
}

void Mouse::collide(Door* object)
{
	if (m_numberKeys > 0) {
		setScore(SCORE_OREN_DOOR);
		object->setStatus(false);
		
	}
	if (object->getStatus())
		m_sprite.setPosition(m_previousPostion);
}

void Mouse::collide(Key* object)
{
	if (object->getStatus()) {

		object->setStatus(false);
		m_numberKeys++;
	}
}

void Mouse::collide(Gift* object)
{
	TypeGift witchGift = object->getType();
	
	if (object->getStatus()) {
		switch (witchGift)
		{
		case ADD_HEART_GIFT:
			if (m_life < 3)
				m_life++;
			break;
		case HIDE_CAT_GIFT:
			m_timerCatsStop += 10;
			m_stoppingPower = true;
			break;
		case ADD_TIME_GIFT:
			m_moreTime += 10;
			break;
		default:
			break;
		}
		setScore(SCORE_GIFT);
		object->setStatus(false);
		//add sound
	}
}
