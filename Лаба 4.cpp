#define _CRT_SECURE_NO_WARNINGS
#define MAX_RECORDS 10
#define MAX_EMPLOYEE 20
#define MAX_ORDER 10
#define ESCAPE 27
#define NOMINMAX

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

// Глобальные флаги для проверки создания магазина и заказов
bool StoreCreated = false;
bool OrderCreated = false;

int main()
{
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);    

    Store vinylStore;
    Order* ordersArray = nullptr;

    // Двумерный массив для хранения информации о виниловых пластинках и их итоговой стоимости
    string vinylInfo[MAX_ORDER][3];

    int input;

    // Главный цикл программы
    do {
        system("cls");

        // Выводим заголовок программы
        cout << "\t~~Лабораторная работа №5~~" << endl;
        cout << endl;

        // Выводим меню действий
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
        cout << "11. Посмотреть информацию о заказанных пластинках" << endl;
        cout << "0. Выход из программы" << endl;

        cout << "\nВыберите действие: ";

        // Проверяем корректность ввода числа
        while (!(cin >> input)) {
            cin.clear(); //Сбрасываем флаг ошибки, если таковая была
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); //Игнорируем оставшиеся в потоке данные
            cout << "\nНекорректный ввод!\n\nВыберите действие: ";
        }
        cin.ignore(); // Очищаем буфер после ввода числа

        // Обработка введенного действи
        switch (input) {
            
        // Создание магазина пластинок
        case 1:
            do {
                system("cls");
                try
                {
                    if (!StoreCreated)
                    {
                        vinylStore = inputStore();
                        StoreCreated = true;
                    }
                    else
                    {
                        // Предупреждение при попытке создать новый магазин при уже существующем
                        cout << "\n\t\t~~ПРЕДУПРЕЖДЕНИЕ~~" << endl;
                        cout << "-------------------------------------------" << endl;
                        cout << "Магазин уже создан. Хотите создать новый магазин?" << endl;
                        cout << "Введите ответ (y/n): ";
                        char response;
                        cin >> response;
                        cout << "-------------------------------------------" << endl;

                        // Обработка ответа пользователя
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
                }
                catch (const std::exception& ex)
                {
                    cout << ex.what() << endl;
                }
                cout << "\nЧтобы продолжить нажмите 'Esc'" << endl;
            } while (_getch() != ESCAPE);
            break;

        // Добавление пластинок в магазин
        case 2:
            if (StoreCreated) 
            {
                do {
                    try
                    {
                        system("cls");
                        addVinylRecordsToStore(vinylStore);
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        // Добавление сотрудников в магазин
        case 3:
            if (StoreCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        addEmployeesToStore(vinylStore);
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        // Удаление пластинки из ассортимента магазина
        case 4:
            if (StoreCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        removeVinylRecord(vinylStore);
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        // Удаление сотрудника из магазина
        case 5:
            if (StoreCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        removeEmployee(vinylStore);
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        // Просмотр информации о магазине
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

        // Просмотр информации о сотрудниках магазина
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

        // Просмотр ассортимента магазина
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

        // Создание заказа
        case 9:
            if (StoreCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        ordersArray = inputOrders(vinylStore, vinylInfo);
                        OrderCreated = true;
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "Чтобы продолжить нажмите 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                Sleep(1500);
            }
            break;

        // Просмотр информации о заказе
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

        // Просмотр информации о заказанных пластинках
        case 11:
            if (StoreCreated && OrderCreated)
            {
                do {
                    system("cls");
                    outputVinylInfo(vinylInfo);
                    cout << "Чтобы закончить просмотр нажмите 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nНи одного заказа не найдено!" << endl;
                Sleep(1500);
            }
            break;

        // Выход из программы
        case 0:
            cout << "\n\t--------------" << endl;
            cout << "\t До свидания!" << endl;
            cout << "\t--------------" << endl;
            break;

        // Обработка некорректного ввода
        default:
            cout << "\nНекорректный выбор!\n" << endl;
            Sleep(1000);
        }
    } while (input != 0);

    // Освобождение памяти
    delete[] ordersArray;

    return 0;
}