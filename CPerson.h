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
    string get_name() const;
    int get_age() const;
    string get_country() const;
    void set_name(string _name);
    void set_age(int _age);
    void set_country(string _country);
    ~CPerson();
};
