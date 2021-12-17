#pragma once
#include <iostream>
#include <utility>


class Country
{
public:
	//запрет на явное преобразование и вызов данных конструкторов
	explicit Country(int& population, double& inflation);
	explicit Country(int& population);
	explicit Country(double& inflation);
	// основные вариации конструкторов
	Country():name_(""), population_(0), inflation_(0) {}
	Country(std::string name, const int& population, const double inflation) :name_(std::move(name)), population_(population), inflation_(inflation) {}
	Country(std::string name):name_(std::move(name))
	{
		population_ = 0;
		inflation_ = 0;
	}
	//конструктор копирования
	Country(const Country& country):name_(country.GetName()),population_(country.GetPopulation()),inflation_(country.GetInflation()){}
	std::string GetName() const { return name_; }
	void SetName(std::string& name) { name_ = move(name); }
	int GetPopulation() const { return population_; }
	void SetPopulation(const int& population) { population_ = population; }
	double GetInflation() const { return inflation_; }
	void SetInflation(const double& inflation) { inflation_ = inflation; }
	Country& operator= (const Country& country);
	bool operator==(const Country& country) const;
	Country& operator+ (const Country& other) const;
	friend std::ostream& operator <<(std::ostream& out, const Country& country);
	
	~Country()
	{
		name_.clear();
	}
private:
	std::string name_;
	int population_;
	double inflation_;
};

