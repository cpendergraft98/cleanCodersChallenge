set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_AUTOMOC ON)

cmake_minimum_required(VERSION 3.14)

project(TicTacToe)

set(CMAKE_CXX_STANDARD 17)

# Find QT Modules
find_package(Qt6 REQUIRED COMPONENTS Widgets)

# Process the .ui file
qt6_wrap_ui(GENERATED_HEADERS gui/mainwindow.ui gui/endwindow.ui gui/startwindow.ui)

# Define the executable
add_executable(TicTacToe
    gui/main.cpp
    gui/mainwindow.cpp
    gui/endwindow.cpp
    gui/startwindow.cpp
    src/ticTacToe.cpp
    ${GENERATED_HEADERS}
)

# Include source directories
target_include_directories(TicTacToe
    PRIVATE
        src
        gui
        ${CMAKE_BINARY_DIR}
)

# Link the executable to Qt libraries
target_link_libraries(TicTacToe Qt6::Widgets)
