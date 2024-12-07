#ifndef PUBLISH_AD_VIEW_H
#define PUBLISH_AD_VIEW_H

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

#endif // PUBLISH_AD_VIEW_H

