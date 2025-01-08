cmake_minimum_required(VERSION 3.20)
project(leti-esoft-24-25-A2)

add_executable(leti-esoft-24-25-A2 main.cpp
        headers/
        sources/
        headers/models/Property.h
        headers/models/Advertisement.h
        headers/DisplayListedPropertiesView.h
        headers/models/Lease.h
        headers/PublishAdView.h
        headers/ListingRepository.h
        headers/models/Sale.h
        headers/PropertyContainer.h
        headers/models/Listing.h
        headers/models/BookingService.h
        headers/BookingView.h
        headers/models/VisitRequest.h
        sources/DisplayListedPropertiesView.cpp
        sources/ListingRepository.cpp
        sources/PropertyContainer.cpp
        sources/PublishAdView.cpp
        sources/BookingView.cpp
        headers/models/Client.h
        headers/models/RealEstateAgent.h
        headers/models/Visit.h
)
