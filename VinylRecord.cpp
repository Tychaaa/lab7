#include "VinylRecord.h"

// Контруктор без параметров
VinylRecord::VinylRecord() : albumName(""), artist(""), year(0), genre(""), price(0), quantity(0) {}

// Контруктор с параметрами
VinylRecord::VinylRecord(string album, string artist, int year, string genre, float price, int quantity)
    : albumName(album), artist(artist), year(year), genre(genre), price(price), quantity(quantity) {}

// Деструктор
VinylRecord::~VinylRecord() {}

// Определение метода для вывода информации о виниловой пластинке
void VinylRecord::outputVinylRecord()
{
    cout << "Название альбома: " << albumName << endl;
    cout << "Исполнитель: " << artist << endl;
    cout << "Год выпуска: " << year << endl;
    cout << "Жанр: " << genre << endl;
    cout << "Цена: " << price << endl;
    cout << "Количество в наличии: " << quantity << endl;
    cout << endl;
}

// Определение метода для установки названия виниловой пластинки
void VinylRecord::setAlbumName(string albumName)
{
    this->albumName = albumName;
}

// Определение метода для установки исполнителя виниловой пластинки
void VinylRecord::setArtist(string artist)
{
    this->artist = artist;
}

// Определение метода для установки года выпуска виниловой пластинки
void VinylRecord::setYear(int year)
{
    this->year = year;
}

// Определение метода для установки жанра виниловой пластинки
void VinylRecord::setGenre(string genre)
{
    this->genre = genre;
}

// Определение метода для получения стоимости виниловой пластинке
void VinylRecord::setPrice(float price)
{
    this->price = price;
}

// Определение для установки количества виниловой пластинки
void VinylRecord::setQuantity(int quantity)
{
    this->quantity = quantity;
}

// Определение метода для получения названия виниловой пластинки
const string VinylRecord::getAlbumName()
{
    return albumName;
}

// Определение метода для получения исполнителя виниловой пластинки
const string VinylRecord::getArtist()
{
    return artist;
}

// Определение метода для получения года выпуска виниловой пластинки
const int VinylRecord::getYear()
{
    return year;
}

// Определение метода для получения жанра виниловой пластинки
const string VinylRecord::getGenre()
{
    return genre;
}

// Определение метода для получения стоимости виниловой пластинке
const float VinylRecord::getPrice()
{
    return price;
}

// Определение для получения количества виниловой пластинки
const int VinylRecord::getQuantity()
{
    return quantity;
}

// Функция для ввода информации о виниловой пластинке
void inputVinylRecord(string* album, string* artist, int* year, string* genre, float* price, int* quantity)
{
    cin.ignore();

    cout << "Введите название альбома: ";
    getline(cin, *album);

    cout << "Введите исполнителя: ";
    getline(cin, *artist);

    cout << "Введите год выпуска: ";
    cin >> *year;
    cin.ignore();

    cout << "Введите жанр: ";
    getline(cin, *genre);

    cout << "Введите цену: ";
    cin >> *price;

    cout << "Введите количество в наличии: ";
    cin >> *quantity;

    cout << endl;
}
