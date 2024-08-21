#include<bits/stdc++.h>
using namespace std;

void pattern1(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    // 1 
    // 2 2 
    // 3 3 3 
    // 4 4 4 4 
    // 5 5 5 5 5
}

void pattern2(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    // 5 5 5 5 5 
    // 4 4 4 4 
    // 3 3 3 
    // 2 2 
    // 1
}

void pattern3(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    //         1 
    //       2 2 
    //     3 3 3 
    //   4 4 4 4 
    // 5 5 5 5 5
}

void pattern4(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    // 5 5 5 5 5 
    //   4 4 4 4 
    //     3 3 3 
    //       2 2 
    //         1
}

void pattern5(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<k<<" ";
        }
        cout<<endl;
    }

    //         1 
    //       1 2 3 
    //     1 2 3 4 5 
    //   1 2 3 4 5 6 7 
    // 1 2 3 4 5 6 7 8 9
}

void pattern6(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<k<<" ";
        }
        cout<<endl;
    }

    // 1 2 3 4 5 6 7 8 9 
    //   1 2 3 4 5 6 7 
    //     1 2 3 4 5 
    //       1 2 3 
    //         1
}

void pattern7(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<k<<" ";
        }
        cout<<endl;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<k<<" ";
        }
        cout<<endl;
    }

    //         1 
    //       1 2 3 
    //     1 2 3 4 5 
    //   1 2 3 4 5 6 7 
    // 1 2 3 4 5 6 7 8 9 
    //   1 2 3 4 5 6 7 
    //     1 2 3 4 5 
    //       1 2 3 
    //         1
}

void pattern8(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    //         1 
    //       2 2 2 
    //     3 3 3 3 3 
    //   4 4 4 4 4 4 4 
    // 5 5 5 5 5 5 5 5 5
}

void pattern9(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    // 5 5 5 5 5 5 5 5 5 
    //   4 4 4 4 4 4 4 
    //     3 3 3 3 3 
    //       2 2 2 
    //         1
}

void pattern10(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    //         1 
    //       2 2 2 
    //     3 3 3 3 3 
    //   4 4 4 4 4 4 4 
    // 5 5 5 5 5 5 5 5 5 
    //   4 4 4 4 4 4 4 
    //     3 3 3 3 3 
    //       2 2 2 
    //         1
}

void pattern11(int n){
     for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= n - i; j++) {
            cout << " ";
        }

        int C = 1; 

        for (int k = 1; k <= i; k++) {
            cout << C << " ";
            C = C * (i - k) / k;
        }
        cout << endl;
    }

    //     1 
    //    1 1 
    //   1 2 1 
    //  1 3 3 1 
    // 1 4 6 4 1

    // pascal's triangle
}

void pattern12(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            int x = (i+j)%2 == 0 ? 1 : 0;
            cout<<x<<" ";
        }
        cout<<endl;
    }

    // 1 
    // 0 1 
    // 1 0 1 
    // 0 1 0 1 
    // 1 0 1 0 1
}

void pattern13(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "<<" ";
        }
        for (int k = 1; k <= (2 * i) - 1; k++) {
            if (k == 1 || k == (2 * i) - 1) {
                cout << i<<" ";
            } else {
                cout << " "<<" ";
            }
        }
        cout << endl;
    }
    
    for (int i = n-1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "<<" "; 
        }
        for (int k = 1; k <= (2 * i) - 1; k++) {
            if (k == 1 || k == (2 * i) - 1) {
                cout << i<<" ";
            } else {
                cout << " "<<" ";
            }
        }
        cout << endl;
    } 

    //         1 
    //       2   2 
    //     3       3 
    //   4           4 
    // 5               5 
    //   4           4 
    //     3       3 
    //       2   2 
    //         1
}

void pattern14(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<i<<" ";
        }
        cout<<endl;
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    // 5 5 5 5 5 5 5 5 5 
    //   4 4 4 4 4 4 4 
    //     3 3 3 3 3 
    //       2 2 2 
    //         1 
    //       2 2 2 
    //     3 3 3 3 3 
    //   4 4 4 4 4 4 4 
    // 5 5 5 5 5 5 5 5 5
}

void pattern15(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    for(int i=2; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<k<<" ";
        }
        cout<<endl;
    }

    // 1 2 3 4 5 6 7 8 9 
    //   1 2 3 4 5 6 7 
    //     1 2 3 4 5 
    //       1 2 3 
    //         1 
    //       1 2 3 
    //     1 2 3 4 5 
    //   1 2 3 4 5 6 7 
    // 1 2 3 4 5 6 7 8 9
}

void pattern16(int n) {
    for (int i = 1; i <= n; i++) {
        // Leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << "  ";
        }

        // Stars and inner spaces
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1 || i == n) {
                cout << j<< " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    //         1 
    //       1   3 
    //     1       5 
    //   1           7 
    // 1 2 3 4 5 6 7 8 9 
}

void pattern17(int n) {
    for (int i = 1; i <= n; i++) {
        // Leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << "  ";
        }

        // Stars and inner spaces
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1 || i == n) {
                cout << i<< " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    //         1 
    //       2   2 
    //     3       3 
    //   4           4 
    // 5 5 5 5 5 5 5 5 5
}

int main(){

    return 0;
}