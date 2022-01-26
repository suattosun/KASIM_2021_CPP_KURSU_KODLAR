/*
	lets pretend that you have a car game and you need a new car must acommpany to the car already
		created. how can you do that?
		note this will run 5 years later even with addition of new brands added...
	you can do it by virtual constructor like following clone()
		you have to implement clone() in your newly added classes too
*/

class Car {
public:
	virtual Car* clone() = 0; 
};
class Audi : public Car {
public:
	virtual Car* clone() {
		return new Audi;
	}
};
void car_game(Car& car) {
	// you need to do it dynamically here
	Car* p = car.clone();
}
