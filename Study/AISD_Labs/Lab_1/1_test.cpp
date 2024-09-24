#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    std::set<char> A = {'A', 'B', 'C', 'D', 'E'}; // Множество A
    std::set<char> B = {'B', 'D', 'F'};               // Множество B
    std::set<char> C = {'D','F', 'G', 'H'};                    // Множество C
    std::set<char> D = {'A', 'C', 'I'};          // Множество D

    std::set<char> result;

    // Добавляем элементы из A, не находящиеся в B и C
    for (const auto& ch : A) {
        if (!(B.find(ch) != B.end() || C.find(ch) != C.end())) {
            result.insert(ch);
        }
    }

    // Добавляем элементы из D
    result.insert(D.begin(), D.end());

    // Вывод результата
    std::cout << "Result set: ";
    for (const auto& ch : result) {
        std::cout << ch << ' ';
    }

    return 0;
}