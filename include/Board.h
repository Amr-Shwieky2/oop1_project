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
const char GIFT_CH = '$';
const char ROAD_CH = ' ';

class Board
{
public:
	Board();
	Board(Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats, const int& numberOfLevel);
	sf::Vector2f getBoardSize();
	void readLevel(Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats, const int& numberOfLevel);

	void setMouse(Mouse& mouse, sf::Vector2f position);
	void setCat(std::vector<std::unique_ptr<Cat>>& cats, sf::Vector2f position);


	NonMovable* getCharacters(sf::Vector2f position);
	std::vector<std::vector<std::unique_ptr<NonMovable>>> &getMap();

	void drawNonMovable(sf::RenderWindow& window);
	//void clear_vector();//??!

private:
	
	void openFile();
	void setBoardSize();
	void pushToMap(const char& characters, size_t& row, size_t& col, 
		Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats);

	std::vector<std::vector<std::unique_ptr<NonMovable>>> m_board;

	std::ifstream m_file;

	int m_row, m_col;

	int m_numberOfLevel;
	int m_numberOfCats;
};


