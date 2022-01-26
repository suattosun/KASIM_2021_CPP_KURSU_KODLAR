/*
	class types: concrete classes (can be instantiated), abstract classes (cannot be instantiated)
	concrete class provides interface + implementation:
		has only normal functions, static binding
		if the derived classes are going to have the same functionality, base class provides
			a specific interface and implementation to the derived classes
	polymorphic class (still concrete) provides interface + default implementation:
		(can be overridded): has at least one virtual function, dynamic binding (runtime or late binding)
		if functionality may change, base class provides an interface and default implementation to the
			derived classes which they can override
		note that all classes derived from a polymorphic class are going to be polymorphic classes !!!
	abstract class provides only interface: (note abstract is not a keyword in cpp)
		has at least one pure virtual function
		you cannot instantiate an abstract class
		if functionality must be overridden by derived classes, base class only provides an interface

*/


class Airplane {
public:
	// normal function: should not be changed by derived classes
	int fly();

	// virtual function: can be overriden by derived classes
	virtual void takeoff();

	// pure virtual function: MUST be overriden by derived classes
	// note if you do not override then your derived class will be an abstract class too !!!
	virtual void land() = 0;
};

class Boeing : public Airplane {

};