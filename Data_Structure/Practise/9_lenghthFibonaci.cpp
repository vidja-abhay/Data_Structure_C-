#include <iostream>
#include <vector>
using namespace std;

vector<long long> generateFibonacci(int length) {
    vector<long long> fib(length);
    
    if (length >= 1) fib[0] = 0;
    if (length >= 2) fib[1] = 1;
    
    for (int i = 2; i < length; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    return fib;
}

void printFibonacci(const vector<long long>& fib) {
    cout << "Fibonacci series of length " << fib.size() << " is:" << endl;
    for (long long num : fib) {
        cout << num << " ";
    }
    cout << endl;
}

int main() {
    int length;
    cout << "Enter the length of Fibonacci series you want to generate: ";
    cin >> length;

    if (length <= 0) {
        cout << "Please enter a positive integer." << endl;
        return 1;
    }

    vector<long long> fibSeries = generateFibonacci(length);
    printFibonacci(fibSeries);

    return 0;
}