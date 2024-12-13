
#ifndef NUMERICAL_X_O_H
#define NUMERICAL_X_O_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class NumericalTicTacToeBoard : public Board<int> {
public:
    NumericalTicTacToeBoard() {
        rows = 3;
        columns = 3;
        board = new int*[rows];
        for (int i = 0; i < rows; ++i) {
            board[i] = new int[columns];
            for (int j = 0; j < columns; ++j) {
                board[i][j] = 0;
            }
        }
    }

    ~NumericalTicTacToeBoard() {
        for (int i = 0; i < rows; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    bool update_board(int x, int y, int symbol) override {
        if (x < 0 || x >= columns || y < 0 || y >= rows || board[y][x] != 0) return false;
        board[y][x] = symbol;
        ++n_moves;
        return true;
    }

    void display_board() override {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                if (board[i][j] == 0) {
                    cout << ".";
                } else {
                    cout << board[i][j];
                }
                if (j < columns - 1) cout << " | ";
            }
            cout << endl;
            if (i < rows - 1) cout << "---------" << endl;
        }
    }

    bool is_win() override {
        for (int i = 0; i < rows; ++i) {
            if (board[i][0] + board[i][1] + board[i][2] == 15) return true;
        }
        for (int j = 0; j < columns; ++j) {
            if (board[0][j] + board[1][j] + board[2][j] == 15) return true;
        }
        if (board[0][0] + board[1][1] + board[2][2] == 15) return true;
        if (board[0][2] + board[1][1] + board[2][0] == 15) return true;
        return false;
    }

    bool is_draw() override {
        return n_moves == rows * columns && !is_win();
    }

    bool game_is_over() override {
        return is_win() || is_draw();
    }
};

class NumericalTicTacToePlayer : public Player<int> {
private:
    vector<int> available_numbers;
public:
    NumericalTicTacToePlayer(string name, int symbol) : Player(name, symbol) {
        if (symbol % 2 == 1) {
            available_numbers = {1, 3, 5, 7, 9};
        } else {
            available_numbers = {2, 4, 6, 8, 10};
        }
    }

    void getmove(int& x, int& y, int& number) override {
        cout << name << " (" << symbol << "), enter your move (row, column, number): ";
        cin >> y >> x >> number;
        if (find(available_numbers.begin(), available_numbers.end(), number) != available_numbers.end()) {
            symbol = number;
            available_numbers.erase(remove(available_numbers.begin(), available_numbers.end(), number), available_numbers.end());
        } else {
            cout << "Invalid number. Try again.\n";
            getmove(x, y, number);
        }
    }
};

class NumericalTicTacToeRandomPlayer : public RandomPlayer<int> {
private:
    vector<int> available_numbers;
public:
    NumericalTicTacToeRandomPlayer(int symbol) : RandomPlayer(symbol) {
        if (symbol % 2 == 1) {
            available_numbers = {1, 3, 5, 7, 9};
        } else {
            available_numbers = {2, 4, 6, 8, 10};
        }
    }

    void getmove(int& x, int& y, int& number) override {
        x = rand() % 3;
        y = rand() % 3;
        number = available_numbers[rand() % available_numbers.size()];
        symbol = number;
        available_numbers.erase(remove(available_numbers.begin(), available_numbers.end(), number), available_numbers.end());
    }
};

#endif //NUMERICAL_X_O_H
