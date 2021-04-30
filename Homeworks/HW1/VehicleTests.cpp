#include "Vehicle.h"
#include "catch2.hpp"
#include <cassert>

TEST_CASE("Vehicle constructor", "[Vehicle]")
{
	SECTION("Vehicle_NonEmptyArguments_InitializePropertiesProperly")
	{
		//Arrage
		const char reg[] = "M1234BM";
		const char descrp[] = "Volkswagen Golf";
		const size_t spaces = 2;
		Vehicle s(reg, descrp, spaces);

		//Act
		bool areEqualReg = strcmp(s.registration(), reg) == 0;
		bool areEqualDescrp = strcmp(s.description(), descrp) == 0;
		bool areEqualSpaces = spaces == s.space();

		//Assert
		REQUIRE(areEqualReg == true);
		REQUIRE(areEqualDescrp == true);
		REQUIRE(areEqualSpaces == true);
	}
}

TEST_CASE("Vehicle registration class method", "[registration]")
{
	SECTION("registration_NonEmptyVIN_ReturnNonEmptyString")
	{
		//Arrage
		const char reg[] = "M1234BM";
		const char descrp[] = "Volkswagen Golf";
		const size_t spaces = 2;
		Vehicle s(reg, descrp, spaces);

		//Act
		bool isEmpty = strlen(s.registration()) == 0;

		//Assert
		REQUIRE(isEmpty == false);
	}

	SECTION("registration_NonEmptyVIN_HaveTheSameStringAsInitializer")
	{
		//Arrage
		const char reg[] = "M1234BM"; // Initializer
		const char descrp[] = "Volkswagen Golf";
		const size_t spaces = 2;
		Vehicle s(reg, descrp, spaces);

		//Act
		bool areSame = strcmp(reg, s.registration()) == 0;

		//Assert
		REQUIRE(areSame == true);
	}
}

TEST_CASE("Vehicle description class method", "[description]")
{
	SECTION("description_NonEmptyDescription_ReturnNonEmptyString")
	{
		//Arrage
		const char reg[] = "M1234BM";
		const char descrp[] = "Volkswagen Golf";
		const size_t spaces = 2;
		Vehicle s(reg, descrp, spaces);

		//Act
		bool isEmpty = strlen(s.description()) == 0;

		//Assert
		REQUIRE(isEmpty == false);
	}

	SECTION("description_NonEmptyDescription_HaveTheSameStringAsInitializer")
	{
		//Arrage
		const char reg[] = "M1234BM"; // Initializer
		const char descrp[] = "Volkswagen Golf";
		const size_t spaces = 2;
		Vehicle s(reg, descrp, spaces);

		//Act
		bool areSame = strcmp(descrp, s.description()) == 0;

		//Assert
		REQUIRE(areSame == true);
	}
}

TEST_CASE("Vehicle space class method", "[space]")
{
	SECTION("space_NonZeroSpace_ReturnNonZeroSpace")
	{
		//Arrage
		const char reg[] = "M1234BM";
		const char descrp[] = "Volkswagen Golf";
		const size_t spaces = 2;
		Vehicle s(reg, descrp, spaces);

		//Act
		bool isZero = s.space() == 0;

		//Assert
		REQUIRE(isZero == false);
	}

	SECTION("space_NonZeroSpace_HaveTheSameSpaceAsInitializer")
	{
		//Arrage
		const char reg[] = "M1234BM"; // Initializer
		const char descrp[] = "Volkswagen Golf";
		const size_t spaces = 2;
		Vehicle s(reg, descrp, spaces);

		//Act
		bool areSame = spaces == s.space();

		//Assert
		REQUIRE(areSame == true);
	}
}