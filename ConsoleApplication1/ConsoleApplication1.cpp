#include <iostream>

using namespace std;

struct WORKER {
    int tabNum;
    string name;
    string position;
    int year;
    double salary;
};

//������� �������������� ���������� � ��������� 
void editWorker(WORKER* w, WORKER& newW, int n) {
    bool b = false;
    while (b == false)
    {
        int count = 0;
        int tempnum;
        cout << "������� ��������� �����: ";
        cin >> tempnum;
        if (tempnum > 0) {
            for (int j = 0; j < n; j++) {
                if (w[j].tabNum == tempnum) {
                    cout << "�������� ����� ��� ����������" << endl;
                    count++;
                }
            }
            if (count == 0) {
                newW.tabNum = tempnum;
                b = true;
            }
        }
        else {
            cout << "������� �������� ������ ����" << endl;
        }
    }
    cout << "������� ���: ";
    cin >> newW.name;
    cout << "������� ���������: ";
    cin >> newW.position;
    cout << "������� ��� ����� �� ������: ";
    cin >> newW.year;
    cout << "������� ��������: ";
    cin >> newW.salary;
}

//������� ��� ����� ������� �������
void inputArray(WORKER* w, int n) {
    for (int i = 0; i < n; i++) {
        cout << "������� ���������� � ���������  " << i + 1 << ": \n";
        bool b = false;
        while (b == false)
        {
            int count = 0;
            int tempnum;
            cout << "������� ��������� �����: ";
            cin >> tempnum;
            for (int j = 0; j < n; j++) {
                if (w[j].tabNum == tempnum) {
                    cout << "�������� ����� ��� ����������" << endl;
                    count++;
                }
            }
            if (count == 0) {
                w[i].tabNum = tempnum;
                b = true;
            }
        }
        cout << "������� ���: ";
        cin >> w[i].name;
        cout << "������� ���������: ";
        cin >> w[i].position;
        cout << "������� ��� ����� �� ������: ";
        cin >> w[i].year;
        cout << "������� ��������: ";
        cin >> w[i].salary;
    }
    cout << "\n";
}

//������� ��� ������ ������� ������� 
void printArray(WORKER* w, int n, int ident) {
    cout << "Tab Number\tName\t\tPosition\tYear\tSalary\n";
    cout << "----------\t----\t\t--------\t----\t------\n";
    if (ident == 1) {
        cout << w->tabNum << "\t\t" << w->name << "\t\t" << w->position << "\t\t" << w->year << "\t" << w->salary << "\n";
    }
    else {
        for (int i = 0; i < n; i++) {
            cout << w[i].tabNum << "\t\t" << w[i].name << "\t\t" << w[i].position << "\t\t" << w[i].year << "\t" << w[i].salary << "\n";
        }
    }
    cout << "\n";
}

//������� ��� ���������� ������� ������� �� �����
void sortArray(WORKER* w, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (w[i].name < w[j].name) {
                WORKER temp = w[i];
                w[i] = w[j];
                w[j] = temp;
            }
        }
    }
    cout << "������ ������������ �� ��������\n\n";
}

//������� ������ ��������� �� ���������� ������  
WORKER searchWorker(WORKER* w, int n, int tabNum) {
    for (int i = 0; i < n; i++) {
        if (w[i].tabNum == tabNum)
            return w[i];
    }
    WORKER notFound;
    notFound.name = "��� ���������� � ����� �������.";
    return notFound;
}

//������� ��� ������ ���� ������� �� ������ ������ x 
void workerExperience(WORKER* w, int n, int x) {
    int currentYear = 2023;
    int count = 0;
    cout << "����� ���������� �� ������ ������ ��� " << x << " ���:\n\n";
    for (int i = 0; i < n; i++) {
        if (currentYear - w[i].year > x) {
            cout << w[i].name << "\n";
            count += 1;
        }
    }
    if (count == 0) { cout << "��� ���������� � ����� ������" << endl; }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n, exp, ch;
    cout << "������� ���������� ����������: ";
    cin >> n;
    WORKER* w = new WORKER[n]; // ������ �����������
    inputArray(w, n);
    while (true) {
        int tabNum = 0;
        cout << "2. ������� ������� �������\n";
        cout << "3. ����������� ������� �� ��������\n";
        cout << "4. ����� �������� �� ���������� ������\n";
        cout << "5. ������� ������ ������� �� �����\n";
        cout << "6. �������� ������ � ���������\n";
        cout << "�������� ���� �����: ";
        cin >> ch; cout << endl;
        WORKER found;
        switch(ch) 
        {
        case 2:
            // ����� �������
            printArray(w, n, 0);
            break;
        case 3:
            // ���������� �������
            sortArray(w, n);
            break;
        case 4:
            // ����� ����������
            cout << "������� ����� ��� ������: ";
            cin >> tabNum;
            if (tabNum > 0) {
                found = searchWorker(w, n, tabNum);
                if (found.name != "��� ���������� � ����� �������.") {
                    cout << "��������� ������:\n\n";
                    printArray(&found, n, 1);
                }                
                else {
                    cout << "��� ���������� � ����� �������." << endl << endl;
                }
            }
            else {
                cout << "������� �������� ������ 0" << endl << endl;
            }
            break;
            
        case 5:
            // ������� ������ ������� �� �����
            while (true){
                cout << "\n������� ����������� ���� (� �����): ";
                cin >> exp;
                if (exp >= 0) {
                    break;
                }
            }
            workerExperience(w, n, exp);
            break;
        case 6:
            // Edit worker 
            cout << "\n������� ����� ���������� ��� ���������: ";
            cin >> tabNum;
            WORKER* newW = 0;
            for (int i = 0; i < n; i++) {
                if (w[i].tabNum == tabNum)
                    newW = &w[i];
            }
            if (newW == 0)
                cout << "��� ���������� � ����� �������.\n";
            else {
                cout << "\n��������� ���������  " << newW->name << ":\n";
                editWorker(w, *newW, n);
                cout << "\n������ ��������.\n";
            }
            break;
        }
    }
    return 0;
}