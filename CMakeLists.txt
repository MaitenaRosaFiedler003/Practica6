cmake_minimum_required(VERSION 3.26)
project(P2)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(P2
        Coche.cpp
        Coche.h
        main.cpp
        Usuario.h
        Usuario.cpp
        Reanelcar.h
        Reanelcar.cpp
        PuntoRecarga.cpp
        PuntoRecarga.h
        Trayecto.cpp
        Trayecto.h
        Fecha.cpp
        Fecha.h
        Usuario.cpp
        ThashUsuario.h
        ThashUsuario.cpp)
