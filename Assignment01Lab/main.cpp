#include <iostream>
#include <string>

int main() {
	int choice = 0;

	while (choice != 4) {
		std::cout << "1. Add vehicle" << std::endl;
		std::cout << "2. Remove vehicle by ID" << std::endl;
		std::cout << "3. Update vehicle by ID" << std::endl;
		std::cout << "4. Find vehicle by ID" << std::endl;
		std::cout << "5. Display all vehicles" << std::endl;
		std::cout << "6. Display store statistics" << std::endl;
		std::cout << "7. Exit" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice) {
		case 1:
			//do something
			break;
		case 2:
			//do something
			break;
		case 3:
			//do something
			break;
		case 4:
			//do something
			break;
		case 5:
			//do something
			break;
		case 6:
			//do something
			break;
		case 7:
			std::cout << "Exiting the program." << std::endl;
			break;
		default:
			std::cout << "Invalid choice. Please try again." << std::endl;
		}
	}
}