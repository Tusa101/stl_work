#include <iostream>
#include "country_class.h"


Country& Country::operator= (Country& country)
{
	if (&country == this) return *this;
	this->name_ = country.GetName();
	this->population_ = country.GetPopulation();
	this->inflation_ = country.GetInflation();
	return *this;
}

bool Country::operator==(const Country& country) const
{
	if (this->name_ == country.GetName() && this->population_ == country.GetPopulation() && this->inflation_ == country.GetInflation())
	{
		return true;
	}
	return false;
}

std::ostream& operator <<(std::ostream& out, const Country& country)
{
	std::cout << "Имя: " << country.GetName() << ", Наcеление: " << country.GetPopulation() << "млн.чел., Инфляция: " << country.GetInflation() << "%.";
	return out;
}