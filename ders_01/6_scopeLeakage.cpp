// scope leakage is defining a variable/object in a larger scope than it is used

class Myclass {};

int main() {

	int i;
	for (i = 0; i < 10; i++) {
	//...
	}
	// if i is not going to be here it is scope leakage

	// object x is defined here, but will be used later down there after some other codes
	Myclass x; //  x will start using resources here
	//...
	//...
	//-- if you are going to use object x here, define here 
	//
	// also you need to delete object appropriately otherwise it will continue to use resources

	// in cpp initialize a variable when defining and define wherever it is first used
	int y;
	//..
	//..
	y = 10;		// define and init here like int y = 10;
}
