#include "Order.h"

// Контруктор без параметров
Order::Order() : orderNumber(0), orderDate(""), quantityOrdered(0), totalCost(0) {}

// Контруктор с параметрами
Order::Order(string date, Employee emp, Customer cust, VinylRecord record, int quantity, float cost)
    : orderDate(date), employee(emp), customer(cust), orderedRecord(record), quantityOrdered(quantity), totalCost(cost) 
{
    orderNumber = generateOrderNumber();
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

// Статический метод для генерации уникального номера заказа
int Order::generateOrderNumber() 
{
    random_device rd;  // Источник энтропии
    mt19937 gen(rd()); // Генератор случайных чисел
    uniform_int_distribution<> dist(1, 1000); // Равномерное распределение от 1 до 1000

    return dist(gen);
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

// Метод для получения заказанной пластинки
VinylRecord& Order::getOrderedRecord()
{
    return orderedRecord;
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
