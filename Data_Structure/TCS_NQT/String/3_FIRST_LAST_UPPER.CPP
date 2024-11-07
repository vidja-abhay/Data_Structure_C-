#include<bits/stdc++.h>
using namespace std;

void firstLast(string &s) {
    if (s.empty()) return;

    s[0] = toupper(s[0]);  // Capitalize first character
    s[s.length()-1] = toupper(s[s.length()-1]);  // Capitalize last character

    for(int i = 1; i < s.length() - 1; i++) {
        if(s[i] == ' ') {
            s[i-1] = toupper(s[i-1]);
            if (i+1 < s.length()) {
                s[i+1] = toupper(s[i+1]);
            }
        }
    }
}

int main() {
    string str;
    getline(cin, str);
    firstLast(str);
    cout << str;
    return 0;
}