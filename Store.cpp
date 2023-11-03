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

void Store::outputEmployees()
{
    cout << "\n\t~~Информация о сотрудниках магазина \"" << getStoreName() << "\"~~" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        if (employeesInStore[i].getFirstName() != "") {
            cout << "Сотрудник #" << i + 1 << endl;
            cout << "Имя: " << employeesInStore[i].getFirstName() << endl;
            cout << "Фамилия: " << employeesInStore[i].getLastName() << endl;
            cout << "Должность: " << employeesInStore[i].getPosition() << endl;
            cout << "Зарплата: " << employeesInStore[i].getSalary() << endl;
            cout << "---------------------------" << endl;
        }
    }
    cout << endl;
}

void Store::outputEmployeesShortList()
{
    cout << "Сотрудники магазина:" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        if (employeesInStore[i].getFirstName() != "") {
            cout << i + 1 << ") " << employeesInStore[i].getFirstName() << " " << employeesInStore[i].getLastName() << " - " << employeesInStore[i].getPosition() << endl;
        }
    }
}

void Store::outputVinylRecords()
{
    cout << "\n\t~~Информация о виниловых пластинках в магазине \"" << getStoreName() << "\"~~" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < numRecords; ++i) {
        if (vinylRecordsInStore[i].getAlbumName() != "") {
            cout << "Виниловая пластинка #" << i + 1 << endl;
            cout << "Название альбома: " << vinylRecordsInStore[i].getAlbumName() << endl;
            cout << "Исполнитель: " << vinylRecordsInStore[i].getArtist() << endl;
            cout << "Год выпуска: " << vinylRecordsInStore[i].getYear() << endl;
            cout << "Жанр: " << vinylRecordsInStore[i].getGenre() << endl;
            cout << "Цена: " << vinylRecordsInStore[i].getPrice() << endl;
            cout << "Количество в наличии: " << vinylRecordsInStore[i].getQuantity() << endl;
            cout << "---------------------------" << endl;
        }
    }
    cout << endl;
}

void Store::outputVinylRecordsShortList()
{
    cout << "Пластинки в наличии:" << endl;
    for (int i = 0; i < numRecords; ++i) {
        if (vinylRecordsInStore[i].getAlbumName() != "") {
            cout << i + 1 << ") " << vinylRecordsInStore[i].getAlbumName() << " - " << vinylRecordsInStore[i].getArtist() << " (" << vinylRecordsInStore[i].getQuantity() << " шт.)" << endl;
        }
    }
}

// Определение метода для вывода информации о магазине
void Store::outputStore()
{
    cout << "\n\t~~Информация о магазине~~" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Название магазина: " << getStoreName() << endl;
    cout << "Адрес магазина: " << getStoreAddress() << endl;
    outputVinylRecordsShortList();
    outputEmployeesShortList();
    cout << "-------------------------------------------\n" << endl;
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
