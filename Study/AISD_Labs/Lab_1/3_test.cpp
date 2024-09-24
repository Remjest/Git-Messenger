#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

struct Node{
    char data;
    Node* next;
    Node(char val) : data(val), next(nullptr){}
};

class LinkedList {
public:
    Node* head;
    LinkedList(): head(nullptr) {}

    void append(char data) {
        Node* newNode = new Node(data);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* last = head;
        while (last->next) {
            last = last->next;
        }
        last->next = newNode;
    }

    bool find(char value) {
        Node* current = head;
        while (current) {
            if (current->data == value) {
                return true; // элемент найден
            }
            current = current->next;
        }
        return false; // элемент не найден
    }

    // Метод для отображения линейного списка
    void display() {
        Node* current = head;
        while (current) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "nullptr" << endl;
    }

    // Деструктор для освобождения памяти
    ~LinkedList() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

void getting_set(LinkedList *List){
    string input;
    cout << "Input Set:\n";
    getline(cin, input);
    for (char ch : input){
        (*List).append(ch);
    }

};

int main() {

    LinkedList AA;
    LinkedList BB;
    LinkedList CC;
    LinkedList DD;
    LinkedList EE;

    getting_set(&AA);
    getting_set(&BB);
    getting_set(&CC);
    getting_set(&DD);


    Node *currentA = AA.head;
    // Добавляем элементы из A, не находящиеся в B и C
    while (currentA) {
        if (!(BB.find(currentA->data) || CC.find(currentA->data))) {
            EE.append(currentA->data);
        }
        currentA = currentA->next;
    }

    Node *currentD = DD.head;
    // Добавляем элементы из D
    while (currentD) {
        if (!EE.find(currentD->data)) {
            EE.append(currentD->data);
        }
        currentD = currentD->next;
    }

    // Вывод результата
    Node *currentE = EE.head;
    std::cout << "Result set: ";
    while (currentE) {
        std::cout << currentE->data << ' ';
        currentE = currentE->next;
    }

    return 0;
}