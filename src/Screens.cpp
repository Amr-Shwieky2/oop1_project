#include "Screens.h"

Screens::Screens() {
	setOpeningGame();
	setBackground();
	setSound();
}

void Screens::setBackground() {
	m_backgroundTexture.loadFromFile("Tom&Jerry.png");
	m_backgroundSprite.setScale((float)(40 * P_SIZE) / m_backgroundTexture.getSize().x,
		(float)(22 * P_SIZE) / m_backgroundTexture.getSize().y);
	m_backgroundSprite.setTexture(m_backgroundTexture);

}
void Screens::setOpeningGame() {
	m_startTheGame.loadFromFile("startGame.png");
	m_startTheGameSprite.setTexture(m_startTheGame);
	// Set the origin of the sprite to its center
	m_startTheGameSprite.setOrigin(m_startTheGameSprite.getLocalBounds().width / 2, m_startTheGameSprite.getLocalBounds().height / 2);
	// Set the position of the sprite to the center of the window
	m_startTheGameSprite.setPosition(640, 350);
	//m_openingSoundBuffer.loadFromFile("opening.wav");
	//m_openingSound.setBuffer(m_openingSoundBuffer);
}

void Screens::setSound() {
	m_soundOn.loadFromFile("soundOn.png");
	m_soundOnSprite.setTexture(m_soundOn);
	m_sounOff.loadFromFile("soundOff.png");
	m_soundOffSprite.setTexture(m_sounOff);

	//sf::Vector2f buttonSize(5, P_SIZE);
	sf::Vector2f buttonPosition(20, 20);

	m_soundOnSprite.setScale(sf::Vector2f(((float)P_SIZE / m_soundOnSprite.getGlobalBounds().width),
										((float)P_SIZE / m_soundOnSprite.getGlobalBounds().height)));
	m_soundOnSprite.setPosition(20, 20);

	m_soundOffSprite.setScale(sf::Vector2f(((float)P_SIZE / m_soundOffSprite.getGlobalBounds().width),
										((float)P_SIZE / m_soundOffSprite.getGlobalBounds().height)));
	
	m_soundOffSprite.setPosition(20, 20);
}

void Screens::drawStarter(sf::RenderWindow& window) const {
	window.clear();
	window.draw(m_startTheGameSprite);
	window.display();
}

void Screens::OpeningBackground(sf::RenderWindow& window) {
	float backgroundOpacity = 255;
	sf::Clock clock;
	while (true) {
		float elapsedTime = clock.getElapsedTime().asSeconds();
		// If elapsed time is less than 3 seconds, wait
		if (elapsedTime < 3.0f) {
			sf::sleep(sf::seconds(0.1f)); // Adjust sleep time as needed
		}
		else {
			// Gradually decrease background opacity
			backgroundOpacity -= 5.0f; // Adjust decrement as needed
			if (backgroundOpacity < 0) backgroundOpacity = 0;

			// Set the background opacity
			m_startTheGameSprite.setColor(sf::Color(255, 255, 255, backgroundOpacity));
		}
		drawStarter(window);
		// after 3 secod stop oppening music
		if (elapsedTime >= 3.0f && backgroundOpacity <= 0) {
			std::cout << "Background removed!" << std::endl;
			// stop usic
			break;
		}
	}
}

void Screens::drawBackground(sf::RenderWindow& window) {
	window.draw(m_backgroundSprite);
}

void Screens::drawStarterSection(sf::RenderWindow& window) {
	sf::Font font;
	font.loadFromFile("sectionFont.ttf");
	if (!font.loadFromFile("sectionFont.ttf")) { // Load your desired font file
		std::cerr << "Failed to load font." << std::endl;
		return;
	}

	//sf::Text newGameText, tableText, exitText;
	unsigned int fontSize = 40; // Set the desired font size

	m_newGameText = createText("New Game", font, fontSize);
	m_tableText = createText("Scores", font, fontSize);
	m_exitText = createText("Exit", font, fontSize);

	// Draw the text objects
	drawTextInStarter(m_newGameText, window);
	drawTextInStarter(m_tableText, window);
	drawTextInStarter(m_exitText, window);
}

void Screens::drawSoundButton(sf::RenderWindow& window, bool flag) {
	flag ? window.draw(m_soundOnSprite) : window.draw(m_soundOffSprite);
}

sf::Text Screens::createText(const std::string& str,const sf::Font& font, unsigned int fontSize) {
	sf::Text text;
	text.setFont(font);
	text.setString(str);
	text.setFillColor(sf::Color::Black);
	text.setStyle(sf::Text::Bold);
	text.setCharacterSize(fontSize);
	return text;
}

void Screens::drawTextInStarter(sf::Text& text, sf::RenderWindow& window) {
	static int i = 1;
	// Get the size of the window
	if (i <= 3) {
		sf::Vector2u windowSize = window.getSize();
		float xPos = (windowSize.x - text.getLocalBounds().width) / 2;
		text.setPosition(xPos,100 +(120 * i) );
		
		window.draw(text);
		
		i++;
	}
	//window.display();
}

void Screens::buttonReleased(sf::Event event, sf::RenderWindow& window) {
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;

	sf::Vector2f pos((float)(x - (x % P_SIZE)), (float)(y - (y % P_SIZE)));

	int newGameText = m_newGameText.getPosition().y;
	int tableText = m_tableText.getPosition().y;
	int exitText = m_exitText.getPosition().y;

	if (pos.x == m_newGameText.getPosition().x) {
		switch (checkButtons((int)pos.y))
		{
		case 220: 
			break;

		case 340:
			break;

		case 460:
			break;

		default:
			break;
		}
	}
	else if (checkSoundIconPressed(pos.x) == 20) {
		std::cout << "Noor";
		drawSoundButton(window, m_mute);
		!m_mute;
	}
}

int Screens::checkSoundIconPressed(int val) {
	if (val >= 15 && val <= 55) return 20;
	return 0;
}

int Screens::checkButtons(int val) {
	int i;

	if (val >= 200 && val <= 240) {
		i = 1;
	}
	else if (val >= 320 && val <= 360) {
		i = 2;
	}
	else if (val >= 440 && val <= 480) {
		i = 3;
	}
	else
		;

	return ((i * 120) + 100);
}

void Screens::drawMap(sf::RenderWindow& window) {
	m_board.drawNonMovable(window);
	//window.draw(m_backgroundSprite);
}

//
//void Screens::draw(sf::RenderWindow& window) const {
//	window.draw(m_backgroundSprite);
//}
