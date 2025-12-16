#include "InstantPurchase.h"

InstantPurchase::InstantPurchase(Vehicle& vehicle, double basePrice, double salesTaxRate)
	: Purchase(vehicle, basePrice), salesTaxRate(salesTaxRate) {};

double InstantPurchase::calculateTotalCost() const {
    return basePrice * (1.0 + salesTaxRate);
}

void InstantPurchase::displayPurchase() {
	cout << "Instant purchase.\n";
	Purchase::displayPurchase();
	cout << "Price: " << basePrice << "\n";
	cout << "Sales tax rate: " << salesTaxRate << "\n";
	cout << "Total cost: " << calculateTotalCost() << "\n";
}
