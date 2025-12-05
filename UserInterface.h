#include "MenuOption.h"
#include "Dealership.h"

class UserInterface {
public:
	void start();
private:
	void displayMenu();
	MenuOption getMenuOptionFromInt(int choice);
	void addVehicle(Dealership& dealership);
	Vehicle getVehicle();
};

