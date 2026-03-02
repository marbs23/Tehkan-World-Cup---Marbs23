#include "CPerson.h"

CPerson::CPerson(/* args */)
{
}

CPerson::CPerson(string _name, int _age, string _country)
{
    this->name = _name;
    this->age = _age;
    this->country = _country;
}

CPerson::~CPerson()
{
}