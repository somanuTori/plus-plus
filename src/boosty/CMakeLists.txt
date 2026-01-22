cmake_minimum_required(VERSION 3.25)
project(BoostyProject)

# 1. Пригнічуємо попередження про застарілий FindBoost
cmake_policy(SET CMP0167 NEW)
# 2. Дозволяємо використовувати Boost_ROOT
cmake_policy(SET CMP0144 NEW)

# 3. Шукаємо Boost.
# Оскільки ви встановили його в /usr/local, він знайдеться сам.

find_package(Boost 1.90.0 REQUIRED CONFIG)
add_executable(BoostyProject src/boosty/example.cpp)

# 4. Лінкуємо хедери
target_link_libraries(BoostyProject Boost::headers)


