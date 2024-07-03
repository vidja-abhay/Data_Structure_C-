#include <iostream>
using namespace std;

void drawPattern(int n) {
    // Upper half
    for (int i = 1; i <= n; i++) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Lower half
    for (int i = n - 1; i >= 1; i--) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        // Print stars
        for (int k = 1; k <= i; k++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int height;
    cout << "Enter the height of the pattern (should be odd): ";
    cin >> height;
    
    // Ensure height is odd
    if (height % 2 == 0) height++;
    
    drawPattern((height + 1) / 2);
    
    return 0;
}