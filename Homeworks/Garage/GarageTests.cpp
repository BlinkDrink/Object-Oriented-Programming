#include "Garage.h"
#include "catch2.hpp"
#include <cassert>

TEST_CASE("Garage Constructor with argument size", "[Garage]") {
	SECTION("Garage_SizeZero_Throw") {
		// Assert
		REQUIRE_THROWS(Garage(0));
	}

	SECTION("Garage_SizeZero_Throw") {
		// Arrage
		Garage g(5);

		// Assert
		REQUIRE(g.size() == 0);
	}
}

TEST_CASE("Garage Copy constructor", "[Garage]")
{
	SECTION("Garage_GivenAGarage_CopyGarageProperly")
	{
		//Arrange
		Garage g2(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("B4321GD", "Citroen C3", 5);

		//Act
		g2.insert(v1);
		g2.insert(v2);
		Garage g1(g2);

		//Assert
		REQUIRE(g1.size() == 2);
		REQUIRE(g1.empty() == false);
		REQUIRE(g1.find("B4321GD") != nullptr);
		REQUIRE(g2.size() == 2);
		REQUIRE(g2.empty() == false);
	}
}

TEST_CASE("Garage Copy assignment operator", "[operator=]")
{
	SECTION("operator=_GivenNonEmptyGarage_CopyContentsProperly")
	{
		//Arrange
		Garage g2(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("B4321GD", "Citroen C3", 5);

		//Act
		g2.insert(v1);
		g2.insert(v2);
		Garage g1(10);
		g1 = g2;

		//Assert
		REQUIRE(g1.size() == 2);
		REQUIRE(g1.empty() == false);
		REQUIRE(g1.find("B4321GD") != nullptr);
		REQUIRE(g2.size() == 2);
		REQUIRE(g2.empty() == false);
	}

	SECTION("operator=_ChainMultipleGarages_CopyThemProperly")
	{
		//Arrange
		Garage g2(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("B4321GD", "Citroen C3", 5);

		//Act
		g2.insert(v1);
		g2.insert(v2);
		Garage g1(10);
		Garage g3(10);
		g1 = g3 = g2;

		//Assert
		REQUIRE(g1.size() == 2);
		REQUIRE(g1.empty() == false);
		REQUIRE(g1.find("B4321GD") != nullptr);

		REQUIRE(g2.size() == 2);
		REQUIRE(g2.empty() == false);

		REQUIRE(g3.find("B4321GD") != nullptr);
		REQUIRE(g3.size() == 2);
		REQUIRE(g3.empty() == false);
	}
}

TEST_CASE("Garage Move constructor", "[Garage]")
{
	SECTION("Garage_GivenNonEmptyGarage_MoveGarageContentsProperly")
	{
		//Arrange
		Garage g2(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("B4321GD", "Citroen C3", 5);

		//Act
		g2.insert(v1);
		g2.insert(v2);
		Garage g1(std::move(g2));

		//Assert
		REQUIRE(g1.size() == 2);
		REQUIRE(g1.empty() == false);
		REQUIRE(g1.find("M1234BP") != nullptr);
		REQUIRE(g2.size() == 0);
		REQUIRE(g2.empty() == true);
	}
}

TEST_CASE("Garage Move assignment operator", "[operator=]")
{
	SECTION("operator=_GivenNonEmptyGarage_MoveGarageContentsProperly")
	{
		//Arrange
		Garage g2(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("B4321GD", "Citroen C3", 5);

		//Act
		g2.insert(v1);
		g2.insert(v2);
		Garage g1(10);
		g1 = std::move(g2);

		//Assert
		REQUIRE(g1.size() == 2);
		REQUIRE(g1.empty() == false);
		REQUIRE(g1.find("M1234BP") != nullptr);
		REQUIRE(g2.size() == 0);
		REQUIRE(g2.empty() == true);
	}
}

TEST_CASE("Garage insert class method", "[insert]")
{
	SECTION("insert_VehicleThatDoesntExistInGarage_IncrementCarsNumber")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);

		//Act
		g1.insert(v1);

		//Assert
		REQUIRE(g1.size() == 1);
	}

	SECTION("insert_CarWithSpacesMoreThanCapacity_ThrowOutOfRangeException")
	{
		//Arrange
		Garage g1(4);
		Vehicle v1("M1234BP", "Opel Astra", 3);
		Vehicle v2("M4321DG", "Mercedes", 2);

		//Act
		g1.insert(v1);

		//Assert
		REQUIRE_THROWS_AS(g1.insert(v2), std::out_of_range);
	}

	SECTION("insert_CarWithExistingRegistrationNumber_ThrowInvalidArgumentException")
	{
		//Arrange
		Garage g1(5);
		Vehicle v1("M1234BP", "Opel Astra", 2);
		Vehicle v2("M1234BP", "Mercedes", 2);

		//Act
		g1.insert(v1);

		//Assert
		REQUIRE_THROWS_AS(g1.insert(v2), std::invalid_argument);
	}

	SECTION("insert_VehicleThatDoesntExistInGarage_GarageShouldntBeEmpty")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);

		//Act
		g1.insert(v1);

		//Assert
		REQUIRE(g1.empty() == false);
	}

	SECTION("insert_VehicleThatDoesntExistInGarage_VehicleShouldBeFound")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);

		//Act
		g1.insert(v1);

		//Assert
		REQUIRE(g1.find("M1234BP") != nullptr);
	}
}

TEST_CASE("Garage erase class method", "[erase]")
{
	SECTION("erase_WithAvailableVehicle_ShouldRemoveVehicleProperly")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		g1.insert(v1);

		//Act
		g1.erase("M1234BP");

		//Assert
		REQUIRE(g1.size() == 0);
	}

	SECTION("erase_WithUnavailableVehicle_DoesNothing")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		g1.insert(v1);

		//Act
		g1.erase("NonExistant");

		//Assert
		REQUIRE(g1.size() == 1);
	}

	SECTION("erase_TwoConsecutiveVehicles_RemoveThemBoth")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("M4321PR", "Mercedes", 5);
		g1.insert(v1);
		g1.insert(v2);

		//Act
		g1.erase("M1234BP");
		g1.erase("M4321PR");

		//Assert
		REQUIRE(g1.size() == 0);
		REQUIRE(g1.empty() == true);
	}

	SECTION("erase_OnGarageWithCopyConstructor_RemoveVehiclesProperly")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("M4321PR", "Mercedes", 5);
		g1.insert(v1);
		g1.insert(v2);

		//Act
		Garage g2(g1);
		g2.erase("M1234BP");
		g2.erase("M4321PR");

		//Assert
		REQUIRE(g2.size() == 0);
		REQUIRE(g2.empty() == true);
	}
}

TEST_CASE("Garage at class method", "[at]")
{
	SECTION("at_WithValidPositionAndNonEmptyGarage_ReturnVehicle")
	{
		//Arrange
		const char reg[] = "M1234BP";
		const char descr[] = "Opel Astra";
		Garage g1(10);
		Vehicle v1(reg, descr, 5);
		g1.insert(v1);

		//Act
		Vehicle v2 = g1.at(0);

		//Assert
		REQUIRE(strcmp(v2.description(), descr) == 0);
		REQUIRE(strcmp(v2.registration(), reg) == 0);
		REQUIRE(v2.space() == 5);
	}
}

TEST_CASE("Garage operator[]", "[operator[]]")
{
	SECTION("operator[]_WithValidPositionAndNonEmptyGarage_ReturnVehicle")
	{
		//Arrange
		const char reg[] = "M1234BP";
		const char descr[] = "Opel Astra";
		Garage g1(10);
		Vehicle v1(reg, descr, 5);
		g1.insert(v1);

		//Act
		Vehicle v2 = g1[0];

		//Assert
		REQUIRE(strcmp(v2.description(), descr) == 0);
		REQUIRE(strcmp(v2.registration(), reg) == 0);
		REQUIRE(v2.space() == 5);
	}
}

TEST_CASE("Garage empty class method", "[empty]")
{
	SECTION("empty_OnNonEmptyGarage_False")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		g1.insert(v1);

		//Act
		bool isEmpty = g1.empty();

		//Assert
		REQUIRE(isEmpty == false);
	}

	SECTION("empty_OnEmptyGarage_True")
	{
		//Arrange
		Garage g1(10);

		//Act
		bool isEmpty = g1.empty();

		//Assert
		REQUIRE(isEmpty == true);
	}

	SECTION("empty_WithOneVehicleAfterErase_True")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);

		//Act
		g1.insert(v1);
		g1.erase("M1234BP");
		bool isEmpty = g1.empty();

		//Assert
		REQUIRE(isEmpty == true);
	}
}

TEST_CASE("Garage size class method", "[size]")
{
	SECTION("size_OnEmptyGarage_Zero")
	{
		//Arrange
		Garage g1(10);

		//Act
		int size = g1.size();

		//Assert
		REQUIRE(size == 0);
	}

	SECTION("size_OnNonEmptyGarage_NonZero")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);

		//Act
		g1.insert(v1);
		size_t size = g1.size();

		//Assert
		REQUIRE(size != 0);
	}

	SECTION("size_AfterErasingLastVehicle_Zero")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);

		//Act
		g1.insert(v1);
		g1.erase("M1234BP");
		size_t size = g1.size();

		//Assert
		REQUIRE(size == 0);
	}
}

TEST_CASE("Garage clear class method", "[clear]")
{
	SECTION("clear_NonEmptyGarage_SizeShouldBeZero")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);

		//Act
		g1.insert(v1);
		g1.clear();
		size_t size = g1.size();

		//Assert
		REQUIRE(size == 0);
	}

	SECTION("clear_AfterErasingLastElement_DoNothing")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);

		//Act
		g1.insert(v1);
		g1.erase("M1234BP");
		g1.clear();
		size_t size = g1.size();

		//Assert
		REQUIRE(size == 0);
	}

	SECTION("clear_MoreThanThreeVehicles_RemoveThemAll")
	{
		//Arrange
		Garage g1(15);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("M4321PR", "Mercedes", 5);
		Vehicle v3("M9876SK", "Mazda", 5);

		//Act
		g1.insert(v1);
		g1.insert(v2);
		g1.insert(v3);
		g1.clear();
		size_t size = g1.size();

		//Assert
		REQUIRE(size == 0);
	}
}

TEST_CASE("Garage find class method", "[find]")
{
	SECTION("find_ExistingVehicleInGarage_ReturnTheVehicle")
	{
		//Arrange
		Garage g1(15);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("M4321PR", "Mercedes", 5);
		Vehicle v3("M9876SK", "Mazda", 5);

		//Act
		g1.insert(v1);
		g1.insert(v2);
		g1.insert(v3);
		const Vehicle* v = g1.find("M1234BP");

		//Assert
		REQUIRE(strcmp(v1.registration(), v->registration()) == 0);
		REQUIRE(strcmp(v1.description(), v->description()) == 0);
		REQUIRE(v1.space() == v->space());
	}

	SECTION("find_NonExistingVehicle_ReturnNullptr")
	{
		//Arrange
		Garage g1(10);
		Vehicle v1("M1234BP", "Opel Astra", 5);

		//Act
		g1.insert(v1);
		const Vehicle* v = g1.find("none");

		//Assert
		REQUIRE(v == nullptr);
	}

	SECTION("find_AfterClearClassMethod_ReturnNullptr")
	{
		//Arrange
		Garage g1(15);
		Vehicle v1("M1234BP", "Opel Astra", 5);
		Vehicle v2("M4321PR", "Mercedes", 5);
		Vehicle v3("M9876SK", "Mazda", 5);


		//Act
		g1.insert(v1);
		g1.insert(v2);
		g1.insert(v3);
		g1.clear();

		//Assert
		REQUIRE(g1.find("M1234BP") == nullptr);
	}
}