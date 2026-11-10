#pragma once
#include "Vehicle.h"

class Node {
public:
	Vehicle* vehicle;
	Node* next;
	Node(Vehicle* vehicle) : vehicle(vehicle), next(nullptr) {}
};