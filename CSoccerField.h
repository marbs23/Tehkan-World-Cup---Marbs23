#include <iostream>
using namespace std;
class CSoccerField
{
private:
    string name;
    int rows;
    int cols;
public:
    CSoccerField(/* args */);
    ~CSoccerField();
    void setRows(int _rows);
    void setCols(int _cols);
};