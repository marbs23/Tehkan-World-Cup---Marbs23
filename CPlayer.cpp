#include "CPlayer.h"

CPlayer::CPlayer(): CPerson()
{
    this->letter = ' ';
    this->posX = 0;
    this->posY = 0;
}

CPlayer::CPlayer(char l, int pX, int pY): CPerson()
{
    this->letter = l;
    this->posX = pX;
    this->posY = pY;
}

char CPlayer::get_letter() const {return letter;}
int CPlayer::get_posX() const {return posX;}
int CPlayer::get_posY() const {return posY;}
void CPlayer::set_letter(char _letter) {letter = _letter;}
void CPlayer::set_posX(int _posX) {posX = _posX;}
void CPlayer::set_posY(int _posY) {posY = _posY;}

CPlayer::~CPlayer()
{
}