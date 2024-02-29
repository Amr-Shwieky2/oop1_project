#pragma once
#include <memory>
#include <vector>
#include <fstream>
#include <iostream>
#include <string>

#include "NonMovable.h"
#include "Cat.h"
#include "Mouse.h"


// Symbols 
const char MOUSE_CH = '%';
const char CAT_CH = '^';
const char DOOR_CH = 'D';
const char WALL_CH = '#';
const char KEY_CH = 'F';
const char CHEESE_CH = '*';
const char REMOVE_CAT_GIFT_CH = '-';
const char ADD_HEART_GIFT_CH = '+';
const char ADD_TIME_GIFT_CH = '$';
const char ROAD_CH = ' ';

class Board
{
public:
	Board(Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats, const int& numberOfLevel);
	sf::Vector2f getBoardSize();
	void drawBoard(sf::RenderWindow& window);
	void readLevel(Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats, const int& numberOfLevel);

	void setMouse(Mouse& mouse, sf::Vector2f position);
	void setCat(std::vector<std::unique_ptr<Cat>>& cats, sf::Vector2f position);

	int getCheeseCounter() const;
	int getCatsNumber()const;

	NonMovable* getCharacters(sf::Vector2f position, Direction direction);
	std::vector<std::vector<std::unique_ptr<NonMovable>>> &getMap();


	bool checkOutOfMap(sf::Vector2f position);

	sf::Time getTime()const;
	int getnumberOfLevel()const;


	std::vector<std::vector<sf::Vector3i>> getBfsTree(sf::Vector2i start);

private:
	std::vector<sf::Vector2i> searchNeighbors(const sf::Vector2i center);
	void openFile();
	void setBoardSize();
	void pushToMap(const char&, size_t&, size_t&, Mouse&, std::vector<std::unique_ptr<Cat>>& );

	std::vector<std::vector<std::unique_ptr<NonMovable>>> m_board;

	std::ifstream m_file;

	int m_row, m_col;
	sf::Time m_time;

	int m_numberOfLevel;
	int m_numberOfCats;
	int m_numberOfCheese;
};


