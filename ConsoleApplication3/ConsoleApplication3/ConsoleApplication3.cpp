// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <chrono>
using namespace std;

void bubbleSorting(int *Mass) {
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 99; j++) {
            if (Mass[j] > Mass[j + 1]) {
                swap(Mass[j], Mass[j + 1]);
            }
        }
    }
}

void swapElement(int a, int b ,int *Mass) {
    swap(Mass[a], Mass[b]);
}

void averageValue(int max, int min, int* Mass) {
    int coincidences = 0;
    int average;

    average = (max + min) / 2;

    for (int i = 0; i < 100; i++)
    {
        if (Mass[i] == average) {
            coincidences++;
            cout << "Индекс числа в массиве равного среднему " << i << endl;
        }
    }

    cout << average << " " << coincidences << endl;
}

void findMaxMinAverage(int max, int min, int* Mass) {


    for (int i = 0; i < 100; i++) {
        if (Mass[i] > max) {
            max = Mass[i];
        }
    }

    for (int j = 99; j > 0; j--) {
        if (Mass[j] < min) {
            min = Mass[j];
        }
    }

    averageValue(max, min, Mass);

    cout << max << " " << min << endl;
}

void moreThem(int a, int *Mass) {
    int count = 0;
    for (int i = 0; i < 100; i++) {
        if (Mass[i] > a) {
            count++;
        }
    }
    cout << "Количесво элементов больше введенного числа " << count << endl;
}

void lessThem(int b, int* Mass) {
    int count = 0;
    for (int i = 0; i < 100; i++) {
        if (Mass[i] < b) {
            count++;
        }
    }
    cout << "Количесво элементов меньше введенного числа " << count << endl;
}

void checkMass(int c, int *Mass) {
    int countNumber = 0;
    for (int i = 0; i < 100; i++) {
        if (Mass[i] == c) {
            countNumber++;
        }
    }
    if (countNumber > 0) {
        cout << "число найдено в массиве" << endl;
    } else {
        cout << "число не найдено в массиве" << endl;
    }

}

void binarySearch(int c, int* Mass) {
    int l = 0;
    int r = 99;
    int mid;
    bool flag = false;
    while ((l <= r) && (!flag == true)) {
        mid = (l + r) / 2;

        if (Mass[mid] == c) {
            flag = true;
        }

        if (Mass[mid] > c) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    if (flag) {
        cout << "число найдено в массиве";
    }
    else {
        cout << " число не найдено в массиве";
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int a, b, c, d, min = 0, max = 0;
    int Mass[100];

    for (int i = 0; i < 100; i++) {
        Mass[i] = rand() % 200 - 100;
    }

    for (int j = 0; j < 100; j++) {
        cout << Mass[j] << endl;
    }


    findMaxMinAverage(max, min, Mass);


    auto start = std::chrono::system_clock::now();
    bubbleSorting(Mass);
    auto end = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    std::cout << "Затраченное время на сортировку: " << elapsed.count() << " секунд" << endl;

    for (int j = 0; j < 100; j++) {
        cout << Mass[j] << endl;
    }
    
    cout << "Введите число для поиска в массиве количества элементов больше чем это число" << endl;
    cin >> a;

    moreThem(a, Mass);

    cout << "Введите число для поиска в массиве количества элементов меньше чем это число" << endl;
    cin >> b;

    lessThem(b, Mass);

    cout << "введите число для поиска его в массиве " << endl;
    cin >> c;
    
    checkMass(c, Mass);

    cout << "введите число для поиска его в массиве " << endl;
    cin >> d;

    binarySearch(d, Mass);
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
