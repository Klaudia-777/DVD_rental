cmake_minimum_required(VERSION 3.12)
project(DVD_rental)

set(CMAKE_CXX_STANDARD 17)

add_executable(DVD_rental main.cpp RentalService.cpp RentalService.h MovieBase.cpp MovieBase.h DVD.cpp DVD.h movieGenre.h Status.h base.h)