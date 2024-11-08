#include <fstream>
#include <iostream>
#include <print>
#include "PokedexParser.h"

using json = PokedexParser;
int main()
{
	std::ifstream input("./content/pokedex.json");  // Open the file
	if (!input.is_open())
	{
		std::cout << "Failed to load json file!" << std::endl;
		return -1;
	}

	auto pokeList = json::CreateParser(input);

	for (auto& poke : pokeList) {
		std::print("{}. {} [", poke.id, poke.name);
		for (auto& type : poke.type)
		{
			std::print("{}", type);
			if (&type != &poke.type.back())
				std::print(", ");
		}
		std::print("]\n");
	}

	return 0;
}