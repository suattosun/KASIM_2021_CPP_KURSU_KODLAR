#include "car.h"

void car_game(Car& car) {
	car.start();
	car.run();
	car.stop();
}


int main() {
	for (int i = 0; i < 100; i++)
	{
		Car* ptr = createRandomCar();
		car_game(*ptr);
		(void) getchar();
		delete(ptr);
	}
}