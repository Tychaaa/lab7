#include "Store.h"

// Контруктор без параметров
Store::Store() : storeName(""), storeAddress("") {}

// Контруктор с параметрами
Store::Store(string name, string address, VinylRecord* vinylRecordsArray, Employee* employeeArray) : storeName(name), storeAddress(address) {
    // Инициализация массивов в конструкторе
    for (int i = 0; i < numRecords; ++i) {
        vinylRecordsInStore[i] = vinylRecordsArray[i];
    }

    for (int i = 0; i < numEmployees; ++i) {
        employeesInStore[i] = employeeArray[i];
    }
}

// Деструктор
Store::~Store() {}

// Определение метода для вывода информации о магазине
void Store::outputStore()
{
    cout << "Информация о магазине:" << endl;
    cout << "Название: " << storeName << endl;
    cout << "Адрес: " << storeAddress << endl;
    cout << endl;

    cout << "Информация о виниловых пластинках в магазине:" << endl;
    cout << endl;
    for (int i = 0; i < numRecords; ++i) {
        cout << "Виниловая пластинка #" << i + 1 << ":" << endl;
        vinylRecordsInStore[i].outputVinylRecord();
    }

    cout << "Информация о сотрудниках магазина:" << endl;
    cout << endl;
    for (int i = 0; i < numEmployees; ++i) {
        cout << "Сотрудник #" << i + 1 << ":" << endl;
        employeesInStore[i].outputEmployee();
    }
}

// Метод для установки названия магазина
void Store::setStoreName(string storeName)
{
    this->storeName = storeName;
}

// Метод для установки адреса магазина
void Store::setStoreAddress(string storeAddress)
{
    this->storeAddress = storeAddress;
}

// Метод для получения названия магазина
const string Store::getStoreName()
{
    return storeName;
}

// Метод для получения адреса магазина
const string Store::getStoreAddress()
{
    return storeAddress;
}

// Методы для получения массива виниловых пластинок в магазине
VinylRecord* Store::getVinylRecordsInStore()
{
    return vinylRecordsInStore;
}

// Методы для получения массива сотрудников магазина
Employee* Store::getEmployeesInStore()
{
    return employeesInStore;
}
