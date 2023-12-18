#include "Functions.h"

// ������� ��� ����� ���������� � ��������
Store inputStore() 
{
    cout << "\n\t~~�������� ��������~~" << endl;
    cout << "-------------------------------------------" << endl;

    string name, address;

    cout << "������� �������� ��������: ";
    getline(cin, name);

    cout << "������� ����� ��������: ";
    getline(cin, address);

    cout << "-------------------------------------------" << endl;

    cout << "������� ���������� ��������� ���������: ";
    cin >> numRecords;

    // ������� ���������� �� ���� ������������� ��������
    if (cin.fail()) 
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~������~~\n���������� ��������� ������ ���� ������������� ����� ������!\n");
    }
    if (numRecords <= 0)
    {
        throw exception("\n\t~~��������������~~\n���������� ��������� ������ ���� ������ ����!\n");
    }

    cout << "-------------------------------------------" << endl;

    // ������������ ������ �������� ������ VinylRecord
    VinylRecord* vinylRecordsArray = new VinylRecord[numRecords];

    for (int i = 0; i < numRecords; ++i) {
        // ���� ������ � ��������� ���������
        string album, artist, genre;
        int year, quantity;
        float price;

        cout << "��������� ��������� #" << i + 1 << endl;
        inputVinylRecord(album, artist, year, genre, price, quantity);

        // �������� ������� � ���������� ��� � ������
        vinylRecordsArray[i] = VinylRecord(album, artist, year, genre, price, quantity);

        cout << "-------------------------------------------" << endl;
    }

    cout << "������� ���������� ����������� ��������: ";
    cin >> numEmployees;

    // ������� ���������� �� ���� ������������� ��������
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~������~~\n���������� ����������� ������ ���� ������������� ����� ������!\n");
    }
    if (numEmployees <= 0)
    {
        throw exception("\n\t~~��������������~~\n���������� ����������� ������ ���� ������ ����!\n");
    }

    cout << "-------------------------------------------" << endl;

    // ������������ ������ �������� ������ Employee
    Employee* employeeArray = new Employee[numEmployees];

    for (int i = 0; i < numEmployees; i++) {
        // ���� ������ � ����������
        string firstName, lastName, position;
        float salary;

        cout << "��������� #" << i + 1 << ":" << endl;
        inputEmployee(&firstName, &lastName, &position, &salary);

        // �������� ������� � ���������� ��� � ������
        employeeArray[i] = Employee(firstName, lastName, position, salary);

        cout << "-------------------------------------------" << endl;
    }

    // ������� ������� � �������������� ������������ � ����������� � ���������� ���
    Store store(name, address, vinylRecordsArray, employeeArray);

    // ������������ ������
    delete[] vinylRecordsArray;
    delete[] employeeArray;

    // ���������� ��������� ������ ��������
    return store;
}

OnlineStore inputOnlineStore(Store& baseStore)
{
    cout << "\n\t~~�������� ��������-��������~~" << endl;
    cout << "-------------------------------------------" << endl;

    // ���� �������������� ������ ��� ��������-��������
    string website, storeEmail, storePhone;
    vector<string> supportedPaymentMethods;

    cout << "������� ���-���� ��������-��������: ";
    getline(cin, website);

    cout << "������� email ��������-��������: ";
    getline(cin, storeEmail);

    cout << "������� ������� ��������-��������: ";
    getline(cin, storePhone);

    // ���� �������������� ������� ������
    cout << "������� �������������� ������ ������ (������� 'end' ��� ����������):" << endl;
    string paymentMethod;
    while (true) {
        cout << "����� ������: ";
        getline(cin, paymentMethod);

        if (paymentMethod == "end") {
            break;
        }

        supportedPaymentMethods.push_back(paymentMethod);
    }

    // ������� ������ ��������-�������� � �������������� ������������ � �����������
    OnlineStore onlineStore(baseStore.getStoreName(), baseStore.getStoreAddress(),
        baseStore.getVinylRecordsInStore(), baseStore.getEmployeesInStore(),
        supportedPaymentMethods, website, storeEmail, storePhone);

    // ���������� ��������� ������ ��������-��������
    return onlineStore;
}

// ������� ��� ���������� ��������� ��������� � �������
void addVinylRecordsToStore(Store& store, OnlineStore& onlineStore)
{
    cout << "\n\t~~���������� ����� ��������� � �������~~" << endl;

    cout << "-------------------------------------------" << endl;
    int numNewRecords;
    cout << "������� ���������� ����� ��������� ���������: ";
    cin >> numNewRecords;

    // ������� ���������� �� ���� ������������� ��������
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~������~~\n���������� ��������� ������ ���� ������������� ����� ������!\n");
    }
    if (numNewRecords <= 0)
    {
        throw exception("\n\t~~��������������~~\n���������� ��������� ������ ���� ������ ����!\n");
    }

    int newTotalRecords = numRecords + numNewRecords;

    // �������� ��������� �� ������ ��������� ��������� � ��������
    VinylRecord* oldRecords = store.getVinylRecordsInStore();

    // ������� ��������� ������, ���� ��������� ������������ ���������
    VinylRecord* tempRecords = new VinylRecord[newTotalRecords];

    // �������� ������������ ��������� �� ��������� ������
    for (int i = 0; i < numRecords; ++i) {
        tempRecords[i] = oldRecords[i];
    }

    cout << "-------------------------------------------" << endl;
    // ������ � ��������� ����� ��������� �� ��������� ������
    for (int i = numRecords; i < newTotalRecords; ++i) {
        // ���� ������ � ��������� ���������
        string album, artist, genre;
        int year, quantity;
        float price;

        cout << "��������� ��������� #" << i + 1 << endl;
        inputVinylRecord(album, artist, year, genre, price, quantity);
        cout << "-------------------------------------------" << endl;

        // ������� ����� ��������� � ��������� �� ��������� ������
        tempRecords[i] = VinylRecord(album, artist, year, genre, price, quantity);
    }

    // ��������� ���������� ��������� � ��������
    numRecords = newTotalRecords;

    // ��������� ������ ��������� �������� �� ����� ��������� ������
    store.setVinylRecordsInStore(tempRecords);
    onlineStore.setVinylRecordsInStore(tempRecords);

    delete[] tempRecords;
}

// ������� ��� ���������� ����������� � �������
void addEmployeesToStore(Store& store, OnlineStore& onlineStore)
{
    cout << "\n\t~~���������� ����� ����������� � �������~~" << endl;

    cout << "-------------------------------------------" << endl;
    int numNewEmployees;
    cout << "������� ���������� ����� �����������: ";
    cin >> numNewEmployees;

    // ������� ���������� �� ���� ������������� ��������
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~������~~\n���������� ����������� ������ ���� ������������� ����� ������!\n");
    }
    if (numNewEmployees <= 0)
    {
        throw exception("\n\t~~��������������~~\n���������� ����������� ������ ���� ������ ����!\n");
    }

    int newTotalEmployees = numEmployees + numNewEmployees;

    // �������� ��������� �� ������ ����������� � ��������
    Employee* oldEmployees = store.getEmployeesInStore();

    // ������� ��������� ������, ���� ��������� ������������ �����������
    Employee* tempEmployees = new Employee[newTotalEmployees];

    // �������� ������������ ����������� �� ��������� ������
    for (int i = 0; i < numEmployees; ++i) {
        tempEmployees[i] = oldEmployees[i];
    }

    cout << "-------------------------------------------" << endl;
    // ������ � ��������� ����� ����������� �� ��������� ������
    for (int i = numEmployees; i < newTotalEmployees; ++i) {
        // ���� ������ � ����������
        string firstName, lastName, position;
        float salary;

        cout << "��������� #" << i + 1 << ":" << endl;
        inputEmployee(&firstName, &lastName, &position, &salary);
        cout << "-------------------------------------------" << endl;

        // ������� ������ ���������� � ��������� �� ��������� ������
        tempEmployees[i] = Employee(firstName, lastName, position, salary);
    }

    // ��������� ���������� ����������� � ��������
    numEmployees = newTotalEmployees;

    // ��������� ������ ����������� �������� �� ����� ��������� ������
    store.setEmployeesInStore(tempEmployees);
    onlineStore.setEmployeesInStore(tempEmployees);

    delete[] tempEmployees;
}

// ������� ��� �������� ��������� ��������� �� ��������
void removeVinylRecord(Store& store, OnlineStore& onlineStore)
{
    // ������� ���������� �� ��������
    if (numRecords == 1)
    {
        throw exception("\n\t~~��������������~~\n���������� ������� ������������ ���������!\n");
    }

    cout << "\n\t~~�������� ��������� ��������� �� ��������~~" << endl;

    cout << "-------------------------------------------" << endl;
    store.outputVinylRecordsShortList();
    cout << "-------------------------------------------" << endl;

    int index;
    cout << "�������� ��������� ��������� ��� ��������: ";
    cin >> index;

    // �������� ��������� �� ������ ��������� ��������� � ��������
    VinylRecord* vinylRecords = store.getVinylRecordsInStore();

    // ���������, ��� ������ ��������� � ���������� ��������
    if (index >= 1 && index <= numRecords)
    {
        // ������� ���������, ������� � ���������� �������, ����� "��������" ��������� ���������
        for (int i = index - 1; i < numRecords; ++i)
        {
            vinylRecords[i] = vinylRecords[i + 1];
        }

        // ��������� ���������� ��������� ��������� � ��������
        numRecords--;

        // ��������� ������ ��������� ��������� ��������
        store.setVinylRecordsInStore(vinylRecords);
        onlineStore.setVinylRecordsInStore(vinylRecords);

        cout << "��������� ��������� ������� �������!" << endl;
    }
    else
    {
        throw exception("������: ������������ ������ ��������� ���������.\n");
    }

    cout << "-------------------------------------------" << endl;
}

// ������� ��� �������� ���������� �� ��������
void removeEmployee(Store& store, OnlineStore& onlineStore)
{
    // ������� ���������� �� ��������
    if (numEmployees == 1) 
    {
        throw exception("\n\t~~��������������~~\n���������� ������� ���������� ����������!\n");
    }

    cout << "\n\t~~�������� ����������� �� ��������~~" << endl;

    cout << "-------------------------------------------" << endl;
    store.outputEmployeesShortList();
    cout << "-------------------------------------------" << endl;

    int index;
    cout << "�������� ���������� ��� ��������: ";
    cin >> index;

    // �������� ��������� �� ������ ����������� � ��������
    Employee* employees = store.getEmployeesInStore();

    // ���������, ��� ������ ��������� � ���������� ��������
    if (index >= 1 && index <= numEmployees)
    {
        // ������� �����������, ������� � ���������� �������, ����� "��������" ���������� ����������
        for (int i = index - 1; i < numEmployees; ++i)
        {
            employees[i] = employees[i + 1];
        }

        // ��������� ���������� ����������� � ��������
        numEmployees--;

        // ��������� ������ ����������� ��������
        store.setEmployeesInStore(employees);
        onlineStore.setEmployeesInStore(employees);

        cout << "��������� ������� ������!" << endl;
    }
    else
    {
        throw exception("������: ������������ ������ ����������.\n");
    }
    cout << "-------------------------------------------" << endl;
}

// ������� ��� ����� ���������� � �������
vector<Order> inputOrders(Store store, string vinylInfo[][3])
{
    cout << "\n\t~~�������� ������~~" << endl;

    cout << "-------------------------------------------" << endl;
    cout << "������� ���������� �������: ";
    cin >> numOrders;

    // ������� ���������� �� ���� ������������� ��������
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("\n\t\t~~������~~\n���������� ������� ������ ���� ������������� ����� ������!\n");
    }
    if (numOrders <= 0)
    {
        throw exception("\n\t~~��������������~~\n���������� ������� ������ ���� ������ ����!\n");
    }

    cin.ignore();

    // �������� ������� ��� �������� �������
    vector<Order> ordersVector;

    cout << "-------------------------------------------" << endl;
    for (int i = 0; i < numOrders; ++i) {
        cout << "\t����� #" << i + 1 << ":" << endl;

        string orderDate;

        cout << "-------------------------------------------" << endl;
        cout << "������� ���� ������: ";
        getline(cin, orderDate);

        int employeeIndex;
        bool isValidChoice = false;

        cout << "-------------------------------------------" << endl;
        
        // �������� ��������� �� ������ ����������� � ��������
        Employee* employees = store.getEmployeesInStore();
        store.outputEmployeesShortList();

        cout << "�������� ����������, �������������� �����: ";

        do {
            int choice;

            while (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\n������������ ����!\n";
                cout << "������� ���������� ���������� ��������� ���������: ";
            }

            if (choice >= 1 && choice <= numEmployees) {
                employeeIndex = choice - 1;
                isValidChoice = true;
            }
            else {
                cout << "������������ �����.\n" << endl;
                cout << "�������� ����������, �������������� �����: ";
            }
        } while (!isValidChoice);

        string clientFirstName, clientLastName, clientAddress;
        float clientMoney;

        cout << "-------------------------------------------" << endl;
        cout << "������� ���������� � �������, ����������� �����:" << endl;
        inputCustomer(&clientFirstName, &clientLastName, &clientMoney, &clientAddress);

        int vinylIndex;
        isValidChoice = false;

        cout << "-------------------------------------------" << endl;
        
        // �������� ��������� �� ������ ��������� ��������� � ��������
        VinylRecord* vinylRecords = store.getVinylRecordsInStore();
        store.outputVinylRecordsShortList();

        cout << "�������� ��������� ��������� ��� ������: ";

        do {
            int choice;

            while (!(cin >> choice)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\n������������ ����!\n";
                cout << "�������� ��������� ��������� ��� ������: ";
            }

            if (choice >= 1 && choice <= numRecords) {
                vinylIndex = choice - 1;
                isValidChoice = true;
            }
            else {
                cout << "������������ �����.\n" << endl;
                cout << "�������� ��������� ��������� ��� ������: ";
            }
        } while (!isValidChoice);

        cout << "-------------------------------------------" << endl;
        int quantityOrdered;
        do {
            cout << "������� ���������� ���������� ��������� ���������: ";

            while (!(cin >> quantityOrdered)) {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "\n������������ ����!\n";
                cout << "������� ���������� ���������� ��������� ���������: ";
            }

            cin.ignore();
            cout << "-------------------------------------------" << endl;

            // �������� �� ������� ��������� � �������� (������������� �������)
            if (!checkAvailability(vinylRecords[vinylIndex], quantityOrdered, store)) {
                cout << "������������ ��������� � �������. ����������, �������� ����������." << endl;
            }
        } while (!checkAvailability(vinylRecords[vinylIndex], quantityOrdered, store));

        float totalCost = vinylRecords[vinylIndex].getPrice() * quantityOrdered;

        // ���������� ������ � ������
        ordersVector.push_back(Order(orderDate, employees[employeeIndex], Customer(clientFirstName, clientLastName, clientMoney, clientAddress), vinylRecords[vinylIndex], quantityOrdered, totalCost));

        // ��������� ���������� � ��������� ��������� � � �������� ��������� � ��������� ������
        vinylInfo[i][0] = to_string(ordersVector[i].getOrderNumber()); // ����� ������
        vinylInfo[i][1] = vinylRecords[vinylIndex].getAlbumName();      // �������� ��������� ���������
        vinylInfo[i][2] = to_string(totalCost);                         // �������� ���������
    }

    return ordersVector;
}

// ������� ��� ������ ���������� � ���������� ����������
void outputVinylInfo(string vinylInfo[][3]) {
    cout << "\n\t~~���������� � ��������� ���������� � �������~~" << endl;
    cout << "---------------------------------------------------------------" << endl;

    cout << setw(15) << left << "����� ������" << setw(30) << left << "�������� ���������" << setw(20) << left << "�������� ���������" << endl;

    for (int i = 0; i < numOrders; ++i) {
        cout << setw(15) << left << vinylInfo[i][0] << setw(30) << left << vinylInfo[i][1] << setw(20) << left << vinylInfo[i][2] << endl;
    }
    cout << "---------------------------------------------------------------" << endl;
    cout << endl;
}

// ����������� ������� ��� ������ ���������� � �������
void outputOrders(vector<Order>& ordersVector) {
    cout << "\n\t~~���������� � �������~~" << endl;
    cout << "-------------------------------------------" << endl;

    for (size_t i = 0; i < ordersVector.size(); ++i) {
        cout << "����� #" << i + 1 << ":" << endl;
        ordersVector[i].outputOrder();
        cout << "-------------------------------------------" << endl;
    }
}

// ������� ��� ���������� ������� �� ������ ������ � �������� ������ �������
vector<Order> getSortedOrderByOrderNumber(vector<Order>& ordersVector) {
    vector<Order> sortedOrders = ordersVector;
    sort(sortedOrders.begin(), sortedOrders.end(), [](Order& a, Order& b) {
        return a.getOrderNumber() < b.getOrderNumber();
        });
    return sortedOrders;
}


// ������� ��� ���������� ������� �� �������� ��������� � �������� ������ �������
vector<Order> getSortedOrderByTotalCostDescending(vector<Order>& ordersVector) {
    vector<Order> sortedOrders = ordersVector;
    sort(sortedOrders.begin(), sortedOrders.end(), [](Order& a, Order& b) {
        return a.getTotalCost() > b.getTotalCost();
        });
    return sortedOrders;
}


// ������������� ������� ��� �������� ������� ������������ ���������� ���������� ��������� � ��������
bool checkAvailability(VinylRecord& orderedRecord, int orderedQuantity, Store& store) {
    // �������� ������ ��������� ��������� � ��������
    VinylRecord* vinylRecordsInStore = store.getVinylRecordsInStore();

    // ����� ����������� ������� � ��������
    for (int i = 0; i < numRecords; ++i) {
        if (vinylRecordsInStore[i].getAlbumName() == orderedRecord.getAlbumName() &&
            vinylRecordsInStore[i].getArtist() == orderedRecord.getArtist()) {
            // ������ ���������� ������ � ��������
            // ���������, ���� �� � ������� ����������� ���������� ���������� ���������
            if (vinylRecordsInStore[i].getQuantity() >= orderedQuantity) {
                // ����������� ���������� ���������� ��������� � �������
                return true;
            }
            else {
                // ������������� ���������� ���������� ��������� � �������
                return false;
            }
        }
    }

    // ���������� ������ �� ������ � ��������
    return false;
}

// ������� ��� ����� ���������� � ��������� ��������� (������ �������� ����� ������)
void inputVinylRecord(string& album, string& artist, int& year, string& genre, float& price, int& quantity)
{
    cin.ignore();

    cout << "������� �������� �������: ";
    getline(cin, album);

    cout << "������� �����������: ";
    getline(cin, artist);

    cout << "������� ��� �������: ";

    while (!(cin >> year)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n������������ ����!\n";
        cout << "������� ��� �������: ";
    }

    cin.ignore();

    cout << "������� ����: ";
    getline(cin, genre);

    cout << "������� ����: ";

    while (!(cin >> price)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n������������ ����!\n";
        cout << "������� ����: ";
    }

    cout << "������� ���������� � �������: ";

    while (!(cin >> quantity)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n������������ ����!\n";
        cout << "������� ���������� � �������: ";
    }
}

// ������� ��� ����� ���������� � ������� (������ �������� ����� ���������)
void inputCustomer(string* firstName, string* lastName, float* money, string* address)
{
    cout << "������� ��� �������: ";
    cin >> *firstName;

    cout << "������� ������� �������: ";
    cin >> *lastName;

    cout << "������� ���������� ����� �������: ";

    while (!(cin >> *money)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n������������ ����!\n";
        cout << "������� ���������� ����� �������: ";
    }

    cout << "������� ����� �������� �������: ";
    cin.ignore(); // ������� ����� ��� ���������� ������
    getline(cin, *address);
}

// ������� ��� ����� ���������� � ���������� ��������
void inputEmployee(string* firstName, string* lastName, string* position, float* salary) 
{
    cout << "������� ��� ����������: ";
    cin >> *firstName;

    cout << "������� ������� ����������: ";
    cin >> *lastName;

    cout << "������� ��������� ����������: ";
    cin.ignore();
    getline(cin, *position);

    cout << "������� �������� ����������: ";

    while (!(cin >> *salary)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n������������ ����!\n";
        cout << "������� �������� ����������: ";
    }
}

// ���� �������������� ��������
void editStoreMenu(Store& vinylStore, OnlineStore& onlineStore) {
    int input;
    do {
        system("cls"); // ������� ������

        // ������� ��������� ���������
        cout << "\t~~������������ ������ �6~~" << endl;
        cout << endl;

        // ������� ���� �������������� ��������
        cout << "���� �������������� ��������:" << endl;
        cout << "1. �������� ��������� � �������" << endl;
        cout << "2. �������� ����������� � �������" << endl;
        cout << "3. ������� ��������� �� ������������" << endl;
        cout << "4. ������� ���������� �� ��������" << endl;
        cout << "0. ��������� � ������� ����" << endl;
        cout << "\n�������� ��������: ";

        while (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ����! �������� ��������: ";
        }
        cin.ignore();

        switch (input) {
        case 1:
            // ���������� ��������� � �������
            if (StoreCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        addVinylRecordsToStore(vinylStore, onlineStore);
                        cout << "����� ���������� ������� 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "����� ���������� ������� 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 2:
            // ���������� ����������� � �������
            if (StoreCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        addEmployeesToStore(vinylStore, onlineStore);
                        cout << "����� ���������� ������� 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "����� ���������� ������� 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 3:
            // �������� ��������� �� ������������ ��������
            if (StoreCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        removeVinylRecord(vinylStore, onlineStore);
                        cout << "����� ���������� ������� 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "����� ���������� ������� 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 4:
            // �������� ���������� �� ��������
            if (StoreCreated)
            {
                do {
                    try
                    {
                        system("cls");
                        removeEmployee(vinylStore, onlineStore);
                        cout << "����� ���������� ������� 'Esc'" << endl;
                    }
                    catch (const std::exception& ex)
                    {
                        cout << ex.what() << endl;
                        cout << "����� ���������� ������� 'Esc'" << endl;
                    }
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 0:
            return; // ������������ � ������� ����
        default:
            cout << "������������ �����!" << std::endl;
        }
    } while (true);
}

// ���� ������ ����������
void outputInformationMenu(Store& vinylStore, vector<Order>& ordersVector, string vinylInfo[][3], OnlineStore& onlineStore) {
    int input;
    do {
        system("cls"); // ������� ������

        // ������� ��������� ���������
        cout << "\t~~������������ ������ �6~~" << endl;
        cout << endl;

        // ������� ���� ������ ����������
        cout << "���� ������ ����������:" << endl;
        cout << "1. ���������� ���������� � �������� (����� Display)" << endl;
        cout << "2. ���������� ���������� � �������� (�������� <<)" << endl;
        cout << "3. ���������� ���������� � ��������-�������� (����� Display)" << endl;
        cout << "4. ���������� ���������� � ��������-�������� (�������� <<)" << endl;
        cout << "5. ���������� ���������� � �����������" << endl;
        cout << "6. ���������� ����������� ��������" << endl;
        cout << "7. ���������� ���������� � ������" << endl;
        cout << "8. ���������� ���������� � ������ (���������� �� ���������)" << endl;
        cout << "9. ���������� ���������� � ������ (���������� �� ������ ������)" << endl;
        cout << "10. ���������� ���������� � ���������� ����������" << endl;
        cout << "0. ��������� � ������� ����" << endl;
        cout << "\n�������� ��������: ";

        while (!(cin >> input)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "������������ ����! �������� ��������: ";
        }
        cin.ignore();

        switch (input) {
        case 1:
            // ����� ���������� � �������� (����� Display)
            if (StoreCreated)
            {
                do {
                    system("cls");
                    vinylStore.outputStore();
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 2:
            // ����� ���������� � �������� (�������� <<)
            if (StoreCreated)
            {
                do {
                    system("cls");
                    cout << vinylStore << endl; // �������� ����� Display ��������� �������� <<
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 3:
            // ����� ���������� � ��������-�������� (����� Display)
            if (OnlineStoreCreated)
            {
                do {
                    system("cls");
                    onlineStore.outputStore();
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 4:
            // ����� ���������� � ��������-�������� (�������� <<)
            if (OnlineStoreCreated)
            {
                do {
                    system("cls");
                    cout << onlineStore << endl; // �������� ����� Display ��������� �������� <<
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 5:
            // ����� ���������� � �����������
            if (StoreCreated)
            {
                do {
                    system("cls");
                    vinylStore.outputEmployees();
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 6:
            // ����� ������������ ��������
            if (StoreCreated)
            {
                do {
                    system("cls");
                    vinylStore.outputVinylRecords();
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n������ ��� ��������������� ���� ��������, �������� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 7:
            // ����� ���������� � ������
            if (StoreCreated && OrderCreated)
            {
                do {
                    system("cls");
                    // �������� ������������� ������� �� ������
                    outputOrders(ordersVector);
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n�� ������ ������ �� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 8:
            // ����� ���������� � ������ (��������������� �� ��������� �������)
            if (StoreCreated && OrderCreated)
            {
                do {
                    system("cls");
                    // �������� ��������������� ������ �� �������� ��������� ������ (�� ��������)
                    vector<Order> sortedOrderByTotalCost = getSortedOrderByTotalCostDescending(ordersVector);
                    // ����� ���������������� ������ �������
                    outputOrders(sortedOrderByTotalCost);
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n�� ������ ������ �� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 9:
            // ����� ���������� � ������ (��������������� �� ������ ������)
            if (StoreCreated && OrderCreated)
            {
                do {
                    system("cls");
                    // �������� ��������������� ������ �� ������ ������
                    vector<Order> sortedOrderByOrderNumber = getSortedOrderByOrderNumber(ordersVector);
                    // ����� ���������������� ������ �������
                    outputOrders(sortedOrderByOrderNumber);
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n�� ������ ������ �� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 10:
            // ����� ���������� � ���������� ����������
            if (StoreCreated && OrderCreated)
            {
                do {
                    system("cls");
                    outputVinylInfo(vinylInfo);
                    cout << "����� ��������� �������� ������� 'Esc'" << endl;
                } while (_getch() != ESCAPE);
            }
            else {
                cout << "\n�� ������ ������ �� �������!" << endl;
                Sleep(1500);
            }
            break;
        case 0:
            return; // ������������ � ������� ����
        default:
            cout << "������������ �����!" << endl;
        }
    } while (true);
}