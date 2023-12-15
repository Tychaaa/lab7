#pragma once
#include "Store.h"

#include <vector>
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
    OnlineStore(string name, string address, VinylRecord* vinylRecordsArray, Employee* employeeArray, const vector<string>& paymentMethods);
    // Деструктор
    ~OnlineStore();

    // Метод для вывода информации о магазине
    void outputStore() override;

    // Геттер для поддерживаемых методов оплаты
    const vector<string>& getSupportedPaymentMethods();
};

