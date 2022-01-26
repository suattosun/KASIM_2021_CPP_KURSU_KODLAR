#ifndef CAR_H
#define CAR_H

#include <ostream>

/*
	note that in your derived class if you do not override any of the abstract base class's
	pure virtual functions, your derived class will be an abstract class too !!!
	hence your derived class is not going to be a concrete class, so you won't be able to
	instantiate it and trying to create an object from it (instantiation) will be syntax error
*/
/*
	even if you do not use virtual keyword in derived classes they are still virtual
	and 2. level derived classes can override that function, and they are virtual too
*/


// -------------------------------
class Car {
public:
	virtual void start() = 0;
	virtual void run() = 0;
	virtual void stop() = 0;
	virtual ~Car() = default;		// viortual dtor
};

// -------------------------------
class Bmw : public Car {
public:
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

class BmwCoupe : public Bmw {		// new 2nd level derived class
public:
	virtual void start()override;
	virtual void run()override;
	// virtual void stop()override;		// lets do not override stop() and see output
};

// -------------------------------
class Volvo : public Car {
public:
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
class Audi : public Car {
public:
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
class Mercedes : public Car {
public:
	virtual void start()override;
	virtual void run()override;
	virtual void stop()override;
};

// -------------------------------
Car* createRandomCar(void);

#endif