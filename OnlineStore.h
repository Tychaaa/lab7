#pragma once
#include "Store.h"

#include <vector>
#include <random>
using namespace std;

extern int numRecords;

class OnlineStore :
    public Store
{
private:

    string website;
    string store_email;
    string store_phone;
    int onlineUsersCount;
    vector<string> supportedPaymentMethods;

public:

    // Контруктор без параметров
    OnlineStore();
    // Контруктор с параметрами
    OnlineStore(string name, string address, VinylRecord* vinylRecordsArray, Employee* employeeArray, const vector<string>& paymentMethods,
        string website, string storeEmail, string storePhone);
    // Деструктор
    ~OnlineStore();

    // Метод для вывода информации о магазине
    void outputStore() override;

    // Перегрузка оператора << для вывода информации об онлайн-магазине
    friend ostream& operator<<(ostream& os, OnlineStore& onlineStore);

    // Метод для генерации случайного количества пользователей онлайн
    int generateRandomUsersCount();

    // Перегрузка оператора присваивания объекту производного класса объектов базового класса
    OnlineStore& operator=(Store& other);

    // Сеттеры для класса
    void setWebsite(string newWebsite);
    void setStoreEmail(string newStoreEmail);
    void setStorePhone(string newStorePhone);
    void setOnlineUsersCount();
    void setSupportedPaymentMethods(vector<string>& methods);

    // Геттеры для класса
    const string getWebsite();
    const string getStoreEmail();
    const string getStorePhone();
    const int getOnlineUsersCount();
    const vector<string>& getSupportedPaymentMethods();
};

