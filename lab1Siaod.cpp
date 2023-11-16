#include <iostream>
#include <bitset>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdio.h> 
#include <time.h> 

using namespace std;

int task_1_1(int n) {
    int mask = (1 << 7) | (1 << 8) | (1 << 9) | (1 << 10) | (1 << 11);
    n |= mask; 
    // n = 0xFDD;
    return n;
}
int task_1_2(int n) {
    int mask = 0xF75F;
    n &= mask;
    return n;
}
int task_1_3(int n) {
    n <<= 5;
    return n;
}
int task_1_4(int n) {
    n >>= 5;
    return n;
}
int task_1_5(int num, int n) {
    int mask = 1 << n;
    mask = ~mask;
    num &= mask;
    return num;
}

int main()
{
    setlocale(LC_ALL, "RUS");
    cout << "30 вариант \n";
    cout << "Введите номер задания:\n";
    int numTask;
    cin >> numTask;
    vector<int> nums;
    unsigned char bitArray = 0;
    unsigned char bits[8] = { 0 };
    int num;
    switch (numTask) {
    case(1):
        cout << "Введите номер подзадания: \n";
        cin >> num;
        int variable;
        switch (num) {
        case (1):
            variable = 0x5D;
            cout << bitset<sizeof(int) * 4 >(variable) << endl;
            cout << bitset<sizeof(int) * 4 >(task_1_1(variable)) << endl;
            break;
        case (2):
            cin >> variable;
            cout << bitset<sizeof(int) * 4 >(variable) << endl;
            cout << bitset<sizeof(int) * 4 >(task_1_2(variable)) << endl;
            break;
        case(3):
            cin >> variable;
            cout << bitset<sizeof(int) * 4 >(variable) << endl;
            cout << bitset<sizeof(int) * 4 >(task_1_3(variable)) << endl;
            break;
        case(4):
            cin >> variable;
            cout << bitset<sizeof(int) * 4 >(variable) << endl;
            cout << bitset<sizeof(int) * 4 >(task_1_4(variable)) << endl;
            break;
        case(5):
            int bitNumber;
            cin >> variable;
            cin >> bitNumber;
            cout << bitset<sizeof(int) * 4 >(variable) << endl;
            cout << bitset<sizeof(int) * 4 >(task_1_5(variable, bitNumber)) << endl;
            break;
        }
        break;
    case(2):
        cout << "Введите номер подзадания: \n";
        cin >> num;
        switch (num) {
        case (1):
            cout << "Введите не более восьми чисел со значениями [0, 7]. Если желаете завершить ввод введите число 8\n";
            int n;
            while (cin >> n) {
                if (n == 8)
                    break;
                else {
                    nums.push_back(n);
                    bitArray |= (1 <<(7 - n % 8));
                }
            }

            cout << "Битовый массив:";
            cout << bitset<sizeof(int) * 2 >(bitArray) << endl;

            cout << "Отсортированный массив:";
            for (int i = 0; i < 8; i++) {
                if (bitArray & (1 << i))
                    cout << i << " ";
            }
            break;
        case (2):
            cout << "Введите не более 64 чисел со значениями [0, 63]. Если желаете завершить ввод введите число 64\n";
            while (cin >> n) {
                if (n == 64)
                    break;
                bits[n / 8] |= (1 << (7 - n % 8));
            }
            cout << "Битовый массив:";
            for (int i = 0; i < 8; i++) {
                cout << bitset<8>(bits[i]) << " ";
            }
            cout << "\nОтсортированный массив:";
            for (int i = 0; i < 8; i++) {
                for (int j = 7; j >= 0; j--) {
                    if (bits[i] & (1 << j))
                        cout << i * 8 + 7 - j << " ";
                }
            }
            break;
        }
        break;
    case (3):
        // тренировка на 20 чисел
        clock_t start = clock();

        ifstream inputFile("C:\\Users\\Sasha\\OneDrive\\Рабочий стол\\универ\\3_семестр\\СиАОД\\lab1Siaod\\input.txt");
        ofstream outputFile("C:\\Users\\Sasha\\OneDrive\\Рабочий стол\\универ\\3_семестр\\СиАОД\\lab1Siaod\\output.txt");
        if (inputFile.is_open()){
            cout << "open\n";
        }
        else {
            cout << "closed\n";
        }
        if (outputFile.is_open()) {
            cout << "open\n";
        }
        else {
            "closed\n";
        } 
        vector<int> bitArray2(1000 + 1, 0);

        int n;
        while (inputFile >> n) { bitArray2[n] = 1; }

        for (int i = 0; i <= 1000; i++) {
            if ((bitArray2[i] == 1))
            {
                outputFile << i << "\n";
            }
        }

        inputFile.close();
        outputFile.close();

        cout << "Тренировочный файл на 20 чисел отсортирован.\n";

        clock_t end = clock();
        double seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("The time: %f seconds\n", seconds);

        // на 100 чисел
        start = clock();

        ifstream inputFile100("C:\\Users\\Sasha\\OneDrive\\Рабочий стол\\универ\\3_семестр\\СиАОД\\lab1Siaod\\input100.txt");
        ofstream outputFile100("C:\\Users\\Sasha\\OneDrive\\Рабочий стол\\универ\\3_семестр\\СиАОД\\lab1Siaod\\output100.txt");

        vector<int> bitArray100(1000 + 1, 0);
        while (inputFile100 >> n) { bitArray100[n] = 1; }

        for (int i = 0; i <= 1000; i++) {
            if ((bitArray100[i] == 1))
            {
                outputFile100 << i << "\n";
            }
        }

        inputFile100.close();
        outputFile100.close();

        cout << "Файл на 100 чисел отсортирован.\n";

        end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("The time: %f seconds\n", seconds);

        // на 1000 чисел
        start = clock();

        ifstream inputFile1000("C:\\Users\\Sasha\\OneDrive\\Рабочий стол\\универ\\3_семестр\\СиАОД\\lab1Siaod\\input1000.txt");
        ofstream outputFile1000("C:\\Users\\Sasha\\OneDrive\\Рабочий стол\\универ\\3_семестр\\СиАОД\\lab1Siaod\\output1000.txt");

        vector<int> bitArray1000(10000 + 1, 0);
        while (inputFile1000 >> n) { bitArray1000[n] = 1; }

        for (int i = 0; i <= 10000; i++) {
            if ((bitArray1000[i] == 1))
            {
                outputFile1000 << i << "\n";
            }
        }

        inputFile1000.close();
        outputFile1000.close();

        cout << "Файл на 1000 чисел отсортирован.\n";

        end = clock();
        seconds = (double)(end - start) / CLOCKS_PER_SEC;
        printf("The time: %f seconds\n", seconds);
    }
    return (0);
}
