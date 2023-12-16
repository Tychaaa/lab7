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
    setOnlineUsersCount();

    // Выводим дополнительную информацию об онлайн-магазине
    cout << "\n\t~~Информация об онлайн-магазине~~" << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Название магазина: " << storeName << endl;
    cout << "Адрес магазина: " << storeAddress << endl;
    cout << "Сайт магазина: " << website << endl;
    cout << "Email магазина: " << store_email << endl;
    cout << "Телефон магазина: " << store_phone << endl;
    outputVinylRecordsShortList();
    cout << "Количество человек онлайн: " << onlineUsersCount << endl;
    cout << "Поддерживаемые методы оплаты:" << endl;
    for (size_t i = 0; i < supportedPaymentMethods.size(); ++i) {
        cout << i + 1 << ") " << supportedPaymentMethods[i] << endl;
    }
    cout << "-------------------------------------------" << endl;
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

// Перегрузка оператора присваивания объекту производного класса объектов базового класса
OnlineStore& OnlineStore::operator=(Store& other)
{
    if (this != &other) {
        // Копируем общие данные
        setStoreName(other.getStoreName());
        setStoreAddress(other.getStoreAddress());
        setVinylRecordsInStore(other.getVinylRecordsInStore());
        setEmployeesInStore(other.getEmployeesInStore());
    }
    return *this;
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
void OnlineStore::setOnlineUsersCount()
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

// Перегрузка оператора << для вывода информации об онлайн-магазине
ostream& operator<<(ostream& os, OnlineStore& onlineStore)
{
    onlineStore.setOnlineUsersCount();

    // Выводим дополнительную информацию об онлайн-магазине
    os << "\n\t~~Информация об онлайн-магазине~~" << endl;
    os << "-------------------------------------------" << endl;
    os << "Название магазина: " << onlineStore.getStoreName() << endl;
    os << "Адрес магазина: " << onlineStore.getStoreAddress() << endl;
    os << "Сайт магазина: " << onlineStore.website << endl;
    os << "Email магазина: " << onlineStore.store_email << endl;
    os << "Телефон магазина: " << onlineStore.store_phone << endl;

    // Вывод информации о виниловых пластинках
    os << "Пластинки в наличии:" << endl;
    int recordNumber = 1;
    VinylRecord* recordsBegin = onlineStore.getVinylRecordsInStore();
    VinylRecord* recordsEnd = recordsBegin + numRecords;
    for (VinylRecord* record = recordsBegin; record != recordsEnd; ++record) {
        if (record->getAlbumName() != "") {
            os << recordNumber << ") " << record->getAlbumName() << " - " << record->getArtist() << " (" << record->getQuantity() << " шт.)" << endl;
            recordNumber++;
        }
    }

    os << "Количество человек онлайн: " << onlineStore.onlineUsersCount << endl;
    os << "Поддерживаемые методы оплаты:" << endl;
    for (size_t i = 0; i < onlineStore.supportedPaymentMethods.size(); ++i) {
        os << i + 1 << ") " << onlineStore.supportedPaymentMethods[i] << endl;
    }
    os << "-------------------------------------------" << endl;

    return os;
}
