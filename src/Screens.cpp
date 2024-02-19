#include "Screens.h"

Screens::Screens() {
	setOpeningGame();
	setBackground();
	setSound();
	setInformation();
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
}

void Screens::setInformation() {
	sf::Font font;
	font.loadFromFile("sectionFont.ttf");
	if (!font.loadFromFile("sectionFont.ttf")) { // Load your desired font file
		std::cerr << "Failed to load font." << std::endl;
		return;
	}

	unsigned int fontSize = 40; // Set the desired font size

	m_newGameText = createText("New Game", font, fontSize);
	m_tableText = createText("Scores", font, fontSize);
	m_exitText = createText("Exit", font, fontSize);
}

void Screens::setSound() {


	m_soundOn.loadFromFile("soundOn.png");
	m_soundOnSprite.setTexture(m_soundOn);
	m_soundOff.loadFromFile("soundOff.png");
	m_soundOffSprite.setTexture(m_soundOff);

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
	//m_openingSound.play();
	while (true) {
		float elapsedTime = clock.getElapsedTime().asSeconds();
		// If elapsed time is less than 6 seconds, wait
		if (elapsedTime < 10.0f) {
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
		if (elapsedTime >= 10.0f && backgroundOpacity <= 0) {
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

	unsigned int fontSize = 40; // Set the desired font size

	m_newGameText = createText("New Game", font, fontSize);
	m_tableText = createText("Scores", font, fontSize);
	m_exitText = createText("Exit", font, fontSize);
	// Draw the text objects
	drawTextInStarter(m_newGameText, window, 1);
	drawTextInStarter(m_tableText, window, 2);
	drawTextInStarter(m_exitText, window, 3);
}

void Screens::drawSoundButton(sf::RenderWindow& window, bool flag) {
	if (flag) {
		window.draw(m_soundOffSprite);
	}
	else {
		window.draw(m_soundOnSprite);
	}
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

void Screens::drawTextInStarter(sf::Text& text, sf::RenderWindow& window, int i) {
	sf::Vector2u windowSize = window.getSize();
	float xPos = (windowSize.x - text.getLocalBounds().width) / 2;
	text.setPosition(xPos,100 +(120 * i) );
	window.draw(text);
}

void Screens::drawMap(sf::RenderWindow& window) {
	//m_board.drawNonMovable(window);
	//window.draw(m_backgroundSprite);
}

//
//void Screens::draw(sf::RenderWindow& window) const {
//	window.draw(m_backgroundSprite);
//}
