#include "../../../Headers/Infrastructure/infrastructure/memory/ListingRepository.h"
#include <algorithm>
#include <iostream>

class InMemoryListingRepository : public ListingRepository {
private:
    std::vector<Listing> listings;

public:
    // Método para obter todas as listagens
    std::vector<Listing> getListings() override {
        return listings; // Retorna todas as listagens armazenadas
    }

    // Método para filtrar listagens com base em critérios específicos
    std::vector<Listing> getFilteredListings(const std::string& criteria) override {
        std::vector<Listing> filteredListings;
        for (const auto& listing : listings) {
            // Suponhamos que o critério seja baseado no título ou tipo da listagem
            if (listing.getTitle().find(criteria) != std::string::npos ||
                listing.getBusinessType().find(criteria) != std::string::npos) {
                filteredListings.push_back(listing);
            }
        }
        return filteredListings;
    }

    // Método para salvar uma nova listagem
    void saveListing(const Listing& listing) override {
        listings.push_back(listing); // Simulando um salvamento em memória
        std::cout << "Listing saved: " << listing.getTitle() << std::endl;
    }

    // Opcional: Construtor e destruidor
    InMemoryListingRepository() = default;
    ~InMemoryListingRepository() = default;
};
//
// Created by pedro on 07/12/2024.
//
