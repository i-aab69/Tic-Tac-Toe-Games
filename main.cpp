#include "BoardGame_Classes.h"
#include "Four-in-a-row.h"
#include "NumericalTicTacToe.h"
#include "FourByFourTicTacToe.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

void printNumericalTicTacToeRules() {
    cout << "Rules:\n";
    cout << "Player 1 typically starts and uses odd numbers (1, 3, 5, 7, 9),\n";
    cout << "while Player 2 uses even numbers (2, 4, 6, 8).\n";
    cout << "Players alternate turns, placing one number in an empty cell on the board.\n";
    cout << "Each number can only be used once.\n";
}

void printFourByFourTicTacToeRules() {
    cout << "Rules:\n";
    cout << "Players alternate turns, moving one of their tokens to an immediately adjacent open square.\n";
    cout << "Tokens can be moved horizontally or vertically but not diagonally.\n";
    cout << "Tokens may not jump over other tokens.\n";
    cout << "The goal is to align three of your tokens in a row. This can be achieved horizontally, vertically, or diagonally.\n";
    cout << "The first player to get three tokens in a row wins the game.\n";
}

int main() {
    srand(static_cast<unsigned>(time(0)));

    int choice;
    cout << "Choose a game to play:\n";
    cout << "1. Four-in-a-Row\n";
    cout << "2. Numerical Tic-Tac-Toe\n";
    cout << "3. 4x4 Tic-Tac-Toe\n";
    cout << "Enter your choice (1, 2, or 3): ";
    cin >> choice;

    if (choice == 1) {
        // Four-in-a-Row game
        Four_In_A_Row_Board fourInARowBoard;
        Four_In_A_Row_Player fourInARowPlayer1("Player 1", 'X');
        Four_In_A_Row_Player fourInARowPlayer2("Player 2", 'O');

        fourInARowPlayer1.setBoard(&fourInARowBoard);
        fourInARowPlayer2.setBoard(&fourInARowBoard);

        Player<char>* fourInARowPlayers[2] = {&fourInARowPlayer1, &fourInARowPlayer2};
        GameManager<char> fourInARowGame(&fourInARowBoard, fourInARowPlayers);
        fourInARowGame.run();
    } else if (choice == 2) {
        // Numerical Tic-Tac-Toe game
        printNumericalTicTacToeRules();
        NumericalTicTacToeBoard numericalTicTacToeBoard;
        NumericalTicTacToePlayer numericalTicTacToePlayer1("Player 1", 1);
        NumericalTicTacToePlayer numericalTicTacToePlayer2("Player 2", 2);

        numericalTicTacToePlayer1.setBoard(&numericalTicTacToeBoard);
        numericalTicTacToePlayer2.setBoard(&numericalTicTacToeBoard);

        Player<int>* numericalTicTacToePlayers[2] = {&numericalTicTacToePlayer1, &numericalTicTacToePlayer2};
        GameManager<int> numericalTicTacToeGame(&numericalTicTacToeBoard, numericalTicTacToePlayers);
        numericalTicTacToeGame.run();
    } else if (choice == 3) {
        // 4x4 Tic-Tac-Toe game
        printFourByFourTicTacToeRules();
        FourByFourTicTacToeBoard fourByFourTicTacToeBoard;
        FourByFourTicTacToePlayer fourByFourTicTacToePlayer1("Player 1", 'X');
        FourByFourTicTacToePlayer fourByFourTicTacToePlayer2("Player 2", 'O');

        fourByFourTicTacToePlayer1.setBoard(&fourByFourTicTacToeBoard);
        fourByFourTicTacToePlayer2.setBoard(&fourByFourTicTacToeBoard);

        Player<char>* fourByFourTicTacToePlayers[2] = {&fourByFourTicTacToePlayer1, &fourByFourTicTacToePlayer2};
        GameManager<char> fourByFourTicTacToeGame(&fourByFourTicTacToeBoard, fourByFourTicTacToePlayers);
        fourByFourTicTacToeGame.run();
    } else {
        cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}