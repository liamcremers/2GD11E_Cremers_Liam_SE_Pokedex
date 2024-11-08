cmake_minimum_required (VERSION 3.8)

#Prevent DOWNLOAD_EXTRACT_TIMESTAMP warning
cmake_policy(SET CMP0135 NEW)

# Ensure Unicode support for Windows
if (WIN32)
    add_compile_options(-DUNICODE -D_UNICODE)
    add_compile_options(/utf-8)  # Ensure source files are treated as UTF-8
endif()

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("2GD11E_Cremers_Liam_SE_Pokedex")
set_property(GLOBAL PROPERTY USE_FOLDERS ON)

# toggle 'cache' between NLOHMANN and jsoncpp
set(JSON_LIBRARY "jsoncpp" CACHE STRING "Choose the json library to use")
set_property(CACHE JSON_LIBRARY PROPERTY STRINGS "jsoncpp" "NLOHMANN") 


set(SOURCES 
    "main.cpp"
    "PokedexParser.h"
    
)

if(JSON_LIBRARY STREQUAL "NLOHMANN")
    list(APPEND SOURCES "PokedexParserNlohmann.cpp")
    elseif(JSON_LIBRARY STREQUAL "jsoncpp")
    list(APPEND SOURCES "PokedexParserJsoncpp.cpp")
endif()

add_executable (2GD11E_Cremers_Liam_SE_Pokedex ${SOURCES}  )
set_property(DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT 2GD11E_Cremers_Liam_SE_Pokedex)

#copy content to build directory
add_custom_command(
        TARGET ${PROJECT_NAME} POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_directory_if_different
                ${CMAKE_SOURCE_DIR}/content
                $<TARGET_FILE_DIR:${PROJECT_NAME}>/content)

set(CMAKE_MODULE_PATH "${CMAKE_MODULE_PATH};${CMAKE_CURRENT_SOURCE_DIR}/cmake")


configure_file(${CMAKE_SOURCE_DIR}/content/pokedex.json ${CMAKE_BINARY_DIR}/content/pokedex.json COPYONLY)

# Print out the value of JSON_LIBRARY
message(STATUS "JSON_LIBRARY is set to: ${JSON_LIBRARY}")
# Check for correct value of JSON_LIBRARY
if(JSON_LIBRARY STREQUAL "NLOHMANN")
  include(nlohmann_simple)
  message(STATUS "Using NLOHMANN")
  add_definitions(-DNLOHMANN)
elseif(JSON_LIBRARY STREQUAL "jsoncpp")
  include(jsoncpp)

    set_target_properties(
      jsoncpp_static
      PROPERTIES FOLDER "External/jsoncpp")
  
  message(STATUS "Using jsoncpp")
  add_definitions(-DJSONCPP)
else()
  message(STATUS "Invalid value for JSON_LIBRARY: ${JSON_LIBRARY}")
endif()



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 2GD11E_Cremers_Liam_SE_Pokedex PROPERTY CXX_STANDARD 23)
endif()
