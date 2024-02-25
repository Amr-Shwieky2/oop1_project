#pragma once

#include "Gift.h"

class ThirdGift : public Gift {
public:
	ThirdGift() : Gift(m_position, AddTime) {
		m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(TIME_GIFT)));
		m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
			((float)P_SIZE / m_sprite.getGlobalBounds().height)));
	};

private:

};