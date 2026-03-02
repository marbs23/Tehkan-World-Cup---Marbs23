#include <CPerson.h>
class CPlayer:public CPerson
{
private:
    char letter;
    int posX;
    int posY;
public:
    CPlayer();
    CPlayer(char l, int pX, int pY);
    ~CPlayer();
};