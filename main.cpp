#include <iostream>
//Дек. Добавление, удаление, и поиск узла.

/*
size()	Возвращает размер дека
empty()	Возвращает true, если дек пуста, или false, если непуст
clear()	Очищает дек
front()	Возвращает значение первого элемента в деке
back()	Возвращает значение последнего элемента в деке
pop_front()	Удаляет первый элемент из дека, не возвращает значение
pop_back()	Удаляет последний элемент из дека, не возвращает значение
push_front(elem)	Добавляет новый элемент elem в начало дека
push_back(elem)	Добавляет новый элемент elem в конец дека
 */

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
        Node(T new_value) : value(new_value), next(nullptr), prev(nullptr) {}
    };
    Node* first;
    Node* last;
public:
    Deque() : first(nullptr), last(nullptr) {}

    explicit Deque(int size) : first(nullptr), last(nullptr) {
        for(size_t i = 0; i < size; i++) {
            push_back({});
        }
    }

    Deque(int size, T value) : first(nullptr), last(nullptr) {
        for(size_t i = 0; i < size; i++) {
            push_back(value);
        }
    }

    Deque(std::initializer_list<T> l) {
        first = new Node(*l.begin());
        last = nullptr;
        for(size_t i = 0; i < l.size(); i++) {
            push_back(*(l.begin() + i));
        }
    }

    Deque(Node* begin, Node* end) {
        for(auto i = first; i != last; i->next) {
            push_back(i->value);
        }
    }

    //Возвращает размер дека
    size_t size() {
        return 5;
    }

    //Возвращает true, если дек пуст, или false, если непуст
    bool empty() {
        return first == nullptr;
    }
    void push_back(T value) {
        Node* p = new Node(value);

        if(last == nullptr) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        p->prev = last;
        last = p;
        first->prev = last;
        last->next = first;
    }
    void push_front(T value) {
        Node* p = new Node(value);
        if(first == nullptr) {
            first = p;
            last = p;
            return;
        }
        first->prev = p;
        p->next = first;
        first = p;
        first->prev = last;
        last->next = first;
    }
    void print() {
        if(empty()) {// проверка на пустоту
            cout << "Элементов нет";
            return;
        }
        Node* p = first;
        while(p != last) {
            cout << p->value << " ";// вывод значения
            p = p->next;
        }
        cout << p->value;
    }
    void erase(int index) { // удаление
        if(empty()) {// проверка
            return;
        }
        Node* p = first;
        for(int i = 0; i < index; i++) {
            p = p->next;
        }
        if(p == first) {
            first = p->next;
            delete p;
            return;
        }
        if(p == last) {
            while(p->next != last) p = p->next;
            p->next = first;
            delete last;
            last = p;
            return;
        }
        Node* prevP = p->prev;
        Node* nextP = p->next;
        prevP->next = nextP;
        nextP->prev = prevP;
        delete p;
    }
    Node* find(T value) {
        if(empty()) {
            return nullptr;
        }
        Node* p = first;
        while(p && p->value != value) {
            if(p->next == first) { //
                p = nullptr;
                break;
            }
            p = p->next;
        }
        if(p) {
            return p;
        } else {
            cout << "Элемент не найден." << endl;
            return nullptr;
        }
    }
    Node* begin() {
        return first;
    }
    Node* end() {
        return last;
    }

};

int main() {
    Deque<int> d = {1, 2, 3, 4, 5};
    d.print();
    cout << endl;
    Deque<int> d2(d.begin(), d.end());
    d2.print();
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