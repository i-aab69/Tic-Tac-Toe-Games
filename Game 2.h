#include "BoardGame_Classes.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

class FourInARowBoard : public Board<char> {
public:
    FourInARowBoard(int r = 6, int c = 7) {
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

    ~FourInARowBoard() {
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
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = 0; j < columns; ++j) {
                cout << "|" << (board[i][j] == ' ' ? '.' : board[i][j]);
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
                    board[r][c] == board[r][c + 3])
                    return true;

                if (r + 3 < rows &&
                    board[r][c] == board[r + 1][c] &&
                    board[r][c] == board[r + 2][c] &&
                    board[r][c] == board[r + 3][c])
                    return true;

                if (r + 3 < rows && c + 3 < columns &&
                    board[r][c] == board[r + 1][c + 1] &&
                    board[r][c] == board[r + 2][c + 2] &&
                    board[r][c] == board[r + 3][c + 3])
                    return true;

                if (r + 3 < rows && c - 3 >= 0 &&
                    board[r][c] == board[r + 1][c - 1] &&
                    board[r][c] == board[r + 2][c - 2] &&
                    board[r][c] == board[r + 3][c - 3])
                    return true;
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

class FourInARowPlayer : public Player<char> {
public:
    FourInARowPlayer(string name, char symbol) : Player(name, symbol) {}
    FourInARowPlayer(char symbol) : Player(symbol) {}

    void getmove(int& x, int& y) override {
        cout << name << " (" << symbol << "), enter your column (0-6): ";
        cin >> x;
        y = 0;
    }
};

class FourInARowRandomPlayer : public RandomPlayer<char> {
public:
    FourInARowRandomPlayer(char symbol) : RandomPlayer(symbol) {}

    void getmove(int& x, int& y) override {
        x = rand() % 7;
        y = 0;
    }
};

int main() {
    srand(static_cast<unsigned>(time(0)));

    FourInARowBoard board;
    FourInARowPlayer player1("Player 1", 'X');
    FourInARowPlayer player2("Player 2", 'O');

    player1.setBoard(&board);
    player2.setBoard(&board);

    Player<char>* players[2] = {&player1, &player2};
    GameManager<char> game(&board, players);

    game.run();

    return 0;
}
