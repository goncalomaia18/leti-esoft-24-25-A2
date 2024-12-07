#include <iostream>

using namespace std;

int main() {
    locale::global(locale(""));
    wcout.imbue(locale());

    wcout << L"Hello, World!" << std::endl;

    return 0;
}