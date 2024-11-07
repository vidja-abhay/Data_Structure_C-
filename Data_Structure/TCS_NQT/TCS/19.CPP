// WRITE A PROGRAM TO TAKE INPUT O X AND Y IN A NEW LINE. PRINT THE NUMBER WHICH IS NEARER THE INTEGER X WHEN DIVIDED BY Y.

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int X, Y;
    cout << "Enter the value of X: ";
    cin >> X;
    cout << "Enter the value of Y: ";
    cin >> Y;

    if (Y == 0) {
        cout << "Division by zero is not allowed." << endl;
        return 1;
    }

    // Find the nearest multiples of Y
    int quotient = X / Y;
    int lowerMultiple = Y * quotient;
    int upperMultiple = Y * (quotient + 1);

    // Determine which multiple is closer to X
    if (abs(X - lowerMultiple) < abs(X - upperMultiple)) {
        cout << "The number nearer to " << X << " when divided by " << Y << " is: " << lowerMultiple << endl;
    } else {
        cout << "The number nearer to " << X << " when divided by " << Y << " is: " << upperMultiple << endl;
    }

    return 0;
}
