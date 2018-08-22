#include "CarTests.h"

CarTests::CarTests()
{
	carTests();
}

void CarTests::carTests()
{
	Car car{ "vhigh", "vhigh", "2", "2", "small", "low", "unacc" };
	assert(car.carProperty[0] == 1);
	assert(car.carProperty[1] == 1);
	assert(car.carProperty[2] == 1);
	assert(car.carProperty[3] == 1);
	assert(car.carProperty[4] == 1);
	assert(car.carProperty[5] == 1);
	assert(car.carProperty[6] == 1);
}
