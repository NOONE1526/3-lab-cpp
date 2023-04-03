#include <iostream>

using namespace std;

struct WORKER {
    int tabNum;
    string name;
    string position;
    int year;
    double salary;
};

//Функция редактирования информации о работнике 
void editWorker(WORKER* w, WORKER& newW, int n) {
    bool b = false;
    while (b == false)
    {
        int count = 0;
        int tempnum;
        cout << "Введите табельный номер: ";
        cin >> tempnum;
        if (tempnum > 0) {
            for (int j = 0; j < n; j++) {
                if (w[j].tabNum == tempnum) {
                    cout << "введённый номер уже существует" << endl;
                    count++;
                }
            }
            if (count == 0) {
                newW.tabNum = tempnum;
                b = true;
            }
        }
        else {
            cout << "Введите значение больше нуля" << endl;
        }
    }
    cout << "Введите имя: ";
    cin >> newW.name;
    cout << "Введите должность: ";
    cin >> newW.position;
    cout << "Введите год приёма на работу: ";
    cin >> newW.year;
    cout << "Введите зарплату: ";
    cin >> newW.salary;
}

//Функция для ввода массива рабочих
void inputArray(WORKER* w, int n) {
    for (int i = 0; i < n; i++) {
        cout << "Введите информацию о работнике  " << i + 1 << ": \n";
        bool b = false;
        while (b == false)
        {
            int count = 0;
            int tempnum;
            cout << "Введите табельный номер: ";
            cin >> tempnum;
            for (int j = 0; j < n; j++) {
                if (w[j].tabNum == tempnum) {
                    cout << "введённый номер уже существует" << endl;
                    count++;
                }
            }
            if (count == 0) {
                w[i].tabNum = tempnum;
                b = true;
            }
        }
        cout << "Введите имя: ";
        cin >> w[i].name;
        cout << "Введите должность: ";
        cin >> w[i].position;
        cout << "Введите год приёма на работу: ";
        cin >> w[i].year;
        cout << "Введите зарплату: ";
        cin >> w[i].salary;
    }
    cout << "\n";
}

//Функция для вывода массива рабочих 
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

//Функция для сортировки массива рабочих по имени
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
    cout << "Массив отсортирован по алфавиту\n\n";
}

//Функция поиска работника по табельному номеру  
WORKER searchWorker(WORKER* w, int n, int tabNum) {
    for (int i = 0; i < n; i++) {
        if (w[i].tabNum == tabNum)
            return w[i];
    }
    WORKER notFound;
    notFound.name = "Нет работников с таким номером.";
    return notFound;
}

//Функция для вывода имен рабочих со стажем больше x 
void workerExperience(WORKER* w, int n, int x) {
    int currentYear = 2023;
    int count = 0;
    cout << "Имена работников со стажем больше чем " << x << " лет:\n\n";
    for (int i = 0; i < n; i++) {
        if (currentYear - w[i].year > x) {
            cout << w[i].name << "\n";
            count += 1;
        }
    }
    if (count == 0) { cout << "Нет работников с таким стажем" << endl; }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "ru");
    int n, exp, ch;
    cout << "Введите количество работников: ";
    cin >> n;
    WORKER* w = new WORKER[n]; // Массив сотрудников
    inputArray(w, n);
    while (true) {
        int tabNum = 0;
        cout << "2. Вывести таблицу рабочих\n";
        cout << "3. Сортировать таблицу по алфавиту\n";
        cout << "4. Поиск рабочего по табельному номеру\n";
        cout << "5. Вывести список рабочих по стажу\n";
        cout << "6. Изменить данные о работнике\n";
        cout << "Выберите один пункт: ";
        cin >> ch; cout << endl;
        WORKER found;
        switch(ch) 
        {
        case 2:
            // Вывод массива
            printArray(w, n, 0);
            break;
        case 3:
            // Сортировка массива
            sortArray(w, n);
            break;
        case 4:
            // Поиск сотрудника
            cout << "Введите номер для поиска: ";
            cin >> tabNum;
            if (tabNum > 0) {
                found = searchWorker(w, n, tabNum);
                if (found.name != "Нет работников с таким номером.") {
                    cout << "Результат поиска:\n\n";
                    printArray(&found, n, 1);
                }                
                else {
                    cout << "Нет работников с таким номером." << endl << endl;
                }
            }
            else {
                cout << "введите значение больше 0" << endl << endl;
            }
            break;
            
        case 5:
            // Вывести список рабочих по стажу
            while (true){
                cout << "\nВведите минимальный стаж (в годах): ";
                cin >> exp;
                if (exp >= 0) {
                    break;
                }
            }
            workerExperience(w, n, exp);
            break;
        case 6:
            // Edit worker 
            cout << "\nВведите номер сотрудника для изменения: ";
            cin >> tabNum;
            WORKER* newW = 0;
            for (int i = 0; i < n; i++) {
                if (w[i].tabNum == tabNum)
                    newW = &w[i];
            }
            if (newW == 0)
                cout << "Нет работников с таким номером.\n";
            else {
                cout << "\nИзменение работника  " << newW->name << ":\n";
                editWorker(w, *newW, n);
                cout << "\nДанные изменены.\n";
            }
            break;
        }
    }
    return 0;
}