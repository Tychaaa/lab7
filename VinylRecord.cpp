#include "VinylRecord.h"

//  онтруктор без параметров
VinylRecord::VinylRecord() : albumName(""), artist(""), year(0), genre(""), price(0), quantity(0) {}

//  онтруктор с параметрами
VinylRecord::VinylRecord(string album, string artist, int year, string genre, float price, int quantity)
    : albumName(album), artist(artist), year(year), genre(genre), price(price), quantity(quantity) {}

// ƒеструктор
VinylRecord::~VinylRecord() {}

// ќпределение метода дл€ вывода информации о виниловой пластинке
void VinylRecord::outputVinylRecord()
{
    cout << "Ќазвание альбома: " << albumName << endl;
    cout << "»сполнитель: " << artist << endl;
    cout << "√од выпуска: " << year << endl;
    cout << "∆анр: " << genre << endl;
    cout << "÷ена: " << price << endl;
    cout << " оличество в наличии: " << quantity << endl;
    cout << endl;
}

// ќпределение метода дл€ установки названи€ виниловой пластинки
void VinylRecord::setAlbumName(string albumName)
{
    this->albumName = albumName;
}

// ќпределение метода дл€ установки исполнител€ виниловой пластинки
void VinylRecord::setArtist(string artist)
{
    this->artist = artist;
}

// ќпределение метода дл€ установки года выпуска виниловой пластинки
void VinylRecord::setYear(int year)
{
    this->year = year;
}

// ќпределение метода дл€ установки жанра виниловой пластинки
void VinylRecord::setGenre(string genre)
{
    this->genre = genre;
}

// ќпределение метода дл€ получени€ стоимости виниловой пластинке
void VinylRecord::setPrice(float price)
{
    this->price = price;
}

// ќпределение дл€ установки количества виниловой пластинки
void VinylRecord::setQuantity(int quantity)
{
    this->quantity = quantity;
}

// ќпределение метода дл€ получени€ названи€ виниловой пластинки
const string VinylRecord::getAlbumName()
{
    return albumName;
}

// ќпределение метода дл€ получени€ исполнител€ виниловой пластинки
const string VinylRecord::getArtist()
{
    return artist;
}

// ќпределение метода дл€ получени€ года выпуска виниловой пластинки
const int VinylRecord::getYear()
{
    return year;
}

// ќпределение метода дл€ получени€ жанра виниловой пластинки
const string VinylRecord::getGenre()
{
    return genre;
}

// ќпределение метода дл€ получени€ стоимости виниловой пластинке
const float VinylRecord::getPrice()
{
    return price;
}

// ќпределение дл€ получени€ количества виниловой пластинки
const int VinylRecord::getQuantity()
{
    return quantity;
}