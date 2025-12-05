#include "UserInterface.h"
#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

void UserInterface::start() {
	vector<Vehicle> vehicles = Dealership::parseVehicles(Dealership::getVehicleData());
	set<string> uniqueCities;
	for (Vehicle vehicle : vehicles) {
		uniqueCities.insert(vehicle.city);
	}

	vector<Dealership> dealerships = vector<Dealership>();

	for (const string& city : uniqueCities) {
		vector<Vehicle> dealershipVehicles;
		auto isInTargetCity = [&city](const Vehicle& v) {
			return v.city == city;
			};
	
		copy_if(vehicles.begin(), vehicles.end(), back_inserter(dealershipVehicles), isInTargetCity);
		dealerships.push_back(Dealership(dealershipVehicles, city));
	}



	/*Dealership dealership = Dealership();*/
	MenuOption userChoice = MenuOption::ShowVehicles;
	bool proceed = true;
	int input;

	for (Dealership dealership : dealerships) {
		cout << dealership.city << "\n";
		dealership.displayInventory();
	}

	//while (proceed) {
	//	displayMenu();

	//	// Use std::cin for simple input reading
	//	if (!(cin >> input)) {
	//		// Handle bad input (e.g., user enters text instead of number)
	//		cin.clear();
	//		cin.ignore(10000, '\n');
	//		input = static_cast<int>(MenuOption::Quit);
	//	}

	//	userChoice = getMenuOptionFromInt(input);

	//	switch (userChoice) {
	//	case MenuOption::ShowVehicles:
	//		dealership.displayInventory();
	//		break;
	//	case MenuOption::AddVehicle:
	//		addVehicle(dealership);
	//		break;
	//	case MenuOption::SearchVehicle: {
	//		int vin;
	//		cout << "Enter the vin number: ";
	//		cin >> vin;
	//		Vehicle foundVehicle = dealership.searchVehicleByVin(vin);
	//		foundVehicle.display();
	//		break;
	//	}
	//	case MenuOption::DeleteVehicle: {
	//		int vin;
	//		cout << "Enter the vin number: ";
	//		cin >> vin;
	//		dealership.deleteVehicleByVin(vin);
	//		break;
	//	}
	//	case MenuOption::EditVehicle: {
	//		int vin;
	//		cout << "Enter the vin number: ";
	//		cin >> vin;
	//		string color;
	//		cout << "Enter the new color: ";
	//		cin >> color;
	//		Vehicle editedVehicle = dealership.editVehicleColor(vin, color);
	//		editedVehicle.display();
	//		break;
	//	}
	//	case MenuOption::Quit:
	//		proceed = false;
	//		break;
	//	}
	//}
}

void UserInterface::displayMenu() {
	cout << "Menu:\n";
	cout << "1 - show vehicles\n";
	cout << "2 - add vehicle\n";
	cout << "3 - search vehicle\n";
	cout << "4 - delete vehicle\n";
	cout << "5 - edit vehicle\n";
	cout << "6 - quit\n";
	cout << "Please enter your choice: ";
}

MenuOption UserInterface::getMenuOptionFromInt(int choice) {
	if (choice >= static_cast<int>(MenuOption::ShowVehicles) &&
		choice <= static_cast<int>(MenuOption::Quit)) {

		// Cast the integer safely to the enum class type
		return static_cast<MenuOption>(choice);
	}
	// Default to Quit for any invalid input outside the range
	return MenuOption::Quit;
}

void UserInterface::addVehicle(Dealership& dealership) {
	int vin;
	int year;
	string make;
	string model;
	string color;
	int price;
	string city;
	cout << "Enter the vin number: ";
	cin >> vin;
	cout << "Enter the year: ";
	cin >> year;
	cout << "Enter the make: ";
	cin >> make;
	cout << "Enter the model: ";
	cin >> model;
	cout << "Enter the color: ";
	cin >> color;
	cout << "Enter the price: ";
	cin >> price;
	cout << "Enter the city: ";
	Vehicle vehicle = Vehicle(vin, year, make, model, color, city, price);
	dealership.addVehicle(vehicle);
}

Vehicle UserInterface::getVehicle() {
	int vin;
	int year;
	string make;
	string model;
	string color;
	int price;
	string city;
	cout << "Enter the vin number:";
	cin >> vin;
	cout << "Enter the year:";
	cin >> year;
	cout << "Enter the make:";
	cin >> make;
	cout << "Enter the model:";
	cin >> model;
	cout << "Enter the color: ";
	cin >> color;
	cout << "Enter the price: ";
	cin >> price;
	cout << "Enter the city: ";
	cin >> city;
	Vehicle vehicle = Vehicle(vin, year, make, model, color, city, price);
	return vehicle;
}

//void UserInterface::
