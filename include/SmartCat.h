#pragma once
#include "Cat.h"

class SmartCat : Cat
{
public:
	SmartCat() : Cat() {};
	/*std::vector<std::vector<sf::Vector3i>> getBfsTree(sf::Vector2i start,
		const std::vector<std::vector<std::unique_ptr<NonMovable>>>& NonMovableIcon,
		Board& board);*/

	void move(float passedTime, sf::Vector2f boardSize, const std::vector<std::vector<sf::Vector3i>>& Tree);

private:
	Direction getBfsMove(const sf::Vector2i& start,
		const sf::Vector2i& destination);
	
	//std::vector<sf::Vector2i> searchNeighbors(const sf::Vector2i center, const std::vector<std::vector<std::unique_ptr<NonMovable>>>& NonMovableIcon, Board& board);
};

