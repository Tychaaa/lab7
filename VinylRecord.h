#pragma once

#include <string>
#include <iostream>
using namespace std;

// Класс для объекта "Виниловая пластинка"
class VinylRecord {
private:

    string albumName;   // Название альбома
    string artist;      // Исполнитель
    int year;           // Год выпуска
    string genre;       // Жанр
    float price;        // Цена
    int quantity;       // Количество в наличии

public:

    // Контруктор без параметров
    VinylRecord();
    // Контруктор с параметрами
    VinylRecord(string album, string artist, int year, string genre, float price, int quantity);
    // Деструктор
    ~VinylRecord();

    // Метод для вывода информации о виниловой пластинке
    void outputVinylRecord();

    // Сеттеры для класса
    void setAlbumName(string albumName);
    void setArtist(string artist);
    void setYear(int year);
    void setGenre(string genre);
    void setPrice(float price);
    void setQuantity(int quantity);

    // Геттеры для класса
    const string getAlbumName();
    const string getArtist();
    const int getYear();
    const string getGenre();
    const float getPrice();
    const int getQuantity();
};

