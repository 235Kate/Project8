#include "CreditPurchase.h"

CreditPurchase::CreditPurchase(Vehicle& vehicle, double basePrice, double interestRate, int loanTermMonths)
	: Purchase(vehicle, basePrice), interestRate(interestRate), loanTermMonths(loanTermMonths) {};

double CreditPurchase::calculateTotalCost() const {
    // Simple calculation: Total Paid = Base Price + (Base Price * Interest Rate * Years)
    double totalInterest = basePrice * interestRate * (loanTermMonths / 12.0);
    return basePrice + totalInterest;
}

void CreditPurchase::displayPurchase() {
    cout << "Credit purchase.\n";
    Purchase::displayPurchase();
    cout << "Price: " << basePrice << "\n";
    cout << "Interest rate: " << interestRate << "\n";
    cout << "Loan term months: " << loanTermMonths << "\n";
}
