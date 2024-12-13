#include "BoardGame_Classes.h"
#include "Four-in-a-row.h"
#include "NumericalTicTacToe.h"
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

int main() {
    srand(static_cast<unsigned>(time(0)));

    int choice;
    cout << "Choose a game to play:\n";
    cout << "1. Four-in-a-Row\n";
    cout << "2. Numerical Tic-Tac-Toe\n";
    cout << "Enter your choice (1 or 2): ";
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
    } else {
        cout << "Invalid choice. Exiting.\n";
    }

    return 0;
}