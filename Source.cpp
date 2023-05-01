#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// Функція для створення нового файлу з текстовим вмістом
void createFile(string fileName) {
    ofstream fout(fileName);
    char ch;
    string s;
    do
    {
        cin.get();
        cin.sync();
        cout << "enter line: "; getline(cin, s);
        fout << s << endl;
        cout << "continue? (y/n): "; cin >> ch;
    } while (ch == 'y' || ch == 'Y');

    cout << endl;

    cout << "Текстовий масив створено!";
}

// Функція для підрахунку кількості слів та розділових знаків у рядку
void countWordsAndDelimiters(string inputLine, int& numWords, int& numDelimiters) {
    numWords = 0;
    numDelimiters = 0;
    for (char& c : inputLine) {
        if (isspace(c) || ispunct(c)) {
            numWords++;
        }
        if (ispunct(c)) {
            numDelimiters++;
        }
    }
    numWords++; // Останнє слово не містить пробілу після себе, тому додаємо його окремо
}

// Функція для запису кількості слів та розділових знаків у новий файл
void writeModifiedFile(string inputFileName, string outputFileName) {
    string inputLine;
    int numWords, numDelimiters;

    // Відкриваємо вхідний та вихідний файл
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // Зчитуємо кожен рядок з вхідного файлу, підраховуємо кількість слів та розділових знаків,
    // дописуємо ці значення на початок рядка та записуємо рядок у вихідний файл
    while (getline(inputFile, inputLine)) {
        countWordsAndDelimiters(inputLine, numWords, numDelimiters);
        outputFile << numWords << " " << inputLine << " " << numDelimiters << "\n";
    }

    // Закриваємо файли
    inputFile.close();
    outputFile.close();
}

// Функція для виведення вмісту файлу на екран
void printFile(string fileName)
{
    ifstream fin(fileName);
    string s;
    while (getline(fin, s))
    {
        cout << s << endl;
    }
    cout << endl;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    string Firstfile, SecondFile;

    cout << "Введіть ім'я першого файлу: ";
    cin >> Firstfile;

    cout << "Введіть ім'я другого файлу: ";
    cin >> SecondFile;

    cin.ignore();

    int menuItem;

    do {
        cout << endl << endl << endl;
        cout << "Виберіть дію:" << endl << endl;
        cout << " [1] - створення текстового масиву" << endl;
        cout << " [2] - вивід данних" << endl;
        cout << " [3] - модифікувати текстовий масив" << endl;
        cout << " [0] - вихід та завершення роботи програми" << endl << endl;
        cout << "Введіть значення: "; cin >> menuItem;
        cout << endl << endl << endl;

        switch (menuItem)
        {
        case 1:
            createFile(Firstfile);
            break;
        case 2:
            printFile(Firstfile);
            break;
        case 3:
            writeModifiedFile(Firstfile, SecondFile);
            printFile(SecondFile);
            break;
        case 0:
            break;
        default:
            cout << "Ви ввели помилкове значення! "
                "Слід ввести число - номер вибраного пункту меню" << endl;
        }
    } while (menuItem != 0);

    return 0;
}

