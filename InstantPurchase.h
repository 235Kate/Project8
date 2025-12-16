#ifndef InstantPurchase_h
#define InstantPurchase_h
#include "Purchase.h"
class InstantPurchase:public Purchase
{
public:
	double salesTaxRate;
	InstantPurchase(Vehicle& vehicle, double basePrice, double salesTaxRate);
	double calculateTotalCost() const override;
	void displayPurchase() override;
};
#endif
