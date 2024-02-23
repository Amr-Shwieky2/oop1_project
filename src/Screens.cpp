#include "Screens.h"

Screens::Screens() {
	setOpeningGame();
	setCounters();
	setBackground();
	setSoundTexture();
	setSoundBuffers();
	setMenu();
	setInformation();
	setStory();
}

void Screens::setBackground() {
	m_backgroundTexture.loadFromFile("Tom&Jerry.png");
	m_backgroundSprite.setScale((float)(40 * P_SIZE) / m_backgroundTexture.getSize().x,
		(float)(22 * P_SIZE) / m_backgroundTexture.getSize().y);
	m_backgroundSprite.setTexture(m_backgroundTexture);

}

void Screens::setLevelsOpenings(float colSize, float rowSize, unsigned int numberOfLevel){
	sf::Texture text;
	text.loadFromFile("new-level" + std::to_string((numberOfLevel % 5) + 1) + ".png");
	m_levelsBackgroundsTexture.push_back(text);

	sf::Sprite sprite;
	sprite.setScale(colSize, rowSize);
	sprite.setTexture(text); // Set the texture for the sprite
	m_levelsBackgroundsSprite.push_back(sprite);
}

void Screens::setCounters() {
	for (size_t i = 0; i < 5; i++) {
		m_countersTexture[i].loadFromFile(std::to_string(i + 1) + ".png");
		m_countersSprite[i].setTexture(m_countersTexture[i]);

		// Resize the sprite to 64x64
		m_countersSprite[i].setScale(64.0f / m_countersTexture[i].getSize().x, 64.0f / m_countersTexture[i].getSize().y);
		m_countersSprite[i].setPosition(620, 600);
	}
}


void Screens::setOpeningGame() {
	m_startTheGame.loadFromFile("startGame.png");
	m_startTheGameSprite.setTexture(m_startTheGame);
	// Set the origin of the sprite to its center
	m_startTheGameSprite.setOrigin(m_startTheGameSprite.getLocalBounds().width / 2, m_startTheGameSprite.getLocalBounds().height / 2);
	// Set the position of the sprite to the center of the window
	m_startTheGameSprite.setPosition(640, 350);
}

void Screens::setMenu() {
	m_font.loadFromFile("sectionFont.ttf");
	if (!m_font.loadFromFile("sectionFont.ttf")) { // Load your desired font file
		std::cerr << "Failed to load font." << std::endl;
		exit(EXIT_FAILURE);
	}

	unsigned int fontSize = 40; // Set the desired font size

	m_newGameText = createText("New Game", m_font, fontSize);
	m_tableText = createText("Scores", m_font, fontSize);
	m_exitText = createText("Exit", m_font, fontSize);
}

void Screens::setInformation() {
	std::ifstream file("information.txt");
	if (!file.is_open()) {
		std::cerr << "Cannot open Information file\n";
		exit (EXIT_FAILURE);
	}

	// Read the content of the file into a string
	std::string line;
	while (std::getline(file, line)) {
		m_informationTextStr += line + "\n";
	}

	m_skipTexture.loadFromFile("skip.png");
	m_skipSprite.setTexture(m_skipTexture);
	m_skipSprite.setPosition(1200, 40);
	m_skipSprite.setScale(32 / m_skipSprite.getGlobalBounds().width, 32 / m_skipSprite.getGlobalBounds().height);
}

void Screens::drawInformation(sf::RenderWindow& window) {
	sf::Text text;
	text.setFont(m_font); // Set the font
	text.setString(m_informationTextStr); // Set the text
	text.setCharacterSize(36); // Set the character size
	text.setFillColor(sf::Color::Black); // Set the fill color
	text.setPosition(20, 20); // Set the position
	window.draw(m_skipSprite);
	window.draw(text);
}

void Screens::drawStory(sf::RenderWindow& window, unsigned int i, float interpolation, int animationIndex) {
	if (interpolation >= 1.0f) { 	// Calculate interpolation factor
		interpolation = 1.0f;
	}

	sf::Uint8 alpha = static_cast<sf::Uint8>(255 * interpolation);
	float rotation = 360.0f * interpolation; // Rotate 360 degrees

	switch (animationIndex) {
	case 0: // Animation 1: Change opacity
		m_storySprite[i].setColor(sf::Color(255, 255, 255, alpha));
		break;
	case 1: // Animation 2: Rotate
		m_storySprite[i].setRotation(rotation);
		break;
	default: // Default to animation 1
		m_storySprite[i].setColor(sf::Color(255, 255, 255, alpha));
		break;
	}
	window.draw(m_storySprite[i]);
}

void Screens::drawLevelOpenning(sf::RenderWindow& window, unsigned int openingNum) {
	sf::Clock clock;
	int seconds = 0;
	m_sound[4].play();
	while (true) {
		float elapsedTime = clock.getElapsedTime().asSeconds();
		window.clear();
		window.draw(m_levelsBackgroundsSprite.at(openingNum - 1));
		window.display();
		// Increment sprite index every second
		if (elapsedTime >= 1.0f) {
			seconds++;
			clock.restart(); // Restart the clock to accurately measure time for the next sprite
		}
		if (seconds == 5) {
			break;
		}
	}
}


void Screens::setSoundTexture() {
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

void Screens::OpeningBackground(sf::RenderWindow& window) {
	sf::Clock clock;
	int spriteIndex = 0; // Variable to keep track of which sprite to draw
	m_sound[0].play();
	while (true) {
		float elapsedTime = clock.getElapsedTime().asSeconds();
		drawStarter(window, spriteIndex);
		// Increment sprite index every second
		if (elapsedTime >= 1.0f) {
			spriteIndex++;
			clock.restart(); // Restart the clock to accurately measure time for the next sprite
		}
		if (spriteIndex == 5) {
			std::cout << "Background removed!" << std::endl;
			break;
		}
	}
}

sf::Font Screens::getFont() const {
	return m_font;
}

void Screens::drawStarter(sf::RenderWindow& window, int spriteIndex) const {
	window.clear();
	// Draw the start sprite
	window.draw(m_startTheGameSprite);
	// Draw the current counter sprite
	if (spriteIndex < 5) {
		window.draw(m_countersSprite[4 - spriteIndex]);
	}
	window.display();
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
	m_tableText = createText("Information", font, fontSize);
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
	text.setPosition(xPos,100 + float(120 * i) );
	window.draw(text);
}

void Screens::setSoundBuffers() {
	std::vector<std::string> sounds = { "opening.wav" , "click.wav",  "tomRunning.wav" , "catch.wav" , "tom-lose.wav"};
	for (size_t i = 0; i < SOUNDS; i++) {
		m_soundBuffer[i].loadFromFile(sounds.at(i));
		m_sound[i].setBuffer(m_soundBuffer[i]);
	}
}

void Screens::setStory() {
	for (size_t i = 0; i < STORY_SCREENS; i++) {
		m_storyTexture[i].loadFromFile("story" + std::to_string(i + 1) + ".png");
		m_storySprite[i].setScale((float)(40 * P_SIZE) / m_storyTexture[i].getSize().x,
			(float)(22 * P_SIZE) / m_storyTexture[i].getSize().y);
		m_storySprite[i].setTexture(m_storyTexture[i]);
	}
}

void Screens::playPauseSound(int i , bool mute) {
	mute ? m_sound[i].stop() : m_sound[i].play();
}