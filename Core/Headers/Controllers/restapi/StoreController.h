#ifndef STORECONTROLLER_H
#define STORECONTROLLER_H
//teste
#include <string>
#include <unordered_set>

class StoreController {
private:
    std::unordered_set<std::string> storeCodes; // To store unique store codes

    bool isValidStoreCode(const std::string& code);
    bool isValidTime(const std::string& time);
    std::string getFieldValue(const std::string& data, const std::string& fieldName);

public:
    std::string registerStore(const std::string& storeData);
};

#endif // STORECONTROLLER_H
