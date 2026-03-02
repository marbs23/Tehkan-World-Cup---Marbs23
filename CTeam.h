#include <iostream>
#include <vector>
#include "CPlayer.h"
using namespace std;
class CTeam
{
private:
    string name;
    vector<CPlayer*> players;
    CPerson coach;
public:
    CTeam();
    CTeam(string n);
    string get_name() const;
    vector<CPlayer*> get_players() const;
    CPerson get_coach() const;
    void set_name(string _name);
    void set_players(vector<CPlayer*> _players);
    void set_coach(CPerson _coach);
    ~CTeam();
};