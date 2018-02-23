/*************************************************************************
* Title: Package Inheritance Hierarchy
* File: CIS278_Week14-12.12.cpp
* Author: James Eli
* Date: 2/7/2018
*
* Exercise 12.12 on page 574, Package Inheritance Hierarchy
* Use the Package inheritance hierarchy created in Exercise 11.9 to create 
* a program that displays the address information and calculates the 
* shipping costs for several packages. The program should contain a vector 
* of Package pointers to objects of classes TwoDayPackage and 
* OvernightPackage. Loop through the vector to process the Packages 
* polymorphically. For each Package, invoke get functions to obtain the 
* address information of the sender and the recipient, then print the two 
* addresses as they would appear on the mailing labels. Also, call each 
* Package’s calculateCost member function and print the result. Keep track 
* of the total shipping cost for all packages in the vector, and display 
* this total when the loop terminates.

* Notes:
*  (1) Compiled with MS Visual Studio 2017 Community (v141).
*
* Submitted in partial fulfillment of the requirements of PCC CIS-278.
*************************************************************************
* Change Log:
*   02/07/2018: Initial release. JME
*************************************************************************/
#include <iostream>
#include <string>  
#include <vector> 

// Package class hierarchy.
#include "package.h"
#include "twodaypackage.h"
#include "overnightpackage.h"

using namespace std;

int main()
{
	try
	{
		vector<Package*> pPackages;
		double totalShippingCost{ 0. };
		Address a("James Eli", "9999 Main St.", "Tucson", "AZ", 85740);
		Address b( "Bill Walker", "1120 East 35th Ave.", "Anchorage", "AK", 99508 );

		// Create packages of 3 different types and insert into vector.
		Package *p = new Package(a, b, 100);
		TwoDayPackage *tdp = new TwoDayPackage({ "Donald Trump", "1600 Pennsylvania Ave.", "Washington", "DC", 20500 }, a, 100, 9.99);
		OvernightPackage *onp = new OvernightPackage(b, { "Hillary Clinton", "20 West 45th Street", "New York", "NY", 10036 }, 100, 1.50);
		pPackages.push_back(p);
		pPackages.push_back((Package*)tdp);
		pPackages.push_back((Package*)onp);

		// Call packages polymorphically.
		for (auto p : pPackages)
		{
			cout << *p << endl;	//cout << (*p).toString() << endl;
			totalShippingCost += p->calculateCost();
		}

		// Display total cost.
		cout << "Total shipping cost is $" << totalShippingCost << endl;

		// Clean up.
		pPackages.clear();
		delete p, tdp, onp;
	}
	catch (const exception& e)
	{
		cout << "Oops! Exception: " << e.what() << endl;
	}

	return 0;
}
