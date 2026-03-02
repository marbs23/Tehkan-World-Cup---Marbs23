#include "CGame.h"
CGame::CGame()
{
    // TODO: init button personalize game
    this->soccerField = CSoccerField("sts");
    this->redTeam = new CTeam("red",CPerson("coach1",25,"Peru"));
    this->blueTeam = new CTeam("blue",CPerson("coach2",27,"Alemania"));
    this->posXBall = 25;
    this->posYBall = 60;
    this->current_team = "BLUE";
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
    char** matrix = soccerField.get_matrix();
    for (int i = 0; i < N_ROWS; i++)
    {
        for (int j = 0; j < N_COLS; j++)
        {
            cout << matrix[i][j];
        }
        cout << endl;
    }
    
    // 2. Print Teams
    // 3. Print Ball
}

bool CGame::verify_goal()
{
    return 0;
}



CGame::~CGame()
{
}