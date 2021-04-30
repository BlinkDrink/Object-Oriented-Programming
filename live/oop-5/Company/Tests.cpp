//#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
//#include "catch.hpp"
#include <cassert>
#include "Company.h"

int main() {
	Company c;
	Employee p("Pepe", "Logistics", 19, 700);
	Employee y("Yani", "Graphic Designs", 20, 999);

	char* nam = p.getName();
	*(nam + 1) = 'a';

	c.addEmployee(&p);
	c.addEmployee(&y);
	c.removeEmployee(&p);

	p.toString();

	return 0;
}