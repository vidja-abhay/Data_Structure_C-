#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

vector<int> listPrimes(int n) {
    vector<bool> isPrime(n + 1, true);
    vector<int> primes;

    // 0 and 1 are not prime
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i <= sqrt(n); i++) {
        if (isPrime[i]) {
            for (int j = i * i; j <= n; j += i) {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (isPrime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    vector<int> primes = listPrimes(n);

    cout << "Prime numbers up to " << n << " are:" << endl;
    for (int prime : primes) {
        cout << prime << " ";
    }
    cout << endl;

    return 0;
}