//#define CATCH_CONFIG_MAIN
//#include "Registration.h"
//#include<cassert>
//#include "catch2.hpp"
//
//TEST_CASE("Registration constructor", "[Registration]") {
//	SECTION("Registration_GivenValidCarRegNumber_InitializeRegistrationProperly") {
//		//Arrange
//		char reg[] = "XX1234YY";
//		Registration s(reg);
//		bool areEqual = true;
//
//		//Act
//		for (size_t i = 0; i < 9; i++)
//		{
//			if (s.toString()[i] != reg[i])
//			{
//				areEqual = false;
//				break;
//			}
//		}
//
//		//Assert
//		REQUIRE(areEqual == true);
//	}
//}