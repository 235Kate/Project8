//
//  Dealership.cpp
//  Pet2
//
//  Created by Olga Goncharuk on 04.11.2025.
//

#include "Dealership.h"
#include <string>
#include <sstream>
#include <algorithm>
#include <stdexcept>

using namespace std;

Dealership::Dealership(const vector<Vehicle>& vehicles, const string& city) : inventory(vehicles), city(city) {}

Dealership::Dealership() {
    cout << "\n--- Dealership Created ---\n";
    cout << "with vehicles created: " << inventory.size() << "\n\n";
    inventory = vector<Vehicle>();
}

void Dealership::displayInventory() {
    for (size_t i = 0; i < inventory.size(); ++i) {
        cout << "Vehicle " << i + 1 << ":";
        inventory[i].display();
        cout << "\n";
    }
}
vector<Vehicle> Dealership::parseVehicles(const string& csvData) {
    vector<Vehicle> vehicles;
    stringstream ss(csvData);
    string line;

    // Read the header line first and ignore it
    if (!getline(ss, line)) {
        cout << "Error: CSV data is empty." << std::endl;
        return vehicles;
    }
    cout << "Header Skipped: " << line << std::endl;

    // Process data lines
    while (getline(ss, line)) {
        if (line.empty()) continue; // Skip empty lines

        stringstream lineStream(line);
        string cell;
        vector<string> cells;

        // Split the line by the '|' delimiter
        while (getline(lineStream, cell, '|')) {
            cells.push_back(trim(cell)); // Trim whitespace from each cell
        }

        if (cells.size() != 7) {
            cerr << "Skipping malformed line (expected 7 columns, got " << cells.size() << "): " << line << endl;
            continue;
        }

        try {
            // Attempt to convert the necessary strings to numbers
            int vin = std::stoi(cells[0]);
            int year = std::stoi(cells[1]);
            string make = cells[2];
            string model = cells[3];
            string color = cells[4];
            string city = cells[5];
            int price = stoi(cells[6]);

            // Create and store the new Vehicle object
            vehicles.emplace_back(vin, year, make, model, color, city, price);
            cout << "Successfully parsed and created vehicle." << endl;

        }
        catch (const invalid_argument& e) {
            cerr << "Parsing error: Invalid number format in line: " << line << endl;
        }
        catch (const std::out_of_range& e) {
            cerr << "Parsing error: Number out of range in line: " << line << endl;
        }
        catch (const std::exception& e) {
            cerr << "An unexpected error occurred: " << e.what() << endl;
        }
    }

    return vehicles;
}

// Helper function to remove leading/trailing whitespace from a string
string Dealership::trim(const string& str) {
    // Find the first non-space character
    size_t first = str.find_first_not_of(" \t\n\r");
    if (string::npos == first) {
        return str; // String is all whitespace
    }
    // Find the last non-space character
    size_t last = str.find_last_not_of(" \t\n\r");
    // Return the trimmed substring
    return str.substr(first, (last - first + 1));
}

void Dealership::addVehicle(Vehicle& vehicle) {
    inventory.push_back(vehicle);
}

Vehicle* Dealership::searchVehicleByVin(int vin) {
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].vin == vin) {
            return &inventory[i];
        }
    }
    return nullptr;
}

void Dealership::deleteVehicleByVin(int vin) {
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].vin == vin) {
            // 2. Calculate the iterator: begin() + index
            auto iterator_to_delete = inventory.begin() + i;
            inventory.erase(iterator_to_delete);
        }
    }
}

Vehicle& Dealership::editVehicleColor(int vin, string color) {
    for (size_t i = 0; i < inventory.size(); ++i) {
        if (inventory[i].vin == vin) {
            inventory[i].color = color;
            return inventory[i];
        }
    }
}