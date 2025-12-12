#include "UserInterface.h"
#include <iostream>
#include <set>
#include <algorithm>
#include "InstantPurchase.h"
#include "CreditPurchase.h"
using namespace std;

void UserInterface::start() {
	vector<Vehicle> vehicles = Dealership::parseVehicles(Dealership::getVehicleData());
	set<string> uniqueCities;
	for (Vehicle vehicle : vehicles) {
		uniqueCities.insert(vehicle.city);
	}

	/*vector<Dealership> dealerships = vector<Dealership>();*/

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

	while (proceed) {
		displayMenu();

		// Use std::cin for simple input reading
		if (!(cin >> input)) {
			// Handle bad input (e.g., user enters text instead of number)
			cin.clear();
			cin.ignore(10000, '\n');
			input = static_cast<int>(MenuOption::Quit);
		}

		userChoice = getMenuOptionFromInt(input);

		switch (userChoice) {
		case MenuOption::ShowVehicles:
			displayInventoryForDealership();
			break;
		case MenuOption::AddVehicle:
			addVehicleForDealership();
			break;
		case MenuOption::SearchVehicle: {
			searchVehicleInDealership();
			break;
		}
		case MenuOption::DeleteVehicle: {
			deleteVehicleFromDealership();
			break;
		}
		case MenuOption::EditVehicle: {
			editVehicleColorInDealership();
			break;
		}
		case MenuOption::BuyVehicle: {
			break;
		}
		case MenuOption::Quit:
			proceed = false;
			break;
		}
	}
}

void UserInterface::displayMenu() {
	cout << "Menu:\n";
	cout << "1 - show vehicles\n";
	cout << "2 - add vehicle\n";
	cout << "3 - search vehicle\n";
	cout << "4 - delete vehicle\n";
	cout << "5 - edit vehicle\n";
	cout << "6 - buy a vehicle\n";
	cout << "7 - quit\n";
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
	Vehicle vehicle = Vehicle(vin, year, make, model, color, dealership.city, price);
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

void UserInterface::displayInventoryForDealership() {
	string city;
	cout << "Enter a city: ";
	cin >> city;
	for (Dealership dealership : dealerships) {
		if (dealership.city == city) {
			dealership.displayInventory();
			break;
		}
	}
}

void UserInterface::addVehicleForDealership() {
	string city;
	cout << "Enter a city: ";
	cin >> city;
	for (Dealership& dealership : dealerships) {
		if (dealership.city == city) {
			addVehicle(dealership);
			break;
		}
	}
}

void UserInterface::searchVehicleInDealership() {
	int vin;
	cout << "Enter the vin number: ";
	cin >> vin;
	bool found = false;
	for (Dealership& dealership : dealerships) {
		Vehicle* foundVehicle = dealership.searchVehicleByVin(vin);
		if (foundVehicle != nullptr) {
			foundVehicle->display();
			found = true;
		}
	}
	if (found == false) {
		cout << "Vehicle not found.";
	}
}

void UserInterface::deleteVehicleFromDealership() {
	int vin;
	cout << "Enter the vin number: ";
	cin >> vin;
	bool found = false;
	for (Dealership& dealership : dealerships) {
		Vehicle* foundVehicle = dealership.searchVehicleByVin(vin);
		if (foundVehicle != nullptr) {
			foundVehicle->display();
			found = true;
			dealership.deleteVehicleByVin(vin);
			break;
		}
	}
	if (found == false) {
		cout << "Vehicle not found.";
	}
}

void UserInterface::editVehicleColorInDealership() {
	int vin;
	cout << "Enter the vin number: ";
	cin >> vin;
	bool found = false;
	for (Dealership& dealership : dealerships) {
		Vehicle* foundVehicle = dealership.searchVehicleByVin(vin);
		if (foundVehicle != nullptr) {
			foundVehicle->display();
			found = true;
			string color;
			cout << "Enter the color: ";
			cin >> color;
			dealership.editVehicleColor(vin, color);
			break;
		}
	}
	if (found == false) {
		cout << "Vehicle not found.";
	}
}

void UserInterface::buyVehicle() {
	int vin;
	cout << "Enter the vin number: ";
	cin >> vin;
	int userChoice;
	cout << "Enter 1 for an instant purchase.\n";
	cout << "Enter 2 for a credit purchase.\n";
	cin >> userChoice;
	bool found = false;
	for (Dealership& dealership : dealerships) {
		Vehicle* foundVehicle = dealership.searchVehicleByVin(vin);
		if (foundVehicle != nullptr) {
			foundVehicle->display();
			if (userChoice == 1) {
				unique_ptr<Purchase> new_record = make_unique<InstantPurchase>(*foundVehicle, foundVehicle->price, 0.02);
				sales_records.push_back(move(new_record));
			}
			found = true;
		}
	}
	if (found == false) {
		cout << "Vehicle not found.";
	}

}