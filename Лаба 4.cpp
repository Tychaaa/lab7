#define _CRT_SECURE_NO_WARNINGS
#define MAX_RECORDS 10
#define MAX_EMPLOYEE 20
#define MAX_ORDER 10
#define ESCAPE 27

#include <iostream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include "Functions.h" // Заголовочный файл с функциями

// Заголовочные файлы для классов
#include "VinylRecord.h"
#include "Human.h"
#include "Customer.h"
#include "Employee.h"
#include "Store.h"
#include "Order.h"

using namespace std;

// Глобальные переменные для подсчета количества пластинок, сотрудников и заказов
int numRecords, numEmployees, numOrders;

bool StoreCreated = false;
bool OrderCreated = false;

int main()
{
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);    

    Store vinylStore;

    int input;

    // Главный цикл программы
    do {
        system("cls");

        cout << "\t~~Модификация программы из лабораторной работы №2~~" << endl;
        cout << endl;

        cout << "Главное меню:" << endl;
        cout << "1. Создать магазин пластинок" << endl;
        cout << "2. Посмотреть информацию о магазине" << endl;
        cout << "3. Посмотреть информацию о сотрудниках" << endl;
        cout << "4. Посмотреть ассортимент магазина" << endl;
        cout << "5. Создать заказ" << endl;
        cout << "6. Посмотреть информацию о заказе" << endl;
        cout << "0. Выход из программы" << endl;

        cout << "Выберите действие: ";
        while (!(cin >> input)) {
            {
                cin.clear(); //Сбрасываем флаг ошибки, если таковая была
                cin.ignore(1000, '\n'); //Игнорируем оставшиеся в потоке данные
                cout << "\nНекорректный ввод!\n\nВыберите действие: ";
            }
        }
        cin.ignore(); // Очищаем буфер после ввода числа

        switch (input) {
        case 1:
            vinylStore = inputStore();
            Sleep(1000);
            break;
        case 2:
            do {
                system("cls");
                vinylStore.outputStore();
                cout << "Чтобы закончить просмотр нажмите 'Esc'" << endl;
            } while (_getch() != ESCAPE);
            break;
        case 3:
            do {
                system("cls");
                vinylStore.outputEmployees();
                cout << "Чтобы закончить просмотр нажмите 'Esc'" << endl;
            } while (_getch() != ESCAPE);
            break;
        case 4:
            do {
                system("cls");
                vinylStore.outputVinylRecords();
                cout << "Чтобы закончить просмотр нажмите 'Esc'" << endl;
            } while (_getch() != ESCAPE);
            break;
        case 5:
            cout << "действие 5" << endl;
            Sleep(1000);
            break;
        case 6:
            cout << "действие 6" << endl;
            Sleep(1000);
            break;
        case 0:
            cout << "\n\t--------------" << endl;
            cout << "\t До свидания!" << endl;
            cout << "\t--------------" << endl;
            break;
        default:
            cout << "\nНекорректный выбор!\n" << endl;
            Sleep(1000);
        }
    } while (input != 0);

    return 0;
}
