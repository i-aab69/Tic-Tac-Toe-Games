#ifndef FOUR_IN_A_ROW_H
#define FOUR_IN_A_ROW_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <cstdlib>
using namespace std;

class Four_In_A_Row_Board : public Board<char> {
public:
    Four_In_A_Row_Board(int r = 6, int c = 7) {
        rows = r;
        columns = c;
        board = new char*[rows];
        for (int i = 0; i < rows; ++i) {
            board[i] = new char[columns];
            for (int j = 0; j < columns; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    ~Four_In_A_Row_Board() {
        for (int i = 0; i < rows; ++i) {
            delete[] board[i];
        }
        delete[] board;
    }

    bool update_board(int x, int y, char symbol) override {
        if (x < 0 || x >= columns || board[rows - 1][x] != ' ') return false;
        for (int i = 0; i < rows; ++i) {
            if (board[i][x] == ' ') {
                board[i][x] = symbol;
                ++n_moves;
                return true;
            }
        }
        return false;
    }

    void display_board() override {
        cout << "\n" ;
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = 0; j < columns; ++j) {
                cout << "| " << (board[i][j] == ' ' ? '-' : board[i][j]);
            }
            cout << "|\n";
        }
        cout << " 0  1  2  3  4  5  6\n";
    }

    bool is_win() override {
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < columns; ++c) {
                if (board[r][c] == ' ') continue;

                if (c + 3 < columns &&
                    board[r][c] == board[r][c + 1] &&
                    board[r][c] == board[r][c + 2] &&
                    board[r][c] == board[r][c + 3]) {
                    return true;
                }

                if (r + 3 < rows &&
                    board[r][c] == board[r + 1][c] &&
                    board[r][c] == board[r + 2][c] &&
                    board[r][c] == board[r + 3][c]) {
                    return true;
                }

                if (r + 3 < rows && c + 3 < columns &&
                    board[r][c] == board[r + 1][c + 1] &&
                    board[r][c] == board[r + 2][c + 2] &&
                    board[r][c] == board[r + 3][c + 3]) {
                    return true;
                }

                if (r + 3 < rows && c - 3 >= 0 &&
                    board[r][c] == board[r + 1][c - 1] &&
                    board[r][c] == board[r + 2][c - 2] &&
                    board[r][c] == board[r + 3][c - 3]) {
                    return true;
                }
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

class Four_In_A_Row_Player : public Player<char> {
public:
    Four_In_A_Row_Player(string name, char symbol) : Player(name, symbol) {}
    Four_In_A_Row_Player(char symbol) : Player(symbol) {}

    void getmove(int& x, int& y, char& number) override {
        cout << name << " (" << symbol << "), Enter your column number (0-6): ";
        cin >> x;
        y = 0;
        number = symbol;
    }
};

class Four_In_A_Row_Random_Player : public RandomPlayer<char> {
public:
    Four_In_A_Row_Random_Player(char symbol) : RandomPlayer(symbol) {}

    void getmove(int& x, int& y, char& number) override {
        x = rand() % 7;
        y = 0;
        number = symbol;
    }
};

#endif // FOUR_IN_A_ROW_H