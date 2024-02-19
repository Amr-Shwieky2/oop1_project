#include "Screens.h"

Screens::Screens() {
	setOpeningGame();
	setBackground();
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

void Screens::drawBackground(sf::RenderWindow& window) const {
	window.draw(m_backgroundSprite);
}

void Screens::drawStarterSection(sf::RenderWindow& window) {
	sf::Font font;
	if (!font.loadFromFile("sectionFont.ttf")) { // Load your desired font file
		std::cerr << "Failed to load font." << std::endl;
		return;
	}

	unsigned int fontSize = 18; // Set the desired font size
	sf::Text newGameText = createText("New Game", font, fontSize, window);
	sf::Text tableText = createText("Scores", font, fontSize, window);
	sf::Text exitText = createText("Exit", font, fontSize, window);
	// Draw the text objects
	window.draw(newGameText);
	window.draw(tableText);
	window.draw(exitText);
}

sf::Text Screens::createText(std::string str, sf::Font font, unsigned int fontSize, sf::RenderWindow& window) {
	sf::Text text(str, font, fontSize);
	text.setFillColor(sf::Color::White);
	text.setStyle(sf::Text::Bold);
	text.setPosition((window.getSize().x - text.getLocalBounds().width) / 2, window.getSize().y / 2 + 50);
	return text;
}


void Screens::drawMap(sf::RenderWindow& window) {
	m_board.drawNonMovable(window);
	//window.draw(m_backgroundSprite);
}

//
//void Screens::draw(sf::RenderWindow& window) const {
//	window.draw(m_backgroundSprite);
//}
