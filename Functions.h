#pragma once
#include "Store.h"

#include <string>
#include <iostream>
#include <Windows.h>
using namespace std;

Store inputStore();

void addVinylRecordsToStore(Store& store);

void addEmployeesToStore(Store& store);

void removeVinylRecord(Store& store);

void removeEmployee(Store& store);

// Функция для ввода информации о виниловой пластинке
void inputVinylRecord(string& album, string& artist, int& year, string& genre, float& price, int& quantity);

// Функция для ввода информации о клиенте
void inputCustomer(string* firstName, string* lastName, float* money, string* address);

// Функция для ввода информации о сотруднике магазина
void inputEmployee(string* firstName, string* lastName, string* position, float* salary);
