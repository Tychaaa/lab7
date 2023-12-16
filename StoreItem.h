#pragma once

#include <string>
#include <iostream>
using namespace std;

// Класс для объекта "Магазин", который продает
// не только виниловые пластинки, но также компакт-диски и кассеты
template <typename T1, typename T2>
class StoreItem {

private:

	T1 itemName;
	T2 price;

public:

	// Контруктор без параметров
	StoreItem() : itemName(), price() {}
	// Контруктор с параметрами
	StoreItem(T1 itemName, T2 price) : itemName(itemName), price(price) {}
	// Деструктор
	~StoreItem() {}

	// Метод для вывода информации о товаре
	void displayInfo() {
		cout << "Товар: " << itemName << ", Цена: " << price << " руб." << endl;
	}
};
