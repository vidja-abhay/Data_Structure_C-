#include<bits/stdc++.h>

using namespace std;
int main() {
  int n = 5;
 
  int arr[n][2] = {{1, 2}, {2, 1}, {3, 4}, {4, 5}, {5, 4}}; 
  cout << "The Symmetric Pairs are: " << endl;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      if (arr[j][0] == arr[i][1] && arr[j][1] == arr[i][0]) {
        cout << "(" << arr[i][1] << " " << arr[i][0] << ")" << " ";
        break;
      }
    }
  }

}