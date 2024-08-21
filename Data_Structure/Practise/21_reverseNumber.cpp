#include <iostream>

using namespace std;

int reverseNumber(int num) {
    int reversed = 0;
    while (num != 0) {
        int digit = num % 10;
        reversed = reversed * 10 + digit;
        num /= 10;
    }
    return reversed;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    int reversedNum = reverseNumber(num);

    cout << "Reversed number: " << reversedNum << endl;

    return 0;
}