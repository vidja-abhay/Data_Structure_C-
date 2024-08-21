#include <iostream>
using namespace std;

void drawReverseLeftTriangle(int n) {
    for (int i = n; i >= 1; i--) {
        // Print stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int height;
    cout << "Enter the height of the reverse left triangle: ";
    cin >> height;
    
    drawReverseLeftTriangle(height);
    
    return 0;
}