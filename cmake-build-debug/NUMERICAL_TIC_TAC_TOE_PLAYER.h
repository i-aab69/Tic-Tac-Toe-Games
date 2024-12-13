#ifndef _NUMERICAL_TIC_TAC_TOE_PLAYER_H
#define _NUMERICAL_TIC_TAC_TOE_PLAYER_H

#include "BoardGame_Classes.h"
#include <iostream>

using namespace std;

template <typename T>
class Numerical_Tic_Tac_Toe_Player : public Player<T> {
public:
    Numerical_Tic_Tac_Toe_Player(string name, T symbol);
    void getmove(int& x, int& y, T& number) override;
};

template <typename T>
Numerical_Tic_Tac_Toe_Player<T>::Numerical_Tic_Tac_Toe_Player(string name, T symbol) : Player<T>(name, symbol) {}

template <typename T>
void Numerical_Tic_Tac_Toe_Player<T>::getmove(int& x, int& y, T& number) {
    cout << "\n" << this->name << " (" << this->symbol << "), enter your move x, y (0 to 2) and number: ";
    cin >> x >> y >> number;
}

#endif //_NUMERICAL_TIC_TAC_TOE_PLAYER_H