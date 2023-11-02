#include "Functions.h"

// ‘ункци€ дл€ ввода информации о виниловой пластинке
void inputVinylRecord(string* album, string* artist, int* year, string* genre, float* price, int* quantity)
{
    cin.ignore();

    cout << "¬ведите название альбома: ";
    getline(cin, *album);

    cout << "¬ведите исполнител€: ";
    getline(cin, *artist);

    cout << "¬ведите год выпуска: ";
    cin >> *year;
    cin.ignore();

    cout << "¬ведите жанр: ";
    getline(cin, *genre);

    cout << "¬ведите цену: ";
    cin >> *price;

    cout << "¬ведите количество в наличии: ";
    cin >> *quantity;

    cout << endl;
}

// ‘ункци€ дл€ ввода информации о клиенте
void inputCustomer(string* firstName, string* lastName, float* money, string* address)
{
    cout << "¬ведите им€ клиента: ";
    cin >> *firstName;

    cout << "¬ведите фамилию клиента: ";
    cin >> *lastName;

    cout << "¬ведите количества денег клиента: ";
    cin >> *money;

    cout << "¬ведите адрес доставки клиента: ";
    cin.ignore(); // ќчищаем буфер дл€ считывани€ строки
    getline(cin, *address);

    cout << endl;
}

// ‘ункци€ дл€ ввода информации о сотруднике магазина
void inputEmployee(string* firstName, string* lastName, string* position, float* salary) 
{

    cout << "¬ведите им€ сотрудника: ";
    cin >> *firstName;

    cout << "¬ведите фамилию сотрудника: ";
    cin >> *lastName;

    cout << "¬ведите должность сотрудника: ";
    cin.ignore();
    getline(cin, *position);

    cout << "¬ведите зарплату сотрудника: ";
    cin >> *salary;

    cout << endl;
}