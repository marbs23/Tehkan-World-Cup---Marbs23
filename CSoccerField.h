#include <iostream>
using namespace std;
const int N_ROWS = 51;
const int N_COLS = 121;
class CSoccerField
{
private:
    string name;
    int rows;
    int cols;
    char** matrix;
public:
    CSoccerField();
    CSoccerField(string _name);
    string get_name() const;
    int get_rows() const;
    int get_cols() const;
    char** get_matrix() const;
    void set_name(string _name);
    void set_rows(int _rows);
    void set_cols(int _cols);
    void set_matrix(char** _matrix);
    ~CSoccerField();
};