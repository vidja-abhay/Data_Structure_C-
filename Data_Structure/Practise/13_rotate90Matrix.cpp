// C++ program to rotate a matrix
// by 90 degrees
#include <bits/stdc++.h>

using namespace std;

// Function to
// rotate a N x M matrix
// by 90 degrees in
// clockwise direction
void rotateMatrix(vector<vector<int> >& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int> > new_mat(m, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            new_mat[j][n - i - 1] = mat[i][j];
        }
    }
    mat = new_mat;
}

// Function to print the matrix
void displayMatrix(vector<vector<int> >& mat)
{
    int n = mat.size();
    int m = mat[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

/* Driver code */
int main()
{
    // Test Case 1
    int n, m;
    cin >> n >> m;
    
    // Initialize mat with proper size
    vector<vector<int>> mat(n, vector<int>(m));
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> mat[i][j];
        }
    }
    
    // Function call
    rotateMatrix(mat);
    
    // Print rotated matrix
    displayMatrix(mat);
    
    return 0;
}
