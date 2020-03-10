// OS_Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "windows.h"
#include "BinaryTree.h"

using namespace std;


int main()
{
    //буферы для Сonsole
    DWORD bufferDWORD;
    COORD point;
    point.X = 0; point.Y = 0;
    LPCWSTR bufferLPCWSTR;
    const char* bufferConstChar;
    char bufferCharArr[4];
    

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);

    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    BinaryTree tree;
    int m1 = 1;
    while (m1 != 0) {
        bufferLPCWSTR = L"MENU";
        SetConsoleTitle(bufferLPCWSTR);
        system("cls"); // очистка экрана
        bufferConstChar ="Press 1, to add leaf.\n";
        WriteFile(hOut, bufferConstChar,strlen(bufferConstChar),&bufferDWORD, NULL);

        bufferConstChar = "Press 2, to add n random leafs.\n";
        WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

        bufferConstChar = "Press 3, to find leaf by key.\n";
        WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

        bufferConstChar = "Press 4, to delete leaf.\n";
        WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

        bufferConstChar = "Press 5, to print tree.\n";
        WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

        bufferConstChar = "Press 6, to clear tree.\n";
        WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

        bufferConstChar = "Press 7, to write tree in file.\n";
        WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

        bufferConstChar = "Press 8, to read tree from file.\n";
        WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

        bufferConstChar = "Press 0, to exit.\n";
        WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
        ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
        m1 = atoi(bufferCharArr);
        switch (m1) {
        case 1:
        {
            int key, data;
            bufferLPCWSTR = L"Add leaf";
            SetConsoleTitle(bufferLPCWSTR);
            system("cls");
            bufferConstChar = "Write key of leaf:";
            WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
            
            ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
            key = atoi(bufferCharArr);

            bufferConstChar = "Write value of leaf:";
            WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
            
            ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
            data = atoi(bufferCharArr);
            tree.AddLeaf(key, data);
        }
            break;
        case 2:
        {
            system("cls");
            bufferLPCWSTR = L"Add n random leafs";
            SetConsoleTitle(bufferLPCWSTR);
            int n = 0;
            bufferConstChar = "Write n of leafs:\n";
            WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
            
            ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
            n = atoi(bufferCharArr);

            while (n < 0) {
                bufferConstChar = "Error!!! Write n of leafs >=0:";
                WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
                
                ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
                n = atoi(bufferCharArr);
            }
            tree.AddRandomLeafs(n);
        }
            break;
        case 3: 
        {
            int key;
            system("cls");
            bufferLPCWSTR = L"Find leaf by key";
            SetConsoleTitle(bufferLPCWSTR);

            bufferConstChar = "Write key of leaf:\n";
            WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

            ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
            key = atoi(bufferCharArr);


            tree.FindLeafDataByKey(key);

            bufferConstChar = "\nPress any char & Enter to exit.\n";
            WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);
            ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
        }
            break;
        case 4:
        {
            int key;
            system("cls");
            bufferLPCWSTR = L"Delete leaf";
            SetConsoleTitle(bufferLPCWSTR);

            bufferConstChar = "Write key of leaf:\n";
            WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

            ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
            key = atoi(bufferCharArr);
            tree.DeleteLeafByKey(key);

            bufferConstChar = "\nPress any char & Enter to exit.\n";
            WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

            ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
        }
            break;
        case 5:
        {   
            system("cls");
            bufferLPCWSTR = L"Print tree";
            SetConsoleTitle(bufferLPCWSTR);
            tree.PrintBinaryTree();

            bufferConstChar = "\nPress any char & Enter to exit.\n";
            WriteFile(hOut, bufferConstChar, strlen(bufferConstChar), &bufferDWORD, NULL);

            ReadFile(hIn, bufferCharArr, 4, &bufferDWORD, NULL);
        }
        break;
        case 6: {
            tree.~BinaryTree();
            break;
        }
        case 7: {
            tree.WriteBinaryTreeToFile();
            break;
        }
        case 8: {
            tree.ReadBinaryTreeFromFile();
            break;
        }
        case 0:
            break;
        default:
            break;
        }
    }
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
