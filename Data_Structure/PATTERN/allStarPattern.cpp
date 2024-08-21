#include<bits/stdc++.h>
using namespace std;

// 1. Left Triangle
void pattern1(int n){
    for(int i=1; i<=n; i++){

        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        cout<<endl;
    }

    // * 
    // * * 
    // * * * 
    // * * * * 
    // * * * * * 
}

// 2. Flipped Left Triangle
void pattern2(int n){
    for(int i=n; i>=1; i--){

        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        cout<<endl;
    }

    // * * * * * 
    // * * * * 
    // * * * 
    // * * 
    // *
}

// 3. Right Triangle
void pattern3(int n){
    for(int i=1; i<=n; i++){

        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }

        for(int k=1; k<=i; k++){
            cout<<"* ";
        }

        cout<<endl;
    }

    //         * 
    //       * * 
    //     * * * 
    //   * * * * 
    // * * * * *
}

// 4. Flipped Right Triangle
void pattern4(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }

        for(int k=1; k<=i; k++){
            cout<<"* ";
        }

        cout<<endl;
    }

    // * * * * * 
    //   * * * * 
    //     * * * 
    //       * * 
    //         *
}

// 5. Simple Pyramid
void pattern5(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //         * 
    //       * * * 
    //     * * * * * 
    //   * * * * * * * 
    // * * * * * * * * *
}

// 6. Flipped Pyramid
void pattern6(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(2*i)-1; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // * * * * * * * * * 
    //   * * * * * * * 
    //     * * * * * 
    //       * * * 
    //         * 
}

// 7. Pyramid With Each Row Contain * = Row No.
void pattern7(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //     * 
    //    * * 
    //   * * * 
    //  * * * * 
    // * * * * *
}

// 8. Flipped Pyramid With Each Row Contain * = Row No.
void pattern8(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // * * * * * 
    //  * * * * 
    //   * * * 
    //    * * 
    //     * 
}

// 9. Half Diamond
void pattern9(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // * 
    // * * 
    // * * * 
    // * * * * 
    // * * * * * 
    // * * * * 
    // * * * 
    // * * 
    // *
}

// 10. Flipped Half Diamond
void pattern10(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //         * 
    //       * * 
    //     * * * 
    //   * * * * 
    // * * * * * 
    //   * * * * 
    //     * * * 
    //       * * 
    //         *
}

// 11. Full Diamod
void pattern11(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(i*2)-1; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=(i*2)-1; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //         * 
    //       * * * 
    //     * * * * * 
    //   * * * * * * * 
    // * * * * * * * * * 
    //   * * * * * * * 
    //     * * * * * 
    //       * * * 
    //         *
}

// 12. Hollow Diamond
void pattern12(int n) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "<<" ";
        }
        for (int k = 1; k <= (2 * i) - 1; k++) {
            if (k == 1 || k == (2 * i) - 1) {
                cout << "* ";
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
                cout << "* ";
            } else {
                cout << " "<<" ";
            }
        }
        cout << endl;
    }

    //         * 
    //       *   * 
    //     *       * 
    //   *           * 
    // *               * 
    //   *           * 
    //     *       * 
    //       *   * 
    //         * 
}

// 13. Tilled Full Diamond Left
void pattern13(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // * 
    // * * 
    // * * * 
    // * * * * 
    // * * * * * 
    //   * * * * 
    //     * * * 
    //       * * 
    //         *
}

// 14. Tilled Full Diamond Right
void pattern14(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=i; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=n-1; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //         * 
    //       * * 
    //     * * * 
    //   * * * * 
    // * * * * * 
    // * * * * 
    // * * * 
    // * * 
    // *
}

// 15. Upper Half Butterfly
void pattern15(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        for(int k=1; k<=(n*2) - (i*2); k++){
            cout<<" "<<" ";
        }

        for(int l=1; l<=i; l++){
            cout<<"* ";
        }

        cout<<endl;
    }

    // *                 * 
    // * *             * * 
    // * * *         * * * 
    // * * * *     * * * * 
    // * * * * * * * * * *
}

// 16. Lower Half Butterfly
void pattern16(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        for(int k=1; k<=(n*2)-(i*2); k++){
            cout<<" "<<" ";
        }

        for(int l=1; l<=i; l++){
            cout<<"* ";
        }

        cout<<endl;
    }

    // * * * * * * * * * * 
    // * * * *     * * * * 
    // * * *         * * * 
    // * *             * * 
    // *                 *
}

// 17. Butterfly
void pattern17(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        for(int k=1; k<=(n*2) - (i*2); k++){
            cout<<" "<<" ";
        }

        for(int l=1; l<=i; l++){
            cout<<"* ";
        }

        cout<<endl;
    }

    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        for(int k=1; k<=(n*2)-(i*2); k++){
            cout<<" "<<" ";
        }

        for(int l=1; l<=i; l++){
            cout<<"* ";
        }

        cout<<endl;
    }

    // *                 * 
    // * *             * * 
    // * * *         * * * 
    // * * * *     * * * * 
    // * * * * * * * * * * 
    // * * * * * * * * * * 
    // * * * *     * * * * 
    // * * *         * * * 
    // * *             * * 
    // *                 * 
}

// 18. Hollow Diamond with outer parts fill with *
void pattern18(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        for(int k=1; k<=(n*2)-(i*2); k++){
            cout<<" "<<" ";
        }

        for(int l=1; l<=i; l++){
            cout<<"* ";
        }

        cout<<endl;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=i; j++){
            cout<<"* ";
        }

        for(int k=1; k<=(n*2) - (i*2); k++){
            cout<<" "<<" ";
        }

        for(int l=1; l<=i; l++){
            cout<<"* ";
        }

        cout<<endl;
    }

    // * * * * * * * * * * 
    // * * * *     * * * * 
    // * * *         * * * 
    // * *             * * 
    // *                 * 
    // *                 * 
    // * *             * * 
    // * * *         * * * 
    // * * * *     * * * * 
    // * * * * * * * * * *
}

// 19. Filled Rhombus
void pattern19(int n){
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }
        for(int k=1; k<=n; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    //         * * * * * 
    //       * * * * * 
    //     * * * * * 
    //   * * * * * 
    // * * * * *
}

// 20. Hollow Rhombus
void pattern20(int n){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n-i; j++)
        {
            cout << " " << " ";
        }

        if (i == 1 || i == n)
        {
            for (int j = 1; j <= n; j++)
            {
                cout << '*' << " ";
            }
        }

        else{
            cout<<'*'<<" ";
            for(int j=1;j<=n-2;j++){
                cout<<" "<<" ";
            }
            cout<<'*'<<" ";
        }

         cout<<endl;
    }
}

// 21. Hourglass
void pattern21(int n){
    for(int i=n; i>=1; i--){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }

        for(int k=1; k<=(2*i)-1; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    for(int i=2; i<=n; i++){
        for(int j=1; j<=n-i; j++){
            cout<<" "<<" ";
        }

        for(int k=1; k<=(2*i)-1; k++){
            cout<<"* ";
        }
        cout<<endl;
    }

    // * * * * * * * * * 
    //   * * * * * * * 
    //     * * * * * 
    //       * * * 
    //         * 
    //       * * * 
    //     * * * * * 
    //   * * * * * * * 
    // * * * * * * * * *
}

// 12. X
void pattern22(int n) {
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "<<" "; 
        }
        for (int k = 1; k <= (2 * i) - 1; k++) {
            if (k == 1 || k == (2 * i) - 1) {
                cout << "* ";
            } else {
                cout << " "<<" ";
            }
        }
        cout << endl;
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= n - i; j++) {
            cout << " "<<" ";
        }
        for (int k = 1; k <= (2 * i) - 1; k++) {
            if (k == 1 || k == (2 * i) - 1) {
                cout << "* ";
            } else {
                cout << " "<<" ";
            }
        }
        cout << endl;
    }

    // *               * 
    //   *           * 
    //     *       * 
    //       *   * 
    //         * 
    //       *   * 
    //     *       * 
    //   *           * 
    // *               *
}

void pattern23(int n) {
    for (int i = 1; i <= n; i++) {
        // Leading spaces
        for (int j = 1; j <= n - i; j++) {
            cout << "  ";
        }

        // Stars and inner spaces
        for (int j = 1; j <= 2 * i - 1; j++) {
            if (j == 1 || j == 2 * i - 1 || i == n) {
                cout << "* ";
            } else {
                cout << "  ";
            }
        }
        cout << endl;
    }
}


int main(){

    pattern7(5);

    return 0;
}