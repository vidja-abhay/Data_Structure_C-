#include <iostream>
using namespace std;

class Shallow {

    

public:
int* data;
    // Constructor to initialize the object
    Shallow(int value) {
        data = new int;   // dynamically allocate memory
        *data = value;    // assign value
        cout << "Constructor: Allocated memory and set value to " << *data << endl;
    }

    // Shallow Copy Constructor
    Shallow(Shallow& source) {
        // Copy the pointer, not the actual data
        data = source.data;
        cout << "Shallow copy constructor: Copied the pointer, data points to " << *data << endl;
    }

    // Destructor to free memory
    ~Shallow() {
        delete data;   // Free allocated memory
        cout << "Destructor: Freed memory!" << endl;
    }

    // Function to display the value
    void display() const {
        cout << "Value: " << *data << endl;
    }
};

int main() {
    Shallow obj1(10);    // Create first object
    obj1.display();

    Shallow obj2 = obj1; // Shallow copy of obj1
    obj2.display();
    
    *obj2.data = 5;
    
    obj1.display();
    
    obj2.display();
    
    

    return 0;
}
