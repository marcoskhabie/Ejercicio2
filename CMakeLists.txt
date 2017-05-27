cmake_minimum_required(VERSION 3.6)
project(Ejercicio2)

set(CMAKE_C_STANDARD 90)

set(SOURCE_FILES main.c Market.c Market.h Product.c Product.h RegisteredUser.c RegisteredUser.h Provider.c Provider.h Factory.c Factory.h Sale.c Sale.h SaleLine.c SaleLine.h)
add_executable(Ejercicio2 ${SOURCE_FILES})