#include <iostream>
using namespace std;
const int N_ROWS = 51;
const int N_COLS = 121;
class CSoccerField
{
private:
    string name;
    int rows = N_ROWS;
    int cols = N_COLS;
    char matrix[N_ROWS][N_COLS];
public:
    CSoccerField();
    ~CSoccerField();
};