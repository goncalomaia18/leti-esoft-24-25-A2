#ifndef TASKS_UTILS_H
#define TASKS_UTILS_H

#include <iostream>
#include <optional>
#include <vector>

using namespace std;

class Utils {
private:
    //std::wostream out;
    //std::wistream in;
    bool isNumber(const wstring &value, bool acceptDecimal);

    wstring readNumber(const wstring &prompt, bool acceptDecimal);

public:
    Utils();

    wstring string2wstring(const string &str);

    void printEmptyLine();

    void printEmptyLines(int count);

    void printLine(const string &line);

    void printLines(const vector<string> &lines);

    void printLine(const wstring &line);

    void printLines(const vector<wstring> &lines);

    void readEnterToContinue();

    wstring readLine(const wstring &prompt);

    wstring readNonEmptyLine(const wstring &prompt);

    bool readBoolean(const wstring &prompt);

    int readInteger(const wstring &prompt);

    int readInteger(const wstring &prompt, int min, int max);

    double readDouble(const wstring &prompt);

    double readDouble(const wstring &prompt, double min, double max);

    optional<int> doSelection(const wstring &prompt, const vector<wstring> &options, bool cancel, const wstring &cancelMsg);
};

#endif //TASKS_UTILS_H