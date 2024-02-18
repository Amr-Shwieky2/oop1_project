#pragma once

#include "Screens.h"
#include <thread>

class Controller
{
public:
	Controller();
	//~Controller();

private:
	Board m_board;
    Screens m_screens;
};