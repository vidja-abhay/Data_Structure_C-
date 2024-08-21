#include <bits/stdc++.h>
using namespace std;

void pattern1(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << char('A' + j) << " ";
        }
        cout << endl;
    }

    // A 
    // A B 
    // A B C 
    // A B C D 
    // A B C D E
}

void pattern2(int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            cout << char('A' + i) << " ";
        }
        cout << endl;
    }

    // A 
    // B B 
    // C C C 
    // D D D D 
    // E E E E E
}

void pattern3(int n) {
    for (int i = 0; i < n; i++) {
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for (int j = 0; j <= i; j++) {
            cout << char('A' + i) << " ";
        }
        cout << endl;
    }

//           A 
//         B B 
//       C C C 
//     D D D D 
//   E E E E E
}

void pattern4(int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=0; k<=(2*i); k++){
            cout<<char('A' + k)<<" ";
        }
        cout<<endl;
    }

    //           A 
    //         A B C 
    //       A B C D E 
    //     A B C D E F G 
    //   A B C D E F G H I
}

void pattern5(int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=0; k<=(2*i); k++){
            cout<<char('A' + i)<<" ";
        }
        cout<<endl;
    }

    //           A 
    //         B B B 
    //       C C C C C 
    //     D D D D D D D 
    //   E E E E E E E E E
}

void pattern6(int n){
    for(int i=0; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=0; k<=(2*i); k++){
            cout<<char('A' + k)<<" ";
        }
        cout<<endl;
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=0; k<=(2*i); k++){
            cout<<char('A' + k)<<" ";
        }
        cout<<endl;
    }

//           A 
//         A B C 
//       A B C D E 
//     A B C D E F G 
//   A B C D E F G H I 
//     A B C D E F G 
//       A B C D E 
//         A B C 
//           A
}

void pattern7(int n){
    for(int i=n-1; i>=0; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=0; k<=(2*i); k++){
            cout<<char('A' + k)<<" ";
        }
        cout<<endl;
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=0; k<=(2*i); k++){
            cout<<char('A' + k)<<" ";
        }
        cout<<endl;
    }

//   A B C D E F G H I 
//     A B C D E F G 
//       A B C D E 
//         A B C 
//           A 
//         A B C 
//       A B C D E 
//     A B C D E F G 
//   A B C D E F G H I
}

void pattern(int n){
    for (int i = 0; i < n; i++) {
        // Leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << "  ";
        }

        // Stars and inner spaces
        for (int j = 0; j <= 2 * i ; j++) {
            if (j == 0 || j == 2 * i  || i == n-1) {
                cout << char('A' + j)<< " ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }

    //           A 
    //         A   C 
    //       A       E 
    //     A           G 
    //   A B C D E F G H I 
}

int main() {

    return 0;
}
