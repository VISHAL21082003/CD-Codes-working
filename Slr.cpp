#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

class SLRParser {
private:
    vector<string> grammar;
    map<int, map<string, string>> actionTable;
    map<int, map<string, int>> goToTable;
    stack<int> stateStack;
    stack<string> symbolStack;
    vector<string> input;
public:
    SLRParser(vector<string> grammar, 
              map<int, map<string, string>> actionTable,
              map<int, map<string, int>> goToTable, 
              vector<string> input) {
        this->grammar = grammar;
        this->actionTable = actionTable;
        this->goToTable = goToTable;
        this->input = input;
    }

    bool parse() {
        stateStack.push(0);
        int inputIndex = 0;

        while (inputIndex < input.size()) {
            int currentState = stateStack.top();
            string currentSymbol = input[inputIndex];

            if (actionTable.find(currentState) != actionTable.end() && 
                actionTable[currentState].find(currentSymbol) != actionTable[currentState].end()) {
                string action = actionTable[currentState][currentSymbol];
                
                if (action.substr(0, 1) == "s") {
                    int nextState = stoi(action.substr(1));
                    stateStack.push(nextState);
                    symbolStack.push(currentSymbol);
                    inputIndex++;
                } else if (action.substr(0, 1) == "r") {
                    int productionIndex = stoi(action.substr(1));
                    string production = grammar[productionIndex];
                    istringstream iss(production);
                    string leftPart, rightPart;
                    iss >> leftPart;
                    iss >> rightPart;
                    int len = count_if(rightPart.begin(), rightPart.end(), [](char c) { return c == ' '; });
                    for (int i = 0; i < len; i++) {
                        stateStack.pop();
                        symbolStack.pop();
                    }
                    currentState = stateStack.top();
                    string nonTerminal = leftPart;
                    stateStack.push(goToTable[currentState][nonTerminal]);
                    symbolStack.push(nonTerminal);
                } else if (action == "accept") {
                    return true;
                }
            } else {
                // No valid action in action table, parsing fails
                return false;
            }
        }
        // No more input symbols, parsing fails
        return false;
    }
};

int main() {
    // Example grammar
    vector<string> grammar = { "S -> E", "E -> E + T", "E -> T", "T -> id" };

    // Example action table
    map<int, map<string, string>> actionTable = {
        {0, {{"id", "s3"}}},
        {1, {{"+", "s4"}}},
        {3, {{"$", "accept"}}},
        {4, {{"id", "s3"}}}
    };

    // Example go-to table
    map<int, map<string, int>> goToTable = {
        {0, {{"E", 1}}},
        {1, {{"T", 2}}}
    };

    // Example input
    vector<string> input = {"id", "+", "id", "$"};

    SLRParser parser(grammar, actionTable, goToTable, input);
    bool result = parser.parse();

    if (result) {
        cout << "Input string accepted by grammar." << endl;
    } else {
        cout << "Input string rejected by grammar." << endl;
    }

    return 0;
}
