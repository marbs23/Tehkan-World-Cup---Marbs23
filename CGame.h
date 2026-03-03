#include "CSoccerField.h"
#include "CTeam.h"
class CGame
{
private:
    CSoccerField* soccerField;
    CTeam* redTeam;
    CTeam* blueTeam;
    int posXBall;
    int posYBall;
    vector<string> commands;
    string current_team;
public:
    CGame();
    void actions();
    void play();
    void print();
    bool verify_goal();
    void take_commands();
    pair<int,int> direction();
    ~CGame();
};