#include <iostream>

/*
	virtual dispatch mechanism still works for base class's non-virtual function
*/

using namespace std;
class Car {
public:
	virtual void run() {
		cout << "Car is running \n";
	}
	void get_maintenance() {
		run();		// here for this function virtual dispatch mechanism still works
					// calling object's this will be passed to get_maintenance(), and this->run();
	}
};

class Skoda : public Car {
};

int main() {
	Skoda s;
	s.get_maintenance();
}

