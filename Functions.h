#pragma once
#include "Store.h"
#include "Order.h"
#include "OnlineStore.h"

#define MAX_ORDER 10
#define NOMINMAX
#define ESCAPE 27

#include <string>
#include <iostream>
#include <Windows.h>
#include <conio.h>
#include <vector>
#include <iomanip> // Для использования setw
using namespace std;

extern bool StoreCreated;
extern bool OnlineStoreCreated;
extern bool OrderCreated;

// Функция для ввода информации о магазине
Store inputStore();

OnlineStore inputOnlineStore(Store& baseStore);

// Функция для добавления виниловых пластинок в магазин
void addVinylRecordsToStore(Store& store, OnlineStore& onlineStore);

// Функция для добавления сотрудников в магазин
void addEmployeesToStore(Store& store, OnlineStore& onlineStore);

// Функция для удаления виниловой пластинки из магазина
void removeVinylRecord(Store& store, OnlineStore& onlineStore);

// Функция для удаления сотрудника из магазина
void removeEmployee(Store& store);

// Функция для ввода информации о заказах
vector<Order> inputOrders(Store store, string vinylInfo[][3]);

// Функция для ввода информации о заказанных пластинках
void outputVinylInfo(string vinylInfo[][3]);

// Функция для вывода информации о заказах
void outputOrders(vector<Order>& ordersVector);

// Функция для ввода информации о виниловой пластинке
void inputVinylRecord(string& album, string& artist, int& year, string& genre, float& price, int& quantity);

// Функция для ввода информации о клиенте
void inputCustomer(string* firstName, string* lastName, float* money, string* address);

// Функция для ввода информации о сотруднике магазина
void inputEmployee(string* firstName, string* lastName, string* position, float* salary);

// Меню радактирования магазина
void editStoreMenu(Store& vinylStore, OnlineStore& onlineStore);

// Меню вывода информации
void outputInformationMenu(Store& vinylStore, vector<Order>& ordersVector, string vinylInfo[][3], OnlineStore& onlineStore);