#include <fstream>
#include <vector>

struct Pokemon
{
	int id{};
	std::string name{};
	std::vector<std::string> type{};
};

class PokedexParser
{
public:
	static std::vector<Pokemon> CreateParser(std::ifstream& file);
private:
	std::vector<Pokemon> pokemonList;
};
