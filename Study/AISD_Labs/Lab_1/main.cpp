#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <bitset>
#include <chrono>

const int SHIFT = 65;
const int ONE = 1;

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
            if (current->data == value) return true;
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

    void bubbleSort() {
        if (head == nullptr || head->next == nullptr) {
            return;
        }

        bool swapped;
        Node* last = nullptr;
        do {
            swapped = false;
            Node* current = head;
            while (current->next != last) {
                if (current->data > current->next->data) {
                    std::swap(current->data, current->next->data);
                    swapped = true;
                }
                current = current->next;
            }
            last = current;
        } while (swapped);
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

void rand_array(char arr[], int size) {
    char letters[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    random_device rd;
    mt19937 g(rd());
    shuffle(letters, letters + 26, g); // Перемешиваем массив

    for (int i = 0; i < size; i++) {
        arr[i] = letters[i % 26]; // Заполняем только нужное количество элементов
        cout << arr[i] << " ";
//        cout << arr[i];
    }
    arr[size] = '\0';
    cout << "\n";
}

void getting_list(char arr[], LinkedList* list_by_vector, int size) {
    for (int i = 0; i < size; i++) {
        (*list_by_vector).append(arr[i]);
    }
    (*list_by_vector).display();
}

void getting_bool(const char arr[], bool* universum) {
    for (size_t i = 0;  arr[i]; ++i) {
        universum[(int)arr[i] - SHIFT] = true;
    }
    for (int i = 0; i < 26; i++){
        cout << universum[i] << ' ';
    }

    cout << "\n";
}

int getting_machine_word(const char arr[]) {
    int word = 0;
    for (size_t i = 0; arr[i]; ++i) {
        word = word | ONE << (arr[i] - SHIFT);
    }
    bitset<sizeof(int) * 8> binary(word);
    cout << binary << '\n';
    return word;
}


int logical_processing_arr(int size, char A[], char B[], char C[], char D[], char E[]){
    int j = 0;
    // Добавляем элементы из A, не находящиеся в B и C
    for (int i = 0; A[i]; i++) {
        if (!(find(B,B+size,A[i]) != (B+size) || find(C,C+size,A[i]) != (C+size))) {
            E[j] = A[i];
            j++;
        }
    }

    // Добавляем элементы из D
    for (int i = 0; D[i]; i++) {
        if (find(E,E+size,D[i]) == (E+size)){
            E[j] = D[i];
            j++;
        }
    }
    E[j] = '\0';
    return j;
}

void logical_processing_li(LinkedList* A, LinkedList* B, LinkedList* C, LinkedList* D, LinkedList* E){
    Node *currentA = (*A).head;
    // Добавляем элементы из A, не находящиеся в B и C
    while (currentA) {
        if (!((*B).find(currentA->data) || (*C).find(currentA->data))) {
            (*E).append(currentA->data);
        }
        currentA = currentA->next;
    }

    Node *currentD = (*D).head;
    // Добавляем элементы из D
    while (currentD) {
        if (!(*E).find(currentD->data)) {
            (*E).append(currentD->data);
        }
        currentD = currentD->next;
    }
}

void logical_processing_bool(const bool* A,const bool* B,const bool* C,const bool* D, bool* E) {
    for (size_t i = 0; i < 26; i++) {
        E[i] = A[i] && !(B[i] || C[i]) || D[i];
    }
}

void logical_processing_machine(int A, int B, int C, int D, int& E){
    E = A & ~(B | C) | D;
}

char convert_from_universum(bool element, int i){
    if (element) {
        return char(i + SHIFT);
    } else { return 0; }
}



int main() {
    int size;

    char arr_A[26];
    char arr_B[26];
    char arr_C[26];
    char arr_D[26];
    char arr_E[26];

    LinkedList li_A;
    LinkedList li_B;
    LinkedList li_C;
    LinkedList li_D;
    LinkedList li_E;

    bool bool_A[26] = {false};
    bool bool_B[26] = {false};
    bool bool_C[26] = {false};
    bool bool_D[26] = {false};
    bool bool_E[26] = {false};

    int Mword_A = 0;
    int Mword_B = 0;
    int Mword_C = 0;
    int Mword_D = 0;
    int Mword_E = 0;

    cout << "Enter the power of the arrays:\n";
    cin >> size;
    while (size > 26) {
        cout << "The size of the array cannot be more than 26, since there are only 26 uppercase Latin letters. Try again:\n";
        cin >> size;
    }

        cout << "Creating arrays with random letters:\n";
        rand_array(arr_A,size);
        rand_array(arr_B,size);
        rand_array(arr_C,size);
        rand_array(arr_D,size);

        cout << "Creating lists by arrays:\n";
        getting_list(arr_A, &li_A, size);
        getting_list(arr_B, &li_B, size);
        getting_list(arr_C, &li_C, size);
        getting_list(arr_D, &li_D, size);

        cout << "Creating universums by arrays:\n";
        getting_bool(arr_A, bool_A);
        getting_bool(arr_B, bool_B);
        getting_bool(arr_C, bool_C);
        getting_bool(arr_D, bool_D);

        cout << "Creating machine words by arrays:\n";
        Mword_A = getting_machine_word(arr_A);
        Mword_B = getting_machine_word(arr_B);
        Mword_C = getting_machine_word(arr_C);
        Mword_D = getting_machine_word(arr_D);

        auto t1_arr = chrono::high_resolution_clock::now( );
        int result_size = logical_processing_arr(size,arr_A,arr_B,arr_C,arr_D,arr_E);
        auto t2_arr = chrono::high_resolution_clock::now( );
        auto time_arr = chrono::duration_cast<chrono::duration<double, micro>>(t2_arr - t1_arr).count();

    sort(arr_E, arr_E + result_size);
    cout << "The result of processing the array: \t Execution time: " << time_arr << "\n";
    for (int i = 0; arr_E[i]; i++){
        cout << arr_E[i] << ' ';
    }

        auto t1_li = chrono::high_resolution_clock::now( );
        logical_processing_li(&li_A, &li_B, &li_C, &li_D, &li_E);
    auto t2_li = chrono::high_resolution_clock::now( );
    auto time_li = chrono::duration_cast<chrono::duration<double, micro>>(t2_li - t1_li).count();

    li_E.bubbleSort();
    Node *currentE = li_E.head;
    cout << "\nThe result of processing the list: \t Execution time: " << time_li << "\n";
    while (currentE) {
        std::cout << currentE->data << ' ';
        currentE = currentE->next;
    }

    auto t1_bool = chrono::high_resolution_clock::now( );
        logical_processing_bool(bool_A, bool_B, bool_C, bool_D, bool_E);
    auto t2_bool = chrono::high_resolution_clock::now( );
    auto time_bool = chrono::duration_cast<chrono::duration<double, micro>>(t2_bool - t1_bool).count();

    cout << "\nThe result of processing the universum: \t Execution time: " << time_bool << "\n";
    for (int i = 0; i < 26; i++) {
        if (bool_E[i]){
            cout << convert_from_universum(bool_E[i], i) << ' ';
        }
    }

    auto t1_mword = chrono::high_resolution_clock::now( );
        logical_processing_machine(Mword_A,Mword_B,Mword_C,Mword_D,Mword_E);
    auto t2_mword = chrono::high_resolution_clock::now( );
    auto time_mword = chrono::duration_cast<chrono::duration<double, micro>>(t2_mword - t1_mword).count();

    cout << "\nThe result of processing the machine word: \t Execution time: " << time_mword << "\n";
    for (int i = 0; i < sizeof(int)*8; ++i) {
        if (Mword_E & 1 << i) {
            cout << (unsigned char)(i + SHIFT) << ' ';
        }
    }


//    cout << "Execution time for arrays: " << (double)time_arr / CLK_TCK / iteration<< "\n";
//    cout << "Execution time for lists: " << (double)time_li / CLK_TCK / iteration<< "\n";
//    cout << "Execution time for universums: " << (double)time_bool / CLK_TCK / iteration<< "\n";
//    cout << "Execution time for machine words: " << (double)time_mword / CLK_TCK / iteration<< "\n";

    return 0;
}