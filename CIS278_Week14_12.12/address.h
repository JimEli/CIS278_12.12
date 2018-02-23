#ifndef _ADDRESS_CLASS_
#define _ADDRESS_CLASS_

// An address class.
struct Address {
	// Constructor.
	Address(std::string n, std::string a, std::string c, std::string s, unsigned z) :
		name{ n }, address{ a }, city{ c }, state{ s }, zipCode{ z } { }

	// Print formatted address information. 
	friend std::ostream& operator<< (std::ostream& os, const Address& addr)
	{
		return os << " " << addr.name << "\n " << addr.address << "\n " << addr.city << ", " << addr.state
				  << "  " << std::setw(5) << std::fixed << std::setprecision(5) << addr.zipCode << std::endl;
	}

private:
	std::string name{ "" };
	std::string address{ "" };
	std::string city{ "" };
	std::string state{ "" };
	unsigned zipCode{ 0 };

};

#endif
