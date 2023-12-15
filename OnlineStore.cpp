#include "OnlineStore.h"

OnlineStore::OnlineStore() : Store(), website(""), store_email(""), store_phone(""), onlineUsersCount(0) {}

OnlineStore::~OnlineStore() {}

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
