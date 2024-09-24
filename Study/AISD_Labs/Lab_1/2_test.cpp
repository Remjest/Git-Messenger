#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

void getting_set(set<char> *xSet){
    string input;
    cout << "Input Set:\n";
    getline(cin, input);
    for (char ch : input){
        (*xSet).insert(ch);
    }
};

int main() {

    std::set<char> A; // Множество A
    std::set<char> B;               // Множество B
    std::set<char> C;                    // Множество C
    std::set<char> D;          // Множество D

    getting_set(&A);
    getting_set(&B);
    getting_set(&C);
    getting_set(&D);

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