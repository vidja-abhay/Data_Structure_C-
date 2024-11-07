#include <iostream>
using namespace std;

class Deep {

    

public:
int* data;
    // Constructor
    Deep(int value) {
        data = new int;   // allocate memory on the heap
        *data = value;    // assign value
    }

    // Deep Copy Constructor
    Deep(const Deep& source) {
        data = new int;           // allocate new memory
        *data = *(source.data);   // copy the actual value
        cout << "Deep copy constructor called!" << endl;
    }

    // Destructor
    ~Deep() {
        delete data;  // free allocated memory
        cout << "Destructor freeing data!" << endl;
    }

    // Display the value
    void display() const {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    Deep obj1(10);
    obj1.display();

    // Deep copy
    Deep obj2 = obj1;  // This is a deep copy
    obj2.display();

    // Changing obj2 will NOT affect obj1 since they have separate memory
    *obj2.data = 20;  // Safe: modifying obj2 does not modify obj1

    return 0;
}
