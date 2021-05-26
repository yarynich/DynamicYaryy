// DynamicYaryy.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#pragma comment(lib, "C:\\Users\\eyary\\source\\repos\\DLLYaryy\\Release\\DLLYaryy.lib") //автоматически залинкует библиотеку
#include <iostream>
#include "windows.h"

typedef int(group_number)(int);
typedef void(name_sername)(char*);

int main()
{
    HINSTANCE hDll=LoadLibrary(L"DLLYaryy.dll");
    if (hDll == NULL)
    {
        std::cout << L"Ошибка подключения библиотеки!";
        return 1;
    }

    group_number* g_number;
    name_sername* s_name;
    g_number = (group_number*)GetProcAddress(hDll, "g_number");
    s_name = (name_sername*)GetProcAddress(hDll, "s_name");
    if (g_number == NULL)
    {
        std::cout << L"Ошибка подключения функции number";
        return 1;
    }
    if (s_name == NULL)
    {
        std::cout << L"Ошибка подключения функции name";
        return 1;
    }

    std::cout << "Number of group: " << g_number(561220) << "\n";
    char name[20];
    s_name(name);
    std::cout << "Name and sername: " << name << "\n";
    system("pause");
    FreeLibrary(hDll);
    return 0;
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
