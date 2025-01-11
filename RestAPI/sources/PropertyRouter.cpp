#include "../headers/PropertyRouter.h"
#include <headers/controllers/restapi/HttpResult.h>
#include <../RestAPI/headers/PropertyRouter.h>
#include <headers/domain/shared/StringUtils.h>

PropertyRouter::PropertyRouter() : RouterConfig("/categories") {
}

void PropertyRouter::configure(httplib::Server &svr) {
    string patternBase = this->baseResource + "(\\/?)";
    string patternBaseWithId = this->baseResource + "/(\\w+)";

    svr.Get(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            PropertyController ctrl(extractBearerToken(req));
            try {
                result = ctrl.getAll();
            }
            catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Get(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            PropertyController ctrl(extractBearerToken(req));
            try {
                result = ctrl.getById(StringUtils::toWString(req.matches[1]));
            }
            catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Put(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            PropertyController ctrl(extractBearerToken(req));
            try {
                auto jsonObj = JSON::Load(req.body);
                wstring code = StringUtils::toWString(jsonObj["code"].ToString());
                wstring description = StringUtils::toWString(jsonObj["description"].ToString());
                if (StringUtils::toWString(req.matches[1]) == code)
                    result = ctrl.putCategory(code, description);
                else {
                    result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                    result.setResult("Category Code on Body does not match the one on the URL.");
                }
            }
            catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Post(patternBase, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            CategoryController ctrl(extractBearerToken(req));
            try {
                auto jsonObj = JSON::Load(req.body);
                wstring code = StringUtils::toWString(jsonObj["code"].ToString());
                wstring description = StringUtils::toWString(jsonObj["description"].ToString());
                result = ctrl.postCategory(code, description);
            }
            catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_BAD_REQUEST);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });

    svr.Delete(patternBaseWithId, [&](const httplib::Request &req, httplib::Response &res) {
        HttpResult result;
        try {
            CategoryController ctrl(extractBearerToken(req));
            try {
                result = ctrl.deleteCategory(StringUtils::toWString(req.matches[1]));
            }
            catch (exception e) {
                result.setHttpStatus(HttpStatus::HTTP_SERVER_ERROR);
                result.setResult(e.what());
            }
        }
        catch (invalid_argument e) {
            result.setHttpStatus(HttpStatus::HTTP_CLIENT_ERROR_NOT_AUTH);
        }
        setHttpResponse(res, result);
    });
}