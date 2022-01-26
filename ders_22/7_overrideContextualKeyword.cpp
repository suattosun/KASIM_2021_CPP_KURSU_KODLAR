
/*
	override is a contextual keyword like final
	contextual keyword is a keyword which can have special meaing for special usages
		previous usages will still be valid, but for a speacial usage it will have a new meaning
*/
/* override keyword is added to the language to prevent :
	unintended mistakes while trying to override a virtual function, gives errors
	trying to override a non - virtual function, virtual dispatch mechanism is processed with override keyword
	interface change erorrs
		class Car { public: virtual void run(); };
		if interface is changed to run(double); it is compile error if override is used in derived classes
*/
class Base {
public:
	virtual void func(int, int);
};

class Der : public Base {
public:
	void func(int, int)override;  // to emphasize that we are intending to override a function
	
	// override can be a function name or a variable name as well
	int override = 5;
	int override();
};