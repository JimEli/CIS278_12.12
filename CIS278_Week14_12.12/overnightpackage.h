/*
* Class OvernightPackage should inherit directly from class Package and contain
* an additional data member representing an additional fee per ounce charged
* for overnight-delivery service. OvernightPackage should redefine member
* function calculateCost so that it adds the additional fee per ounce to the
* standard cost per ounce before calculating the shipping cost.
*/
#ifndef _OVERNIGHT_PACKAGE_CLASS_
#define _OVERNIGHT_PACKAGE_CLASS_

#include "package.h"

static const double defaultOvernightAddlCostPerOunce{ 0. };

// Create derived OvernightPackage class inherit from base class Package.
class OvernightPackage : Package
{
private:
	double overnightAddlCostPerOunce{ defaultOvernightAddlCostPerOunce };

public:
	// Constructor.
	OvernightPackage(Address s, Address r, unsigned w, double f) : overnightAddlCostPerOunce{ f }, Package(s, r, w) { }

	// Class specific setter and getter.
	void setOvernightAddlCostPerOunce(double f)
	{
		if (f > 0.)
			overnightAddlCostPerOunce = f;
		else
			throw std::invalid_argument("overnight fee must be positive");
	}
	double getOvernightAddlCostPerOunce() const { return overnightAddlCostPerOunce; };

	// Overload base class member function.
	double calculateCost() const { return Package::getWeight() * (Package::getCostPerOunce() + overnightAddlCostPerOunce); }

	// Overload toString method.
	std::string toString()
	{
		std::stringstream stream;

		// Combine base class stuff with overnightPackage output.
		stream << "(overnight delivery) is $" << std::fixed << std::setprecision(2) << calculateCost() << std::endl;
		return baseString() + stream.str();
	}

};

#endif
