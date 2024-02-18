#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

#include "Utilities.h"
#include "Icon.h"

#include <string>


class Board
{
public:
	Board();
	//~Board();


private:
	Utilities m_utilities;
	std::vector<std::string> m_levels;
};

