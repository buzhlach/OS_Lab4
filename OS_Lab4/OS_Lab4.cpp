// OS_Lab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "windows.h"
#include "BinaryTree.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    system("chcp 1251");
    BinaryTree tree;
    int m1 = 1;
    while (m1 != 0) {
        system("cls");
        cout << "Press 1, to add leaf." << endl;
        cout << "Press 2, to add n random leafs." << endl;
        cout << "Press 3, to find leaf by key." << endl;
        cout << "Press 4, to delete leaf." << endl;
        cout << "Press 5, to print tree" << endl;
        cout << "Press 6, to clear tree" << endl;
        cout << "Press 0, to exit." << endl;
        cin >> m1;
        switch (m1) {
        case 1:
            int key, data;
            system("cls");
            cout << "Write key of leaf:"<<endl;
            cin >> key;
            cout << "Write value of leaf:" << endl;
            cin >> data;
            tree.AddLeaf(key, data);
            break;
        case 2:
        {
            system("cls");
            int n = 0;
            cout << "Write n of leafs:";
            cin >> n;
            while (n < 0) {
                cout << "Error!!! Write n of leafs >=0:";
                cin >> n;
            }
            tree.AddRandomLeafs(n);
        }
            break;
        case 3: 
        {
            system("cls");
            cout << "Write key of leaf:" << endl;
            cin >> key;
            tree.FindLeafDataByKey(key);
            cout << endl << "Press any char & Enter to exit." << endl;
            string s;
            cin >> s; 
        }
            break;
        case 4:
        {
            system("cls");
            cout << "Write key of leaf:" << endl;
            cin >> key;
            tree.DeleteLeafByKey(key);
            cout << endl << "Press any char & Enter to exit." << endl;
            string s;
            cin >> s;
        }
            break;
        case 5:
        {system("cls");
        tree.PrintBinaryTree();
        cout <<endl<< "Press any char & Enter to exit." << endl;
        string s;
        cin >> s;
        }
            break;
        case 6:
            tree.~BinaryTree();
            break;
        case 0:
            break;
        default:
            cout << "Something goes wrong! Press Enter to go to menu & pay respects";
            getchar();
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
