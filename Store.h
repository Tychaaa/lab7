#pragma once
#define MAX_RECORDS 10
#define MAX_EMPLOYEE 20

#include "VinylRecord.h"
#include "Employee.h"

#include <string>
#include <iostream>
using namespace std;

// Глобальные переменные для подсчета количества пластинок и сотрудников
extern int numRecords, numEmployees;

// Класс для объекта "Магазин"
class Store {
private:

    string storeName;    // Название магазина
    string storeAddress; // Адрес магазина
    VinylRecord vinylRecordsInStore[MAX_RECORDS]; // Список имеющихся в магазине виниловых пластинок
    Employee employeesInStore[MAX_EMPLOYEE];      // Список сотрудников магазина

public:

    // Контруктор без параметров
    Store();
    // Контруктор с параметрами
    Store(string name, string address, VinylRecord* vinylRecordsArray, Employee* employeeArray);
    // Деструктор
    ~Store();

    void outputEmployees();
    void outputEmployeesShortList();
    void outputVinylRecords();
    void outputVinylRecordsShortList();

    // Метод для вывода информации о магазине
    void outputStore();

    // Сеттеры для класса
    void setStoreName(string storeName);
    void setStoreAddress(string storeAddress);
    /*void setVinylRecordsInStore(VinylRecord* vinylRecordsArray);
    void setEmployeesInStore(Employee* employeeArray);*/

    // Геттеры для класса
    const string getStoreName();
    const string getStoreAddress();   
    VinylRecord* getVinylRecordsInStore();    
    Employee* getEmployeesInStore();
};

