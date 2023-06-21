cmake_minimum_required(VERSION 3.20)
project(chatbot)

set(CMAKE_CXX_STANDARD 20)

add_executable(chatbot main.cpp Message.cpp Behavior.cpp User.cpp Bot.cpp NotImplementedException.cpp
        RegexpValidator.cpp sortingUtils.cpp)
