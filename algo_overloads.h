#pragma once
#include "country_class.h"
class ByLength
{
public:
	bool operator() (const Country& ctr1, const Country& ctr2) const
	{
		return (ctr1.GetName().length() > ctr2.GetName().length()) ? true : false;
	}
};//
class ByAlphabet
{
public:
	bool operator() (const Country& ctr1, const Country& ctr2) const
	{
		return (ctr1.GetName() < ctr2.GetName()) ? true : false;
	}
};//
class ByPopulation
{
public:
	bool operator() (const Country& ctr1, const Country& ctr2) const
	{
		return (ctr1.GetPopulation() > ctr2.GetPopulation()) ? true : false;
	}
};//
class ByInflation
{
public:
	bool operator() (const Country& ctr1, const Country& ctr2) const
	{
		return (ctr1.GetInflation() > ctr2.GetInflation()) ? true : false;
	}
};//

class Extremum
{
public:
	bool operator() (const Country& ctr1, const Country& ctr2) const
	{
		if (ctr1.GetInflation() == ctr2.GetInflation())
		{
			return (ctr1.GetPopulation() < ctr2.GetPopulation()) ? true : false;
		}
		return (ctr1.GetInflation() < ctr2.GetInflation()) ? true : false;
	}
};//

class GreaterPopulation
{
	int param;
public:
	GreaterPopulation(const int& par) : param(par) {}
	bool operator() (const Country& country) const
	{
		return country.GetPopulation() > param;
	}
};//
class GreaterLength
{
	unsigned int param;
public:
	GreaterLength(const unsigned int& par) : param(par) {}
	bool operator() (const Country& country) const
	{
		return country.GetName().length() > param;
	}//
};
class GreaterInflation
{
	int param;
public:
	GreaterInflation(const int& par) : param(par) {}
	bool operator() (const Country& country) const
	{
		return country.GetInflation() > param;
	}
};///

class FindName
{
	std::string param;
public:
	FindName(const std::string& par) : param(par) {}
	bool operator() (const Country& country) const
	{
		return country.GetName() == param;
	}
};//
class FindPopulation
{
	int param;
public:
	FindPopulation(const int& par) : param(par) {}
	bool operator() (const Country& country) const
	{
		return country.GetPopulation() == param;
	}
};//

class FindInflation
{
	double param;
public:
	FindInflation(const double& par) : param(par) {}
	bool operator() (const Country& country) const
	{
		return country.GetInflation() == param;
	}
};//