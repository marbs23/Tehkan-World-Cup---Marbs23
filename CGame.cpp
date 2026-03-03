#include "CGame.h"
CGame::CGame()
{
    // TODO: init button personalize game
    this->soccerField = new CSoccerField();
    this->redTeam = new CTeam("red");
    this->blueTeam = new CTeam("blue");
    this->posXBall = 60;
    this->posYBall = 25;
    this->current_team = "BLUE";
    this->commands = vector<string>(5);
}

void CGame::actions()
{
    char **matrix = soccerField->get_matrix();
    bool flag_use_ball = false;

    CTeam *team = (current_team == "BLUE") ? blueTeam : redTeam;
    CPlayer *player_to_check;
    for (auto &&i : team->get_players())
    {
        if (i->get_letter() == commands[0][0])
            player_to_check = i;
    }
    int posPlayerX = player_to_check->get_posX();
    int posPlayerY = player_to_check->get_posY();
    int number_spaces = stoi(commands[3]);
    pair<int, int> dir = direction();

    if ((posPlayerY + 2 >= posYBall && posPlayerY - 2 <= posYBall) &&
        (posPlayerX + 2 >= posXBall && posPlayerX - 2 <= posXBall)) flag_use_ball = true;

    if (commands[2] == "BALL")
    {
        if (number_spaces >= 1 || number_spaces <= 40)
        {
            if (flag_use_ball)
            {
                if (dir.first != 0)
                    posYBall += dir.first * number_spaces;
                if (dir.second != 0)
                    posXBall += dir.second * number_spaces;
            }
            else
                cout << "Operation invalid";
        }
    }
    else if (commands[2] == "PLAYER")
    {
        if (number_spaces >= 1 || number_spaces <= 10)
        {
            int finalPosPlayerY = posPlayerY + dir.first * number_spaces;
            int finalPosPlayerX = posPlayerX + dir.second * number_spaces;
            if (dir.first != 0)
                player_to_check->set_posY(finalPosPlayerY);
            if (dir.second != 0)
                player_to_check->set_posX(finalPosPlayerX);
            posXBall = finalPosPlayerX + 1;
        }
    }
    else
    {
        cout << "Invalid move" << endl;
    }

    int dir_team = (commands[4] == "RIGHT") ? 1 : -1;
    for (auto &&i : team->get_players())
        i->set_posX(i->get_posX() + dir_team * 4);
}

pair<int, int> CGame::direction()
{
    string dir = commands[1];
    if (dir == "LEFT")
        return {0, -1};
    else if (dir == "DOWN-LEFT")
        return {1, -1};
    else if (dir == "DOWN")
        return {1, 0};
    else if (dir == "DOWN-RIGHT")
        return {1, 1};
    else if (dir == "RIGHT")
        return {0, 1};
    else if (dir == "UP-RIGHT")
        return {-1, 1};
    else if (dir == "UP")
        return {-1, 0};
    else if (dir == "UP-LEFT")
        return {-1, -1};
    else
        return {0, 0};
}

void CGame::play()
{
    print();
    while (true)
    {
        // 1. Take commands of user
        take_commands();

        // 2. Do actions
        actions();

        // 3. Check boundaries
        check_boundaries();

        // 3. Print field
        print();

        // 4. Verify goal
        if (verify_goal())
            break;

        // 5. Change current team
        current_team = (current_team == "BLUE") ? "RED" : "BLUE";
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
    char **matrix = soccerField->get_matrix();
    // 1. Clear matrix about previous plays
    for (int i = 0; i < soccerField->get_rows(); i++)
    {
        for (int j = 0; j < soccerField->get_cols(); j++)
        {
            if (matrix[i][j] != '#') matrix[i][j] = ' ';
        }
    }

    // 2. Put Teams in matrix
    for (auto &&player : redTeam->get_players())
    {
        matrix[player->get_posY()][player->get_posX()] = player->get_letter();
    }

    for (auto &&player : blueTeam->get_players())
    {
        matrix[player->get_posY()][player->get_posX()] = player->get_letter();
    }

    // 3. Put Ball in matrix
    matrix[posYBall][posXBall] = 'X';

    // 4. Print field
    for (int i = 0; i < 123; i++)
        cout << "-";
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

    for (int i = 0; i < 123; i++)
        cout << "-";
    cout << endl;
}

void CGame::check_boundaries()
{
    if (posXBall < 0)
        posXBall = 0;
    else if (posXBall > 120)
        posXBall = 120;
    if (posYBall < 0)
        posYBall = 0;
    else if (posYBall > 50)
        posYBall = 50;

    for (auto &&player : redTeam->get_players())
    {
        if (player->get_posX() < 0)
            player->set_posX(0);
        else if (player->get_posX() > 120)
            player->set_posX(120);
        if (player->get_posY() < 0)
            player->set_posY(0);
        else if (player->get_posY() > 50)
            player->set_posY(50);
    }

    for (auto &&player : blueTeam->get_players())
    {
        if (player->get_posX() < 0)
            player->set_posX(0);
        else if (player->get_posX() > 120)
            player->set_posX(120);
        if (player->get_posY() < 0)
            player->set_posY(0);
        else if (player->get_posY() > 50)
            player->set_posY(50);
    }
}

bool CGame::verify_goal()
{
    if ((posXBall == 0 || posXBall == 120) && (posYBall < 38 && posYBall > 12))
    {
        return true;
    }
    return false;
}

CGame::~CGame()
{
    delete soccerField;
    delete redTeam;
    delete blueTeam;
}