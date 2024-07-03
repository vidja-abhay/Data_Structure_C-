#include <iostream>
using namespace std;

void drawReverseRightTriangle(int n) {
    for (int i = n; i >= 1; i--) {
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
    cout << "Enter the height of the reverse right triangle: ";
    cin >> height;
    
    drawReverseRightTriangle(height);
    
    return 0;
}