#pragma once
#include "Store.h"

#include <vector>
#include <random>
using namespace std;

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

    // Метод для генерации случайного количества пользователей онлайн
    int generateRandomUsersCount();

    // Сеттеры для класса
    void setWebsite(string newWebsite);
    void setStoreEmail(string newStoreEmail);
    void setStorePhone(string newStorePhone);
    void setOnlineUsersCount(int count);
    void setSupportedPaymentMethods(vector<string>& methods);

    // Геттеры для класса
    const string getWebsite();
    const string getStoreEmail();
    const string getStorePhone();
    const int getOnlineUsersCount();
    const vector<string>& getSupportedPaymentMethods();
};

