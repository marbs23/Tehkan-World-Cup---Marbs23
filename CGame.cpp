#include "CGame.h"
CGame::CGame()
{
}

CGame::CGame(CSoccerField _sF, CTeam* rT, CTeam* bT, int pXBall, int pYBall)
{

}

void CGame::actions()
{

}

void CGame::play()
{
    print();
    while (true)
    {
        // 1. Take commands of user
        take_commands();
        // 2. Actions
        actions();
        // 3. Print field
        print();
        // 4. Verify goal
        if (verify_goal()) break;
    }
    
}

void CGame::take_commands()
{
    cout << current_team << ": ";
    for (int i = 0; i < 5; i++)
    {
        string command;
        cin >> command;
        commands[i] = command;
    }
}

void CGame::print()
{
    // 1. Print field
    // 2. Print Teams
    // 3. Print Ball
}

bool CGame::verify_goal()
{

}



CGame::~CGame()
{
}