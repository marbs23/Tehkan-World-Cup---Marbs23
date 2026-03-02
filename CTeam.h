#include <iostream>
#include <vector>
#include <CPlayer.h>
using namespace std;
class CTeam
{
private:
    string name;
    vector<CPlayer*> players;
    CPerson coach;
public:
    CTeam();
    CTeam(string n, CPerson c);
    string get_name() const;
    ~CTeam();
};