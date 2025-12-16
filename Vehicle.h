#ifndef Vehicle_h
#define Vehicle_h
#include <iostream>
#include "Product.h"
using namespace std;
class Vehicle : public Product
{
public:
	int vin;
	int year;
	string make;
	string model;
	string color;
	double price;
	string city;

	Vehicle(int aVin, int aYear, string& aMake, string& aModel, string& aColor, string city, double price);

	void display();
};
#endif