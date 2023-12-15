#pragma once

#include "Human.h"
#include <string>
#include <iostream>
using namespace std;

// Класс для объекта "Сотрудник магазина"
class Employee : public Human {
private:

    Human person;       // Используем класс Human для представления сотрудника
    string position;    // Должность
    float salary;       // Зарплата

public:

    // Контруктор без параметров
    Employee();
    // Контруктор с параметрами
    Employee(string first, string last, string pos, float sal);
    // Деструктор
    ~Employee();

    // Метод для вывода информации о сотруднике
    void outputEmployee();

    // Сеттеры для класса
    void setFirstName(string first);
    void setLastName(string last);
    void setPosition(string position);
    void setSalary(float salary);

    // Геттеры для класса
    const string getFirstName();
    const string getLastName();
    const string getPosition();
    const float getSalary();
};

