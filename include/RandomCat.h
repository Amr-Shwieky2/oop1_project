#pragma once
#include "Cat.h"

class RandomCat : public Cat
{
public:
	RandomCat() : Cat() {};
	
	void move(float passedTime, sf::Vector2f boardSize,
		const std::vector<std::vector<sf::Vector3i>>& Tree); //Tree do not use in this move 
private:
	Direction getRandomDirection();
	///adacawsafcae
};

