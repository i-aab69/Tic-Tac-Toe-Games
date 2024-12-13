#ifndef _BOARDGAME_CLASSES_H
#define _BOARDGAME_CLASSES_H

#include <string>
#include <vector>
using namespace std;

template <typename T>
class Board {
protected:
    int rows, columns;
    T** board;
    int n_moves = 0;

public:
    virtual bool update_board(int x, int y, T symbol) = 0;
    virtual void display_board() = 0;
    virtual bool is_win() = 0;
    virtual bool is_draw() = 0;
    virtual bool game_is_over() = 0;
};

template <typename T>
class Player {
protected:
    string name;
    T symbol;
    Board<T>* boardPtr;

public:
    Player(string n, T symbol);
    Player(T symbol);
    virtual void getmove(int& x, int& y, T& number) = 0;
    T getsymbol();
    string getname();
    void setBoard(Board<T>* b);
};

template <typename T>
class RandomPlayer : public Player<T> {
protected:
    int dimension;

public:
    RandomPlayer(T symbol);
    virtual void getmove(int& x, int& y, T& number) = 0;
};

template <typename T>
class GameManager {
private:
    Board<T>* boardPtr;
    Player<T>* players[2];

public:
    GameManager(Board<T>* bPtr, Player<T>* playerPtr[2]);
    void run();
};

#include <iostream>
using namespace std;

template <typename T>
GameManager<T>::GameManager(Board<T>* bPtr, Player<T>* playerPtr[2]) {
    boardPtr = bPtr;
    players[0] = playerPtr[0];
    players[1] = playerPtr[1];
}

template <typename T>
void GameManager<T>::run() {
    int x, y;
    T number;

    boardPtr->display_board();

    while (!boardPtr->game_is_over()) {
        for (int i : {0, 1}) {
            players[i]->getmove(x, y, number);
            while (!boardPtr->update_board(x, y, number)) {
                players[i]->getmove(x, y, number);
            }
            boardPtr->display_board();
            if (boardPtr->is_win()) {
                cout << players[i]->getname() << " wins\n";
                return;
            }
            if (boardPtr->is_draw()) {
                cout << "Draw!\n";
                return;
            }
        }
    }
}

template <typename T>
Player<T>::Player(std::string n, T symbol) {
    this->name = n;
    this->symbol = symbol;
}

template <typename T>
Player<T>::Player(T symbol) {
    this->name = "Computer";
    this->symbol = symbol;
}

template <typename T>
RandomPlayer<T>::RandomPlayer(T symbol) : Player<T>(symbol) {}

template <typename T>
std::string Player<T>::getname() {
    return this->name;
}

template <typename T>
T Player<T>::getsymbol() {
    return this->symbol;
}

template <typename T>
void Player<T>::setBoard(Board<T>* b) {
    this->boardPtr = b;
}

#endif //_BOARDGAME_CLASSES_H