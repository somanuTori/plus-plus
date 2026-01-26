cmake_minimum_required(VERSION 3.25)
project(BoostyProject)

cmake_policy(SET CMP0167 NEW)
# Boost_ROOT
cmake_policy(SET CMP0144 NEW)


find_package(Boost 1.90.0 REQUIRED CONFIG)
add_executable(BoostyProject src/boosty/example.cpp)

# Лінкуємо хедери
target_link_libraries(BoostyProject Boost::headers)


