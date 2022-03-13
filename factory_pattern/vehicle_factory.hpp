#ifndef vehicle_factory_hpp
#define vehicle_factory_hpp

#include <bits/stdc++.h>
#include "car.hpp"
#include "bike.hpp"
using namespace std;

class VehicleFactory{
public:
	static Vehicle* getVehicle(string vehicleType);
};

#endif