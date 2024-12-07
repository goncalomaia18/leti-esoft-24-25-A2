cmake_minimum_required(VERSION 3.20)
project(leti-esoft-24-25-A2)
project(DHMS)

add_executable(leti-esoft-24-25-A2 main.cpp
        Sources/BookingController.cpp
        headers/BookingController.h
        Sources/BookingService.cpp
        Sources/BookingView.cpp
        Sources/VisitRequest.cpp
        headers/BookingService.h
        headers/BookingView.h
        headers/VisitRequest.h
        )

