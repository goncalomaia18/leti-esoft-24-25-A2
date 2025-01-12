#include "../headers/RouterConfig.h"
#include <headers/domain/shared/StringUtils.h>

RouterConfig::RouterConfig(const string &baseResource) {
    this->baseResource = baseResource;
    if (!this->baseResource.empty() && this->baseResource.back() == '/') {
        this->baseResource.pop_back(); // Remove trailing slash
    }
}

void RouterConfig::setHttpResponse(httplib::Response &res, HttpResult &result) {
    res.status = result.getHttpStatus();
    res.set_content(result.getResult().dump(), "application/json");
}

std::wstring RouterConfig::extractBearerToken(const httplib::Request &req) {
    string token = req.get_header_value("Authorization");
    return StringUtils::toWString(token);
}