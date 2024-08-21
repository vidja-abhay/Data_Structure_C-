#include <bits/stdc++.h>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) return false; // Numbers less than or equal to 1 are not prime
    if (n <= 3) return true;  // 2 and 3 are prime numbers
    if (n % 2 == 0 || n % 3 == 0) return false; // Eliminate multiples of 2 and 3

    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

// Function to find prime factors of a number
vector<int> primeFactorOfNumber(int n) {
    vector<int> vec;

    for (int i = 2; i <= n; i++) {
        if (n % i == 0) {
            if (isPrime(i)) {
                vec.push_back(i);
            }
        }
    }

    return vec;
}

// Function to print a vector of integers
void print(const vector<int>& vec) {
    for (auto i : vec) {
        cout << i << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> factors = primeFactorOfNumber(n);

    cout << "Prime factors of " << n << " are: ";
    print(factors);

    return 0;
}
