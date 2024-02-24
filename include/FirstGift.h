#include "Gift.h"

class FirstGift : public Gift {
public:
	FirstGift(sf::Vector2f position) : Gift() {
		m_position = position;
		m_sprite.setTexture(*(Utilities::instance().getCharactersTexture(HEART_GIFT)));
		m_sprite.setScale(sf::Vector2f(((float)P_SIZE / m_sprite.getGlobalBounds().height),
			((float)P_SIZE / m_sprite.getGlobalBounds().height)));
	};


private:

};