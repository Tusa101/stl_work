#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <functional>
#include "country_class.h"
#include <vector>
using namespace std;
void ConsoleMenu();

int main()
{
    SetConsoleCP(121);
    SetConsoleOutputCP(1251);
    int Var = (int('T') + int('A')) % 7; // var 2 Country
    cout << "\t Лабораторная работа №6. Вариант " << Var<< ".\n";
    cout << " (в лабораторной работе используется контейнер vector)\n\n\n";
  
    Country co_arr[] = { {"Russia",146,7},//0
						   {"USA",332, 6.2},//1
						   {"China",1443,2.5},//2
                           {"England",67,4.2},//3
                           {"Australia",26,2},//4
                           {"Finland",6, 2},//5
                           {"Brasil",213,3.78},//6
                           {"India",1382,4}};//7

    vector<Country> country_v(co_arr, co_arr + 8);
    vector<Country>::iterator i = country_v.begin();
    cout << "-----Начальные данные-----\n";
    while(i!=country_v.end())
    {
        cout << *i << "\n";
        i++;
    }
    ConsoleMenu();
}
