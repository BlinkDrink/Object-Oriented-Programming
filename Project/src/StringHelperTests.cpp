#define CATCH_CONFIG_MAIN
#include<cassert>
#include "catch2.hpp"
#include "StringHelper.h"

TEST_CASE("StringHelper splitBy", "[splitBy]") {
	StringHelper sh;
	SECTION("splitBy_OnNonEmptyString_SplitItProperly") {
		//Arrange
		string toSplit = "Hello healthy world!";

		//Act
		vector<string> parts = sh.splitBy(toSplit, " ");

		//Assert
		REQUIRE(parts[0] == "Hello");
		REQUIRE(parts[1] == "healthy");
		REQUIRE(parts[2] == "world!");
		REQUIRE(parts.size() == 3);
	}

	SECTION("splitBy_OnEmptyString_ReturnEmptyVector") {
		//Arrange
		string toSplit = "";

		//Act
		vector<string> parts = sh.splitBy(toSplit, " ");

		//Assert
		REQUIRE(parts.size() == 0);
	}

	SECTION("splitBy_OnStringWithOneNumber_ReturnNumber") {
		//Arrange
		string toSplit = "0.5";

		//Act
		vector<string> parts = sh.splitBy(toSplit, " ");

		//Assert
		REQUIRE(parts.size() == 1);
		REQUIRE(parts[0] == "0.5");
	}

	SECTION("splitBy_WithDifferentDelimiter_ReturnNonEmptyVector") {
		//Arrange
		string toSplit = "A-|-bra-|-ca-|-da-|-bra";

		//Act
		vector<string> parts = sh.splitBy(toSplit, "-|-");

		//Assert
		REQUIRE(parts.size() == 5);
		REQUIRE(parts[0] == "A");
		REQUIRE(parts[1] == "bra");
		REQUIRE(parts[2] == "ca");
		REQUIRE(parts[3] == "da");
		REQUIRE(parts[4] == "bra");
	}

	SECTION("splitBy_WithDelimeterInEnquotedString_SplitItProperly") {
		//Arrange
		string toSplit = "hello \"Some string\" bye bye";

		//Act
		vector<string> parts = sh.splitBy(toSplit, " ");

		//Assert
		REQUIRE(parts.size() == 4);
		REQUIRE(parts[0] == "hello");
		REQUIRE(parts[1] == "\"Some string\"");
		REQUIRE(parts[2] == "bye");
		REQUIRE(parts[3] == "bye");
	}

	SECTION("splitBy_WithStringConcatenatedToQuotedString_SplitItProperly") {
		//Arrange
		string toSplit = "hello\"Some string\" bye bye";

		//Act
		vector<string> parts = sh.splitBy(toSplit, " ");

		//Assert
		REQUIRE(parts.size() == 3);
		REQUIRE(parts[0] == "hello\"Some string\"");
		REQUIRE(parts[1] == "bye");
		REQUIRE(parts[2] == "bye");
	}

	SECTION("splitBy_WithQuotedStringInTheEnd_SplitItProperly") {
		//Arrange
		string toSplit = "hello bye bye \"Some string\"";

		//Act
		vector<string> parts = sh.splitBy(toSplit, " ");

		//Assert
		REQUIRE(parts.size() == 4);
		REQUIRE(parts[0] == "hello");
		REQUIRE(parts[1] == "bye");
		REQUIRE(parts[2] == "bye");
		REQUIRE(parts[3] == "\"Some string\"");
	}
}

TEST_CASE("StringHelper isStringInteger", "[isStringInteger]") {
	StringHelper sh;
	SECTION("isStringInteger_OnStringThatIsInteger_True") {
		//Assert
		REQUIRE(sh.isStringInteger("1234"));
		REQUIRE(sh.isStringInteger("1234"));
		REQUIRE(sh.isStringInteger("0"));
		REQUIRE(sh.isStringInteger("5812398124"));
		REQUIRE(sh.isStringInteger("17"));
	}

	SECTION("isStringInteger_OnStringThatIsNotInteger_False") {
		//Assert
		REQUIRE(!sh.isStringInteger("95.142"));
		REQUIRE(!sh.isStringInteger("95.142.124"));
		REQUIRE(!sh.isStringInteger("95.142"));
		REQUIRE(!sh.isStringInteger("95   "));
		REQUIRE(!sh.isStringInteger("  95"));
		REQUIRE(!sh.isStringInteger("ABC"));
	}
}

TEST_CASE("StringHelper isStringDouble", "[isStringDouble]") {
	StringHelper sh;
	SECTION("isStringDouble_OnStringThatIsDouble_True") {
		//Assert
		REQUIRE(sh.isStringDouble("1234.12"));
		REQUIRE(sh.isStringDouble("1234.654012"));
		REQUIRE(sh.isStringDouble("0.1201294"));
		REQUIRE(sh.isStringDouble("5812398124.121839124"));
		REQUIRE(sh.isStringDouble("17.0"));
	}

	SECTION("isStringInteger_OnStringThatIsNotInteger_False") {
		//Assert
		REQUIRE(!sh.isStringDouble("95"));
		REQUIRE(!sh.isStringDouble("95.142.124"));
		REQUIRE(!sh.isStringDouble("95..142"));
		REQUIRE(!sh.isStringDouble("95.12   "));
		REQUIRE(!sh.isStringDouble("  95.12"));
		REQUIRE(!sh.isStringDouble("ABC.1251"));
	}
}

TEST_CASE("StringHelper isStringValidFormula", "[isStringValidFormula]") {
	StringHelper sh;
	SECTION("isStringValidFormula_OnValidFormula_True") {
		//Assert
		REQUIRE(sh.isStringValidFormula("=1234.12 + 2^10 - 5000"));
		REQUIRE(sh.isStringValidFormula("=1234.654012/4000*3 - 500"));
		REQUIRE(sh.isStringValidFormula("=0.1201294*1234"));
		REQUIRE(sh.isStringValidFormula("=5812398124.121839124+12"));
		REQUIRE(sh.isStringValidFormula("=-17.0-542"));
		REQUIRE(sh.isStringValidFormula("=95"));
		REQUIRE(sh.isStringValidFormula("=15/15*\"14.14.23\" +  55-55"));
		REQUIRE(sh.isStringValidFormula("=\"123\" + \"Hello world!\"   \":D\""));
		REQUIRE(sh.isStringValidFormula("    =  15"));
	}

	SECTION("isStringValidFormula_OnInvalidFormula_False") {
		//Assert
		REQUIRE(!sh.isStringValidFormula("95"));
		REQUIRE(!sh.isStringValidFormula("="));
		REQUIRE(!sh.isStringValidFormula("    =      "));
		REQUIRE(!sh.isStringValidFormula("95.142.124"));
		REQUIRE(!sh.isStringValidFormula("95..142"));
		REQUIRE(!sh.isStringValidFormula("=95....12   "));
		REQUIRE(!sh.isStringValidFormula("=  95.*.12"));
		REQUIRE(!sh.isStringValidFormula("ABC.421..1521251"));
		REQUIRE(!sh.isStringValidFormula("=\"95"));
		REQUIRE(!sh.isStringValidFormula("\"=95"));
		REQUIRE(!sh.isStringValidFormula("=95+"));
		REQUIRE(!sh.isStringValidFormula("=95+12.12.12"));
	}
}

TEST_CASE("StringHelper trim", "[trim]") {
	StringHelper sh;
	SECTION("trim_OnNonTrimmedString_TrimIt") {
		//Arrange
		string nonTrimmed = "  hello mate     ";

		//Act
		sh.trim(nonTrimmed);

		//Assert
		REQUIRE(nonTrimmed.size() == 10);
	}

	SECTION("trim_OnTrimmedString_DoNothing") {
		//Arrrange
		string trimmed = "hello mate";

		//Act
		sh.trim(trimmed);

		//Assert
		REQUIRE(trimmed.size() == 10);
	}

	SECTION("trim_AfterAddingCharacterToString_TrimItProperly") {
		//Arrrange
		string nonTrimmed = "  hello mate    ";

		//Act
		sh.trim(nonTrimmed);
		nonTrimmed += "   ";
		sh.trim(nonTrimmed);

		//Assert
		REQUIRE(nonTrimmed.size() == 10);
	}
}

TEST_CASE("StringHelper isStringValidString", "[isStringValidString]") {
	StringHelper sh;
	SECTION("isStringValidString_OnString_True") {
		//Assert
		REQUIRE(sh.isStringValidString("\"1234\""));
		REQUIRE(sh.isStringValidString("\"\"1234\"	\""));
		REQUIRE(sh.isStringValidString("\"0\""));
		REQUIRE(sh.isStringValidString("\"Abracadabra\""));
		REQUIRE(sh.isStringValidString("\"17\""));
	}

	SECTION("isStringValidString_OnInvalidString_False") {
		//Assert
		REQUIRE(!sh.isStringInteger("95.142"));
		REQUIRE(!sh.isStringInteger("\"95.142.124"));
		REQUIRE(!sh.isStringInteger("95.142\""));
		REQUIRE(!sh.isStringInteger("95   "));
		REQUIRE(!sh.isStringInteger("  New York \"City\""));
		REQUIRE(!sh.isStringInteger("ABC"));
	}
}

TEST_CASE("StringHelper removeQuotations", "[removeQuotations]") {
	StringHelper sh;
	SECTION("removeQuotations_onQuotedString_RemoveThem") {
		//Arrange
		string quoted = "\"Hello there mate\"";

		//Act
		sh.removeQuotations(quoted);

		//Assert
		REQUIRE(quoted.size() == 16);
		REQUIRE(quoted[0] != '"');
		REQUIRE(quoted[quoted.size() - 1] != '"');
	}

	SECTION("removeQuotations_onNonQuotedString_DoNothing") {
		//Arrange
		string notQuoted = "Hello there mate";

		//Act
		sh.removeQuotations(notQuoted);

		//Assert
		REQUIRE(notQuoted.size() == 16);
		REQUIRE(notQuoted[0] == 'H');
		REQUIRE(notQuoted[notQuoted.size() - 1] == 'e');
	}
}

TEST_CASE("StringHelper addSpaceInBetweenWords", "[addSpaceInBetweenWords]") {
	StringHelper sh;
	SECTION("addSpaceInBetweenWords_OnNonDividedWords_DivideThemWithSpaces") {
		//Arrange
		string nonDivided = "15+44-100*55^10/3";

		//Act
		sh.addSpaceInBetweenWords(nonDivided);

		//Assert
		REQUIRE(nonDivided.size() == 27);
	}

	SECTION("addSpaceInBetweenWords_OnNonDividedNumbers_AddExtraWhiteSpace") {
		//Arrange
		string nonDivided = "15 + 44 - 100 * 55 ^ 10 / 3";

		//Act
		sh.addSpaceInBetweenWords(nonDivided);

		//Assert
		REQUIRE(nonDivided.size() == 37);
		REQUIRE(nonDivided == "15  +  44  -  100  *  55  ^  10  /  3");
	}

	SECTION("addSpaceInBetweenWords_OnNonDividedWords_AddExtraWhiteSpace") {
		//Arrange
		string nonDivided = "abc - def | ghi m 55 ( hello ) my";

		//Act
		sh.addSpaceInBetweenWords(nonDivided);

		//Assert
		REQUIRE(nonDivided.size() == 41);
		REQUIRE(nonDivided == "abc  -  def  |  ghi m 55  (  hello  )  my");
	}

	SECTION("addSpaceInBetweenWords_OnEmptyString_DoNothing") {
		//Arrange
		string nonDivided = "";

		//Act
		sh.addSpaceInBetweenWords(nonDivided);

		//Assert
		REQUIRE(nonDivided.size() == 0);
		REQUIRE(nonDivided == "");
	}
}

TEST_CASE("StringHelper calculateEquationInString", "[calculateEquationInString]") {
	StringHelper sh;
	SECTION("calculateEquationInString_WithValidEquation_ReturnCorrectResult") {
		//Assert
		REQUIRE(stod(sh.calculateEquationInString("-15 - 13 + 12 * 44 - 55 + \"123.123.123\"")) == 445.0);
		REQUIRE(stod(sh.calculateEquationInString("-15-13+12*44-55^2")) == -2525.0);
		REQUIRE(stod(sh.calculateEquationInString("-2000 / 100 + \"123\"/123* 1 - 2^10 ")) == -1043.0);
		REQUIRE(stod(sh.calculateEquationInString("-9 / 4.5 + \"123.50\"/123.50 * 1 - 2.5^10 ")) == -9537.743164);
		REQUIRE(stod(sh.calculateEquationInString("-3^2^4^10")) == 1.4780882941434592331608321020638e+38);
		REQUIRE(stod(sh.calculateEquationInString("0/10")) == 0);
	}

	SECTION("calculateEquationInString_WithInvalidEquation_Return#ERROR") {
		//Assert
		REQUIRE(sh.calculateEquationInString("") == "#ERROR");
		REQUIRE(sh.calculateEquationInString("^15/15*\"0.01.AS\" +  55") == "#ERROR");
		REQUIRE(sh.calculateEquationInString("15/15*\"14.14.23\" +  55-55") == "#ERROR");
		REQUIRE(sh.calculateEquationInString("15/\"0\"") == "#ERROR");
		REQUIRE(sh.calculateEquationInString("10/0") == "#ERROR");
		REQUIRE(sh.calculateEquationInString("") == "#ERROR");
	}
}

TEST_CASE("StringHelper containsPower", "[containsPower]") {
	StringHelper sh;
	vector<string> container = { "hi", "hello", "^" };
	SECTION("containsPower_OnVectorWithPowerSymbol_True") {

		REQUIRE(sh.containsPower(container));
	}

	SECTION("containsPower_OnVectorWithoutPowerSymbol_False") {
		container.pop_back();

		REQUIRE(!sh.containsPower(container));
	}
}

TEST_CASE("StringHelper containsMultiplication", "[containsMultiplication]") {
	StringHelper sh;
	vector<string> container = { "hi", "hello", "*" };
	SECTION("containsMultiplication_OnVectorWithMultiplicationSymbol_True") {

		REQUIRE(sh.containsMultiplication(container));
	}

	SECTION("containsMultiplication_OnVectorWithoutMultiplicationSymbol_False") {
		container.pop_back();

		REQUIRE(!sh.containsMultiplication(container));
	}
}

TEST_CASE("StringHelper containsDivision", "[containsDivision]") {
	StringHelper sh;
	vector<string> container = { "hi", "hello", "/" };
	SECTION("containsDivision_OnVectorWithDivisionSymbol_True") {
		//Assert
		REQUIRE(sh.containsDivision(container));
	}

	SECTION("containsDivision_OnVectorWithoutDivisionSymbol_False") {
		//Arrange
		container.pop_back();

		//Assert
		REQUIRE(!sh.containsDivision(container));
	}
}

TEST_CASE("StringHelper containsAditionOrSubtraction", "[containsAditionOrSubtraction]") {
	StringHelper sh;
	vector<string> container = { "hi", "hello", "+" };
	SECTION("containsAditionOrSubtraction_OnVectorWithAdditionSymbol_True") {
		//Assert
		REQUIRE(sh.containsAditionOrSubtraction(container));
	}

	SECTION("containsAditionOrSubtraction_OnVectorWithSubtractionSymbol_False") {
		//Arrange
		container.pop_back();
		container.push_back("-");

		//Assert
		REQUIRE(sh.containsAditionOrSubtraction(container));
	}

	SECTION("containsAditionOrSubtraction_OnVectorWithoutSubtractionSymbol_False") {
		//Arrange
		container.pop_back();

		//Assert
		REQUIRE(!sh.containsAditionOrSubtraction(container));
	}
}

TEST_CASE("StringHelper removeEmptyStringsInVector", "[removeEmptyStringsInVector]") {
	StringHelper sh;
	vector<string> container = { "hi", "hello", "/", "", "" };
	SECTION("removeEmptyStringsInVector_OnVectorWithEmptyStrings_RemoveThem") {
		//Act
		sh.removeEmptyStringsInVector(container);

		//Assert
		REQUIRE(container.size() == 3);
	}

	SECTION("removeEmptyStringsInVector_OnVectorWithoutEmptyStrings_DoNothing") {
		//Arrange
		vector<string> container = { "hi", "hello", "/" };

		//Act
		sh.removeEmptyStringsInVector(container);

		//Assert
		REQUIRE(container.size() == 3);
	}
}

TEST_CASE("StringHelper getStringFilledWithSpaces", "[getStringFilledWithSpaces]") {
	StringHelper sh;
	SECTION("getStringFilledWithSpaces_WithPositiveNumber_ReturnProperNumberOfSpaces") {
		//Arrange
		size_t numOfSpaces = 5;

		//Act
		string spaces = sh.getStringFilledWithSpaces(numOfSpaces);

		//Assert
		REQUIRE(spaces == "     ");
		REQUIRE(spaces.size() == 5);
	}

	SECTION("getStringFilledWithSpaces_WithZero_ReturnEmptyString") {
		//Arrange
		size_t numOfSpaces = 0;

		//Act
		string spaces = sh.getStringFilledWithSpaces(numOfSpaces);

		//Assert
		REQUIRE(spaces == "");
		REQUIRE(spaces.size() == 0);
	}
}