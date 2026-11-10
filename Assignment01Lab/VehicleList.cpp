#include "VehicleList.h"
#include <iostream>

VehicleList::VehicleList() : head(nullptr) {}
VehicleList::~VehicleList()
{
	Node* current = head;
	while (current != nullptr){
		Node* nextNode = current->next;
		delete current->vehicle;
		delete current;
		current = nextNode;
	}
}

bool VehicleList::AddVehicle(Vehicle* vehicle){

	if (vehicle == nullptr) {
		return false;
	}
	//Check for duplicate ID
	if (FindVehicle(vehicle->GetId()) != nullptr) {
		return false;
	}

	Node* newNode = new Node(vehicle);
	if (head == nullptr){
		head = newNode;
		return true;
	}
	else{
		Node* current = head;
		while (current->next != nullptr){
			current = current->next;
		}
		current->next = newNode;
	}

	return true;
}

bool VehicleList::RemoveVehicle(int id)
{
	if (head == nullptr){
		return false;
	}

	if (head->vehicle->GetId() == id){
		Node* temp = head;
		head = head->next;
		delete temp->vehicle;
		delete temp;
		return true;
	}

	Node* current = head;
	while (current->next != nullptr && current->next->vehicle->GetId() != id){
		current = current->next;
	}

	if (current->next == nullptr){
		return false;
	}

	Node* temp = current->next;
	current->next = current->next->next;
	delete temp->vehicle;
	delete temp;

	return true;
}

Vehicle* VehicleList::FindVehicle(int id) const
{
	Node* current = head;
	while (current != nullptr) {
		if (current->vehicle->GetId() == id) {
			return current->vehicle;
		}
		current = current->next;
	}
	return nullptr;
}

int VehicleList::GetNextID() const
{
	if (head == nullptr) {
		return 1;
	}

	Node* current = head;
	while (current->next != nullptr) {
		current = current->next;
	}

	return current->vehicle->GetId() + 1;
}

int VehicleList::Size() const
{
	int count = 0;
	Node* current = head;
	while (current != nullptr) {
		count++;
		current = current->next;
	}
	return count;
}

int VehicleList::CountType(const std::string& type) const
{
	int count = 0;
	Node* current = head;
	while (current != nullptr) {
		if (current->vehicle->GetType() == type) {
			count++;
		}
		current = current->next;
	}
	return count;
}

double VehicleList::TotalInventoryValue() const
{
	double totalValue = 0.0;
	Node* current = head;
	while (current != nullptr) {
		totalValue += current->vehicle->GetPrice();
		current = current->next;
	}
	return totalValue;
}

Vehicle* VehicleList::MostExpensiveVehicle() const
{
	if (head == nullptr) {
		return nullptr;
	}
	Vehicle* mostExpensive = head->vehicle;
	Node* current = head->next;
	while (current != nullptr) {
		if (current->vehicle->GetPrice() > mostExpensive->GetPrice()) {
			mostExpensive = current->vehicle;
		}
		current = current->next;
	}
	return mostExpensive;
}

void VehicleList::PrintAll() const{
	if (head == nullptr) {
		std::cout << "No vehicles in the list.\n";
		return;
	}

	Node* current = head;
	while (current != nullptr) {
		current->vehicle->PrintInfo();
		std::cout << "------------------------\n";
		current = current->next;
	}
}

void VehicleList::PrintByType(const std::string& type) const
{
	bool found = false;
	Node* current = head;
	while (current != nullptr) {
		if (current->vehicle->GetType() == type) {
			current->vehicle->PrintInfo();
			std::cout << "------------------------\n";
			found = true;
		}
		current = current->next;
	}
	if (!found) {
		std::cout << "No vehicles of type " << type << " found.\n";
	}
}