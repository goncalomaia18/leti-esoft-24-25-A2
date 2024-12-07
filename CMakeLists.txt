cmake_minimum_required(VERSION 3.20)
project(leti-esoft-24-25-A2)
project(DHMS)

add_executable(leti-esoft-24-25-A2 main.cpp
        Sources/
        headers/
        headers/Property.h
        headers/PropertyContainer.h
        headers/BookingController.h
        Sources/BookingController.cpp
        headers/Listing.h
        Sources/VisitRequest.cpp
        Sources/PublishAdView.cpp
        Sources/PublishAdController.cpp
        Sources/PropertyContainer.cpp
        Sources/Property.cpp
        Sources/BookingView.cpp
        Sources/BookingService.cpp
        Sources/Client.cpp
        headers/Client.h
        headers/RealEstateAgent.h
        Sources/RealEstateAgent.cpp
        Sources/Listing.cpp
        headers/Visit.h
        sources/Visit.cpp
)

