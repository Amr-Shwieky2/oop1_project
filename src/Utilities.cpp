#include "Utilities.h"

Utilities::Utilities()
{
	std::ifstream inputFile("Names_images.txt");

	// Check if the file is successfully opened
	if (!inputFile.is_open()) {
		std::cerr << "Unable to open file 'Names_images.txt'" << std::endl;
		exit(EXIT_FAILURE);
	}

	std::string line;
	int i = 0;
	while (std::getline(inputFile, line)) {
		m_CharactersTexture[Characters(i)].loadFromFile(line);

		i++;
	}

	inputFile.close();
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


