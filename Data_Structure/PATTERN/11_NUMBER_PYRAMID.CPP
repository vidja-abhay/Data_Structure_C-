#include <iostream>

using namespace std;

void printPattern_1(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << i << " ";
        }
        cout << endl;
    }

    // OUTPUT

    // 1
    // 2 2
    // 3 3 3
    // 4 4 4 4
    // 5 5 5 5 5
}

void printPattern_2(int rows)
{
    int counter = 1;

    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << counter << " ";
            counter++;
        }
        cout << endl;
    }

    // 1
    // 2 3
    // 4 5 6
    // 7 8 9 10
    // 11 12 13 14 15
}

void printPattern_3(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // 1
    // 1 2
    // 1 2 3
    // 1 2 3 4
    // 1 2 3 4 5
}

void printPattern_4(int rows)
{
    for (int i = rows; i >= 1; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }
        cout << endl;
    }

    // 1 2 3 4 5
    // 1 2 3 4
    // 1 2 3
    // 1 2
    // 1
}

void printPattern_5(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        // Print leading 1 (except for the first row)
        if (i > 1)
        {
            cout << 1 << " ";
        }

        // Print alternating 0s and 1s
        for (int j = 1; j <= i; j++)
        {
            int x = (j % 2 == 0) ? 0 : 1; // Use conditional expression for alternating values
            cout << x << " ";
        }
        cout << endl;
    }

    // 1
    // 0 1
    // 1 0 1
    // 0 1 0 1
    // 1 0 1 0 1
}

void printPattern_6(int n)
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n - i; j++)
        {
            cout << "  ";
        }
        for (int k = i; k >= 1; k--)
        {
            cout << k << " ";
        }
        for (int l = 2; l <= i; l++)
        {
            cout << l << " ";
        }
        cout << endl;
    }

    //         1
    //       2 1 2
    //     3 2 1 2 3
    //   4 3 2 1 2 3 4
    // 5 4 3 2 1 2 3 4 5
}

void printPattern_7(int rows)
{
    for (int i = 1; i <= rows; i++)
    {
        // Calculate spaces for proper centering
        int spaces = rows - i;

        // Print leading spaces
        for (int j = 1; j <= spaces; j++)
        {
            cout << " ";
        }

        // Print increasing numbers
        for (int j = 1; j <= i; j++)
        {
            cout << j << " ";
        }

        cout << endl;
    }

    //     1
    //    1 2
    //   1 2 3
    //  1 2 3 4
    // 1 2 3 4 5
}

int main()
{
    int rows;

    cout << "Enter the number of rows: ";
    cin >> rows;

    printPattern_1(rows);

    printPattern_2(rows);

    printPattern_3(rows);

    return 0;
}