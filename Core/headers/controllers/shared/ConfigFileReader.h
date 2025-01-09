//
// Based on https://rosettacode.org/wiki/Read_a_configuration_file#C.2B.2B
// Based on https://www.cplusplus.com/forum/general/266880/
//

#ifndef TASKS_CONFIGFILEREADER_H
#define TASKS_CONFIGFILEREADER_H

#include <iostream>
#include <iomanip>
#include <string>
#include <exception>
#include <fstream>
#include <algorithm>
#include <wchar.h>

using namespace std;

struct ConfigObject {
    wstring personName;
    wstring persistenceMode;
};

class ConfigFileReader {
private:
    wstring string2wstring(const string &str) {
        wstring result(&str[0], &str[str.size()]);
        return result;
    };

public:
    ConfigFileReader() {};

    ConfigObject getDefault() {
        ConfigObject out;
        out.personName = L"Joe";
        out.persistenceMode = L"LIST";

        return out;
    };

    ConfigObject read_config(string fileName) {
        ConfigObject out = this->getDefault();

        std::string str;
        // std::ifstream is RAII, i.e. no need to call close
        std::ifstream cFile(fileName);
        if (cFile.is_open()) {
            while (!cFile.eof()) {
                while (getline(cFile, str)) {
                    std::string::size_type begin = str.find_first_not_of(" \f\t\v");
                    //Skips blank lines
                    if (begin == std::string::npos)
                        continue;
                    //Skips #
                    if (std::string("#").find(str[begin]) != std::string::npos)
                        continue;
                    std::string firstWord;
                    try {
                        firstWord = str.substr(0, str.find(" "));
                    }
                    catch (std::exception &e) {
                        firstWord = str.erase(str.find_first_of(" "), str.find_first_not_of(" "));
                    }
                    std::transform(firstWord.begin(), firstWord.end(), firstWord.begin(), ::toupper);
                    if (firstWord == "PERSON_NAME")
                        out.personName = string2wstring(str.substr(str.find(" ") + 1, str.length()));
                    if (firstWord == "PERSISTENCE_MODE")
                        out.persistenceMode = string2wstring(str.substr(str.find(" ") + 1, str.length()));
                }
            }
        }
        return out;
    }
};

#endif //TASKS_CONFIGFILEREADER_H