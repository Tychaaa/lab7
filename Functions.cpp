#include "Functions.h"

Store inputStore() 
{
    cout << "\n\t~~Создание магазина~~" << endl;
    cout << "-------------------------------------------" << endl;

    string name, address;

    cout << "Введите название магазина: ";
    getline(cin, name);

    cout << "Введите адрес магазина: ";
    getline(cin, address);

    cout << "-------------------------------------------" << endl;

    cout << "Введите количество виниловых пластинок: ";
    cin >> numRecords;

    cout << "-------------------------------------------" << endl;

    // Динамический массив объектов класса VinylRecord
    VinylRecord* vinylRecordsArray = new VinylRecord[numRecords];

    for (int i = 0; i < numRecords; ++i) {
        // Ввод данных о виниловой пластинке
        string album, artist, genre;
        int year, quantity;
        float price;

        cout << "Виниловая пластинка #" << i + 1 << endl;
        inputVinylRecord(album, artist, year, genre, price, quantity);

        // Создание объекта и добавление его в массив
        vinylRecordsArray[i] = VinylRecord(album, artist, year, genre, price, quantity);

        cout << "-------------------------------------------" << endl;
    }

    cout << "Введите количество сотрудников магазина: ";
    cin >> numEmployees;

    cout << "-------------------------------------------" << endl;

    // Динамический массив объектов класса Employee
    Employee* employeeArray = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        // Ввод данных о сотруднике
        string firstName, lastName, position;
        float salary;

        cout << "Сотрудник #" << i + 1 << ":" << endl;
        inputEmployee(&firstName, &lastName, &position, &salary);

        // Создание объекта и добавление его в массив
        employeeArray[i] = Employee(firstName, lastName, position, salary);

        cout << "-------------------------------------------" << endl;
    }

    // Создаем магазин с использованием конструктора с параметрами и возвращаем его
    Store store(name, address, vinylRecordsArray, employeeArray);

    delete[] vinylRecordsArray;
    delete[] employeeArray;

    // Возвращаем созданный объект магазина
    return store;
}

void addVinylRecordsToStore(Store& store)
{
    cout << "\n\t~~Добавление новых пластинок в магазин~~" << endl;

    cout << "-------------------------------------------" << endl;
    int numNewRecords;
    cout << "Введите количество новых виниловых пластинок: ";
    cin >> numNewRecords;

    int newTotalRecords = numRecords + numNewRecords;

    // Получаем указатель на массив виниловых пластинок в магазине
    VinylRecord* oldRecords = store.getVinylRecordsInStore();

    // Создаем временный массив, куда скопируем существующие пластинки
    VinylRecord* tempRecords = new VinylRecord[newTotalRecords];

    // Копируем существующие пластинки во временный массив
    for (int i = 0; i < numRecords; ++i) {
        tempRecords[i] = oldRecords[i];
    }

    cout << "-------------------------------------------" << endl;
    // Вводим и добавляем новые пластинки во временный массив
    for (int i = numRecords; i < newTotalRecords; ++i) {
        // Ввод данных о виниловой пластинке
        string album, artist, genre;
        int year, quantity;
        float price;

        cout << "Виниловая пластинка #" << i + 1 << endl;
        inputVinylRecord(album, artist, year, genre, price, quantity);
        cout << "-------------------------------------------" << endl;

        // Создаем новую пластинку и добавляем во временный массив
        tempRecords[i] = VinylRecord(album, artist, year, genre, price, quantity);
    }

    // Обновляем количество пластинок в магазине
    numRecords = newTotalRecords;

    // Обновляем массив пластинок магазина на новый временный массив
    store.setVinylRecordsInStore(tempRecords);

    delete[] tempRecords;
}

void addEmployeesToStore(Store& store)
{
    cout << "\n\t~~Добавление новых сотрудников в магазин~~" << endl;

    cout << "-------------------------------------------" << endl;
    int numNewEmployees;
    cout << "Введите количество новых сотрудников: ";
    cin >> numNewEmployees;

    int newTotalEmployees = numEmployees + numNewEmployees;

    // Получаем указатель на массив сотрудников в магазине
    Employee* oldEmployees = store.getEmployeesInStore();

    // Создаем временный массив, куда скопируем существующих сотрудников
    Employee* tempEmployees = new Employee[newTotalEmployees];

    // Копируем существующих сотрудников во временный массив
    for (int i = 0; i < numEmployees; ++i) {
        tempEmployees[i] = oldEmployees[i];
    }

    cout << "-------------------------------------------" << endl;
    // Вводим и добавляем новых сотрудников во временный массив
    for (int i = numEmployees; i < newTotalEmployees; ++i) {
        // Ввод данных о сотруднике
        string firstName, lastName, position;
        float salary;

        cout << "Сотрудник #" << i + 1 << ":" << endl;
        inputEmployee(&firstName, &lastName, &position, &salary);
        cout << "-------------------------------------------" << endl;

        // Создаем нового сотрудника и добавляем во временный массив
        tempEmployees[i] = Employee(firstName, lastName, position, salary);
    }

    // Обновляем количество сотрудников в магазине
    numEmployees = newTotalEmployees;

    // Обновляем массив сотрудников магазина на новый временный массив
    store.setEmployeesInStore(tempEmployees);

    delete[] tempEmployees;
}

void removeVinylRecord(Store& store)
{
    cout << "\n\t~~Удаление виниловых пластинок из магазина~~" << endl;

    cout << "-------------------------------------------" << endl;
    store.outputVinylRecordsShortList();
    cout << "-------------------------------------------" << endl;

    int index;
    cout << "Выберите виниловую пластинку для удаления: ";
    cin >> index;

    // Получаем указатель на массив виниловых пластинок в магазине
    VinylRecord* vinylRecords = store.getVinylRecordsInStore();

    // Проверяем, что индекс находится в допустимых пределах
    if (index >= 1 && index <= numRecords)
    {
        // Смещаем пластинки, начиная с удаленного индекса, чтобы "заменить" удаленную пластинку
        for (int i = index - 1; i < numRecords; ++i)
        {
            vinylRecords[i] = vinylRecords[i + 1];
        }

        // Уменьшаем количество виниловых пластинок в магазине
        numRecords--;

        // Обновляем массив виниловых пластинок магазина
        store.setVinylRecordsInStore(vinylRecords);

        cout << "Виниловая пластинка успешно удалена!" << endl;
    }
    else
    {
        cout << "Некорректный индекс виниловой пластинки." << endl;
    }

    cout << "-------------------------------------------" << endl;
}

void removeEmployee(Store& store)
{
    cout << "\n\t~~Удаление сотрудников из магазина~~" << endl;

    cout << "-------------------------------------------" << endl;
    store.outputEmployeesShortList();
    cout << "-------------------------------------------" << endl;

    int index;
    cout << "Выберите сотрудника для удаления: ";
    cin >> index;

    // Получаем указатель на массив сотрудников в магазине
    Employee* employees = store.getEmployeesInStore();

    // Проверяем, что индекс находится в допустимых пределах
    if (index >= 1 && index <= numEmployees)
    {
        // Смещаем сотрудников, начиная с удаленного индекса, чтобы "заменить" удаленного сотрудника
        for (int i = index - 1; i < numEmployees; ++i)
        {
            employees[i] = employees[i + 1];
        }

        // Уменьшаем количество сотрудников в магазине
        numEmployees--;

        // Обновляем массив сотрудников магазина
        store.setEmployeesInStore(employees);

        cout << "Сотрудник успешно удален!" << endl;
    }
    else
    {
        cout << "Некорректный индекс сотрудника." << endl;
    }
    cout << "-------------------------------------------" << endl;
}

// Функция для ввода информации о виниловой пластинке (пример возврата через ссылку)
void inputVinylRecord(string& album, string& artist, int& year, string& genre, float& price, int& quantity)
{
    cin.ignore();

    cout << "Введите название альбома: ";
    getline(cin, album);

    cout << "Введите исполнителя: ";
    getline(cin, artist);

    cout << "Введите год выпуска: ";
    cin >> year;
    cin.ignore();

    cout << "Введите жанр: ";
    getline(cin, genre);

    cout << "Введите цену: ";
    cin >> price;

    cout << "Введите количество в наличии: ";
    cin >> quantity;
}

// Функция для ввода информации о клиенте (пример возврата через указатель)
void inputCustomer(string* firstName, string* lastName, float* money, string* address)
{
    cout << "Введите имя клиента: ";
    cin >> *firstName;

    cout << "Введите фамилию клиента: ";
    cin >> *lastName;

    cout << "Введите количества денег клиента: ";
    cin >> *money;

    cout << "Введите адрес доставки клиента: ";
    cin.ignore(); // Очищаем буфер для считывания строки
    getline(cin, *address);

    cout << endl;
}

// Функция для ввода информации о сотруднике магазина
void inputEmployee(string* firstName, string* lastName, string* position, float* salary) 
{

    cout << "Введите имя сотрудника: ";
    cin >> *firstName;

    cout << "Введите фамилию сотрудника: ";
    cin >> *lastName;

    cout << "Введите должность сотрудника: ";
    cin.ignore();
    getline(cin, *position);

    cout << "Введите зарплату сотрудника: ";
    cin >> *salary;
}