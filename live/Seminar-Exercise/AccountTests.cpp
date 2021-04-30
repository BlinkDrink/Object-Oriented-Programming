//#define CATCH_CONFIG_MAIN
//#include "Account.h"
//#include "helpers.h"
//#include "catch.hpp"
//
//TEST_CASE("Account constructor", "[Account]") {
//	SECTION("Account_EmptyStringArgument_InitializeWithEmptyString") {
//		//Arrange
//		Account a("");
//
//		//Act
//		const char* name = a.getName();
//
//		//Assert
//		REQUIRE(getStrLen(name) == 0);
//	}
//
//	SECTION("Account_NonEmptyStringArgument_InitializeWithNonEmptyString") {
//		//Arrange
//		Account a("two");
//		const unsigned nameLen = 3;
//
//		//Act
//		const char* name = a.getName();
//
//		//Assert
//		REQUIRE(getStrLen(name) == nameLen);
//	}
//}
//
//TEST_CASE("getName class method") {
//	SECTION("getName_NonEmptyString_HaveSizeGreaterThanZero") {
//		//Arrange
//		Account a("Three");
//
//		//Act
//		const char* name = a.getName();
//
//		//Assert
//		REQUIRE(getStrLen(name) > 0);
//	}
//
//	SECTION("getName_EmptyString_SizeEqualsZero") {
//		//Arrange
//		Account a("");
//
//		//Act
//		const char* name = a.getName();
//
//		//Assert
//		REQUIRE(getStrLen(name) == 0);
//	}
//}
//
//TEST_CASE("getMoney class method") {
//	SECTION("getMoney_OnNonZeroFundsAcc_ReturnNumberGreaterThanZero") {
//		//Arrange
//		Account a("Three");
//
//		//Act
//		a.setMoney(10);
//
//		//Assert
//		REQUIRE(a.getMoney() > 0);
//	}
//
//	SECTION("getMoney_OnZeroFundsAcc_ReturnZero") {
//		//Arrange
//		Account a("");
//
//		//Assert
//		REQUIRE(a.getMoney() == 0);
//	}
//}
//
//
