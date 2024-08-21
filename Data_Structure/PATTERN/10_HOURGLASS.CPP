#include <iostream>
using namespace std;

void drawPattern(int n) {
    // Upper half of the pattern
    for (int i = n; i >= 1; i--) {
        // Print leading spaces
        for (int j = 0; j < n - i; j++) {
            cout << "  ";
        }
        // Print stars with spaces
        for (int k = 0; k < 2 * i - 1; k++) {
            cout << "* ";
        }
        cout << endl;
    }
    
    // Lower half of the pattern (excluding the middle row)
    for (int i = 2; i <= n; i++) {
        // Print leading spaces
        for (int j = 0; j < n - i; j++) {
            cout << "  ";
        }
        // Print stars with spaces
        for (int k = 0; k < 2 * i - 1; k++) {
            cout << "* ";
        }
        cout << endl;
    }
}

int main() {
    int n = 5; // This will create a 9x9 pattern as shown
    drawPattern(n);
    return 0;
}