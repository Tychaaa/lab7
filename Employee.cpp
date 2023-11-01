#include "Employee.h"

// Контруктор без параметров
Employee::Employee() : position(""), salary(0) {}

// Контруктор с параметрами
Employee::Employee(string first, string last, string pos, float sal)
    : person(first, last), position(pos), salary(sal) {}

// Деструктор
Employee::~Employee() {}

// Определение метода для вывода информации о сотруднике
void Employee::outputEmployee()
{
    cout << "Имя сотрудника: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "Должность: " << position << endl;
    cout << "Зарплата: " << salary << endl;
    cout << endl;
}

// Определение метода для установки имени сотрудника
void Employee::setFirstName(string first)
{
    person.setFirstName(first);
}

// Определение метода для установки фамилии сотрудника
void Employee::setLastName(string last)
{
    person.setLastName(last);
}

// Определение метода для установки должности сотрудника
void Employee::setPosition(string position)
{
    this->position = position;
}

// Определение метода для установки зарплаты сотрудника
void Employee::setSalary(float salary)
{
    this->salary = salary;
}

// Определение метода для получения имени сотрудника
const string Employee::getFirstName()
{
    return person.getFirstName();
}

// Определение метода для получения фамилии сотрудника
const string Employee::getLastName()
{
    return person.getLastName();
}

// Определение метода для получения должности сотрудника
const string Employee::getPosition()
{
    return position;
}

// Определение метода для получения зарплаты сотрудника
const float Employee::getSalary()
{
    return salary;
}

// Функция для ввода информации о сотруднике магазина
void inputEmployee(string* firstName, string* lastName, string* position, float* salary) {

    cout << "Введите имя сотрудника: ";
    cin >> *firstName;

    cout << "Введите фамилию сотрудника: ";
    cin >> *lastName;

    cout << "Введите должность сотрудника: ";
    cin.ignore();
    getline(cin, *position);

    cout << "Введите зарплату сотрудника: ";
    cin >> *salary;

    cout << endl;
}