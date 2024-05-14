#include <iostream>
#include <vector>
#include <set>
#include <string>

using namespace std;

// Function prototypes
void getFirstSets(const vector<string>& productions, vector<set<char>>& first);
void getFollowSets(const vector<string>& productions, const vector<set<char>>& first, vector<set<char>>& follow);

int main() {
    vector<string> productions = {"S->ABc", "A->aA|b", "B->bB|c"};

    vector<set<char>> first(3), follow(3); // Assuming at most 3 non-terminals

    getFirstSets(productions, first);
    getFollowSets(productions, first, follow);

    cout << "FIRST sets:" << endl;
    cout << "S: { ";
    for (const auto& terminal : first[0]) {
        cout << terminal << " ";
    }
    cout << "}" << endl;

    cout << "A: { ";
    for (const auto& terminal : first[1]) {
        cout << terminal << " ";
    }
    cout << "}" << endl;

    cout << "B: { ";
    for (const auto& terminal : first[2]) {
        cout << terminal << " ";
    }
    cout << "}" << endl;

    cout << "\nFOLLOW sets:" << endl;
    cout << "S: { ";
    for (const auto& terminal : follow[0]) {
        cout << terminal << " ";
    }
    cout << "}" << endl;

    cout << "A: { ";
    for (const auto& terminal : follow[1]) {
        cout << terminal << " ";
    }
    cout << "}" << endl;

    cout << "B: { ";
    for (const auto& terminal : follow[2]) {
        cout << terminal << " ";
    }
    cout << "}" << endl;

    return 0;
}

void getFirstSets(const vector<string>& productions, vector<set<char>>& first) {
    for (const auto& production : productions) {
        char lhs = production[0] - 'A'; // Index of the non-terminal
        for (int i = 3; i < production.length(); i++) {
            char symbol = production[i];
            if (isalpha(symbol) && isupper(symbol)) {
                break;
            }
            first[lhs].insert(symbol);
        }
    }
}

void getFollowSets(const vector<string>& productions, const vector<set<char>>& first, vector<set<char>>& follow) {
    follow[0].insert('$'); // Add end marker to FOLLOW of start symbol

    for (const auto& production : productions) {
        char lhs = production[0] - 'A'; // Index of the non-terminal
        for (int i = 3; i < production.length(); i++) {
            char symbol = production[i];
            if (isalpha(symbol) && isupper(symbol)) {
                int symbolIndex = symbol - 'A';
                for (int j = i + 1; j < production.length(); j++) {
                    char next = production[j];
                    if (isalpha(next) && isupper(next)) {
                        int nextIndex = next - 'A';
                        for (const auto& terminal : first[nextIndex]) {
                            follow[symbolIndex].insert(terminal);
                        }
                    } else {
                        follow[symbolIndex].insert(next);
                        break;
                    }
                }
            }
        }
    }
}