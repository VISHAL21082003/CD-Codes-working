#include <iostream>
#include <string>

using namespace std;

// Function to generate code for the if statement
string generateIfCode(string condition, string action) {
    // Initialize an empty string to build the code
    string code;

    // Add the if statement
    code += "if (" + condition + ") {\n";

    // Add the action inside the if block
    code += "\t" + action + "\n";

    // Close the if block
    code += "}";

    // Return the generated code as a string
    return code;
}

// Function to generate code for the while loop
string generateWhileCode(string condition, string action) {
    // Initialize an empty string to build the code
    string code;

    // Add the while loop
    code += "while (" + condition + ") {\n";

    // Add the action inside the while loop
    code += "\t" + action + "\n";

    // Close the while loop
    code += "}";

    // Return the generated code as a string
    return code;
}

int main() {
    // Example input: if (x > 5) { y = x * 2; }
    string if_condition = "x > 5";
    string if_action = "y = x * 2;";

    // Generate code for the if statement
    string if_generatedCode = generateIfCode(if_condition, if_action);

    // Print the generated code for the if statement
    cout << "Generated code for If statement:" << endl;
    cout << if_generatedCode << endl;

    cout << endl;

    // Example input: while (i < 10) { cout << i; i++; }
    string while_condition = "i < 10";
    string while_action = "cout << i; i++;";

    // Generate code for the while loop
    string while_generatedCode = generateWhileCode(while_condition, while_action);

    // Print the generated code for the while loop
    cout << "Generated code for While loop:" << endl;
    cout << while_generatedCode << endl;

    return 0;
}
