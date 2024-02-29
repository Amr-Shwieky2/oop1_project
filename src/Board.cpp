
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
#include <queue>

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
		cats.push_back(std::make_unique < SmartCat >());
	else
		cats.push_back(std::make_unique < RandomCat >());

	size_t catSize = cats.size() - 1;
	cats[catSize]->SetPosition(position);
	cats[catSize]->setStartPosition(position);
}

int Board::getCheeseCounter() const {
	return m_numberOfCheese;
}

int Board::getCatsNumber() const
{
	return m_numberOfCats;
}

NonMovable* Board::getCharacters(sf::Vector2f position, Direction direction)
{
	int row, col;
	if (direction == LEFT || direction == UP) {
		row = static_cast<int>(position.y / P_SIZE);
		col = static_cast<int>(position.x / P_SIZE);
	}
	else
	{
		row = static_cast<int>(std::round(position.y / P_SIZE ));
		col = static_cast<int>(std::round(position.x / P_SIZE ));
	}

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

sf::Time Board::getTime()const
{
	return m_time;
}

int Board::getnumberOfLevel() const
{
	return m_numberOfLevel;
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
		m_board[row][col] = std::make_unique <Wall>();
		break;
	case DOOR_CH:
		m_board[row][col] = std::make_unique <Door>();
		break;
	case CHEESE_CH:
		m_board[row][col] = std::make_unique <Cheese>();
		m_numberOfCheese++;
		break;
	case KEY_CH:
		m_board[row][col] = std::make_unique <Key>();
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




std::vector<std::vector<sf::Vector3i>> Board::getBfsTree(sf::Vector2i start)
{
	// Initialize the BFS tree with distances and parent coordinates
	std::vector<std::vector<sf::Vector3i>> bfsTree;
	bfsTree.assign(m_board.size(), std::vector<sf::Vector3i>(m_board[0].size(),
		sf::Vector3i(INT_MAX, -1, -1))); // Initialize all distances to INT_MAX and parent coordinates to (-1, -1)

	// Set distance of start node to 0
	bfsTree[start.y][start.x].x = 0;

	// Queue to store coordinates to be visited
	std::queue<sf::Vector2i> coordinatesQueue;
	coordinatesQueue.push(start); // Enqueue the starting coordinate

	// Perform BFS traversal
	while (!coordinatesQueue.empty())
	{
		// Dequeue the current coordinate
		sf::Vector2i currentCoord = coordinatesQueue.front();
		coordinatesQueue.pop();

		// Get neighboring coordinates
		std::vector<sf::Vector2i> neighbors = searchNeighbors(currentCoord);

		// Explore neighbors
		for (unsigned int i = 0; i < neighbors.size(); i++)
		{
			// Get the next neighbor coordinate
			sf::Vector2i nextCoord = neighbors[i];

			// Check if the neighbor is valid and unvisited
			if ((nextCoord.y != start.y || nextCoord.x != start.x) &&
				bfsTree[nextCoord.y][nextCoord.x].x == INT_MAX)
			{
				// Enqueue the neighbor
				coordinatesQueue.push(nextCoord);

				// Update distance and parent coordinates of the neighbor
				bfsTree[nextCoord.y][nextCoord.x].x = bfsTree[currentCoord.y][currentCoord.x].x + 1;
				bfsTree[nextCoord.y][nextCoord.x].y = currentCoord.x;
				bfsTree[nextCoord.y][nextCoord.x].z = currentCoord.y;
			}
		}
	}

	// Return the BFS tree
	return bfsTree;
}

std::vector<sf::Vector2i> Board::searchNeighbors(const sf::Vector2i center)
{
	// Define shifts for moving in all four directions
	std::vector<sf::Vector2i> directions = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };

	// Vector to store the neighboring coordinates
	std::vector<sf::Vector2i> neighbors;

	sf::Vector2i nextCoord;

	// Iterate over all possible directions
	for (int i = 0; i < 4; i++)
	{
		// Calculate the next coordinate
		nextCoord = center + directions[i];

		// Check if the next coordinate is within the board boundaries and is not a wall
		if (checkOutOfMap(sf::Vector2f(nextCoord)) &&
			!dynamic_cast<Wall*> (m_board[nextCoord.y][nextCoord.x].get()))
		{
			// Add the valid neighboring coordinate to the list
			neighbors.push_back(nextCoord);
		}
	}

	// Return the neighboring coordinates
	return neighbors;
}