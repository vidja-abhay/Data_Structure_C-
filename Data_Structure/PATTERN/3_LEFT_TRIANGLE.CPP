#include <iostream>
using namespace std;

void drawLeftTriangle(int n) {
    for (int i = 1; i <= n; i++) {
        // Print stars
        for (int j = 1; j <= i; j++) {
            cout << "*";
        }
        cout << endl;
    }
}

int main() {
    int height;
    cout << "Enter the height of the left triangle: ";
    cin >> height;
    
    drawLeftTriangle(height);
    
    return 0;
}