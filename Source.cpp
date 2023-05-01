#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>

using namespace std;

// ������� ��� ��������� ������ ����� � ��������� ������
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

    cout << "��������� ����� ��������!";
}

// ������� ��� ��������� ������� ��� �� ��������� ����� � �����
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
    numWords++; // ������ ����� �� ������ ������ ���� ����, ���� ������ ���� ������
}

// ������� ��� ������ ������� ��� �� ��������� ����� � ����� ����
void writeModifiedFile(string inputFileName, string outputFileName) {
    string inputLine;
    int numWords, numDelimiters;

    // ³�������� ������� �� �������� ����
    ifstream inputFile(inputFileName);
    ofstream outputFile(outputFileName);

    // ������� ����� ����� � �������� �����, ���������� ������� ��� �� ��������� �����,
    // �������� �� �������� �� ������� ����� �� �������� ����� � �������� ����
    while (getline(inputFile, inputLine)) {
        countWordsAndDelimiters(inputLine, numWords, numDelimiters);
        outputFile << numWords << " " << inputLine << " " << numDelimiters << "\n";
    }

    // ��������� �����
    inputFile.close();
    outputFile.close();
}

// ������� ��� ��������� ����� ����� �� �����
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

    cout << "������ ��'� ������� �����: ";
    cin >> Firstfile;

    cout << "������ ��'� ������� �����: ";
    cin >> SecondFile;

    cin.ignore();

    int menuItem;

    do {
        cout << endl << endl << endl;
        cout << "������� ��:" << endl << endl;
        cout << " [1] - ��������� ���������� ������" << endl;
        cout << " [2] - ���� ������" << endl;
        cout << " [3] - ������������ ��������� �����" << endl;
        cout << " [0] - ����� �� ���������� ������ ��������" << endl << endl;
        cout << "������ ��������: "; cin >> menuItem;
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
            cout << "�� ����� ��������� ��������! "
                "��� ������ ����� - ����� ��������� ������ ����" << endl;
        }
    } while (menuItem != 0);

    return 0;
}

