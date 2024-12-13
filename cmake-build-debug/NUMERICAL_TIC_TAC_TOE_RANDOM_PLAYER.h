#ifndef _NUMERICAL_TIC_TAC_TOE_RANDOM_PLAYER_H
#define _NUMERICAL_TIC_TAC_TOE_RANDOM_PLAYER_H

#include "BoardGame_Classes.h"
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
class Numerical_Tic_Tac_Toe_Random_Player : public RandomPlayer<T> {
public:
    Numerical_Tic_Tac_Toe_Random_Player(T symbol);
    void getmove(int& x, int& y, T& number) override;
};

template <typename T>
Numerical_Tic_Tac_Toe_Random_Player<T>::Numerical_Tic_Tac_Toe_Random_Player(T symbol) : RandomPlayer<T>(symbol) {
    this->dimension = 3;
    this->name = "Random Computer Player";
    srand(static_cast<unsigned int>(time(0)));
}

template <typename T>
void Numerical_Tic_Tac_Toe_Random_Player<T>::getmove(int& x, int& y, T& number) {
    x = rand() % this->dimension;
    y = rand() % this->dimension;
    number = (rand() % 9) + 1;
}

#endif //_NUMERICAL_TIC_TAC_TOE_RANDOM_PLAYER_H