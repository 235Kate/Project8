#ifndef UserInterface_h
#define UserInterface_h
#include "MenuOption.h"
#include "Dealership.h"
#include "Purchase.h"

class UserInterface {
public:
	void start();
private:
	void displayMenu();
	MenuOption getMenuOptionFromInt(int choice);
	void addVehicle(Dealership& dealership);
	Vehicle getVehicle();
	void displayInventoryForDealership();
	vector<Dealership> dealerships;

	// We can store pointers to the derived classes in a vector of base class pointers.
	// std::unique_ptr is used for automatic memory management.

	vector<unique_ptr<Purchase>> salesRecords;

	void addVehicleForDealership(); 
	void searchVehicleInDealership();
	void deleteVehicleFromDealership();
	void editVehicleColorInDealership();
	void buyVehicle();
	void displaySales();
};
#endif

