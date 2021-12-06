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
    const int var = (static_cast<int>('T') + static_cast<int>('A')) % 7; // var 2 Country
    cout << "\t Лабораторная работа №6. Вариант " << var<< ".\n";
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
    auto i = country_v.begin();
    cout << "-----Начальные данные-----\n";
    while(i!=country_v.end())
    {
        cout << *i << "\n";
        ++i;
    }
    
    char pressed_button;

    while(true)
    {
        ConsoleMenu();
        cin >> pressed_button;
	    switch (pressed_button)
	    {
        case '+':
        {
            system("cls");
            cout << "---Добавление элемента---\n";
            cout << "Введите новую страну и ее характеристики.\n";
            std::cout << "Известны население и инфляция?([y] - да, [n] - нет)\n >>>";
            char choice;
            std::cin >> choice;

            auto add_country = Country();
            if (choice =='y')
            {
	            std::cout << "Название страны:";
                string name;
                std::cin >> name;
                add_country.SetName(name);
                std::cout << "Население:";
                int population;
                std::cin >> population;
                add_country.SetPopulation(population);
                std::cout << "Инфляция:";
                double inflation;
                std::cin >> inflation;
                add_country.SetInflation(inflation);

                country_v.push_back(add_country);
            }
        }break;
        case '-':
        {
            system("cls");
            cout << "---Удаление элемента---\n";
            unsigned int index;
            const unsigned int v_size = country_v.size();
        	cout << "Введите индекс элемента: ";
            cin >> index;
            
            if (index < v_size - 1)
            {
	            std::cout << "Удален элемент с индексом "<<index<<":\n" << country_v[index] << "\n";
                country_v.erase(country_v.begin() + index);
                break;
            }
            if (index == v_size - 1)
            {
                std::cout << "Удален элемент с индексом " << index << ":\n" << country_v[index] << "\n";
                country_v.pop_back();
                break;
            }
            std::cout << "Элемент по такому индексу не существует.\n";
            
            
        }break;
        case 'o':
        {
            cout << "\n---Данные, находящиеся в данный момент в векторе---\n";
            auto i = country_v.begin();
            int cnt = 0;
            while (i != country_v.end())
            {
                std::cout<< ++cnt << ") " << *i << "\n";
                ++i;
            }
        }break;
        case 's':
        {
            system("cls");
            cout << "\n---Cортировка(возрастание/убывание)---\n";
            std::cout << "Выберите критерий сортировки:\n";
            std::cout << "1. По длине названия страны;\n";
            std::cout << "2. По населению;\n";
            std::cout << "3. По инфляции.\n";
            char criteria;
            std::cin >> criteria;
            std::cout << "Выберите тип сортировки:\n";
            std::cout << "1. По возрастанию;\n";
            std::cout << "2. По убыванию.\n";
            


        }break;
        case 'x':
        {

        }break;
        case 'a':
        {

        }break;
        case 'p':
        {

        }break;
        case 'i':
        {

        }break;
        case 'e':
        {
            system("cls");
            cout << "Завершение работы программы...";
            Sleep(2000);
        }break;
        default:
        {
            cout << "\nФункции на данную кнопку не назначено!\n";
        }break;
	    }
        if(pressed_button == 'e')
            break;
    }
    return 0;
}
