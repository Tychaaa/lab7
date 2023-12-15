#include "OnlineStore.h"

// Контруктор без параметров
OnlineStore::OnlineStore() : Store(), website(""), store_email(""), store_phone(""), onlineUsersCount(0) {}

// Контруктор с параметрами
OnlineStore::OnlineStore(string name, string address, VinylRecord* vinylRecordsArray, Employee* employeeArray, const vector<string>& paymentMethods,
    string website, string storeEmail, string storePhone)
    : Store(name, address, vinylRecordsArray, employeeArray), supportedPaymentMethods(paymentMethods),
    website(website), store_email(storeEmail), store_phone(storePhone)
{
    onlineUsersCount = 0;
}

// Деструктор
OnlineStore::~OnlineStore() {}

// Определение метода для вывода информации о Интернет-магазине
void OnlineStore::outputStore()
{
    Store::outputStore(); // Вызываем метод базового класса

    // Выводим дополнительную информацию об онлайн-магазине
    cout << "\n\t~~Информация об онлайн-магазине~~" << endl;
    cout << "Сайт магазина: " << website << endl;
    cout << "Email магазина: " << store_email << endl;
    cout << "Телефон магазина: " << store_phone << endl;
    cout << "Количество человек онлайн: " << onlineUsersCount << endl;

    cout << "Поддерживаемые методы оплаты: ";
    for (const auto& method : supportedPaymentMethods) {
        cout << method << ", ";
    }
    cout << endl;
}

// Метод для генерации случайного количества пользователей онлайн
int OnlineStore::generateRandomUsersCount()
{
    int onlineUsers;

    random_device rd;  // Источник энтропии
    mt19937 gen(rd()); // Генератор случайных чисел
    uniform_int_distribution<> dist(1, 1000); // Равномерное распределение от 1 до 1000

    onlineUsers = dist(gen);
    
    return onlineUsers;
}

// Метод для установки названия вебсайта
void OnlineStore::setWebsite(string newWebsite)
{
    website = newWebsite;
}

// Метод для установки электронной почты
void OnlineStore::setStoreEmail(string newStoreEmail)
{
    store_email = newStoreEmail;
}

// Метод для установки номера телефона
void OnlineStore::setStorePhone(string newStorePhone)
{
    store_phone = newStorePhone;
}

// Метод для установки количества человек онлайн
void OnlineStore::setOnlineUsersCount(int count)
{
    onlineUsersCount = generateRandomUsersCount();
}

// Метод для установки способов оплаты
void OnlineStore::setSupportedPaymentMethods(vector<string>& methods)
{
    supportedPaymentMethods = methods;
}

// Метод для получения названия вебсайта
const string OnlineStore::getWebsite()
{
    return website;
}

// Метод для получения электронной почты
const string OnlineStore::getStoreEmail()
{
    return store_email;
}

// Метод для получения номера телефона
const string OnlineStore::getStorePhone()
{
    return store_phone;
}

// Метод для получения количества человек онлайн
const int OnlineStore::getOnlineUsersCount()
{
    return onlineUsersCount;
}

// Метод для получения способов оплаты
const vector<string>& OnlineStore::getSupportedPaymentMethods()
{
    return supportedPaymentMethods;
}