#ifndef LETI_ESOFT_24_25_A2_PUBLISH_AD_VIEW_H
#define LETI_ESOFT_24_25_A2_PUBLISH_AD_VIEW_H

#include <string>
#include <memory>
#include "PublishAdController.h"

class PublishAdView {
public:
    explicit PublishAdView(std::shared_ptr<PublishAdController> controller);
    void show();

private:
    std::shared_ptr<PublishAdController> controller;
};

#endif // LETI_ESOFT_24_25_A2_PUBLISH_AD_VIEW_H

