/*
* Base - class Package should include data members representing the name,
* address, city, state and ZIP code for both the sender and the recipient
* of the package, in addition to data members that store the weight(in
* ounces) and cost per ounce to ship the package. Package’s constructor
* should initialize these data members. Ensure that the weight and cost per
* ounce contain positive values. Package should provide a public member
* function calculateCost that returns a double indicating the cost associated
* with shipping the package. Package’s calculateCost function should
* determine the cost by multiplying the weight by the cost per ounce.
*/
#ifndef _PACKAGE_CLASS_
#define _PACKAGE_CLASS_

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include "address.h"

// Default cost per ounce to ship package.
static const double defaultCostPerOunce{ 0.15 };

// Define base Package class data and methods.
class Package
{
private:
	Address senderAddr, recipientAddr;
	unsigned weight;
	double costPerOunce{ defaultCostPerOunce };

protected:
	// Format and return base class output.
	std::string baseString()
	{
		std::stringstream stream;

		stream << std::left << "Sender:\n" << senderAddr
			   << "Recipient:\n" << recipientAddr
			   << "Cost to send " << weight << "oz. ";
		return stream.str();
	}

public:
	// Constructor.
	Package(Address s, Address r, unsigned w) : senderAddr{ s }, recipientAddr{ r } { setWeight(w); }

	// Setters and getters.
	void setSenderAddr(Address a) { senderAddr = a; }
	Address getSenderAddr() const { return senderAddr; };

	void setRecipientAddr(Address a) { recipientAddr = a; }
	Address getRecipientAddr() const { return recipientAddr; }

	void setWeight(unsigned w)
	{
		if (w > 0.)
			weight = w;
		else
			throw std::invalid_argument("package weight must be positive");
	}
	unsigned getWeight() const { return weight; }

	void setCostPerOunce(double cpo)
	{
		if (cpo > 0.)
			costPerOunce = cpo;
		else
			throw std::invalid_argument("cost per ounce must be positive");
	}
	double getCostPerOunce() const { return costPerOunce; };

	// Calcualte shipping cost.
	virtual double calculateCost() const { return weight * costPerOunce; }

	// Create string for output.
	virtual std::string toString()
	{
		std::stringstream stream;

		// Add base class stuff to class specific output.
		stream << "(regular delivery) is $" << std::fixed << std::setprecision(2) << calculateCost() << std::endl;
		return baseString() + stream.str();
	}

	// Stream output.
	friend std::ostream& operator<< (std::ostream& os, Package& p)
	{
		// Retrieve output string and stream it.
		return os << p.toString();
	}

};

#endif