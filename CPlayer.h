#include "CPerson.h"
class CPlayer:public CPerson
{
private:
    char letter;
    int posX;
    int posY;
public:
    CPlayer();
    CPlayer(char l, int pX, int pY);
    char get_letter() const;
    int get_posX() const;
    int get_posY() const;
    void set_letter(char _letter);
    void set_posX(int _posX);
    void set_posY(int _posY);
    ~CPlayer();
};