#pragma once

#include "Human.h"
#include <string>
#include <iostream>
using namespace std;

// Класс для объекта "Клиент"
class Customer {
private:

    Human person;       // Используем класс Human для представления клиента
    float money;        // Кол/во денег
    string address;     // Адрес доставки

public:

    // Конструктор без параметров
    Customer();
    // Контруктор с параметрами
    Customer(string first, string last, float money, string addr);
    // Деструктор
    ~Customer();

    // Метод для вывода информации о клиенте
    void outputCustomer();

    // Сеттеры для класса
    void setFirstName(string first);
    void setLastName(string last);
    void setMoney(float money);
    void setAddress(string address);

    // Геттеры для класса
    const string getFirstName();
    const string getLastName();
    const float getMoney();
    const string getAddress();
};
