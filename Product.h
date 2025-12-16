#pragma once
class Product
{
public:
	double price;
	Product(double price);
	virtual ~Product() = default;
	virtual void displayProduct();
	virtual void thisFunction() const = 0;
};

