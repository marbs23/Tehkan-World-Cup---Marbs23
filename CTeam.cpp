#include "CTeam.h"

CTeam::CTeam()
{
    this->name = "";
    this->players = {};
    this->coach = CPerson();
}

CTeam::CTeam(string n):name(n), coach(CPerson())
{
    vector<pair<int,int>> positions = {{25,0},{4,14},{12,14},{38,14},{46,14},
                                    {9,29},{25,29},{41,29},{4,53},{25,58},{46,53}};
    if (n == "red")
    {
        char letter = 'A';
        for (int i = 0; i < 11; i++)
        {
            CPlayer* newPlayer = new CPlayer(letter,positions[i].second,positions[i].first);
            players.push_back(newPlayer);
            letter++;
        }
        
    } else if (n == "blue")
    {
        char letter = 'L';
        for (int i = 0; i < 11; i++)
        {
            CPlayer* newPlayer = new CPlayer(letter,120-positions[i].second,50-positions[i].first);
            players.push_back(newPlayer);
            letter++;
        }
    } else
    {
        cout << "Incorrect name";
    }
}

string CTeam::get_name() const {return name;}
vector<CPlayer*> CTeam::get_players() const {return players;}
CPerson CTeam::get_coach() const {return coach;}
void CTeam::set_name(string _name) {name = _name;}
void CTeam::set_players(vector<CPlayer*> _players) {players = _players;}
void CTeam::set_coach(CPerson _coach) {coach = _coach;}

CTeam::~CTeam()
{
}