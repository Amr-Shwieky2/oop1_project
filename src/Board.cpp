#include "Board.h"
#include "Cheese.h"
#include "Door.h"
#include "Wall.h"
#include "Key.h"
#include "Gift.h"
#include "SmartCat.h"
#include "RandomCat.h"

Board::Board(Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats, const int& numberOfLevel)
	: m_row(0), m_col(0), m_numberOfLevel(0), m_numberOfCats(0)
{
	readLevel(mouse, cats, numberOfLevel);
}

sf::Vector2f Board::getBoardSize()
{
	sf::Vector2f boardSize;
	boardSize.x = m_board.size() * P_SIZE;
	boardSize.y = m_board[0].size() * P_SIZE;
	return boardSize;
}

void Board::readLevel(Mouse& mouse, std::vector<std::unique_ptr<Cat>>& cats, const int& numberOfLevel)
{
	m_numberOfLevel = numberOfLevel;
	openFile(m_file);
	char nextChar;
	m_file >> m_row >> m_col;
	setBoardSize();

	for (size_t i = 0; i < m_row; i++)
	{
		m_file.get();
		for (size_t j = 0; j < m_col; j++)
		{
			nextChar = m_file.get();
			//add_to_board(c, i, j, pac, m_demons);
		}
	}
	m_file.seekg(0, std::ios::beg);
	m_file.close();
}

void Board::setCat(std::vector<std::unique_ptr<Cat>>& cats, sf::Vector2f position)
{
	
	m_numberOfCats++;
	if (!cats.size() % 2 == 0)
		cats.push_back(std::make_unique < RandomCat >()); // SmartCat
	else
		cats.push_back(std::make_unique < RandomCat >());

	size_t catSize = cats.size() - 1;
	cats[catSize]->SetPosition(position);
	cats[catSize]->setStartPosition(position);
}

void Board::openFile(std::ifstream& input)
{
	
	std::string file = "level" + std::to_string(m_numberOfLevel) + ".txt";
	input.open(file);
	if (!input.is_open())
	{
		std::cerr << "could not open file\n";
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
		m_board[row].at(col) = std::make_unique <Wall>();
		break;
	case DOOR_CH:
		m_board[row].at(col) = std::make_unique <Door>();
		break;
	case CHEESE_CH:
		m_board[row].at(col) = std::make_unique <Cheese>();
		break;
	case KEY_CH:
		m_board[row].at(col) = std::make_unique <Key>();
		break;
	case GIFT_CH:
		m_board[row].at(col) = std::make_unique <Gift>();
		break;
	case CAT_CH:
	default:
		break;
	}
}
