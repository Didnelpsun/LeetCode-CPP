#include "./test/1-twoSum-test.cpp"
#include <windows.h> // SetConsoleOutputCP函数所在库函数，让cmd程序的编码更为utf-8

int main() {
    SetConsoleOutputCP(65001);
    test_1();
    return 0;
}