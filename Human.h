#pragma once

#include <string>
using namespace std;

// Класс для объекта "Человек"
class Human {
private:

    string firstName;   // Имя
    string lastName;    // Фамилия

public:

    // Конструктор без параметров
    Human();
    // Контруктор с параметрами
    Human(string first, string last);
    // Деструктор
    ~Human();

    // Сеттеры для класса
    void setFirstName(string firstName);
    void setLastName(string lastName);

    // Геттеры для класса
    const string getFirstName();
    const string getLastName();
};

