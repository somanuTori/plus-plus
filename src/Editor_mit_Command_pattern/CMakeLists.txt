cmake_minimum_required(VERSION 3.15)
project(text_editor_core LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(include
    include/Document.hpp
    include/Command.hpp
    include/CommandScheduler.hpp
    include/InsertTextCommand.hpp
    include/EraseTextCommand.hpp
    include/ReplaceTextCommand.hpp
)

add_executable(Com_patt_editor
    src/Editor_mit_Command_pattern/main.cpp
    ${INCLUDE}
)

target_include_directories(Com_patt_editor PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
