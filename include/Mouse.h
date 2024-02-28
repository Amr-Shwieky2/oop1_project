#pragma once
#include "Movable.h"

enum { INCREASE_TIME, STOP_CATS, ADD_LIFE };

class Mouse : public Movable
{
public:
	Mouse();

	
	void setDirection(sf::Keyboard::Key direction);
	void move(float passedTime, sf::Vector2f boardSize);
	bool getMouseState() const;
	void setMouseState();

	int getScore()const;
	void setScore(const int& score);

	int getLife()const;
	void setLife(const int& Life);

	int getKeysNumber()const;
	void setKeysNumber(const int& number);


	virtual void collide(Icon*) {};
	virtual void collide(Mouse*) {};
	virtual void collide(Cat* object);
	virtual void collide(Cheese* object);
	virtual void collide(Wall* object); 
	virtual void collide(Door* object);
	virtual void collide(Key* object); 
	virtual void collide(Gift* object); 

private:
	int m_cookieCounter;

	int m_score;
	int m_life;
	int m_numberKeys;
	
	
	bool m_isArrested;

};

