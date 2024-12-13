#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

void Compare_Char_By_Char(ifstream& file1, ifstream& file2) {
    string line1, line2;
    int lineNumber = 0;
    while (getline(file1, line1) && getline(file2, line2)) {
        lineNumber++;
        if (line1 != line2) {
            cout << "Files are different at line " << lineNumber << ":\n";
            cout << "File 1: " << line1 << "\n";
            cout << "File 2: " << line2 << "\n";
            return;
        }
    }

    if (getline(file1, line1) || getline(file2, line2)) {
        cout << "Files are different in length.\n";
    } else {
        cout << "Files are identical (character by character).\n";
    }
}

vector<string> Split_Into_Words(const string& line) {
    vector<string> words;
    string word;
    stringstream ss(line);

    while (ss >> word) {
        words.push_back(word);
    }
    return words;
}

void Compare_Word_By_Word(ifstream& file1, ifstream& file2) {
    string line1, line2;
    int lineNumber = 0;

    while (getline(file1, line1) && getline(file2, line2)) {
        lineNumber++;
        vector<string> words1 = Split_Into_Words(line1);
        vector<string> words2 = Split_Into_Words(line2);

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

int main() {
    string file1Name, file2Name;
    cout << "Enter the first file name: ";
    cin >> file1Name;
    cout << "Enter the second file name: ";
    cin >> file2Name;

    ifstream file1(file1Name);
    ifstream file2(file2Name);

    if (!file1.is_open() || !file2.is_open()) {
        cout << "Error opening one or both files.\n";
        return 1;
    }

    int choice;
    cout << "Choose comparison method: \n1. Character by character\n2. Word by word\n";
    cin >> choice;

    if (choice == 1) {
        Compare_Char_By_Char(file1, file2);
    } else if (choice == 2) {
        Compare_Word_By_Word(file1, file2);
    } else {
        cout << "Invalid choice!\n";
    }

    file1.close();
    file2.close();

    return 0;
}
