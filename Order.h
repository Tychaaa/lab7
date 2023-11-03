#pragma once

#include "VinylRecord.h"
#include "Customer.h"
#include "Employee.h"

#include <string>
#include <iostream>
using namespace std;

// Глобальные переменные для подсчета заказов
extern int numOrders;

// Класс для объекта "Заказ"
class Order {
private:

    static int orderNumberGenerator;  // Генератор номеров заказов
    int orderNumber;    // Номер заказа
    string orderDate;   // Дата заказа
    Employee employee;  // Сотрудник магазина
    Customer customer;  // Клиент
    VinylRecord orderedRecord; // Заказанная виниловая пластинка
    int quantityOrdered;       // Кол/во заказанных виниловых пластинок
    float totalCost;    // Общая стоимость заказа

public:

    // Контруктор без параметров
    Order();
    // Контруктор с параметрами
    Order(string date, Employee emp, Customer cust, VinylRecord record, int quantity, float cost);
    // Деструктор
    ~Order();

    // Метод для вывода информации о заказе
    void outputOrder();

    // Статический метод для генерации уникального номера заказа
    static int generateOrderNumber();
    
    // Сеттеры для класса
    void setOrderDate(string orderDate);
    void setQuantityOrdered(int quantityOrdered);
    void setTotalCost(float totalCost);

    // Геттеры для класса
    const int getOrderNumber();
    const string getOrderDate();
    const int getQuantityOrdered();
    const float getTotalCost();
};