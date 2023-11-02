#include "Customer.h"

//  онструктор без параметров
Customer::Customer() : money(0), address("") {}

//  онтруктор с параметрами
Customer::Customer(string first, string last, float money, string addr)
    : person(first, last), money(money), address(addr) {}

// ƒеструктор
Customer::~Customer() {}

// ќпределение метода дл€ вывода информации о клиенте
void Customer::outputCustomer()
{
    cout << person.getFirstName() << " " << person.getLastName() << endl;
}

// ќпределение метода дл€ установки имени клиента
void Customer::setFirstName(string first)
{
    person.setFirstName(first);
}

// ќпределение метода дл€ установки фамилии клиента
void Customer::setLastName(string last)
{
    person.setLastName(last);
}

// ќпределение метода дл€ установки денег клиента
void Customer::setMoney(float money)
{
    this->money = money;
}

// ќпределение метода дл€ установки адресса клиента
void Customer::setAddress(string address)
{
    this->address = address;
}

// ќпределение метода дл€ получени€ имени клиента
const string Customer::getFirstName()
{
    return person.getFirstName();
}

// ќпределение метода дл€ получени€ фамилии клиента
const string Customer::getLastName()
{
    return person.getLastName();
}

// ќпределение метода дл€ получени€ денег клиента
const float Customer::getMoney()
{
    return money;
}

// ќпределение метода дл€ получени€ адресса клиента
const string Customer::getAddress()
{
    return address;
}