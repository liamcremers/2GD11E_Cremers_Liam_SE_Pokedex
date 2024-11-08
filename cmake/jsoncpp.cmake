# hide the stupid executable options
include(FetchContent)
set(JSONCPP_WITH_TESTS OFF)
set(JSONCPP_WITH_POST_BUILD_UNITTEST OFF)
set(JSONCPP_WITH_EXAMPLE OFF)
set(BUILD_OBJECT_LIBS OFF)
set(BUILD_SHARED_LIBS OFF)

FetchContent_Declare(jsoncpp URL "https://github.com/open-source-parsers/jsoncpp/archive/refs/tags/1.9.6.tar.gz")


FetchContent_MakeAvailable(jsoncpp)

target_link_libraries(${PROJECT_NAME} PRIVATE jsoncpp_static)
