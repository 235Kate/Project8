#ifndef Dealership_hpp
#define Dealership_hpp
#include <vector>
#include "Vehicle.h"

class Dealership {
public:
	vector<Vehicle> inventory;

	Dealership(const vector<Vehicle>& vehicles, const string& city);
	Dealership();
	void displayInventory();
	void addVehicle(Vehicle& vehicle);
	Vehicle* searchVehicleByVin(int vin);
	void deleteVehicleByVin(int vin);
	Vehicle& editVehicleColor(int vin, string color);
	string city;
	static vector<Vehicle> parseVehicles(const string& csvData);
	static const string getVehicleData() {
		return "vin | year | make | model | color | city | price\n"
			"1 | 2015 | Toyota | Corolla | white | New York | 10000 \n"
			"2 | 2020 | Volkswagen | Polo | red | Kyiv | 20000\n"
			// Example of a line with incorrect format for error handling:
			"3 | 2022 | Ford | Fiesta | blue | Berlin | 15000\n"
			"4 | 2020 | Volkswagen | Polo | black | Kyiv | 20000\n"
			"5 | 2019 | Volkswagen | Polo | red | New York | 10000\n";
	}

private:
	static string trim(const string& str);
};

#endif




