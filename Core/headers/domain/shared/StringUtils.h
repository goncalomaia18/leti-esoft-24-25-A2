#ifndef TASKS_STRINGUTILS_H
#define TASKS_STRINGUTILS_H

#include <string>

using namespace std;

class StringUtils {
public:
    static wstring toUpperCase(const wstring &value);

    static wstring toLowerCase(const wstring &value);

    static wstring leftTrim(const wstring &value);

    static wstring rightTrim(const wstring &value);

    static wstring trim(const wstring &value);

    static bool ensureNotNullOrEmpty(const wstring &value);

    static bool ensureNotNullOrEmpty(const wstring &value, int minLength);

    static string toString(const wstring &str);

    static wstring toWString(const string &str);
};

#endif //TASKS_STRINGUTILS_H