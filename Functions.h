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
#include <iomanip> // ��� ������������� setw
using namespace std;

extern bool StoreCreated;
extern bool OnlineStoreCreated;
extern bool OrderCreated;

// ������� ��� ����� ���������� � ��������
Store inputStore();

OnlineStore inputOnlineStore(Store& baseStore);

// ������� ��� ���������� ��������� ��������� � �������
void addVinylRecordsToStore(Store& store, OnlineStore& onlineStore);

// ������� ��� ���������� ����������� � �������
void addEmployeesToStore(Store& store, OnlineStore& onlineStore);

// ������� ��� �������� ��������� ��������� �� ��������
void removeVinylRecord(Store& store, OnlineStore& onlineStore);

// ������� ��� �������� ���������� �� ��������
void removeEmployee(Store& store);

// ������� ��� ����� ���������� � �������
vector<Order> inputOrders(Store store, string vinylInfo[][3]);

// ������� ��� ����� ���������� � ���������� ����������
void outputVinylInfo(string vinylInfo[][3]);

// ������� ��� ������ ���������� � �������
void outputOrders(vector<Order>& ordersVector);

// ������� ��� ����� ���������� � ��������� ���������
void inputVinylRecord(string& album, string& artist, int& year, string& genre, float& price, int& quantity);

// ������� ��� ����� ���������� � �������
void inputCustomer(string* firstName, string* lastName, float* money, string* address);

// ������� ��� ����� ���������� � ���������� ��������
void inputEmployee(string* firstName, string* lastName, string* position, float* salary);

// ���� �������������� ��������
void editStoreMenu(Store& vinylStore, OnlineStore& onlineStore);

// ���� ������ ����������
void outputInformationMenu(Store& vinylStore, vector<Order>& ordersVector, string vinylInfo[][3], OnlineStore& onlineStore);