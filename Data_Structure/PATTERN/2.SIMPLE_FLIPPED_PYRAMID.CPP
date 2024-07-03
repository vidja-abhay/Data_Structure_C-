#include <iostream>
using namespace std;

void drawFlippedPyramid(int n) {
    for (int i = n; i >= 1; i--) {
        // Print spaces
        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }
        
        // Print stars
        for (int k = 1; k <= 2 * i - 1; k++) {
            cout << "*";
        }
        
        cout << endl;
    }
}

int main() {
    int height;
    cout << "Enter the height of the flipped pyramid: ";
    cin >> height;
    
    drawFlippedPyramid(height);
    
    return 0;
}