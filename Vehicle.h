#include <iostream>
using namespace std;
class Vehicle
{
public:
	int vin;
	int year;
	string make;
	string model;
	string color;
	int price;
	string city;

	Vehicle(int aVin, int aYear, string& aMake, string& aModel, string& aColor, string city, int price);

	void display();
};

