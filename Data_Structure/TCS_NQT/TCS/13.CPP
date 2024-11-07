// A PERSON HAS MANY SHOES OF DIFFERENET SIZES AND HE WANTS TO ARRANGE THEM, CALCULATE THE NUMBER OF PAIRS OF SHOES.

// I/P : 8, 7L 7R 7L 8L 6R 7R 8R 6R
// O/P : 3


#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;
    unordered_map<string, int> store;

    for (int i = 0; i < N; ++i) {
        string shoeSize;
        cin >> shoeSize;
        if (store.find(shoeSize) != store.end()) {
            store[shoeSize]++;
        } else {
            store[shoeSize] = 1;
        }
    }

    int pairs = 0;
    for (auto& it : store) {
        string key = it.first;
        int val = it.second;
        string opposite;
        if (key[key.size() - 1] == 'L') {
            opposite = key.substr(0, key.size() - 1) + 'R';
        } else {
            opposite = key.substr(0, key.size() - 1) + 'L';
        }
        if (store.find(opposite) != store.end()) {
            pairs += min(val, store[opposite]);
        }
    }

    cout << pairs / 2 << endl; 

    return 0;
}