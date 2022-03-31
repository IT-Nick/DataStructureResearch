#include <iostream>
//Дек. Добавление, удаление, и поиск узла.

using std::cout;
using std::endl;
using std::cin;

template<typename T>
class Deque {
private:
    struct Node {
        T value;
        Node* next;
        Node* prev;
        explicit Node(T new_value) : value(new_value), next(nullptr), prev(nullptr) {}
    };
    Node* first;
    Node* last;
    int dsize = 0;
public:
    Deque() : first(nullptr), last(nullptr) {}
    //deque<int> d(5); - 0 0 0 0 0
    explicit Deque(int size) : first(nullptr), last(nullptr) {
        for(size_t i = 0; i < size; i++) {
            push_back({});
        }
    }
    //deque<std::string> d(5, "hi"); - hi hi hi hi hi
    Deque(int size, T value) : first(nullptr), last(nullptr) {
        for(size_t i = 0; i < size; i++) {
            push_back(value);
        }
    }
    //deque<int> d = {1, 2, 3, 4, 5};
    //Закомментировал, в связи с использованием initializer_list<T>
    /*Deque(std::initializer_list<T> l) {
        first = new Node(*l.begin());
        last = nullptr;
        for(size_t i = 0; i < l.size(); i++) {
            push_back(*(l.begin() + i));
        }
    }*/
    //Возвращает значение по индексу
    T operator[] (int index) {
        Node* p = first;
        for(int i = 0; i < index; i++) {
            p = p->next;
        }
        return p->value;
    }
    //Возвращает размер дека
    int size() {
        return dsize;
    }
    //Возвращает true, если дек пуст, или false, если непуст
    bool empty() {
        return first == nullptr;
    }
    //Очищает дек
    void clear() {
        for(int i = 0; i < dsize; i++) pop_back();
        first = nullptr;
        last = nullptr;
    }
    //Возвращает значение первого элемента в деке
    T front() {
        return first->value;
    }
    //Возвращает значение последнего элемента в деке
    T back() {
        return last->value;
    }
    //Добавляет новый элемент элемент в начало дека
    void push_front(T value) {
        Node* p = new Node(value);
        dsize++;
        if(first == nullptr) {
            first = p;
            last = p;
            return;
        }
        first->prev = p;
        p->next = first;
        first = p;
    }
    //Добавляет новый элемент элемент в конец дека
    void push_back(T value) {
        Node* p = new Node(value);
        dsize++;
        if(last == nullptr) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        p->prev = last;
        last = p;
    }
    //Удаляет первый элемент из дека, не возвращает значение
    void pop_front() {
        if(empty()) {
            return;
        }
        if(dsize == 1) {
            first = nullptr;
            last = nullptr;
            dsize--;
            return;
        }
        dsize--;
        Node* p = first;
        first = p->next;
        first->prev = nullptr;
        delete p;
    }
    //Удаляет последний элемент из дека, не возвращает значение
    void pop_back() {
        if(empty()) {
            return;
        }
        if(dsize == 1) {
            first = nullptr;
            last = nullptr;
            dsize--;
            return;
        }
        dsize--;
        Node* p = last;
        last = p->prev;
        last->next = nullptr;
        delete p;
    }
    //Печатает дек в консоль
    void print() {
        if(empty()) {
            return;
        }
        cout << endl;
        Node* p = first;
        while(p != last) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << p->value;
    }
    //Удаляет элемент по позиции (индексу) в деке
    void erase(int index) {
        if(empty() || index > dsize || index < 0) {
            cout << "Deque is empty or (0 < index > size)" << endl;
            return;
        }
        Node* p = first;
        for(int i = 0; i < index; i++) {
            p = p->next;
        }
        if(p == first) {
            pop_front();
            return;
        }
        if(p == last) {
            pop_back();
            return;
        }
        Node* lsn = p->prev;
        Node* rsn = p->next;
        lsn->next = rsn;
        rsn->prev = lsn;
        dsize--;
        delete p;
    }
    //Ищет элемент по значению (возвращает адрес узла)
    Node* find(T value) {
        if(empty()) {
            return nullptr;
        }
        Node* p = first;
        while(p && p->value != value) {
            if(p->next == first) {
                p = nullptr;
                break;
            }
            p = p->next;
        }
        if(p) {
            return p;
        } else {
            cout << "Element does not exist." << endl;
            return nullptr;
        }
    }
};

int main() {
    //Deque<int> d = {1, 2, 3, 4, 5};
    Deque<std::string> d2;
    cout << d2.size() << endl;
    d2.push_back("1q");
    d2.push_back("2q");
    d2.push_back("3q");
    d2.push_back("4q");
    d2.push_back("5q");
    d2.push_back("6q");
    d2.print();
    cout << endl << d2.size() << " - size, " << d2.front() << " - first, " << d2.back() << " - last, " << d2.find("3q")->value << " find 9q";
    cout << endl << d2[0] << " " << d2[1] << " " << d2[2] << " " << d2[3] << " " << d2[4] << " " << d2[5] << " ";
    cout << endl << d2.size() << endl;
    d2.clear();
    cout << endl << d2.size() << endl;
    d2.print();
    //cout << endl << d2.size();
    int counter = 100;
/*
    while (--counter) {
        cout << "Введите число: 1 - Добавить в конец, "
                "2 - Добавить в начало "
                "3 - Вывести, "
                "4 - удалить,"
                "5 - поиск" << endl;
        int cmd = 0;// i > 0
        cin >> cmd;
        if (cmd == 1) {
            cout << "Введите число, которое хотите добавить в конец: " << endl;
            int i = 0;
            cin >> i;
            l.push_back(i);
        } else if (cmd == 2) {
            cout << "Введите число, которое хотите добавить в начало: " << endl;
            int i = 0;
            cin >> i;
            l.push_front(i);
        } else if (cmd == 3) {
            l.print();
        } else if (cmd == 4) {
            cout << "Введите позицию, которую хотите удалить: " << endl;
            int i = 0;
            cin >> i;
            l.erase(i);
        } else if (cmd == 5) {
            cout << "Введите значение, которое хотите найти: " << endl;

            int i = 0;
            cin >> i;
            cout << l.find(i);
        }
        cout << endl;
    }
    */
    return 0;
}