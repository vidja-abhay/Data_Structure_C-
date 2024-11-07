// C++ program to demonstrate the number of times
// constructor and destructors are called

#include <iostream>
using namespace std;
// It is static so that every class object has the same
// value
static int Count = 0;
class Test {
public:
    // User-Defined Constructor
    Test()
    {

        // Number of times constructor is called
        Count++;
        cout << "No. of Object created: " << Count << endl;
    }

    // User-Defined Destructor
    ~Test()
    {
        // It will print count in decending order
        cout << "No. of Object destroyed: " << Count
             << endl;
        Count--;
        // Number of times destructor is called
    }
};

// driver code
int main()
{
    Test t, t1, t2, t3;

    return 0;
}


// No. of Object created: 1
// No. of Object created: 2
// No. of Object created: 3
// No. of Object created: 4
// No. of Object destroyed: 4
// No. of Object destroyed: 3
// No. of Object destroyed: 2
// No. of Object destroyed: 1

// Objects are destroyed in the reverse order of their creation. In this case, t3 is the first to be destroyed, while t is the last.