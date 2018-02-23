/*
* Derived-class TwoDayPackage should inherit the functionality of base-class
* Package, but also include a data member that represents a flat fee that the
* shipping company charges for two-day-delivery service. TwoDayPAckage’s
* constructor should receive a value to initialize this data member.
* TwoDayPackage should redefine member function calculateCost so that it
* computes the shipping cost by adding the flat fee to the weight-based cost
* calculated by base-class Package’s calculateCost function.
*/
#ifndef _TWO_DAY_PACKAGE_CLASS_
#define _TWO_DAY_PACKAGE_CLASS_

#include "package.h"

// Default add'l fee to ship 2-day package.
static const double defaultTwoDayFee{ 5.50 };

// Create derived TwoDayPackage class inherit from base class Package.
class TwoDayPackage : Package
{
private:
	double twoDayFee{ defaultTwoDayFee };

public:
	// Constructor.
	TwoDayPackage(Address s, Address r, unsigned w, double f) : twoDayFee{ f }, Package(s, r, w) { }

	// Class specific setter and getter.
	void setTwoDayFee(double f)
	{
		if (f > 0.)
			twoDayFee = f;
		else
			throw std::invalid_argument("two day fee must be positive");
	}
	double getTwoDayFee() const { return twoDayFee; };

	// Overload base class member function.
	double calculateCost() const { return twoDayFee + (Package::getWeight() * Package::getCostPerOunce()); }

	// Overload toString method.
	std::string toString()
	{
		std::stringstream stream;

		// Combine base class stuff with twoDayPackage output.
		stream << "(2-day delivery) is $" << std::fixed << std::setprecision(2) << calculateCost() << std::endl;
		return baseString() + stream.str();
	}

};

#endif
