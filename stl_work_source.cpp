#include <iostream>
#include <vector>

#include "country_class.h"

void ConsoleMenu()
{
	std::cout << "\n-----------------������� ���������-----------------\n";
    std::cout << " + - ���������� ��������;\n";
    std::cout << " - - �������� ��������;\n";
    std::cout << " o - ����� ������ ��� �������� �� �������;\n";
    std::cout << " s - ����������;\n";
    std::cout << " x - ���������� ���������/��������;\n";
    std::cout << " a - ���������� ��������������� ��������;\n";
    std::cout << " p - ����� �������� �� �������� (�-�, �������� ������);\n";
	std::cout << " i - ����� �������� �� �������� (�-�, ������ � ��������� > 2%);\n";
    std::cout << " e - ����� �� ���������.\n";
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
    std::cout << "������ ������� � �������� " << index << ":\n" << country_v[index - 1] << "\n";
}