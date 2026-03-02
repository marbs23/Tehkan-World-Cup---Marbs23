#include "CTeam.h"
CTeam::CTeam(/* args */)
{
}

CTeam::CTeam(string n, CPerson c):name(n), coach(c)
{
    vector<pair<int,int>> positions = {{25,0},{4,14},{12,14},{38,14},{46,14},
                                    {9,29},{25,29},{41,29},{4,53},{25,53},{46,53}};
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

CTeam::~CTeam()
{
}