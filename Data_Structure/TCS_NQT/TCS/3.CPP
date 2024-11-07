// GIVEN TWO INTEGER, FIND SUM OF CUBES ALL NUMBER IN RANGE OF N & M.

// I/P : N = 4, M = 9;

// O/P : 1989


#include <iostream>
using namespace std;

// Function to calculate the sum of cubes in the range [N, M]
int sumOfCubesInRange(int N, int M) {
    int sum = 0;

    // Iterate from N to M
    for (int i = N; i <= M; i++) {
        sum += i * i * i;  // Add the cube of the current number to sum
    }

    return sum;
}

int main() {
    int N = 4;
    int M = 5;

    int result = sumOfCubesInRange(N, M);
    cout << "Sum of cubes from " << N << " to " << M << " is: " << result << endl;

    return 0;
}
