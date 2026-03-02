#include "CSoccerField.h"

CSoccerField::CSoccerField(): name(""), rows(N_ROWS), cols(N_COLS)
{
    matrix = new char*[rows];
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = new char[cols];
        for (int j = 0; j < cols; j++)
        {
            matrix[i][j] = ' ';
        }
    }
    
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

string CSoccerField::get_name() const {return name;}
int CSoccerField::get_rows() const {return rows;}
int CSoccerField::get_cols() const {return cols;}
char** CSoccerField::get_matrix() const {return matrix;}
void CSoccerField::set_name(string _name) {name = _name;}
void CSoccerField::set_rows(int _rows) {rows = _rows;}
void CSoccerField::set_cols(int _cols) {cols = _cols;}
void CSoccerField::set_matrix(char** _matrix) {matrix = _matrix;}

CSoccerField::~CSoccerField()
{
    for (int i = 0; i < rows; i++)
    {
        delete[] matrix[i];
    }
    delete[] matrix;
    matrix == nullptr;
}