#include <iostream>

using namespace std;

struct Node {
    int value;
    Node* next;
    Node* prev;
    Node(int new_value) {
        value = new_value;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyList {
private:
    Node* head;
    Node* tail;
public:
    DoublyList() {
        head = nullptr;
        tail = nullptr;
    }

    bool empty() {
        return head == nullptr;
    }

    void push(int value) {
        Node* p = new Node(value);
        if(tail == nullptr) {
            head = p;
            tail = p;
            return;
        }
        tail->next = p;
        p->prev = tail;
        tail = p;

        p->next = head;
        head->prev = tail;
    }

    void print() {
        if(empty()) {
            cout << endl << "Элементов нет" << endl;
            return;
        }
        cout << endl;
        Node* p = head;
        while(p != tail) {
            cout << p->value << " ";
            p = p->next;
        }
        cout << p->value;
    }

    void pop(int index) {
        Node* p = head;
        for(int i = 0; i < index; i++) {
            p = p->next;
        }
        if(p == head) {
            head = p->next;
            head->prev = tail;
            delete p;
            return;
        }
        if(p == tail) {
            tail = p->prev;
            tail->next = head;
            delete p;
            return;
        }
        Node* ls = p->prev;
        Node* rs = p->next;
        ls->next = rs;
        rs->prev = ls;
        delete p;
    }

    Node* find(int value) {
        if(empty()) {
            cout << "Элементов нет" << endl;
            return nullptr;
        }
        Node* p = head;
        while(p && p->value != value) {
            if(p->next == head) {
                p = nullptr;
                break;
            }
            p = p->next;
        }
        if(p) {
            return p;
        } else {
            cout << "Элемент не найден" << endl;
            return nullptr;
        }
    }

    int operator[] (int index) {
        Node* p = head;
        for(int i = 0; i < index; i++) {
            p = p->next;
        }
        return p->value;
    }

};

int main() {
    DoublyList dl;
    int a = 100;
    while (a--) {
        cout << "Введите команду: 1 - push, 2 - pop, 3 - find, 4 - print, " << endl;
        int cmd = 0;
        cin >> cmd;
        int i = 0;
        if(cmd == 1) {
            cin >> i;
            dl.push(i);
        } else if(cmd == 2) {
            cin >> i;
            dl.pop(i);
        } else if(cmd == 3) {
            cin >> i;
            dl.find(i);
        } else if(cmd == 4) {
            dl.print();
        }
        cout << endl;
    }
    return 0;
}