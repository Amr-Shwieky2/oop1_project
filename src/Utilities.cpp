#include "Utilities.h"

Utilities::Utilities() {
	iconNames("Names_images.txt");
	setLevels("Levels.txt");
}


void Utilities::iconNames(std::string str) {
	std::ifstream inputFile(str);
	checkIfValid(inputFile);
	std::string line;
	int i = 0;
	while (std::getline(inputFile, line)) {
		m_CharactersTexture[Characters(i)].loadFromFile(line);
		i++;
	}
}

void Utilities::setLevels(std::string str) {
	std::ifstream inputFile(str);
	checkIfValid(inputFile);
	std::string line;
	while (std::getline(inputFile, line)) {
		m_levels.push_back(line);
	}
	inputFile.close();
}

void Utilities::checkIfValid(std::ifstream &inputFile) {
	// Check if the file is successfully opened
	if (!inputFile.is_open()) {
		std::cerr << "Unable to open file 'Names_images.txt'" << std::endl; // ????????????????
		exit(EXIT_FAILURE);
	}
}

std::vector<std::string> Utilities::getLevels() {
	return m_levels;
}

sf::Texture* Utilities::getCharactersTexture(size_t shape)
{
	return & m_CharactersTexture[shape];
}
sf::Texture* Utilities::getScreen(size_t screen)
{
	return &m_Screeen[screen];
}
sf::Texture* Utilities::getLifeTexture()
{
	return  &m_lifeCounter;
}
Utilities& Utilities::instance()
{
	static Utilities instance;
	return instance;
}
