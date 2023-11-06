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
    Order* ordersArray = nullptr;

    int input;

    // Главный цикл программы
    do {
        system("cls");

        cout << "\t~~Модификация программы из лабораторной работы №2~~" << endl;
        cout << endl;

        cout << "Главное меню:" << endl;
        cout << "1. Создать магазин пластинок" << endl;
        cout << "2. Добавить пластинки в магазин" << endl;
        cout << "3. Добавить сотрудников в магазин" << endl;
        cout << "4. Удалить пластинку из ассортимента" << endl;
        cout << "5. Удалить сотрудника из магазина" << endl;
        cout << "6. Посмотреть информацию о магазине" << endl;
        cout << "7. Посмотреть информацию о сотрудниках" << endl;
        cout << "8. Посмотреть ассортимент магазина" << endl;
        cout << "9. Создать заказ" << endl;
        cout << "10. Посмотреть информацию о заказе" << endl;
        cout << "0. Выход из программы" << endl;

        cout << "\nВыберите действие: ";
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
            do {
                system("cls");
                if (!StoreCreated) 
                {
                    vinylStore = inputStore();
                    StoreCreated = true;
                }
                else 
                {
                    cout << "\n\t\t~~ПРЕДУПРЕЖДЕНИЕ~~" << endl;
                    cout << "-------------------------------------------" << endl;
                    cout << "Магазин уже создан. Хотите создать новый магазин?" << endl;
                    cout << "Введите ответ (y/n): ";
                    char response;
                    cin >> response;
                    cout << "-------------------------------------------" << endl;

                    if (response == 'y' || response == 'Y') {
                        system("cls");
                        vinylStore = inputStore();
                        // Сбросить флаг создания заказа
                        OrderCreated = false;
                    }
                    else {
                        cout << "Магазин не будет пересоздан." << endl;
                        cout << "-------------------------------------------\n" << endl;
                    }
                }
                cout << "\nЧтобы продолжить нажмите 'Esc'" << endl;
            } while (_getch() != ESCAPE);
            break;

        case 2:
            if (StoreCreated) 
            {
                do {
                    system("cls");
                    addVinylRecordsToStore(vinylStore);
                    cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        case 3:
            if (StoreCreated)
            {
                do {
                    system("cls");
                    addEmployeesToStore(vinylStore);
                    cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        case 4:
            if (StoreCreated)
            {
                do {
                    system("cls");
                    removeVinylRecord(vinylStore);
                    cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        case 5:
            if (StoreCreated)
            {
                do {
                    system("cls");
                    removeEmployee(vinylStore);
                    cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        case 6:
            if (StoreCreated)
            {
                do {
                    system("cls");
                    vinylStore.outputStore();
                    cout << "Чтобы закончить просмотр нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        case 7:
            if (StoreCreated)
            {
                do {
                    system("cls");
                    vinylStore.outputEmployees();
                    cout << "Чтобы закончить просмотр нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        case 8:
            if (StoreCreated)
            {
                do {
                    system("cls");
                    vinylStore.outputVinylRecords();
                    cout << "Чтобы закончить просмотр нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        case 9:
            if (StoreCreated)
            {
                do {
                    system("cls");
                    ordersArray = inputOrders(vinylStore);
                    OrderCreated = true;
                    cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        case 10:
            if (StoreCreated && OrderCreated)
            {
                do {
                    system("cls");
                    outputOrders(ordersArray);
                    cout << "Чтобы закончить просмотр нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nНи одного заказа не найдено!" << endl;
                Sleep(1500);
            }
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

    delete[] ordersArray;

    return 0;
}
