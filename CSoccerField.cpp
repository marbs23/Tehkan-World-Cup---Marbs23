#include <CSoccerField.h>
CSoccerField::CSoccerField(): rows(N_ROWS), cols(N_COLS)
{
    // GOAL SUPERIOR LINES
    for (int j = 0; j < 5; j++)
    {
        matrix[19][j] = '#';
        matrix[19][120-j] = '#';
    }

    // GOAL INFERIOR LINES
    for (int j = 0; j < 5; j++)
    {
        matrix[31][j] = '#';
        matrix[31][120-j] = '#';
    }
    
    // GOAL VERTICAL LINES
    for (int i = 0; i < 11; i++)
    {
        matrix[20+i][4] = '#';
        matrix[20+i][116] = '#';
    }
    
    // AREA SUPERIOR LINES
    for (int j = 0; j < 10; j++)
    {
        matrix[12][j] = '#';
        matrix[12][120-j] = '#';
    }
    
    // AREA INFERIOR LINES
    for (int j = 0; j < 10; j++)
    {
        matrix[38][j] = '#';
        matrix[38][120-j] = '#';
    }
    
    // AREA VERTICAL LINES
    for (int i = 0; i < 25; i++)
    {
        matrix[13+i][9] = '#';
        matrix[13+i][111] = '#';
    }
    
    // TODO: AREA BOMB LINES

}

CSoccerField::~CSoccerField()
{
}