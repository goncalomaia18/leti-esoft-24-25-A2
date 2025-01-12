#include <string>
#include <unordered_set>

class StoreController {
public:
    std::string registerStore(const std::string& storeData);

private:
    bool isValidStoreCode(const std::string& code);
    bool isValidTime(const std::string& time);
    std::string processSingleStore(const std::string& storeData);

    static std::unordered_set<std::string> storeCodes;
};
