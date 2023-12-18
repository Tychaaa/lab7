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
#include <vector>
#include "Functions.h" // Заголовочный файл с функциями

// Заголовочные файлы для классов
#include "VinylRecord.h"
#include "Human.h"
#include "Customer.h"
#include "Employee.h"
#include "Store.h"
#include "Order.h"
#include "OnlineStore.h"
#include "StoreItem.h"

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
    vector<Order> ordersVector;  // Заменяем указатель на вектор
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
        cout << "6. Найти заказ" << endl;
        cout << "7. Демонстрация использования виртуальных функций " << endl;
        cout << "8. Демонстрация использования шаблона класса" << endl;
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
            outputInformationMenu(vinylStore, ordersVector, vinylInfo, onlineStore);
            break;

        // Создание заказа
        case 5:
            if (StoreCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        ordersVector = inputOrders(vinylStore, vinylInfo);
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

        // Найти заказ
        case 6:
            if (StoreCreated && OrderCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        // Используем функцию для поиска заказа и вывода информации
                        findOrderAndDisplay(ordersVector);
                        cout << "Чтобы закончить просмотр нажмите 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "\nЧтобы продолжить нажмите 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\nНи одного заказа не найдено!" << endl;
                Sleep(1500);
            }
            break;
            break;

        // Демонстрация использования виртуальных функций
        case 7:

            do {
                system("cls");

                cout << "\n\t~~Демонстрация использования виртуальных функций~~\n" << endl;

                // Создаем объекты
                Store myStore("My Store", "с.Barnaul", nullptr, nullptr);
                OnlineStore myOnlineStore("My Online Store", "v.Romanovo", nullptr, nullptr, { "Credit Card", "Yandex.Money" }, "www.mystore.com", "info@mystore.com", "+7-961-999-54-73");

                // Вызываем виртуальную функцию через указатель на базовый класс
                cout << "Вызываем виртуальную функцию через указатель на базовый класс\n" << endl;

                Store* ptrStore = &myStore;
                ptrStore->displayInfo();  // Выведет информацию о магазине

                ptrStore = &myOnlineStore;
                ptrStore->displayInfo();  // Выведет информацию о Интернет-магазине, так как метод виртуальный

                // Вызываем виртуальную функцию через динамический объект
                cout << "\nВызываем виртуальную функцию через динамический объект\n" << endl;

                ptrStore = new Store("My another Store", "v.Mamontovo", nullptr, nullptr);
                ptrStore->displayInfo();  // Выведет информацию о магазине

                ptrStore = new OnlineStore("Another Online Store", "с.Novosibirsk", nullptr, nullptr, { "Money", "Qiwi" }, "www.mystore2.com", "information@mystore.com", "123-456-7890");
                ptrStore->displayInfo();  // Выведет информацию о Интернет-магазине

                delete ptrStore;

                cout << "\nЧтобы продолжить нажмите 'Esc'" << endl;
            } while (_getch() != ESCAPE);

            break;

        // Демонстрация использования шаблона класса
        case 8:

            do {
                system("cls");

                cout << "\n\t~~Демонстрация использования шаблона класса~~\n" << endl;

                // Пример использования класса StoreItem с разными типами данных
                StoreItem<string, double> vinylRecord("Classic Vinyl", 1999.90);
                StoreItem<string, double> cd("Rock CD", 1499.50);
                StoreItem<string, double> cassette("80s Mixtape", 999.40);

                // Вывод информации о товарах
                vinylRecord.displayInfo();
                cd.displayInfo();
                cassette.displayInfo();

                cout << "\nЧтобы продолжить нажмите 'Esc'" << endl;
            } while (_getch() != ESCAPE);

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

    return 0;
}