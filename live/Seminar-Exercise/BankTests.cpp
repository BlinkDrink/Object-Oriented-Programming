#define CATCH_CONFIG_MAIN
#include "Bank.h"
#include "helpers.h"
#include "catch.hpp"
#include <cstring>

TEST_CASE("Bank constructor", "[Bank]") {
	SECTION("Bank_WithNonEmptyStringName_InitializeNameWithSizeGreaterThanZero") {
		//Arrange
		Bank b(10, "DSK");

		//Act
		const char* name = b.getName();

		//Assert
		REQUIRE(getStrLen(name) != 0);
	}
}

TEST_CASE("transfer class method", "[transfer]") {
	SECTION("transfer_WithMoneyGreaterThanZero_ChangeBalanceAccordingly") {
		//Arrange
		Bank b(10, "DSK");

		//Act
		Account a("Petko");
		Account t("Teodor");
		b.addAccount(a);
		b.addAccount(t);
		a.setMoney(10);
		t.setMoney(20);
		b.transfer("Petko", "Teodor", 10);

		//Assert
		REQUIRE(t.getMoney() == 30);
	}

	SECTION("transfer_WithZeroMoney_BalanceShouldBeUnchanged") {
		//Arrange
		Bank b(10, "DSK");

		//Act
		Account a("Petko");
		Account t("Teodor");
		b.addAccount(a);
		b.addAccount(t);
		a.setMoney(10);
		t.setMoney(20);
		b.transfer("Petko", "Teodor", 0);

		//Assert
		REQUIRE(t.getMoney() == 20);
	}
}