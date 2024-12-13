#ifndef FOUR_BY_FOUR_TIC_TAC_TOE_H
#define FOUR_BY_FOUR_TIC_TAC_TOE_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FourByFourTicTacToeBoard : public Board<char> {
public:
    FourByFourTicTacToeBoard() {
        rows = 4;
        columns = 4;
        board = new char*[rows];
        for (int i = 0; i < rows; ++i) {
            board[i] = new char[columns];
            for (int j = 0; j < columns; ++j) {
                board[i][j] = ' ';
            }
        }
        // Starting positions
        board[0][0] = 'O';
        board[0][1] = 'X';
        board[0][2] = 'O';
        board[0][3] = 'X';
        board[3][0] = 'X';
        board[3][1] = 'O';
        board[3][2] = 'X';
        board[3][3] = 'O';
    }

    ~FourByFourTicTacToeBoard() {
        for (int i = 0; i < rows; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    bool update_board(int x, int y, char symbol) override {
        if (x < 0 || x >= columns || y < 0 || y >= rows || board[y][x] != ' ') return false;
        board[y][x] = symbol;
        ++n_moves;
        return true;
    }

    void display_board() override {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns; ++j) {
                cout << " " << board[i][j] << " ";
                if (j < columns - 1) cout << "|";
            }
            cout << endl;
            if (i < rows - 1) cout << "---+---+---+---\n";
        }
    }

    bool is_win() override {
        // Check rows and columns
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < columns - 2; ++j) {
                if (board[i][j] != ' ' && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2]) return true;
            }
        }
        for (int j = 0; j < columns; ++j) {
            for (int i = 0; i < rows - 2; ++i) {
                if (board[i][j] != ' ' && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j]) return true;
            }
        }
        // Check diagonals
        for (int i = 0; i < rows - 2; ++i) {
            for (int j = 0; j < columns - 2; ++j) {
                if (board[i][j] != ' ' && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2]) return true;
                if (board[i][j + 2] != ' ' && board[i][j + 2] == board[i + 1][j + 1] && board[i][j + 2] == board[i + 2][j]) return true;
            }
        }
        return false;
    }

    bool is_draw() override {
        return n_moves == rows * columns && !is_win();
    }

    bool game_is_over() override {
        return is_win() || is_draw();
    }
};

class FourByFourTicTacToePlayer : public Player<char> {
public:
    FourByFourTicTacToePlayer(string name, char symbol) : Player(name, symbol) {}

    void getmove(int& x, int& y, char& number) override {
        cout << name << " (" << symbol << "), Enter your move (row, column): ";
        cin >> y >> x;
        number = symbol;
    }
};

class FourByFourTicTacToeRandomPlayer : public RandomPlayer<char> {
public:
    FourByFourTicTacToeRandomPlayer(char symbol) : RandomPlayer(symbol) {}

    void getmove(int& x, int& y, char& number) override {
        x = rand() % 4;
        y = rand() % 4;
        number = symbol;
    }
};

#endif // FOUR_BY_FOUR_TIC_TAC_TOE_H