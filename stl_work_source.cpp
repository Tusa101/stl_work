#include <iostream>
#include <vector>

#include "country_class.h"

void ConsoleMenu()
{
	std::cout << "\n-----------------‘ункции программы-----------------\n";
    std::cout << " + - добавление элемента;\n";
    std::cout << " - - удаление элемента;\n";
    std::cout << " o - вывод списка или элемента по индексу;\n";
    std::cout << " s - сортировка;\n";
    std::cout << " x - нахождение максимума/минимума;\n";
    std::cout << " a - вычисление агрегированного значени€;\n";
    std::cout << " p - поиск элемента по значению (н-р, название страны);\n";
	std::cout << " i - поиск элемента по критерию (н-р, страны с инфл€цией > 2%);\n";
    std::cout << " e - выход из программы.\n";
	std::cout << "\n >>> ";
}
void DisplayVector(std::vector<Country>& country_v)
{
    auto i = country_v.begin();
    int cnt = 0;
    while (i != country_v.end())
    {
        std::cout << ++cnt << ") " << *i << "\n";
        ++i;
    }
}
void DeletedMessage(unsigned int& index, const std::vector<Country>& country_v)
{
    std::cout << "”дален элемент с индексом " << index << ":\n" << country_v[index - 1] << "\n";
}