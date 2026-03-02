#include <iostream>
using namespace std;
class CPerson
{
private:
    string name;
    int age;
    string country;
public:
    CPerson();
    CPerson(string _name, int _age, string _country);
    ~CPerson();
};
