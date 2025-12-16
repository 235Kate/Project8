#include "Purchase.h"

Purchase::Purchase(Vehicle& vehicle, double basePrice)
	:vehicle(vehicle), basePrice(basePrice) {
}

void Purchase::displayPurchase() {
	vehicle.display();
}