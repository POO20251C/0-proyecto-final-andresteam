cmake_minimum_required(VERSION 3.30)
project(0_proyecto_final_andresteam)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(0_proyecto_final_andresteam
    Enemigo.cpp
    Enemigo.h
    Heroe.cpp
    Heroe.h
    Item.cpp
    Item.h
    main.cpp
    Mazmorra.cpp
    Mazmorra.h
    Personaje.cpp
    Personaje.h
    Sala.cpp
    Sala.h
    Score.cpp
    Score.h
    ScoreManager.cpp
    ScoreManager.h)
