#include "Product.h"
#include <iostream>
using namespace std;

Product::Product(double price) : price(price) {}
void Product::displayProduct() {
	cout << "Price: " << price;
}
