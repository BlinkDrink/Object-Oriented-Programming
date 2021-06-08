// #include <cassert>
// #include "../include/catch2.hpp"
// #include "../include/Cell.h"
// #include "../include/StringType.h"
// #include "../include/IntegerType.h"
// #include "../include/DoubleType.h"
// #include "../include/FormulaType.h"

// using std::move;

// TEST_CASE("Cell constructor", "[Cell]")
// {
// 	SECTION("constructor_withIntegerType_initializeCellProperly")
// 	{
// 		//Arrange
// 		Cell c(new IntegerType("150"));

// 		//Assert
// 		REQUIRE(c.getCellType() == DataType::INTEGER);
// 	}

// 	SECTION("constructor_withDoubleType_initializeCellProperly")
// 	{
// 		//Arrange
// 		Cell c(new DoubleType("150.151"));

// 		//Assert
// 		REQUIRE(c.getCellType() == DataType::DOUBLE);
// 	}

// 	SECTION("constructor_withStringType_initializeCellProperly")
// 	{
// 		//Arrange
// 		Cell c(new StringType("Helo"));

// 		//Assert
// 		REQUIRE(c.getCellType() == DataType::STRING);
// 	}

// 	SECTION("constructor_withFormulaType_initializeCellProperly")
// 	{
// 		//Arrange
// 		Cell c(new FormulaType("=1500 / \"123.3\" "));

// 		//Assert
// 		REQUIRE(c.getCellType() == DataType::FORMULA);
// 	}
// }

// TEST_CASE("Cell Copy Constructor", "[Cell]")
// {
// 	SECTION("copyCtor_withNonEmptyCell_CopyProperly")
// 	{
// 		//Arrange
// 		Cell c(new IntegerType("150"));
// 		Cell b(c);

// 		//Act
// 		bool areEqual = b.getContent()->getRawData() == c.getContent()->getRawData();

// 		//Assert
// 		REQUIRE(b.getCellType() == c.getCellType());
// 		REQUIRE(areEqual == true);
// 	}

// 	SECTION("copyCtor_withEmptyCell_CopyProperly")
// 	{
// 		//Arrange
// 		Cell c(nullptr);
// 		Cell b(c);

// 		//Assert
// 		REQUIRE(b.getContent() == nullptr);
// 	}
// }

// TEST_CASE("Cell Copy operator=", "[operator=]")
// {
// 	SECTION("operator=_withNonEmptyCell_CopyProperly")
// 	{
// 		//Arrange
// 		Cell c(new IntegerType("150"));
// 		Cell b = c;

// 		//Act
// 		bool areEqual = b.getContent()->getRawData() == c.getContent()->getRawData();

// 		//Assert
// 		REQUIRE(b.getCellType() == c.getCellType());
// 		REQUIRE(areEqual == true);
// 	}

// 	SECTION("operator=__withEmptyCell_CopyProperly")
// 	{
// 		//Arrange
// 		Cell c(nullptr);
// 		Cell b = c;

// 		//Assert
// 		REQUIRE(b.getContent() == nullptr);
// 	}
// }

// TEST_CASE("Cell Move Constructor", "[Cell]")
// {
// 	SECTION("moveConstructor_withNonEmptyCell_MoveProperly")
// 	{
// 		//Arrange
// 		Cell c(new IntegerType("150"));
// 		Cell b(move(c));

// 		//Act
// 		bool areEqual = c.getContent() == nullptr;
// 		bool areEqualRawDatas = b.getContent()->getRawData() == "150";

// 		//Assert
// 		REQUIRE(b.getCellType() == DataType::INTEGER);
// 		REQUIRE(areEqualRawDatas == true);
// 		REQUIRE(areEqual == true);
// 	}

// 	SECTION("copyCtor_withEmptyCell_MoveProperly")
// 	{
// 		//Arrange
// 		Cell c(nullptr);
// 		Cell b(move(c));

// 		//Assert
// 		REQUIRE(b.getContent() == nullptr);
// 	}
// }

// TEST_CASE("Cell Move operator=", "[Cell]")
// {
// 	SECTION("operator=_withNonEmptyCell_MoveProperly")
// 	{
// 		//Arrange
// 		Cell c(new IntegerType("150"));
// 		Cell b(nullptr);
// 		b = move(c);

// 		//Act
// 		bool areEqual = c.getContent() == nullptr;

// 		//Assert
// 		REQUIRE(b.getCellType() == DataType::INTEGER);
// 		REQUIRE(areEqual == true);
// 	}

// 	SECTION("operator=_withEmptyCell_MoveProperly")
// 	{
// 		//Arrange
// 		Cell c(nullptr);
// 		Cell b(new IntegerType("150"));

// 		//Act
// 		b = move(c);

// 		//Assert
// 		REQUIRE(b.getContent() == nullptr);
// 	}
// }