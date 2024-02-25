#pragma once

#include "Gift.h"

class HeartGift : public Gift {
public:
	HeartGift() : Gift() {
		m_typegift = ADD_HEART_GIFT;
		m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(HEART_GIFT)));
		m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
			((float)P_SIZE / m_sprite.getGlobalBounds().height)));
	};

};