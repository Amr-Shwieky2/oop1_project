
#include "Board.h"
#include "Cheese.h"
#include "Door.h"
#include "Wall.h"
#include "Key.h"
#include "HideCatGift.h"
#include "HeartGift.h"
#include "TimeGift.h"
#include "SmartCat.h"
#include "RandomCat.h"

Board::Board(Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats, const int& numberOfLevel)
	: m_row(0), m_col(0), m_numberOfLevel(0), m_numberOfCats(0), m_numberOfCheese(0)
{
	readLevel(mouse, cats, numberOfLevel);
}

sf::Vector2f Board::getBoardSize()
{
	sf::Vector2f boardSize;
	boardSize.x = static_cast<float>(m_board.size()) * P_SIZE;
	boardSize.y = static_cast<float>(m_board[0].size()) * P_SIZE;
	return boardSize;
}


void Board::drawBoard(sf::RenderWindow &window) {
	for (size_t i = 0; i < m_board.size(); i++) {
		for (size_t j = 0; j < m_board[i].size(); j++) {
			if (m_board[i][j] != nullptr) {
				m_board[i][j]->draw(window, sf::Vector2f(static_cast<float>(j) * P_SIZE, static_cast<float>(i) * P_SIZE));
			}
		}
	}
}

void Board::readLevel(Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats, const int& numberOfLevel)
{
	m_numberOfLevel = numberOfLevel;
	openFile();
	char nextChar;
	float timeInSeconds;
	m_file >> m_row >> m_col >> timeInSeconds;
	m_time = sf::seconds(timeInSeconds);
	setBoardSize();

	for (size_t i = 0; i < m_row; i++)
	{
		m_file.get();
		for (size_t j = 0; j < m_col; j++)
		{
			nextChar = static_cast<char>(m_file.get());
			pushToMap(nextChar, i, j, mouse, cats);
		}
	}
	m_file.seekg(0, std::ios::beg);
	m_file.close();
}

void Board::setMouse(Mouse& mouse, sf::Vector2f position)
{
	mouse.SetPosition(position);
	mouse.setStartPosition(position);
}

void Board::setCat(std::vector<std::unique_ptr<Cat>>& cats, sf::Vector2f position)
{
	m_numberOfCats++;
	if (!(cats.size() % 2 == 0))
		cats.push_back(std::make_unique < RandomCat >()); // SmartCat
	else
		cats.push_back(std::make_unique < RandomCat >());

	size_t catSize = cats.size() - 1;
	cats[catSize]->SetPosition(position);
	cats[catSize]->setStartPosition(position);
}

int Board::getCheeseCounter() const {
	return m_numberOfCheese;
}

NonMovable* Board::getCharacters(sf::Vector2f position)
{
	int row = static_cast<int>(position.y / P_SIZE);
	int col = static_cast<int>(position.x / P_SIZE);


	return m_board[row][col].get();
}

std::vector<std::vector<std::unique_ptr<NonMovable>>>& Board::getMap()
{
	return m_board;
}


bool Board::checkOutOfMap(sf::Vector2f position)
{
	return !(position.x < 0 || position.y < 0 || position.x >= m_board[0].size() ||
		position.y >= m_board.size());
}

void Board::openFile() {
	std::string file = "Level" + std::to_string(m_numberOfLevel) + ".txt";
	m_file.open(file);
	if (!m_file.is_open())
	{
		std::cerr << "could not open level file\n";
		exit(EXIT_FAILURE);
	}
}

void Board::setBoardSize()
{
	m_board.resize(m_row);
	for (size_t i = 0; i < m_row; i++)
		m_board[i].resize(m_col);
}

void Board::pushToMap(const char& characters, size_t& row, size_t& col,
	Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats)
{
	switch (characters)
	{
	case WALL_CH:
		m_board[row][col] = std::make_unique <Wall>(sf::Vector2f(static_cast<float>(row), static_cast<float>(col)));
		break;
	case DOOR_CH:
		m_board[row][col] = std::make_unique <Door>(sf::Vector2f(static_cast<float>(row), static_cast<float>(col)));
		break;
	case CHEESE_CH:
		m_board[row][col] = std::make_unique <Cheese>(sf::Vector2f(static_cast<float>(row), static_cast<float>(col)));
		m_numberOfCheese++;
		break;
	case KEY_CH:
		m_board[row][col] = std::make_unique <Key>(sf::Vector2f(static_cast<float>(row), static_cast<float>(col)));
		break;
	case REMOVE_CAT_GIFT_CH:  
		m_board[row][col] = std::make_unique <HideCatGift>();
		break;
	case ADD_HEART_GIFT_CH: 
		m_board[row][col] = std::make_unique <HeartGift>();
		break;
	case ADD_TIME_GIFT_CH: 
		m_board[row][col] = std::make_unique <TimeGift>();
		break;
	case CAT_CH:
		setCat(cats, sf::Vector2f(static_cast<float>(col) * P_SIZE, static_cast<float>(row) * P_SIZE));
		break;
	case MOUSE_CH:
		setMouse(mouse, sf::Vector2f(static_cast<float>(col) * P_SIZE, static_cast<float>(row) * P_SIZE));
		break;
	default:
		break;
	}
}