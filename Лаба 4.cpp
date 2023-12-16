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
#include "OnlineStore.h"

using namespace std;

// Глобальные переменные для подсчета количества пластинок, сотрудников и заказов
int numRecords, numEmployees, numOrders;

// Глобальные флаги для проверки создания магазина и заказов
bool StoreCreated = false;
bool OnlineStoreCreated = false;
bool OrderCreated = false;

int main()
{
    // Ставим русский язык в консоль
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    Store vinylStore;
    Order* ordersArray = nullptr;
    OnlineStore onlineStore;

    // Двумерный массив для хранения информации о виниловых пластинках и их итоговой стоимости
    string vinylInfo[MAX_ORDER][3];

    int input;

    // Главный цикл программы
    do {
        system("cls");

        // Выводим заголовок программы
        cout << "\t~~Лабораторная работа №6~~" << endl;
        cout << endl;

        // Выводим меню действий
        cout << "Главное меню:" << endl;
        cout << "1. Создать магазин пластинок" << endl;
        cout << "2. Создать Интернет-магазин пластинок" << endl;
        cout << "3. Меню \"Редактирование магазина\"" << endl;
        cout << "4. Меню \"Вывод информации\"" << endl;
        cout << "5. Создать заказ" << endl;
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
                            cin.ignore();
                            system("cls");
                            vinylStore = inputStore();
                            // Сбросить флаг создания заказа
                            OrderCreated = false;
                            OnlineStoreCreated = false;
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

        // Создание Интернет-магазина пластинок
        case 2:
            do {
                system("cls");

                if (StoreCreated && !OnlineStoreCreated)
                {
                    onlineStore = inputOnlineStore(vinylStore);
                    OnlineStoreCreated = true;
                }
                else if (OnlineStoreCreated)
                {
                    // Предупреждение при попытке создать новый магазин при уже существующем
                    cout << "\n\t\t~~ПРЕДУПРЕЖДЕНИЕ~~" << endl;
                    cout << "-------------------------------------------" << endl;
                    cout << "Онлайн-магазин уже создан. Хотите создать новый магазин?" << endl;
                    cout << "Введите ответ (y/n): ";
                    char response;
                    cin >> response;
                    cout << "-------------------------------------------" << endl;

                    // Обработка ответа пользователя
                    if (response == 'y' || response == 'Y') {
                        system("cls");
                        onlineStore = inputOnlineStore(vinylStore);
                    }
                    else {
                        cout << "Магазин не будет пересоздан." << endl;
                        cout << "-------------------------------------------\n" << endl;
                    }
                }
                else {
                    cout << "\nПрежде чем воспользоваться этой функцией, создайте магазин!" << endl;
                    Sleep(1500);
                }

                cout << "\nЧтобы продолжить нажмите 'Esc'" << endl;
            } while (_getch() != ESCAPE);
            break;

        // Переходим в меню редактирования магазина
        case 3:
            editStoreMenu(vinylStore, onlineStore);
            break;

        // Переходим в меню вывода информации
        case 4:
            outputInformationMenu(vinylStore, ordersArray, vinylInfo, onlineStore);
            break;

        // Создание заказа
        case 5:
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