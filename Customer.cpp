#include "Customer.h"

// Конструктор без параметров
Customer::Customer() : money(0), address("") {}

// Контруктор с параметрами
Customer::Customer(string first, string last, float money, string addr)
    : person(first, last), money(money), address(addr) {}

// Деструктор
Customer::~Customer() {}

// Определение метода для вывода информации о клиенте
void Customer::outputCustomer()
{
    cout << person.getFirstName() << " " << person.getLastName() << endl;
}

// Определение метода для установки имени клиента
void Customer::setFirstName(string first)
{
    person.setFirstName(first);
}

// Определение метода для установки фамилии клиента
void Customer::setLastName(string last)
{
    person.setLastName(last);
}

// Определение метода для установки денег клиента
void Customer::setMoney(float money)
{
    this->money = money;
}

// Определение метода для установки адресса клиента
void Customer::setAddress(string address)
{
    this->address = address;
}

// Определение метода для получения имени клиента
const string Customer::getFirstName()
{
    return person.getFirstName();
}

// Определение метода для получения фамилии клиента
const string Customer::getLastName()
{
    return person.getLastName();
}

// Определение метода для получения денег клиента
const float Customer::getMoney()
{
    return money;
}

// Определение метода для получения адресса клиента
const string Customer::getAddress()
{
    return address;
}

// Функция для ввода информации о клиенте
void inputCustomer(string* firstName, string* lastName, float* money, string* address)
{
    cout << "Введите имя клиента: ";
    cin >> *firstName;

    cout << "Введите фамилию клиента: ";
    cin >> *lastName;

    cout << "Введите количества денег клиента: ";
    cin >> *money;

    cout << "Введите адрес доставки клиента: ";
    cin.ignore(); // Очищаем буфер для считывания строки
    getline(cin, *address);

    cout << endl;
}