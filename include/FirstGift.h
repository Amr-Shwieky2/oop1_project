#pragma once

#include "Gift.h"

class FirstGift : public Gift {
public:
	FirstGift() : Gift(position, AddHeart) {
		m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(HEART_GIFT)));
		m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
			((float)P_SIZE / m_sprite.getGlobalBounds().height)));
	};

private:

};