#pragma once

#include "Gift.h"

class SecondGift : public Gift {
public:
	SecondGift() : Gift(position, RemoveCat) {
		m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(CAT_GIFT)));
		m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
			((float)P_SIZE / m_sprite.getGlobalBounds().height)));
	};

private:

};