// CPP program to illustrate
// Private Destructor
#include <iostream>

// A class with private destructor
class Test {
private:
	~Test() {}

public:
    // approch 1
	friend void destructTest(Test*);
    // approch 2
    void destruct() { delete this; }
};

// Only this function can destruct objects of Test
void destructTest(Test* ptr) { delete ptr; }

int main()
{
	// create an object
	Test* ptr = new Test;

	// destruct the object
	destructTest(ptr);

	return 0;
}
