#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <functional>
#include <numeric>
#include "country_class.h"
#include <vector>
//#include "algo_overloads.h"

using namespace std;

void DeletedMessage(unsigned int& index, const std::vector<Country>& country_v);
void ConsoleMenu();
void DisplayVector(std::vector<Country>& country_v);


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
            
            auto add_country = Country();

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
           
        }break;
        case '-':
        {
            system("cls");
            cout << "---Удаление элемента---\n";
            unsigned int index;
            const unsigned int v_size = country_v.size();
        	cout << "Введите индекс элемента: ";
            cin >> index;
            
            if (index > 0 && index < v_size)
            {
                DeletedMessage(index, country_v);
                country_v.erase(country_v.begin() + index - 1);
                break;
            }
            if (index == v_size)
            {
                DeletedMessage(index, country_v);
                country_v.pop_back();
                break;
            }
            std::cout << "Элемент по такому индексу не существует.\n";
            
            
        }break;
        case 'o':
        {
            system("cls");
            std::cout << "\n---Данные, находящиеся в данный момент в векторе---\n";
            DisplayVector(country_v);
        }break;
        case 's':
        {
            system("cls");
            cout << "\n---Cортировка---\n";
            std::cout << "Выберите критерий сортировки:\n";
            std::cout << "1. По длине названия страны;\n";
            std::cout << "2. По алфавиту;\n";
            std::cout << "3. По инфляции;\n";
            std::cout << "4. По населению.\n";
            std::cout << "\n >>> ";
            int criteria;
            std::cin >> criteria;
            switch (criteria)
            {
            case 1:
            {
	            std::cout << "---Сортировка по длине названия---\n";
                sort(country_v.begin(), country_v.end(), [](const Country& ctr1, const Country ctr2)
                {
	                return ctr1.GetName().length() > ctr2.GetName().length();
                });
                DisplayVector(country_v);
            }break;
            case 2:
            {
                std::cout << "---Сортировка по алфавиту---\n";
                auto smth{ [](const Country& ctr1, const Country& ctr2){return ctr1.GetName() < ctr2.GetName();} };
                sort(country_v.begin(), country_v.end(), [](const Country& ctr1, const Country& ctr2)
                {
					return ctr1.GetName() < ctr2.GetName();
                });
                DisplayVector(country_v);
            }break;
            case 3:
            {
                std::cout << "---Сортировка по инфляции---\n";
                sort(country_v.begin(), country_v.end(), [](const Country & ctr1, const Country & ctr2) 
                {
                    return ctr1.GetInflation() > ctr2.GetInflation();
                });
                DisplayVector(country_v);
            }break;
            case 4:
            {
                std::cout << "---Сортировка по населению---\n";
                sort(country_v.begin(), country_v.end(), [](const Country & ctr1, const Country & ctr2) 
                {
                    return ctr1.GetPopulation() > ctr2.GetPopulation();
                });
                DisplayVector(country_v);
            }break;
            default:
            {
                cout << "\nФункции на данную кнопку не назначено!\n";
            }break;
            }
        }break;
        case 'x':
        {
            system("cls");
	        std::cout << "  ---Нахождение максимума/минимума---\n";
            std::cout << "\t(инфляция -> население)\n";
            std::cout << "Выберите интересующий параметр:\n";
            std::cout << "1. Максимум;\n";
            std::cout << "2. Минимум.\n";
            std::cout << ">>> ";
            int criteria;
            std::cin >> criteria;
            auto Extremum{ [](const Country& ctr1, const Country& ctr2)
            {
                if (ctr1.GetInflation() == ctr2.GetInflation())
                {
                    return ctr1.GetPopulation() < ctr2.GetPopulation();
                }
                return ctr1.GetInflation() < ctr2.GetInflation();
            }};
            switch (criteria)
            {
            case 1:
            {
                auto iterator = max_element(country_v.begin(), country_v.end(), Extremum);
                cout << "Максимальный элемент на позиции " << distance(country_v.begin(), iterator) + 1 << ":\n" << *iterator << "\n";
            }break;
            case 2:
            {
                auto iterator = min_element(country_v.begin(), country_v.end(), Extremum);
                cout << "Минимальный элемент на позиции " << distance(country_v.begin(), iterator) + 1 <<":\n"<< *iterator << "\n";
            }break;
			default:
            {
                cout << "\nФункции на данную кнопку не назначено!\n";
            }break;
            }
        }break;
        case 'a':
        {
	        std::cout << "---Вычисление агрегированного значения---\n";
            Country sum = accumulate(country_v.begin(), country_v.end(), Country("",0,0), plus<Country>());
	        std::cout << "Суммарная численность населения стран = "<< sum.GetPopulation() <<" млн.чел.\n";
        }break;
        case 'p':
        {
            system("cls");
            std::cout << "---Поиск элемента по  значению---\n";
            std::cout << "1.Поиск страны с инфляцией inflation = N;\n";
            std::cout << "2.Поиск страны с названием = N;\n";
            std::cout << "3.Поиск страны с населением population = N.\n";
            std::cout << "\nНомер критерия>>> ";
            int criteria;
            std::cin >> criteria;
            std::cout << "\nN = ";
            
            switch (criteria)
            {
            case 1:
            {
                double inflation;
                std::cin >> inflation;
                std::cout << "Страна с инфляцией inflation = " << inflation << ": \n";
                auto country = find_if(country_v.begin(), country_v.end(), [&inflation](const Country& country) 
                    {
                        return country.GetInflation() == inflation;
                    });

            	if (country == country_v.end())
                {
                    std::cout << "Страны с такой инфляцией нет!!!";
                }
                else
                {
                    std::cout << *country << "\n";
                }
            }break;
            case 2:
            {
                string name;
                std::cin >> name;
                std::cout << "Страна с названием = " << name << ": \n";
                auto country = find_if(country_v.begin(), country_v.end(), [&name](const Country& country) 
                {
                    return country.GetName() == name;
                });

                if (country == country_v.end())
                {
                    std::cout << "Страны с таким названием нет!!!";
                }
                else
                {
                    std::cout << *country << "\n";
                }

            }break;
            case 3:
            {
                unsigned int population;
                std::cin >> population;
                std::cout << "Страна с населением population = " << population << ": \n";
                auto country = find_if(country_v.begin(), country_v.end(), [&population](const Country& country) 
                {
                    return country.GetPopulation() == population;
                });

            	if (country == country_v.end())
            	{
                    std::cout << "Страны с таким населением нет!!!";
            	}
                else
                {
                    std::cout << *country << "\n";
                }

            }break;
            default:
            {
                std::cout << "\nФункции на данную кнопку не назначено!\n";
            }break;
            }
                

        }break;
        case 'i':
        {
            system("cls");
            std::cout << "---Поиск элемента по критерию---\n";
            std::cout << "1.Поиск страны с инфляцией inflation > N;\n";
            std::cout << "2.Поиск страны с длиной названия length > N;\n";
            std::cout << "3.Поиск страны с населением population > N.\n";
            std::cout << "\nНомер критерия>>> ";
            int criteria;
            std::cin >> criteria;
            std::cout << "\nN = ";
            float N;
            std::cin >> N;
            switch (criteria)
            {
            case 1:
            {
	            std::cout << "Страна с инфляцией inflation > \n"<< N <<": \n";
                auto country = find_if(country_v.begin(), country_v.end(), [&N](const Country& country) 
                {
                    return country.GetInflation() > N;
                });
                if (country == country_v.end())
                {
                    std::cout << "Страны с такой инфляцией нет!!!";
                }
                else
                {
                    std::cout << *country << "\n";
                }
            }break;
            case 2:
            {
                std::cout << "Страна с длиной названия length > \n" << N << ": \n";
                auto country = find_if(country_v.begin(), country_v.end(), [&N](const Country& country) 
                {
					return country.GetName().length() > static_cast<unsigned int>(N);
                });
                if (country == country_v.end())
                {
                    std::cout << "Страны с таким названием нет!!!";
                }
                else
                {
                    std::cout << *country << "\n";
                }
            }break;
            case 3:
            {
                std::cout << "Страна с населением population > \n" << N << ": \n";
                auto country = find_if(country_v.begin(), country_v.end(), [&N](const Country& country) 
                {
                    return country.GetPopulation() > static_cast<int>(N);
                });
                if (country == country_v.end())
                {
                    std::cout << "Страны с таким населением нет!!!";
                }
                else
                {
                    std::cout << *country << "\n";
                }
            }break;
            default:
            {
                std::cout << "\nФункции на данную кнопку не назначено!\n";
            }break;
            }
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
    system("exit");
    return 0;
}
