#include "Order.h"

int Order::orderNumberGenerator = Order::generateOrderNumber(); // Инициализируем переменную для номера заказа

// Контруктор без параметров
Order::Order() : orderNumber(0), orderDate(""), quantityOrdered(0), totalCost(0) {}

// Контруктор с параметрами
Order::Order(string date, Employee emp, Customer cust, VinylRecord record, int quantity, float cost)
    : orderDate(date), employee(emp), customer(cust), orderedRecord(record), quantityOrdered(quantity), totalCost(cost) 
{
    orderNumber = orderNumberGenerator++;
}

// Деструктор
Order::~Order() {}

// Определение метода для вывода информации о заказе
void Order::outputOrder()
{
    cout << "Номер заказа: " << orderNumber << endl;
    cout << "Дата заказа: " << orderDate << endl;
    cout << "Сотрудник магазина: " << employee.getFirstName() << " " << employee.getLastName() << " (" << employee.getPosition() << ")" << endl;
    cout << "Клиент: ";
    customer.outputCustomer();
    cout << "Заказанная пластинка: " << orderedRecord.getAlbumName() << " - " << quantityOrdered << " шт." << endl;
    cout << "Общая стоимость заказа: " << totalCost << endl;
    cout << endl;

}

int Order::generateOrderNumber() 
{
    srand(static_cast<unsigned int>(time(0)));  // Инициализация генератора случайных чисел
    return rand() % 10000 + 1;  // Генерация случайного числа от 1 до 10000
}

// Метод для установки даты заказа
void Order::setOrderDate(string orderDate)
{
    this->orderDate = orderDate;
}

// Метод для установки количества заказанных пластинок
void Order::setQuantityOrdered(int quantityOrdered)
{
    this->quantityOrdered = quantityOrdered;
}

// Метод для установки итоговой стоимости заказа
void Order::setTotalCost(float totalCost)
{
    this->totalCost = totalCost;
}

// Метод для получения номера заказа
const int Order::getOrderNumber()
{
    return orderNumber;
}

// Метод для получения даты заказа
const string Order::getOrderDate()
{
    return orderDate;
}

// Метод для получения количества заказанных пластинок
const int Order::getQuantityOrdered()
{
    return quantityOrdered;
}

// Метод для получения итоговой стоимости заказа
const float Order::getTotalCost()
{
    return totalCost;
}
