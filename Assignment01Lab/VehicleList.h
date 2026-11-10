#pragma once

#include <string>
#include "Node.h"

class VehicleList {
private:
	Node* head;
public:
	VehicleList();
	~VehicleList();

	bool AddVehicle(Vehicle* vehicle);
	bool RemoveVehicle(int id);
	Vehicle* FindVehicle(int id) const;
	int GetNextID() const;

	int Size() const;
	int CountType(const std::string& type) const;
	double TotalInventoryValue() const;
	Vehicle* MostExpensiveVehicle() const;

	void PrintAll() const;
	void PrintByType(const std::string& type) const;

};