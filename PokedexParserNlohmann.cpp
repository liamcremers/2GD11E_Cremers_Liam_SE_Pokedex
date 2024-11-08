#include "PokedexParser.h"
#include "nlohmann/json.hpp"
#include <fstream>
#include <vector>

std::vector<Pokemon> PokedexParser::CreateParser(std::ifstream& file)
{
	std::vector<Pokemon> pokemonList;
	nlohmann::json jsonData;
	file >> jsonData;

	for (const auto& item : jsonData["pokemon"])
	{
		Pokemon pokemon;
		pokemon.id = item["id"];
		pokemon.name = item["name"];
		pokemon.type = item["type"];
		pokemonList.push_back(pokemon);
	}

	return pokemonList;
}
