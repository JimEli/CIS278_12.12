/*************************************************************************
* Title: Package Inheritance Hierarchy
* File: CIS278_Week13-11.9.cpp
* Author: James Eli
* Date: 2/19/2018
*
* Exercise 11.9 on page 529, Package Inheritance Hierarchy
* Package-delivery services, such as FedEx, DHL and UPS, offer a number of 
* different shipping options, each with specific costs associated. Create 
* an inheritance hierarchy to represent various types of packages. Use class 
* Package as the base class of the hierarchy, then include classes 
* TwoDayPackage and OvernightPackage that derive from Package.
*
* Base-class Package should include data members representing the name, 
* address, city, state and ZIP code for both the sender and the recipient 
* of the package, in addition to data members that store the weight (in 
* ounces) and cost per ounce to ship the package. Package’s constructor 
* should initialize these data members. Ensure that the weight and cost per 
* ounce contain positive values. Package should provide a public member 
* function calculateCost that returns a double indicating the cost associated 
* with shipping the package. Package’s calculateCost function should 
* determine the cost by multiplying the weight by the cost per ounce.
*
* Derived-class TwoDayPackage should inherit the functionality of base-class 
* Package, but also include a data member that represents a flat fee that the 
* shipping company charges for two-day-delivery service. TwoDayPAckage’s 
* constructor should receive a value to initialize this data member. 
*
* TwoDayPackage should redefine member function calculateCost so that it 
* computes the shipping cost by adding the flat fee to the weight-based cost 
* calculated by base-class Package’s calculateCost function.
*
* Class OvernightPackage should inherit directly from class Package and contain 
* an additional data member representing an additional fee per ounce charged 
* for overnight-delivery service. OvernightPackage should redefine member 
* function calculateCost so that it adds the additional fee per ounce to the 
* standard cost per ounce before calculating the shipping cost. 
* 
* Write a test program that creates objects of each type of Package and tests 
* member function calculateCost.
* 
* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   02/19/2018: Initial release. JME
*************************************************************************/
#include <iostream> // cout/endl
#include <string> 

// Package class hierarchy.
#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"

using namespace std;

int main()
{
	try
	{
		// Create a few addresses.
		Address a("James Eli", "9999 Main St.", "Tucson", "AZ", 85740);
		Address b("Bill Walker", "1120 East 35th Ave.", "Anchorage", "AK", 99508);

		// Create packages of each type and display via different methods.
		Package p(a, b, 100);
		cout << p << endl;

		TwoDayPackage tdp({ "Donald Trump", "1600 Pennsylvania Ave.", "Washington", "DC", 20500 }, a, 100, 9.99);
		cout << tdp.toString() << endl;

		OvernightPackage onp(b, { "Hillary Clinton", "20 West 45th Street", "New York", "NY", 10036 }, 100, 1.50);
		cout << "Sender:\n" << onp.getSenderAddr();
		cout << "Recipient:\n" << onp.getRecipientAddr();
		cout << "Cost to send " << onp.getWeight() << "oz. "; 
		cout << "(overnight delivery) is $" << std::fixed << std::setprecision(2) << onp.calculateCost() << endl;
	}
	catch (const exception& e)
	{
		cout << "Oops! Exception: " << e.what() << endl;
	}
	return 0;
}