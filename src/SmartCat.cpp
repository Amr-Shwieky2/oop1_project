#include "SmartCat.h"
#include <queue>
#include "Wall.h"
#include "Board.h"

void SmartCat::move(float passedTime, sf::Vector2f boardSize, const std::vector<std::vector<sf::Vector3i>>& Tree)
{
    //std::vector<std::vector<sf::Vector3i>> Tree = getBfsTree();

	sf::Vector2i start = sf::Vector2i((int)(m_sprite.getPosition().x / P_SIZE),
									  (int)(m_sprite.getPosition().y / P_SIZE));

	m_previousPostion = m_sprite.getPosition();
	float moveDistance = CAT_SPEED * passedTime;

	if (isCentered(m_sprite.getPosition(), getCenter(m_sprite.getPosition()))) {
		m_direction = getBfsMove(start,
			sf::Vector2i(Tree[start.y][start.x].y, Tree[start.y][start.x].z));
	}

	moveDirection(moveDistance);

	if (outOfBoard(boardSize)) {
		m_sprite.setPosition(m_previousPostion);
	}
	m_position = m_sprite.getPosition();
}

Direction SmartCat::getBfsMove(const sf::Vector2i& start, const sf::Vector2i& destination)
{
	if (start.x > destination.x)
		return LEFT;

	if (start.x < destination.x)
		return RIGHT;

	if (start.y > destination.y)
		return UP;

	if (start.y < destination.y)
		return DOWN;

	return UP;
}

//// Function to perform Breadth-First Search (BFS) traversal on a 2D grid and return the BFS tree
//std::vector<std::vector<sf::Vector3i>> SmartCat::getBfsTree(sf::Vector2i start,
//    const std::vector<std::vector<std::unique_ptr<NonMovable>>>& NonMovableIcon, Board& board)
//{
//    // Initialize the BFS tree with distances and parent coordinates
//    std::vector<std::vector<sf::Vector3i>> bfsTree;
//    bfsTree.assign(NonMovableIcon.size(), std::vector<sf::Vector3i>(NonMovableIcon[0].size(),
//        sf::Vector3i(INT_MAX, -1, -1))); // Initialize all distances to INT_MAX and parent coordinates to (-1, -1)
//
//    // Set distance of start node to 0
//    bfsTree[start.y][start.x].x = 0;
//
//    // Queue to store coordinates to be visited
//    std::queue<sf::Vector2i> coordinatesQueue;
//    coordinatesQueue.push(start); // Enqueue the starting coordinate
//
//    // Perform BFS traversal
//    while (!coordinatesQueue.empty())
//    {
//        // Dequeue the current coordinate
//        sf::Vector2i currentCoord = coordinatesQueue.front();
//        coordinatesQueue.pop();
//
//        // Get neighboring coordinates
//        std::vector<sf::Vector2i> neighbors = searchNeighbors(currentCoord, NonMovableIcon, board);
//
//        // Explore neighbors
//        for (unsigned int i = 0; i < neighbors.size(); i++)
//        {
//            // Get the next neighbor coordinate
//            sf::Vector2i nextCoord = neighbors[i];
//
//            // Check if the neighbor is valid and unvisited
//            if ((nextCoord.y != start.y || nextCoord.x != start.x) &&
//                bfsTree[nextCoord.y][nextCoord.x].x == INT_MAX)
//            {
//                // Enqueue the neighbor
//                coordinatesQueue.push(nextCoord);
//
//                // Update distance and parent coordinates of the neighbor
//                bfsTree[nextCoord.y][nextCoord.x].x = bfsTree[currentCoord.y][currentCoord.x].x + 1;
//                bfsTree[nextCoord.y][nextCoord.x].y = currentCoord.x;
//                bfsTree[nextCoord.y][nextCoord.x].z = currentCoord.y;
//            }
//        }
//    }
//
//    // Return the BFS tree
//    return bfsTree;
//}
//std::vector<sf::Vector2i> SmartCat::searchNeighbors(const sf::Vector2i center,
//    const std::vector<std::vector<std::unique_ptr<NonMovable>>>& NonMovableIcon, Board& board)
//{
//
//    // Define shifts for moving in all four directions
//    std::vector<sf::Vector2i> directions = { { 1,0 },{ -1,0 },{ 0,1 },{ 0,-1 } };
//
//    // Vector to store the neighboring coordinates
//    std::vector<sf::Vector2i> neighbors;
//
//    sf::Vector2i nextCoord;
//
//    // Iterate over all possible directions
//    for (int i = 0; i < 4; i++)
//    {
//        // Calculate the next coordinate
//        nextCoord = center + directions[i];
//
//        // Check if the next coordinate is within the board boundaries and is not a wall
//        if (board.cheackOutOfMap(sf::Vector2f(nextCoord)) &&
//            !dynamic_cast<Wall*> (NonMovableIcon[nextCoord.y][nextCoord.x].get()))
//        {
//            // Add the valid neighboring coordinate to the list
//            neighbors.push_back(nextCoord);
//        }
//    }
//
//    // Return the neighboring coordinates
//    return neighbors;
//
//}
