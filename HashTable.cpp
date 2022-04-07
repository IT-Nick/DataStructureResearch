//
// Created by lenovo on 02.04.2022.
//

//#include "HashTable.h"

//Геометрические объекты. (точки, треугольники, параллелограммы и т.д.)
//Создавать, удалять фигуры. Сравнивать их площади (или объемы) выводить сведения

#include <iostream>
#include <cmath>

class GeometricObjects {
public:
    explicit GeometricObjects() {}
    virtual std::string Information() = 0;
    virtual double Square() = 0;
};

class Point : public GeometricObjects {
public:
    std::string Information() override {
        std::cout << "Point" << std::endl;
        return "Point";
    }

    double Square() override {
        return 0;
    }
};

class Triangle : public GeometricObjects {
public:
    explicit Triangle(double new_side1, double new_side2, double new_angle) : side1(new_side1), side2(new_side2), angle(new_angle) {}
    std::string Information() override {
        std::cout << "Triangle" << std::endl;
        return "Triangle";
    }

    double Square() override {
        return side1 * side2 * sin(angle) / 2;
    }

private:
    double side1;
    double side2;
    double angle;
};

class Rectangle : public GeometricObjects {
public:
    explicit Rectangle(double new_side1, double new_side2) : side1(new_side1), side2(new_side2) {}
    std::string Information() override {
        std::cout << "Rectangle" << std::endl;
        return "Rectangle";
    }

    double Square() override {
        return side1 * side2;
    }

private:
    double side1;
    double side2;
};

class Parallelogram : public GeometricObjects {
public:
    explicit Parallelogram(double new_side, double new_height) : side(new_side), height(new_height) {}
    std::string Information() override {
        std::cout << "Parallelogram" << std::endl;
        return "Parallelogram";
    }

    double Square() override {
        return side * height;
    }

private:
    double side;
    double height;
};

class ObjectsManipulation {
public:
    bool empty() {
        return first == nullptr;
    }

    void CreateObject(GeometricObjects& obj) {
        Node* p;
        if(obj.Information() == "Point") {
            Point new_obj;
            p = new Node(new_obj);
        }
        if(obj.Information() == "Triangle") {
            double side1, side2, angle;
            std::cin >> side1 >> side2 >> angle;
            Triangle new_obj(side1, side2, angle);
            p = new Node(new_obj);
        }
        if(obj.Information() == "Rectangle") {
            double side1, side2;
            std::cin >> side1 >> side2;
            Rectangle new_obj(side1, side2);
            p = new Node(new_obj);
        }
        if(obj.Information() == "Parallelogram") {
            double side, height;
            std::cin >> side >> height;
            Parallelogram new_obj(side, height);
            p = new Node(new_obj);
        }

        if(empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }

    void remove_first() {
        if (empty()) return;
        Node* p = first;
        first = p->next;
        delete p;
    }

    void remove_last() {
        if (empty()) return;
        if (first == last) {
            remove_first();
            return;
        }
        Node* p = first;
        while (p->next != last) p = p->next;
        p->next = nullptr;
        delete last;
        last = p;
    }

    void DeleteObject(GeometricObjects& obj) {
        if (empty()) return;
        if (first->object.Information() == obj.Information()) {
            remove_first();
            return;
        }
        else if (last->object.Information() == obj.Information()) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->object.Information() != obj.Information()) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            std::cout << "This element does not exist" << std::endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }
private:
    struct Node {
        GeometricObjects& object;
        Node* next;
        Node(GeometricObjects& new_object) : object(new_object) {}
    };
    Node* first;
    Node* last;
};

bool operator ==(GeometricObjects& go1, GeometricObjects& go2) {
    return go1.Square() == go2.Square();
}

int main() {
    Point p;
    Triangle t();
    ObjectsManipulation om;
    om.CreateObject(p);
    om.CreateObject(t);
    return 0;
}





/*

int main()
{
    setlocale(LC_ALL, "Russian");

    std::cout << "Нихао! Вы в программе для работы с геометрическими фигурами!\n\n";
    Spisok* s = new Spisok;
    int mode = 1;
    while (mode != 0)
    {
        std::cout << "\nВЫбрирай действие:\n1. Добавить фигуру \n2. Удалить фигуру \n3. Сравнить две фигуры \n4. Вывести все фигуры\n0. Выход \n ";
        std::cin >> mode;
        while ((mode != 1) and (mode != 2) and (mode != 3) and (mode != 0) and (mode != 4))
        {
            std::cout << "\n\n*ОШИБКА*\nПовторите ввод: ";
            std::cin >> mode;
        }

        if (mode == 1)
        {
            s->Add();
        }

        if (mode == 2)
        {
            s->Del();
        }

        if (mode == 3)
        {
            s->Srav();
        }
        if (mode == 4)
        {
            s->Print_s();
        }
    }

    delete s;
}
*/
