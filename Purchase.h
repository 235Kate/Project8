#ifndef Purchase_h
#define Purchase_h
#include "Vehicle.h"
class Purchase
{
public:
	Vehicle vehicle;
	double basePrice;
	Purchase(Vehicle& vehicle, double basePrice);

	// Virtual destructor is crucial for proper cleanup when deleting derived class objects
	// through a base class pointer.
	virtual ~Purchase() = default;
	virtual double calculateTotalCost() const = 0;

	virtual void displayPurchase();
};
#endif
