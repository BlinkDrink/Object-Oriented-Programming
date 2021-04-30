#define CATCH_CONFIG_MAIN 
#include "ComplexNumber.h"
#include "catch.hpp"
#include <cassert>

TEST_CASE("addComplexNumbers should work properly", "[addComplexNumbers]")
{
	SECTION("adding negative numbers should result in a negative number")
	{
		ComplexNumber c1 = { -4, -5 };
		ComplexNumber c2 = { -4, -5 };
		ComplexNumber res;

		addComplexNumbers(&res, &c1, &c2);


		REQUIRE(res.real < 0);
		REQUIRE(res.imaginary < 0);
	}

	SECTION("adding positive numbers should result in a positive number")
	{
		ComplexNumber c1 = { 4, 5 };
		ComplexNumber c2 = { 1, 3 };

		ComplexNumber res;

		addComplexNumbers(&res, &c1, &c2);

		REQUIRE(res.real > 0);
		REQUIRE(res.imaginary > 0);
	}

	SECTION("adding two opposite numbers should equal zero")
	{
		ComplexNumber c1 = { 4, 5 };
		ComplexNumber c2 = { -4, -5 };

		ComplexNumber res;

		addComplexNumbers(&res, &c1, &c2);

		REQUIRE(res.real == 0);
		REQUIRE(res.imaginary == 0);
	}

	SECTION("adding a with b, where a > b, result should be positive")
	{
		ComplexNumber c1 = { 4, 5 };
		ComplexNumber c2 = { 1, 3 };

		ComplexNumber res;

		addComplexNumbers(&res, &c1, &c2);

		REQUIRE(res.real > 0);
		REQUIRE(res.imaginary > 0);
	}

	SECTION("adding two zero complex numbers should equal zero")
	{
		ComplexNumber c1 = { 0,0 };
		ComplexNumber c2 = { 0,0 };

		ComplexNumber res;

		addComplexNumbers(&res, &c1, &c2);

		REQUIRE(res.real == 0);
		REQUIRE(res.imaginary == 0);
	}

	SECTION("adding two complex numbers without imaginary part should be a real number")
	{
		ComplexNumber c1 = { 4,0 };
		ComplexNumber c2 = { 5,0 };

		ComplexNumber res;

		addComplexNumbers(&res, &c1, &c2);

		REQUIRE(res.imaginary == 0);
	}
}

TEST_CASE("multiplyComplexNumbers should work properly", "[multiplyComplexNumbers]") {
	SECTION("should multiply real part properly, and complex part") {
		ComplexNumber c1 = { -1, -2 };
		ComplexNumber c2 = { -2, -3 };

		ComplexNumber res;

		multiplyComplexNumbers(&res, &c1, &c2);

		REQUIRE(res.real == -4);
		REQUIRE(res.imaginary == 7);
	}
}