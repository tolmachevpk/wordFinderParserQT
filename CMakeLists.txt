cmake_minimum_required(VERSION 3.19)
project(WordParserFinderQT)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(QT_VERSION 5)
set(REQUIRED_LIBS Core)
set(REQUIRED_LIBS_QUALIFIED Qt5::Core)
find_package(Qt5Widgets REQUIRED)

add_executable(${PROJECT_NAME} Sources/main.cpp Headers/trie.h Sources/trie.cpp Headers/structTrie.h Headers/parser.h Sources/parser.cpp Headers/ahoKorasik.h Sources/ahoKorasik.cpp Headers/mainWindow.h Sources/mainWindow.cpp Headers/lookForMatchesThread.h Sources/lookForMatchesThread.cpp)

if (NOT CMAKE_PREFIX_PATH)
    message(WARNING "CMAKE_PREFIX_PATH is not defined, you may need to set it "
            "(-DCMAKE_PREFIX_PATH=\"path/to/Qt/lib/cmake\" or -DCMAKE_PREFIX_PATH=/usr/include/{host}/qt{version}/ on Ubuntu)")
endif ()

target_link_libraries(${PROJECT_NAME} Qt5::Widgets)
