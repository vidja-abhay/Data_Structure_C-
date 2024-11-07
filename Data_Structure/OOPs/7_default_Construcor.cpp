// CPP code to demonstrate constructor can have default
// arguments
#include <iostream>
using namespace std;
class A {
public:
    int sum = 0;
    A(); // default constructor with no argument
    A(int a, int x = 0) // default constructor with one
                        // default argument
    {
        sum = a + x;
    }
    void print() { cout << "Sum =" << sum << endl; }
};
int main()
{
    // This construct has two arguments. Second argument is
    // initialized with a value of 0 Now we can call the
    // constructor in two possible ways.
    A obj1(10, 20);
    A obj2(5);
    obj1.print();
    obj2.print();
    return 0;
}
