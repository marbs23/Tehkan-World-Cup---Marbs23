#include "CGame.h"
CGame::CGame()
{
    // TODO: init button personalize game
    this->soccerField = new CSoccerField();
    this->redTeam = new CTeam("red");
    this->blueTeam = new CTeam("blue");
    this->posXBall = 25;
    this->posYBall = 60;
    this->current_team = "BLUE";
    this->commands = vector<string>(5);
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
    char** matrix = soccerField->get_matrix();
    // 1. Put Teams in matrix
    for (auto &&player : redTeam->get_players())
    {
        matrix[player->get_posX()][player->get_posY()] = player->get_letter(); 
    }

    for (auto &&player : blueTeam->get_players())
    {
        matrix[player->get_posX()][player->get_posY()] = player->get_letter(); 
    }

    // 2. Put Ball in matrix
    matrix[posXBall][posYBall] = 'X';

    // 3. Print field
    for (int i = 0; i < 123; i++) cout << "-";
    cout << endl;
    
    for (int i = 0; i < N_ROWS; i++)
    {
        cout << "|";
        for (int j = 0; j < N_COLS; j++)
        {
            cout << matrix[i][j];
        }
        cout << "|" << endl;
    }
    
    for (int i = 0; i < 123; i++) cout << "-";
    cout << endl;
}

bool CGame::verify_goal()
{
    return 0;
}



CGame::~CGame()
{
    delete soccerField;
    delete redTeam;
    delete blueTeam;
}