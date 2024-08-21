#include <iostream>
#include <cmath>

using namespace std;

// Function to calculate the power of a number using exponentiation by squaring
double power(double base, int exponent) {
    if (exponent == 0) return 1; // base case: any number to the power of 0 is 1

    double halfPower = power(base, abs(exponent) / 2);

    if (exponent % 2 == 0) {
        // If exponent is even
        if (exponent < 0) {
            return 1 / (halfPower * halfPower);
        } else {
            return halfPower * halfPower;
        }
    } else {
        // If exponent is odd
        if (exponent < 0) {
            return 1 / (base * halfPower * halfPower);
        } else {
            return base * halfPower * halfPower;
        }
    }
}

int main() {
    double base;
    int exponent;

    cout << "Enter the base: ";
    cin >> base;
    cout << "Enter the exponent: ";
    cin >> exponent;

    double result = power(base, exponent);

    cout << base << "^" << exponent << " = " << result << endl;

    return 0;
}
