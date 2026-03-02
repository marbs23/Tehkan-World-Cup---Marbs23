#include "CPerson.h"

CPerson::CPerson()
{
    this->name = " ";
    this->age = 33;
    this->country = "USA";
}

CPerson::CPerson(string _name, int _age, string _country)
{
    this->name = _name;
    this->age = _age;
    this->country = _country;
}

string CPerson::get_name() const {return name;}
int CPerson::get_age() const {return age;}
string CPerson::get_country() const {return country;}
void CPerson::set_name(string _name) {name = _name;}
void CPerson::set_age(int _age) {age = _age;}
void CPerson::set_country(string _country) {country = _country;}

CPerson::~CPerson()
{
}