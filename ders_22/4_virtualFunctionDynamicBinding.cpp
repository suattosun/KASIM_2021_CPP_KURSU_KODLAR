#include <iostream>

using namespace std;

// change eat() function to virtual and see the result
class Animal {
public:
	// virtual void eat() {
	void eat() {
			cout << "animal is eating" << "\n";
	}
};

class Cat : public Animal {
public:
	void eat() {
		cout << "cat is eating" << "\n";
	}
};

class Dog : public Animal {
public:
	void eat() {
		cout << "dog is eating" << "\n";
	}
};

class Tiger : public Animal {
public:
	void eat() {
		cout << "tiger is eating" << "\n";
	}
};

void animal_game(Animal& ra) {
	// when the function is virtual the binding here is done during runtime which is called dynamic binding 
	// when the function is not virtual, binding is done during runtime which is called static binding
	ra.eat();
}

int main() {
	Cat mycat;
	Dog mydog;
	Tiger mytiger;

	animal_game(mycat);
	animal_game(mydog);
	animal_game(mytiger);
}