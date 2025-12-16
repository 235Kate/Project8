#ifndef CreditPurchase_h
#define CreditPurchase_h
#include "Purchase.h"
class CreditPurchase:public Purchase
{
public:
	double interestRate;
	int loanTermMonths;
	CreditPurchase(Vehicle& vehicle, double basePrice, double interestRate, int loanTermMonths);
	double calculateTotalCost() const override;
	void displayPurchase() override;
};
#endif
