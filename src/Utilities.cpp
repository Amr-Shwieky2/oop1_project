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
