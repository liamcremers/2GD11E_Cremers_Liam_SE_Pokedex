# Pokedex Parser

This project is a C++ console application for parsing a Pokémon Pokedex JSON file. It can switch between two JSON parsers, jsoncpp and nlohmann::json, based on CMake configuration.

## Libraries Used
- **JSONCPP** 
- **nlohmann::json** 

## Configuration and Build

1. Clone the repository and open a terminal in the project directory.
     ```bash
      git clone https://github.com/liamcremers/2GD11E_Cremers_Liam_SE_Pokedex
      cd 2GD11E_Cremers_Liam_SE_Pokedex
     ```
2. Configure with CMake:

   - To use **JSONCPP**:
     ```bash
      cmake -S . -B build -DJSON_LIBRARY=jsoncpp
     ```

   - To use **nlohmann JSON**:
     ```bash
      cmake -S . -B build -DJSON_LIBRARY=NLOHMANN
     ```
3. Build the project and Run the Application
   ```bash
   # Build the project:
   cmake --build build
   # Run the Application
   .\build\Debug\2GD11E_Cremers_Liam_SE_Pokedex.exe
   ```
