#include "InstantPurchase.h"

InstantPurchase::InstantPurchase(Vehicle& vehicle, double basePrice, double salesTaxRate)
	: Purchase(vehicle, basePrice), salesTaxRate(salesTaxRate) {};

double InstantPurchase::calculateTotalCost() const {
    return basePrice * (1.0 + salesTaxRate);
}
