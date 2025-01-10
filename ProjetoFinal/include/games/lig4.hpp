#pragma once

#include "../ProjetoFinal/include/games/games.hpp"

class Lig4 : public Games {
  public:
    Lig4 () : Games(6,7) {}
//  Lig4 (int rows, int columns) {}

    int readPlay_lig4 ();

    virtual void printGame () override = 0;
    virtual void verifyPlay () override = 0;
    virtual void verifyWin () override = 0;
};