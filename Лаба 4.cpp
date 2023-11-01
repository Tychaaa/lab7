#define _CRT_SECURE_NO_WARNINGS
#define MAX_RECORDS 10
#define MAX_EMPLOYEE 20
#define MAX_ORDER 10

#include <iostream>
#include <string>
#include <Windows.h>

#include "VinylRecord.h"
#include "Human.h"
#include "Customer.h"
#include "Employee.h"

using namespace std;

// Глобальные переменные для подсчета количества пластинок, сотрудников и заказов
int numRecords, numEmployees, numOrders;

int main()
{
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    cout << "\t~~Программа №2 по реализации АТД на языке C и C++~~" << endl;;
    cout << endl;

    // Объявление переменных для хранения данных о магазине
    string name, address;

    cout << "Введите название магазина: ";
    getline(cin, name);

    cout << "Введите адрес магазина: ";
    getline(cin, address);

    cout << "Введите количество имеющихся виниловых пластинок: ";
    cin >> numRecords;

    cout << endl;

    // Динамический массив объектов класса VinylRecord
    VinylRecord* vinylRecordsArray = new VinylRecord[numRecords];

    for (int i = 0; i < numRecords; ++i) {
        // Объявление переменных для хранения данных о виниловой пластинке
        string album, artist, genre;
        int year, quantity;
        float price;

        cout << "Виниловая пластинка #" << i + 1 << endl;
        // Ввод данных о виниловой пластинке
        inputVinylRecord(&album, &artist, &year, &genre, &price, &quantity);

        // Создание объекта и добавление его в массив
        vinylRecordsArray[i] = VinylRecord(album, artist, year, genre, price, quantity);
    }

    cout << "Введите количество сотрудников магазина: ";
    cin >> numEmployees;

    cout << endl;

    // Динамический массив объектов класса Employee
    Employee* employeeArray = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        // Объявление переменных для хранения данных о сотруднике
        string firstName, lastName, position;
        float salary;

        cout << "Сотрудник #" << i + 1 << ":" << endl;
        // Ввод данных о сотруднике
        inputEmployee(&firstName, &lastName, &position, &salary);

        // Создание объекта и добавление его в массив
        employeeArray[i] = Employee(firstName, lastName, position, salary);
    }

    // Создаем магазин
    Store store1(name, address, vinylRecordsArray, employeeArray);

    cout << "----------------------------------------" << endl;
    cout << endl;

    // Выводим информацию о магазине
    store1.outputStore();

    cout << "----------------------------------------" << endl;
    cout << endl;

    cout << "Введите количество заказов: ";
    cin >> numOrders;

    // Создаем массив указателей на объекты Order (массив динамических объектов)
    Order** ordersArray = new Order * [numOrders];

    // Ввод данных для каждого заказа
    for (int i = 0; i < numOrders; ++i) {
        cout << endl << "Заказ #" << i + 1 << ":" << endl;

        // Объявление переменных для хранения данных о заказе
        int orderNumber;
        string orderDate;

        // Ввод номера заказа и даты заказа
        cout << "Введите номер заказа: ";
        cin >> orderNumber;
        cin.ignore();

        cout << "Введите дату заказа: ";
        getline(cin, orderDate);

        // Показываем возможные варианты сотрудников для выбора
        int employeeIndex;
        bool isValidChoice = false;

        cout << "Выберите сотрудника, обслуживающего заказ:" << endl;

        for (int i = 0; i < numEmployees; i++) {
            cout << i + 1 << ". " << employeeArray[i].getFirstName() << " " << employeeArray[i].getLastName() << endl;
        }

        do {
            int choice;
            cin >> choice;

            if (choice >= 1 && choice <= numEmployees) {
                employeeIndex = choice - 1;
                isValidChoice = true; // Устанавливаем флаг, если выбор сотрудника корректен
            }
            else {
                cout << "Некорректный выбор." << endl;
            }
        } while (!isValidChoice); // Повторяем цикл, пока выбор не станет корректным

        // Объявление переменных для хранения данных о клиенте
        string clientFirstName, clientLastName, clientAddress;
        float clientMoney;

        // Ввод данных о клиенте
        cout << "Введите информацию о клиенте, оформляющем заказ:" << endl;
        inputCustomer(&clientFirstName, &clientLastName, &clientMoney, &clientAddress);

        // Показываем возможные варианты виниловых пластинок для выбора
        int vinylIndex;
        isValidChoice = false;

        cout << "Выберите виниловую пластинку для заказа:" << endl;

        for (int i = 0; i < numRecords; i++) {
            cout << i + 1 << ". " << vinylRecordsArray[i].getAlbumName() << " - " << vinylRecordsArray[i].getArtist() << " (" << vinylRecordsArray[i].getQuantity() << " шт." << ")" << endl;
        }

        do {
            int choice;
            cin >> choice;

            if (choice >= 1 && choice <= numRecords) {
                vinylIndex = choice - 1;
                isValidChoice = true;
            }
            else {
                cout << "Некорректный выбор." << endl;
            }
        } while (!isValidChoice);


        // Ввод количества заказанных виниловых пластинок
        int quantityOrdered;
        cout << "Введите количество заказанных виниловых пластинок: ";
        cin >> quantityOrdered;

        // Рассчет общей стоимости заказа
        float totalCost = vinylRecordsArray[vinylIndex].getPrice() * quantityOrdered;

        // Создание объекта заказа и добавление его в массив указателей на заказы
        ordersArray[i] = new Order(orderNumber, orderDate, employeeArray[employeeIndex], Customer(clientFirstName, clientLastName, clientMoney, clientAddress), vinylRecordsArray[vinylIndex], quantityOrdered, totalCost);
    }

    cout << endl;
    cout << "----------------------------------------" << endl;

    // Отображение информации о заказах
    for (int i = 0; i < numOrders; ++i) {
        cout << endl << "Информация о заказе #" << i + 1 << ":" << endl;
        ordersArray[i]->outputOrder();
    }

    cout << "----------------------------------------" << endl;

    // Освобождаем память, выделенную для каждого заказа
    for (int i = 0; i < numOrders; ++i) {
        delete ordersArray[i];
    }

    // Освобождаем память, выделенную для массивов
    delete[] vinylRecordsArray;
    delete[] employeeArray;
    delete[] ordersArray;

    return 0;
}
