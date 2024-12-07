cmake_minimum_required(VERSION 3.20)
project(leti-esoft-24-25-A2)
project(DHMS)

add_executable(leti-esoft-24-25-A2 main.cpp
        Sources/
        headers/
        headers/Property.h
        headers/Advertisement.h
        headers/DisplayListedPropertiesController.h
        headers/DisplayListedPropertiesService.h
        headers/DisplayListedPropertiesView.h
        headers/Lease.h
        headers/PublishAdView.h
        headers/PublishAdController.h
        headers/ListingRepository.h
        headers/Sale.h
        headers/PropertyContainer.h
        headers/BookingController.h
        Sources/BookingController.cpp
        headers/Listing.h
        Sources/VisitRequest.cpp
        headers/BookingService.h
        headers/BookingView.h
        headers/VisitRequest.h
        Sources/Advertisement.cpp
        Sources/DisplayListedPropertiesController.cpp
        Sources/DisplayListedPropertiesService.cpp
        Sources/DisplayListedPropertiesView.cpp
        Sources/Lease.cpp
        Sources/Listing.cpp
        Sources/ListingRepository.cpp
        Sources/Property.cpp
        Sources/PropertyContainer.cpp
        Sources/PublishAdController.cpp
        Sources/PublishAdView.cpp
        Sources/Sale.cpp
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


