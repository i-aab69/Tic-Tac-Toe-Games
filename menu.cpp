#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <fstream>

using namespace std;

// Code 1: Gender Neutral Replacement
void GenderReplacement() {
    string s1, result, carry;
    cout << "Enter your message:\n";
    cin.ignore();  // To ignore any leftover newline character from previous inputs
    getline(cin, s1);
    istringstream word(s1);

    while (word >> carry) {
        string not_alpha = "";
        for (int i = 0; i < carry.size(); i++) {
            if (!isalpha(carry[i])) {
                if (i == carry.size() - 1) {
                    not_alpha = carry[i];
                    carry.erase(i, 1);
                }
            }
        }

        if (carry == "him" || carry == "Him") {
            result += carry + " or her" + not_alpha + " ";
        } else if (carry == "he" || carry == "He") {
            result += carry + " or she" + not_alpha + " ";
        } else if (carry == "his" || carry == "His") {
            result += carry + " or her" + not_alpha + " ";
        } else {
            result += carry + not_alpha + " ";
        }
    }

    cout << result << endl;
}

// Code 2: Top 10 Player Scores Management
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

void playerScoresMenu() {
    int choice;
    do {
        cout << "1. Add a new Player\n2. Print Top Scores\n3. Find Player's Highest Score\n4. Exit\n";
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

// Code 3: Fractal Pattern
void Fractal_Pattern(int n, int i) {
    if (n < 1) return;

    Fractal_Pattern(n / 2, i);

    for (int j = 0; j < i; j++) cout << "  ";
    for (int j = 0; j < n; j++) cout << "* ";
    cout << "\n";

    Fractal_Pattern(n / 2, i + n / 2);
}

void FractalPattern() {
    int size;
    Fractal_Pattern(8, 0);
}

// Code 4: File Comparison
void compareCharByChar(ifstream& file1, ifstream& file2) {
    string line1, line2;
    int lineNumber = 0;
    while (getline(file1, line1) && getline(file2, line2)) {
        lineNumber++;
        if (line1 != line2) {
            cout << "Files differ at line " << lineNumber << ":\n";
            cout << "File 1: " << line1 << "\n";
            cout << "File 2: " << line2 << "\n";
            return;
        }
    }

    if (getline(file1, line1) || getline(file2, line2)) {
        cout << "Files differ in length.\n";
    } else {
        cout << "Files are identical (character by character).\n";
    }
}

vector<string> splitIntoWords(const string& line) {
    vector<string> words;
    string word;
    stringstream ss(line);

    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

void compareWordByWord(ifstream& file1, ifstream& file2) {
    string line1, line2;
    int lineNumber = 0;

    while (getline(file1, line1) && getline(file2, line2)) {
        lineNumber++;
        vector<string> words1 = splitIntoWords(line1);
        vector<string> words2 = splitIntoWords(line2);

        int minSize = min(words1.size(), words2.size());
        for (int i = 0; i < minSize; ++i) {
            if (words1[i] != words2[i]) {
                cout << "Files differ at line " << lineNumber << ":\n";
                cout << "File 1 word: " << words1[i] << "\n";
                cout << "File 2 word: " << words2[i] << "\n";
                return;
            }
        }

        if (words1.size() != words2.size()) {
            cout << "Files differ in the number of words at line " << lineNumber << "\n";
            return;
        }
    }

    if (getline(file1, line1) || getline(file2, line2)) {
        cout << "Files differ in length.\n";
    } else {
        cout << "Files are identical (word by word).\n";
    }
}

void FileComparison() {
    string file1Name, file2Name;
    cout << "Enter the first file name: ";
    cin >> file1Name;
    cout << "Enter the second file name: ";
    cin >> file2Name;

    ifstream file1(file1Name);
    ifstream file2(file2Name);

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Error opening one or both files.\n";
        return;
    }

    int choice;
    cout << "Choose comparison method: \n1. Character by character\n2. Word by word\n";
    cin >> choice;

    if (choice == 1) {
        compareCharByChar(file1, file2);
    } else if (choice == 2) {
        compareWordByWord(file1, file2);
    } else {
        cout << "Invalid choice!\n";
    }

    file1.close();
    file2.close();
}

int main() {
    int choice;
    do {
        cout << "\nChoose an option:\n";
        cout << "1. Gender Neutral Replacement\n";
        cout << "2. Player Scores Management\n";
        cout << "3. Recursive Star Pattern\n";
        cout << "4. File Comparison\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                GenderReplacement();
                break;
            case 2:
                playerScoresMenu();
                break;
            case 3:
                FractalPattern();
                break;
            case 4:
                FileComparison();
                break;
            case 5:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}
