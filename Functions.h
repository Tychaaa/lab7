#pragma once
#include "Store.h"
#include "Order.h"

#define NOMINMAX
#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

// Функция для ввода информации о магазине
Store inputStore();

// Функция для добавления виниловых пластинок в магазин
void addVinylRecordsToStore(Store& store);

// Функция для добавления сотрудников в магазин
void addEmployeesToStore(Store& store);

// Функция для удаления виниловой пластинки из магазина
void removeVinylRecord(Store& store);

// Функция для удаления сотрудника из магазина
void removeEmployee(Store& store);

// Функция для ввода информации о заказах
Order* inputOrders(Store store);

// Функция для вывода информации о заказах
void outputOrders(Order* ordersArray);

// Функция для ввода информации о виниловой пластинке
void inputVinylRecord(string& album, string& artist, int& year, string& genre, float& price, int& quantity);

// Функция для ввода информации о клиенте
void inputCustomer(string* firstName, string* lastName, float* money, string* address);

// Функция для ввода информации о сотруднике магазина
void inputEmployee(string* firstName, string* lastName, string* position, float* salary);