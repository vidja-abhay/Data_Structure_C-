#include <iostream>
using namespace std;

void printFibonacci(int n) {
    int first = 0, second = 1, next;

    cout << "Fibonacci series up to " << n << " is:" << endl;

    // Print the first two numbers
    if (n >= 1) cout << first << " ";
    if (n >= 2) cout << second << " ";

    // Generate and print the rest of the series
    for (int i = 3; i <= n; i++) {
        next = first + second;
        if (next > n) break;  // Stop if we exceed the limit
        cout << next << " ";
        first = second;
        second = next;
    }
    cout << endl;
}

void printFibonacci2(int n, int a = 0, int b = 1) {
    if (a > n) return;
    
    cout << a << " ";
    
    printFibonacci2(n, b, a + b);
}

int main() {
    int n;
    cout << "Enter the limit for Fibonacci series: ";
    cin >> n;

    printFibonacci(n);

    return 0;
}