#include "Functions.h"

// Функция для ввода информации о магазине
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

    // Создаем исключения на ввод некорректноко значения
    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~ОШИБКА~~\nКоличество пластинок должно быть положительным целым числом!\n");
    }
    if (numRecords <= 0)
    {
        throw exception("\n\t~~ПРЕДУПРЕЖДЕНИЕ~~\nКоличество пластинок должно быть больше нуля!\n");
    }

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

    // Создаем исключения на ввод некорректноко значения
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~ОШИБКА~~\nКоличество сотрудников должно быть положительным целым числом!\n");
    }
    if (numEmployees <= 0)
    {
        throw exception("\n\t~~ПРЕДУПРЕЖДЕНИЕ~~\nКоличество сотрудников должно быть больше нуля!\n");
    }

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

    // Освобождение памяти
    delete[] vinylRecordsArray;
    delete[] employeeArray;

    // Возвращаем созданный объект магазина
    return store;
}

// Функция для добавления виниловых пластинок в магазин
void addVinylRecordsToStore(Store& store)
{
    cout << "\n\t~~Добавление новых пластинок в магазин~~" << endl;

    cout << "-------------------------------------------" << endl;
    int numNewRecords;
    cout << "Введите количество новых виниловых пластинок: ";
    cin >> numNewRecords;

    // Создаем исключения на ввод некорректноко значения
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~ОШИБКА~~\nКоличество пластинок должно быть положительным целым числом!\n");
    }
    if (numNewRecords <= 0)
    {
        throw exception("\n\t~~ПРЕДУПРЕЖДЕНИЕ~~\nКоличество пластинок должно быть больше нуля!\n");
    }

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

// Функция для добавления сотрудников в магазин
void addEmployeesToStore(Store& store)
{
    cout << "\n\t~~Добавление новых сотрудников в магазин~~" << endl;

    cout << "-------------------------------------------" << endl;
    int numNewEmployees;
    cout << "Введите количество новых сотрудников: ";
    cin >> numNewEmployees;

    // Создаем исключения на ввод некорректноко значения
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~ОШИБКА~~\nКоличество сотрудников должно быть положительным целым числом!\n");
    }
    if (numNewEmployees <= 0)
    {
        throw exception("\n\t~~ПРЕДУПРЕЖДЕНИЕ~~\nКоличество сотрудников должно быть больше нуля!\n");
    }

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

// Функция для удаления виниловой пластинки из магазина
void removeVinylRecord(Store& store)
{
    // Создаем исключение по значению
    if (numRecords == 1)
    {
        throw exception("\n\t~~ПРЕДУПРЕЖДЕНИЕ~~\nНевозможно удалить единственную пластинку!\n");
    }

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
        throw exception("Ошибка: Некорректный индекс виниловой пластинки.\n");
    }

    cout << "-------------------------------------------" << endl;
}

// Функция для удаления сотрудника из магазина
void removeEmployee(Store& store)
{
    // Создаем исключение по значению
    if (numEmployees == 1) 
    {
        throw exception("\n\t~~ПРЕДУПРЕЖДЕНИЕ~~\nНевозможно удалить последнего сотрудника!\n");
    }

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
        throw exception("Ошибка: Некорректный индекс сотрудника.\n");
    }
    cout << "-------------------------------------------" << endl;
}

// Функция для ввода информации о заказах
Order* inputOrders(Store store, string vinylInfo[][3])
{
    cout << "\n\t~~Создание заказа~~" << endl;

    cout << "-------------------------------------------" << endl;
    cout << "Введите количество заказов: ";
    cin >> numOrders;

    // Создаем исключения на ввод некорректноко значения
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~ОШИБКА~~\nКоличество заказов должно быть положительным целым числом!\n");
    }
    if (numOrders <= 0)
    {
        throw exception("\n\t~~ПРЕДУПРЕЖДЕНИЕ~~\nКоличество заказов должно быть больше нуля!\n");
    }

    cin.ignore();

    // Создание массива для хранения заказов
    Order* ordersArray = new Order[numOrders];

    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < numOrders; ++i) {
        cout << "\tЗаказ #" << i + 1 << ":" << endl;

        string orderDate;

        cout << "-------------------------------------------" << endl;
        cout << "Введите дату заказа: ";
        getline(cin, orderDate);

        int employeeIndex;
        bool isValidChoice = false;

        cout << "-------------------------------------------" << endl;
        
        // Получаем указатель на массив сотрудников в магазине
        Employee* employees = store.getEmployeesInStore();
        store.outputEmployeesShortList();

        cout << "Выберите сотрудника, обслуживающего заказ: ";

        do {
            int choice;

            while (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\nНекорректный ввод!\n";
                cout << "Введите количество заказанных виниловых пластинок: ";
            }

            if (choice >= 1 && choice <= numEmployees) {
                employeeIndex = choice - 1;
                isValidChoice = true;
            }
            else {
                cout << "Некорректный выбор.\n" << endl;
                cout << "Выберите сотрудника, обслуживающего заказ: ";
            }
        } while (!isValidChoice);

        string clientFirstName, clientLastName, clientAddress;
        float clientMoney;

        cout << "-------------------------------------------" << endl;
        cout << "Введите информацию о клиенте, оформляющем заказ:" << endl;
        inputCustomer(&clientFirstName, &clientLastName, &clientMoney, &clientAddress);

        int vinylIndex;
        isValidChoice = false;

        cout << "-------------------------------------------" << endl;
        
        // Получаем указатель на массив виниловых пластинок в магазине
        VinylRecord* vinylRecords = store.getVinylRecordsInStore();
        store.outputVinylRecordsShortList();

        cout << "Выберите виниловую пластинку для заказа: ";

        do {
            int choice;

            while (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\nНекорректный ввод!\n";
                cout << "Выберите виниловую пластинку для заказа: ";
            }

            if (choice >= 1 && choice <= numRecords) {
                vinylIndex = choice - 1;
                isValidChoice = true;
            }
            else {
                cout << "Некорректный выбор.\n" << endl;
                cout << "Выберите виниловую пластинку для заказа: ";
            }
        } while (!isValidChoice);

        cout << "-------------------------------------------" << endl;
        int quantityOrdered;
        do {
            cout << "Введите количество заказанных виниловых пластинок: ";

            while (!(cin >> quantityOrdered)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\nНекорректный ввод!\n";
                cout << "Введите количество заказанных виниловых пластинок: ";
            }

            cin.ignore();
            cout << "-------------------------------------------" << endl;

            // Проверка на наличие пластинок в магазине (дружественная функция)
            if (!checkAvailability(vinylRecords[vinylIndex], quantityOrdered, store)) {
                cout << "Недостаточно пластинок в наличии. Пожалуйста, уточните количество." << endl;
            }
        } while (!checkAvailability(vinylRecords[vinylIndex], quantityOrdered, store));

        float totalCost = vinylRecords[vinylIndex].getPrice() * quantityOrdered;

        

        ordersArray[i] = Order(orderDate, employees[employeeIndex], Customer(clientFirstName, clientLastName, clientMoney, clientAddress), vinylRecords[vinylIndex], quantityOrdered, totalCost);

        // Добавляем информацию о виниловой пластинке и её итоговой стоимости в двумерный массив
        vinylInfo[i][0] = to_string(ordersArray[i].getOrderNumber()); // Номер заказа
        vinylInfo[i][1] = vinylRecords[vinylIndex].getAlbumName();    // Название виниловой пластинки
        vinylInfo[i][2] = to_string(totalCost);                       // Итоговая стоимость
    }

    return ordersArray;
}

// Функция для вывода информации о заказанных пластинках
void outputVinylInfo(string vinylInfo[][3]) {
    cout << "\n\t~~Информация о виниловых пластинках в заказах~~" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << setw(15) << left << "Номер заказа" << setw(30) << left << "Название пластинки" << setw(20) << left << "Итоговая стоимость" << endl;

    for (int i = 0; i < numOrders; ++i) {
        cout << setw(15) << left << vinylInfo[i][0] << setw(30) << left << vinylInfo[i][1] << setw(20) << left << vinylInfo[i][2] << endl;
    }
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

// Функция для вывода информации о заказах
void outputOrders(Order* ordersArray) {
    cout << "\n\t~~Информация о заказах~~" << endl;
    cout << "-------------------------------------------" << endl;

    for (int i = 0; i < numOrders; ++i) {
        cout << "Заказ #" << i + 1 << ":" << endl;
        ordersArray[i].outputOrder();
        cout << "-------------------------------------------" << endl;
    }
}

// Дружественная функция для проверки наличия достаточного количества заказанных пластинок в магазине
bool checkAvailability(VinylRecord& orderedRecord, int orderedQuantity, Store& store) {
    // Получаем список виниловых пластинок в магазине
    VinylRecord* vinylRecordsInStore = store.getVinylRecordsInStore();

    // Поиск заказанного альбома в магазине
    for (int i = 0; i < numRecords; ++i) {
        if (vinylRecordsInStore[i].getAlbumName() == orderedRecord.getAlbumName() &&
            vinylRecordsInStore[i].getArtist() == orderedRecord.getArtist()) {
            // Найден заказанный альбом в магазине
            // Проверяем, есть ли в наличии достаточное количество заказанных пластинок
            if (vinylRecordsInStore[i].getQuantity() >= orderedQuantity) {
                // Достаточное количество заказанных пластинок в наличии
                return true;
            }
            else {
                // Недостаточное количество заказанных пластинок в наличии
                return false;
            }
        }
    }

    // Заказанный альбом не найден в магазине
    return false;
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

    while (!(cin >> year)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nНекорректный ввод!\n";
        cout << "Введите год выпуска: ";
    }

    cin.ignore();

    cout << "Введите жанр: ";
    getline(cin, genre);

    cout << "Введите цену: ";

    while (!(cin >> price)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nНекорректный ввод!\n";
        cout << "Введите цену: ";
    }

    cout << "Введите количество в наличии: ";

    while (!(cin >> quantity)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nНекорректный ввод!\n";
        cout << "Введите количество в наличии: ";
    }
}

// Функция для ввода информации о клиенте (пример возврата через указатель)
void inputCustomer(string* firstName, string* lastName, float* money, string* address)
{
    cout << "Введите имя клиента: ";
    cin >> *firstName;

    cout << "Введите фамилию клиента: ";
    cin >> *lastName;

    cout << "Введите количества денег клиента: ";

    while (!(cin >> *money)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nНекорректный ввод!\n";
        cout << "Введите количества денег клиента: ";
    }

    cout << "Введите адрес доставки клиента: ";
    cin.ignore(); // Очищаем буфер для считывания строки
    getline(cin, *address);
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

    while (!(cin >> *salary)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\nНекорректный ввод!\n";
        cout << "Введите зарплату сотрудника: ";
    }
}