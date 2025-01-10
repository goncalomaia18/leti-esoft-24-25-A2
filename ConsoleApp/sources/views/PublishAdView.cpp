#include "../headers/PublishAdView.h"
#include <iostream>

PublishAdView::PublishAdView(std::shared_ptr<PublishAdController> controller)
    : controller(controller) {}

void PublishAdView::show() {
    std::cout << "Fetching unpublished properties...\n";
    auto properties = controller->getUnpublishedProperties();

    if (properties.empty()) {
        std::cout << "No unpublished properties available for publication.\n";
        return;
    }

    std::cout << "Select a property to publish:\n";
    for (size_t i = 0; i < properties.size(); ++i) {
        std::cout << i + 1 << ". " << properties[i]->getDescription() << "\n";
    }

    size_t choice;
    std::cin >> choice;
    if (choice < 1 || choice > properties.size()) {
        std::cout << "Invalid choice.\n";
        return;
    }

    auto selectedProperty = properties[choice - 1];
    controller->publishProperty(selectedProperty->getId());
    std::cout << "Property published successfully.\n";
}

