#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Player {
    string name;
    int score;
};

vector<Player> players;

void Add_Player(const string& name, int score) {
    players.push_back({name, score});
    sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.score > b.score;
    });
    if (players.size() > 10) players.pop_back();
}

void Print_Top_Scores() {
    for (const auto& player : players) {
        cout << player.name << " " << player.score << endl;
    }
}

void Find_Player_Score(const string& name) {
    auto it = find_if(players.begin(), players.end(), [&name](const Player& player) {
        return player.name == name;
    });
    if (it != players.end()) cout << "Highest score for " << name << " is " << it->score << endl;
    else cout << name << " is not in the top 10 list." << endl;
}

void Menu() {
    int choice;
    do {
        cout << "1. Add a new Player\n2. Print Top Scores\n3. Find Player's Highest Score\n4. Exit...\n";
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            string name;
            int score;
            cout << "Enter player name: ";
            cin >> name;
            cout << "Enter player score: ";
            cin >> score;
            Add_Player(name, score);
        } else if (choice == 2) {
            Print_Top_Scores();
        } else if (choice == 3) {
            string name;
            cout << "Enter player name: ";
            cin >> name;
            Find_Player_Score(name);
        }
    } while (choice != 4);
}

int main() {
    Menu();
    return 0;
}