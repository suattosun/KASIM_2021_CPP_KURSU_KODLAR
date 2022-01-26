#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

// this is the proof of the dynamic binding of the virtual function call

// change eat() function to virtual and see the result
class Animal {
public:
	virtual void eat() {
	// void eat() {
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

Animal* create_animal() {
	switch(rand() % 3) {
	case 0: cout << "case Cat : \n"; return new Cat;
	case 1: cout << "case Dog : \n";  return new Dog;
	case 2: cout << "case Tiger : \n";  return new Tiger;
	}
}

int main() {
	srand(static_cast<unsigned>(time(nullptr)));
	for (int i = 0; i < 100; i++) {
		animal_game(*create_animal());
		getchar();
	}

}