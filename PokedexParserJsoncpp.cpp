#include "PokedexParser.h"
#include <json/json.h>
#include <fstream>
#include <vector>

std::vector<Pokemon> PokedexParser::CreateParser(std::ifstream& file)
{
	std::vector<Pokemon> pokemonList;
	Json::Value jsonData;
	file >> jsonData;

	for (const auto& item : jsonData["pokemon"])
	{
		Pokemon pokemon;
		pokemon.id = item["id"].asInt();
		pokemon.name = item["name"].asString();
		for (unsigned int i = 0; i < item["type"].size(); i++)
			pokemon.type.push_back(item["type"][i].asString());

		pokemonList.push_back(pokemon);
	}

	return pokemonList;
}
