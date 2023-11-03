#include "Functions.h"

Store inputStore() 
{
    cout << "\n\t~~—оздание магазина~~" << endl;
    cout << "-------------------------------------------" << endl;

    string name, address;

    cout << "¬ведите название магазина: ";
    getline(cin, name);

    cout << "¬ведите адрес магазина: ";
    getline(cin, address);

    cout << "-------------------------------------------" << endl;

    cout << "¬ведите количество виниловых пластинок: ";
    cin >> numRecords;

    cout << "-------------------------------------------" << endl;

    // ƒинамический массив объектов класса VinylRecord
    VinylRecord* vinylRecordsArray = new VinylRecord[numRecords];

    for (int i = 0; i < numRecords; ++i) {
        // ¬вод данных о виниловой пластинке
        string album, artist, genre;
        int year, quantity;
        float price;

        cout << "¬инилова€ пластинка #" << i + 1 << endl;
        inputVinylRecord(album, artist, year, genre, price, quantity);

        // —оздание объекта и добавление его в массив
        vinylRecordsArray[i] = VinylRecord(album, artist, year, genre, price, quantity);

        cout << "-------------------------------------------" << endl;
    }

    cout << "¬ведите количество сотрудников магазина: ";
    cin >> numEmployees;

    cout << "-------------------------------------------" << endl;

    // ƒинамический массив объектов класса Employee
    Employee* employeeArray = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        // ¬вод данных о сотруднике
        string firstName, lastName, position;
        float salary;

        cout << "—отрудник #" << i + 1 << ":" << endl;
        inputEmployee(&firstName, &lastName, &position, &salary);

        // —оздание объекта и добавление его в массив
        employeeArray[i] = Employee(firstName, lastName, position, salary);

        cout << "-------------------------------------------" << endl;
    }

    // —оздаем магазин с использованием конструктора с параметрами и возвращаем его
    Store store(name, address, vinylRecordsArray, employeeArray);

    delete[] vinylRecordsArray;
    delete[] employeeArray;

    // ¬озвращаем созданный объект магазина
    return store;
}

// ‘ункци€ дл€ ввода информации о виниловой пластинке
void inputVinylRecord(string& album, string& artist, int& year, string& genre, float& price, int& quantity)
{
    cin.ignore();

    cout << "¬ведите название альбома: ";
    getline(cin, album);

    cout << "¬ведите исполнител€: ";
    getline(cin, artist);

    cout << "¬ведите год выпуска: ";
    cin >> year;
    cin.ignore();

    cout << "¬ведите жанр: ";
    getline(cin, genre);

    cout << "¬ведите цену: ";
    cin >> price;

    cout << "¬ведите количество в наличии: ";
    cin >> quantity;
}

// ‘ункци€ дл€ ввода информации о клиенте
void inputCustomer(string* firstName, string* lastName, float* money, string* address)
{
    cout << "¬ведите им€ клиента: ";
    cin >> *firstName;

    cout << "¬ведите фамилию клиента: ";
    cin >> *lastName;

    cout << "¬ведите количества денег клиента: ";
    cin >> *money;

    cout << "¬ведите адрес доставки клиента: ";
    cin.ignore(); // ќчищаем буфер дл€ считывани€ строки
    getline(cin, *address);

    cout << endl;
}

// ‘ункци€ дл€ ввода информации о сотруднике магазина
void inputEmployee(string* firstName, string* lastName, string* position, float* salary) 
{

    cout << "¬ведите им€ сотрудника: ";
    cin >> *firstName;

    cout << "¬ведите фамилию сотрудника: ";
    cin >> *lastName;

    cout << "¬ведите должность сотрудника: ";
    cin.ignore();
    getline(cin, *position);

    cout << "¬ведите зарплату сотрудника: ";
    cin >> *salary;
}