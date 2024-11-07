
// Write a program that generates a password adhering to the following conditions:

// The password must consist of at least 8 characters.

// It must contain at least one integer.

// • It must contain at least one special character from the set ('#', '@'}. • It must contain at least one uppercase letter and one lowercase letter.

// • Each character in the password should be incremented by the number of times specified by the second input.

// Your program should take two inputs:

// 1. A string representing the initial password.

// 2. An integer representing the number of times each character should be incremented.

// Your program should then generate and output the modified password.

// Example 1:

// Input1: werV432@

// Input2: 2

// Output: ygtX653#

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function to validate initial password
bool isValidPassword(const string& password) {
    if (password.length() < 8) return false;

    bool hasLower = false, hasUpper = false, hasDigit = false, hasSpecial = false;
    for (char ch : password) {
        if (islower(ch)) hasLower = true;
        if (isupper(ch)) hasUpper = true;
        if (isdigit(ch)) hasDigit = true;
        if (ch == '#' || ch == '@') hasSpecial = true;
    }

    return hasLower && hasUpper && hasDigit && hasSpecial;
}

// Function to increment each character by a given number
string incrementPassword(const string& password, int increment) {
    string modifiedPassword;

    for (char ch : password) {
        if (islower(ch)) {
            modifiedPassword += char(((ch - 'a' + increment) % 26) + 'a');
        } else if (isupper(ch)) {
            modifiedPassword += char(((ch - 'A' + increment) % 26) + 'A');
        } else if (isdigit(ch)) {
            modifiedPassword += char(((ch - '0' + increment) % 10) + '0');
        } else if (ch == '#') {
            modifiedPassword += '@';  // Alternate special character
        } else if (ch == '@') {
            modifiedPassword += '#';  // Alternate special character
        } else {
            modifiedPassword += ch; // Preserve other characters as is
        }
    }

    return modifiedPassword;
}

int main() {
    string initialPassword;
    int increment;

    cout << "Enter the initial password: ";
    cin >> initialPassword;
    cout << "Enter the increment value: ";
    cin >> increment;

    // Validate initial password
    if (!isValidPassword(initialPassword)) {
        cout << "Invalid initial password. It must be at least 8 characters long, contain at least one uppercase letter, one lowercase letter, one digit, and one special character (# or @)." << endl;
        return 1;
    }

    // Generate the modified password
    string modifiedPassword = incrementPassword(initialPassword, increment);

    cout << "Modified password: " << modifiedPassword << endl;

    return 0;
}
