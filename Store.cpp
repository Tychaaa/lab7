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

// Метод для вывода полной информации о сотрудниках магазина
void Store::outputEmployees()
{
    cout << "\n\t~~Информация о сотрудниках магазина \"" << getStoreName() << "\"~~" << endl;
    cout << "---------------------------" << endl;
    int employeeNumber = 1;
    for (auto& employee : employeesInStore) {
        if (employee.getFirstName() != "") {
            cout << "Сотрудник #" << employeeNumber << endl;
            cout << "Имя: " << employee.getFirstName() << endl;
            cout << "Фамилия: " << employee.getLastName() << endl;
            cout << "Должность: " << employee.getPosition() << endl;
            cout << "Зарплата: " << employee.getSalary() << endl;
            cout << "---------------------------" << endl;
            employeeNumber++;
        }
    }
    cout << endl;
}

// Метод для вывода краткой информации о сотрудниках магазина
void Store::outputEmployeesShortList()
{
    cout << "Сотрудники магазина:" << endl;
    int employeeNumber = 1;
    for (auto& employee : employeesInStore) {
        if (employee.getFirstName() != "") {
            cout << employeeNumber << ") " << employee.getFirstName() << " " << employee.getLastName() << " - " << employee.getPosition() << endl;
            employeeNumber++;
        }
    }
}

// Метод для вывода полной информации о виниловых пластинках в магазине
void Store::outputVinylRecords()
{
    cout << "\n\t~~Информация о виниловых пластинках в магазине \"" << getStoreName() << "\"~~" << endl;
    int recordNumber = 1; // Счетчик для номера пластинки
    cout << "---------------------------" << endl;
    for (auto& record : vinylRecordsInStore) {
        if (record.getAlbumName() != "") {
            cout << "Виниловая пластинка #" << recordNumber << endl;
            cout << "Название альбома: " << record.getAlbumName() << endl;
            cout << "Исполнитель: " << record.getArtist() << endl;
            cout << "Год выпуска: " << record.getYear() << endl;
            cout << "Жанр: " << record.getGenre() << endl;
            cout << "Цена: " << record.getPrice() << endl;
            cout << "Количество в наличии: " << record.getQuantity() << endl;
            cout << "---------------------------" << endl;
            recordNumber++;
        }
    }
    cout << endl;
}

// Метод для вывода краткой информации о виниловых пластинках в магазине
void Store::outputVinylRecordsShortList()
{
    cout << "Пластинки в наличии:" << endl;
    int recordNumber = 1;
    for (auto& record : vinylRecordsInStore) {
        if (record.getAlbumName() != "") {
            cout << recordNumber << ") " << record.getAlbumName() << " - " << record.getArtist() << " (" << record.getQuantity() << " шт.)" << endl;
            recordNumber++;
        }
    }
}

// Перегрузка оператора << для вывода информации об онлайн-магазине
ostream& operator<<(ostream& os, Store& store)
{
    os << "\n\t~~Информация о магазине~~" << endl;
    os << "-------------------------------------------" << endl;
    os << "Название магазина: " << store.getStoreName() << endl;
    os << "Адрес магазина: " << store.getStoreAddress() << endl;

    // Вывод информации о виниловых пластинках
    os << "Пластинки в наличии:" << endl;
    int recordNumber = 1;
    VinylRecord* recordsBegin = store.getVinylRecordsInStore();
    VinylRecord* recordsEnd = recordsBegin + numRecords;
    for (VinylRecord* record = recordsBegin; record != recordsEnd; ++record) {
        if (record->getAlbumName() != "") {
            os << recordNumber << ") " << record->getAlbumName() << " - " << record->getArtist() << " (" << record->getQuantity() << " шт.)" << endl;
            recordNumber++;
        }
    }

    // Вывод информации о сотрудниках
    os << "Сотрудники магазина:" << endl;
    int employeeNumber = 1;
    Employee* employeesBegin = store.getEmployeesInStore();
    Employee* employeesEnd = employeesBegin + numEmployees;
    for (Employee* employee = employeesBegin; employee != employeesEnd; ++employee) {
        if (employee->getFirstName() != "") {
            os << employeeNumber << ") " << employee->getFirstName() << " " << employee->getLastName() << " - " << employee->getPosition() << endl;
            employeeNumber++;
        }
    }

    os << "-------------------------------------------" << endl;
    return os;
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

// Метод для установки пластинок в наличии
void Store::setVinylRecordsInStore(VinylRecord* vinylRecordsArray)
{
    // Перебираем все виниловые пластинки и копируем их в массив магазина
    for (int i = 0; i < numRecords; ++i) {
        vinylRecordsInStore[i] = vinylRecordsArray[i];
    }
}

// Метод для установки сотрудников в магазине
void Store::setEmployeesInStore(Employee* employeeArray)
{
    // Перебираем всех сотрудников и копируем их в массив магазина
    for (int i = 0; i < numEmployees; ++i) {
        employeesInStore[i] = employeeArray[i];
    }
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
