#include <iostream>
using namespace std;

void drawHalfDiamond(int n) {
    // Upper half of the diamond
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
    
    // Lower half of the diamond
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int height;
    cout << "Enter the height of half of the diamond: ";
    cin >> height;
    
    drawHalfDiamond(height);
    
    return 0;
}