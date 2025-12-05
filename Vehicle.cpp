#include "Vehicle.h"
#include <iostream>
using namespace std;

Vehicle::Vehicle(int aVin, int aYear, string& aMake, string& aModel, string& aColor, string aCity, int aPrice)
	:vin(aVin), year(aYear), make(aMake), model(aModel), color(aColor), city(aCity), price(aPrice)  {}

void Vehicle::display() {
	cout << "\n";
	cout << "Vin: " << vin << endl;
	cout << "Year: " << year << endl;
	cout << "Make: " << make << endl;
	cout << "Model: " << model << endl;
	cout << "Color: " << color << endl;
	cout << "Price: " << price << endl;
	cout << "City: " << city << endl;
	cout << "\n";
}


