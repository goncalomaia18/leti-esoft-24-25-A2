#ifndef DREAMHOUSE_HTTPRESULT_H
#define DREAMHOUSE_HTTPRESULT_H

#include <string>
#include <thirdparty/SimpleJson.hpp>

#include "../../../../Core/thirdparty/SimpleJSON/json.hpp"

class HttpResult {
private:
    int httpStatus;
    json::JSON result;

public:
    // Common HTTP Status Codes
    static const int HTTP_OK = 200;
    static const int HTTP_CREATED = 201;
    static const int HTTP_NO_CONTENT = 204;
    static const int HTTP_BAD_REQUEST = 400;
    static const int HTTP_UNAUTHORIZED = 401;
    static const int HTTP_FORBIDDEN = 403;
    static const int HTTP_NOT_FOUND = 404;
    static const int HTTP_SERVER_ERROR = 500;

    explicit HttpResult(int httpStatus) : httpStatus(httpStatus) {
        result = json::Object();
    }

    HttpResult(int httpStatus, const std::string& message) : httpStatus(httpStatus) {
        result = json::Object();
        result["message"] = message;
    }

    HttpResult(int httpStatus, const json::JSON& jsonResult) 
        : httpStatus(httpStatus), result(jsonResult) {}

    int getHttpStatus() const { return httpStatus; }
    
    json::JSON getResult() const { return result; }

    void setResult(const json::JSON& jsonResult) {
        result = jsonResult;
    }

    void addToResult(const std::string& key, const json::JSON& value) {
        result[key] = value;
    }
};

#endif 