#include <iostream>
#include <cmath>

using namespace std;

// Function to count the number of digits in a number
int countDigits(int num) {
    int count = 0;
    while (num != 0) {
        count++;
        num /= 10;
    }
    return count;
}

// Function to check if a number is an Armstrong number
bool isArmstrong(int num) {
    int numDigits = countDigits(num);
    int sum = 0;
    int temp = num;
    
    while (temp != 0) {
        int digit = temp % 10;
        sum += pow(digit, numDigits);
        temp /= 10;
    }
    
    return sum == num;
}

int main() {
    int num;

    cout << "Enter a number: ";
    cin >> num;

    if (isArmstrong(num)) {
        cout << num << " is an Armstrong number." << endl;
    } else {
        cout << num << " is not an Armstrong number." << endl;
    }

    return 0;
}
