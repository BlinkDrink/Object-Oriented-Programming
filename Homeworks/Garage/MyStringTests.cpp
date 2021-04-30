#define CATCH_CONFIG_MAIN
#include "MyString.h"
#include "catch2.hpp"

using std::move;

/**
*	Section naming convention is as follows:
*	MethodName_StateUnderTest_ExpectedBehavior
*	Example:
*	admitStudent_MissingMandatoryFields_FailToAdmit
*/

TEST_CASE("MyString Copy constructor", "[MyString]")
{
	SECTION("MyString_GivenMyStringObject_ProperlyCopied)")
	{
		//Arrange
		MyString str1("Hello");
		MyString str2(str1);
		size_t str2Len = str2.size();
		bool areDifferent = false;

		//Act
		for (size_t i = 0; i < str2Len; i++)
		{
			if (str1.at(i) != str2.at(i))
			{
				areDifferent = true;
			}
		}

		//Assert
		REQUIRE(areDifferent == false);
		REQUIRE(str1.size() == str2.size());
	}
}

TEST_CASE("MyString Constructor given const char* argument", "[MyString]")
{
	SECTION("MyString_GivenConstChar*_ProperlyInitialized)")
	{
		//Arrange
		const char str[] = "Hello";
		MyString s(str);
		unsigned sLen = s.size();
		bool areDifferent = false;

		//Act
		for (size_t i = 0; i < sLen; i++)
		{
			if (str[i] != s.at(i))
			{
				areDifferent = true;
			}
		}

		//Assert
		REQUIRE(areDifferent == false);
	}

	SECTION("MyString_GivenConstChar*_HaveEqualLengths)")
	{
		//Arrange
		const char str[] = "Hello";
		MyString s(str);
		unsigned sLen = s.size();
		unsigned strLen = strlen(str);

		//Act
		bool areEqual = sLen == strLen;

		//Assert
		REQUIRE(areEqual == true);
	}

	SECTION("MyString_GivenEmptyString_HaveSizeZero)")
	{
		//Arrange
		const char str[] = "";
		MyString s(str);
		unsigned sLen = s.size();

		//Act
		bool isEqualToZero = sLen == 0;

		//Assert
		REQUIRE(isEqualToZero == true);
	}

	SECTION("MyString_GivenNullPtr_ShouldThrow)")
	{
		//Assert
		REQUIRE_THROWS(MyString(nullptr));
	}

	SECTION("MyString_GivenNullPtr_ShouldThrowInvalidArgumentException)")
	{
		//Assert
		REQUIRE_THROWS_AS(MyString(nullptr), std::invalid_argument);
	}
}

TEST_CASE("MyString Copy assignment operator", "[operator=]")
{
	SECTION("operator=_GivenMyStringObject_ProperlyCopied)")
	{
		//Arrange
		MyString str1("Hello");
		MyString str2 = str1;
		size_t str2Len = str2.size();
		bool areDifferent = false;

		//Act
		for (size_t i = 0; i < str2Len; i++)
		{
			if (str1.at(i) != str2.at(i))
			{
				areDifferent = true;
			}
		}

		//Assert
		REQUIRE(areDifferent == false);
	}

	SECTION("operator=_GivenMyStringObject_HaveEqualLengths")
	{
		//Arrange
		MyString str1("Hello");
		MyString str2 = str1;

		//Act
		bool areEqual = str1.size() == str2.size();

		//Assert
		REQUIRE(areEqual == true);
	}
}

TEST_CASE("MyString Move constructor ", "[MyString]")
{
	SECTION("MyString_GivenMyStringObject_HaveEqualSizeAsTheMovedObject)")
	{
		//Arrange
		MyString s("Hello");
		unsigned sLen = s.size();

		//Act
		MyString t(move(s));

		//Assert
		REQUIRE(t.size() == sLen);
	}
}

TEST_CASE("MyString Move assignment operator", "[operator=]")
{
	SECTION("operator=_GivenMyStringObject_HaveEqualSizeAsTheMovedObject)")
	{
		//Arrange
		MyString s("Hello");
		unsigned sLen = s.size();

		//Act
		MyString t = move(s);

		//Assert
		REQUIRE(t.size() == sLen);
	}
}

TEST_CASE("MyString at class method", "[at]")
{
	SECTION("at_GivenValidIndex_ShouldReturnTheCharacterAtThePos")
	{
		//Arrange
		MyString s("Hello");

		//Act
		const char ch = s.at(2);

		//Assert
		REQUIRE(ch == 'l');
	}

	SECTION("at_GivenInvalidIndex_ShouldThrow")
	{
		//Arrange
		MyString s("Hello");

		//Assert
		REQUIRE_THROWS(s.at(5));
	}

	SECTION("at_GivenInvalidIndex_ShouldThrowOutOfRangeException")
	{
		//Arrange
		MyString s("Hello");

		//Assert
		REQUIRE_THROWS_AS(s.at(5), std::out_of_range);
	}
}

TEST_CASE("MyString operator[]", "[opreator[]]")
{
	SECTION("operator[]_GivenValidIndex_ShouldReturnCorrectCharAtPos")
	{
		//Arrange
		MyString s("Hello");

		//Act
		const char ch = s[2];

		//Assert
		REQUIRE(ch == 'l');
	}
}

TEST_CASE("MyString size class method", "[size]")
{
	SECTION("size_OfNonEmptyString_ShouldReturnNonZero")
	{
		//Arrange
		MyString s("Hello");

		//Act
		unsigned size = s.size();

		//Assert
		REQUIRE(size == 5);
	}
}

TEST_CASE("MyString front class method", "[front]")
{
	SECTION("front_ofNonEmptyString_ShouldReturnFirstCharacter")
	{
		//Arrange
		MyString s("Hello");

		//Act
		char ch = s.front();

		//Assert
		REQUIRE(ch == 'H');
	}

	SECTION("front_ofNonEmptyString_ShouldReturnConstFirstCharacter")
	{
		//Arrange
		MyString s("Hello");

		//Act
		const char ch = s.front();

		//Assert
		REQUIRE(ch == 'H');
	}
}

TEST_CASE("MyString back class method", "[back]")
{
	SECTION("back_ofNonEmptyString_ShouldReturnTheLastElement")
	{
		//Arrange
		MyString s("Hello");

		//Act
		char ch = s.back();

		//Assert
		REQUIRE(ch == 'o');
	}
}

TEST_CASE("MyString empty class method", "[empty]")
{
	SECTION("empty_OnEmptyString_True")
	{
		//Arrange
		MyString s;

		//Act
		bool isEmpty = s.empty();

		//Assert
		REQUIRE(isEmpty == true);
	}

	SECTION("empty_OnNonEmptyString_False")
	{
		//Arrange
		MyString s("Non-Empty");

		//Act
		bool isEmpty = s.empty();

		//Assert
		REQUIRE(isEmpty == false);
	}

	SECTION("empty_AfterErasingTheLastRemainiongChar_True")
	{
		//Arrange
		MyString s("N");

		//Act
		s.pop_back();
		bool isEmpty = s.empty();

		//Assert
		REQUIRE(isEmpty == true);
	}

	SECTION("empty_AfterAddingOneChar_False")
	{
		//Arrange
		MyString s("");

		//Act
		s.push_back('a');
		bool isEmpty = s.empty();

		//Assert
		REQUIRE(isEmpty == false);
	}
}

TEST_CASE("MyString clear class method", "[clear]")
{
	SECTION("clear_OnNonEmptyString_ShouldHaveSizeEqualToZero")
	{
		//Arrange
		MyString s("Hello");

		//Act
		s.clear();

		//Assert
		REQUIRE(s.size() == 0);
	}

	SECTION("clear_OnEmptyString_ShouldNotDoAnything")
	{
		//Arrange
		MyString s;

		//Act
		s.clear();

		//Assert
		REQUIRE(s.size() == 0);
	}
}

TEST_CASE("MyString push_back class method", "[push_back]")
{
	SECTION("push_back_GivenCharacterLiteral_ShouldConcatenateIt")
	{
		//Arrange
		MyString s("H");

		//Act
		s.push_back('!');

		//Assert
		REQUIRE(s[s.size() - 1] == '!');
	}

	SECTION("push_back_GivenNULLTerminate_ShouldThrow")
	{
		//Arrange
		MyString s("H");

		//Assert
		REQUIRE_THROWS(s.push_back('\0'));
	}

	SECTION("push_back_GivenCharacterLiteralOnEmptyString_ShouldConcatenateIt")
	{
		//Arrange
		MyString s;

		//Act
		s.push_back('!');
		s.push_back('!');

		//Assert
		REQUIRE(s[s.size() - 1] == '!');
	}

	SECTION("push_back_GivenCharacterLiteral_ShouldHaveLengthIncrementedBy1")
	{
		//Arrange
		MyString s("Hello");
		unsigned before = s.size();

		//Act
		s.push_back('!');
		unsigned after = s.size();

		//Assert
		REQUIRE(after == before + 1);
	}
}

TEST_CASE("MyString pop_back class method", "[pop_back]")
{
	SECTION("pop_back_OnNonEmptyString_ShouldRemoveTheLastCharacter")
	{
		//Arrange
		MyString s("Hello");

		//Act
		s.pop_back();

		//Assert
		REQUIRE(s[s.size() - 1] == 'l');
	}

	SECTION("pop_back_OnNonEmptyString_ShouldRemoveTheLastCharacter")
	{
		//Arrange
		MyString s;

		//Act
		s.pop_back();

		//Assert
		REQUIRE(s[s.size()] == '\0');
	}

	SECTION("pop_back_OnNonEmptyCharacterString_ShouldDecrementSizeByOne")
	{
		//Arrange
		MyString s("Hello");
		unsigned before = s.size();

		//Act
		s.pop_back();
		unsigned after = s.size();

		//Assert
		REQUIRE(after == before - 1);
	}
}

TEST_CASE("MyString operator+=", "[operator+=]")
{
	SECTION("operator+=_NonEmptyString_ShouldConcatenateProperly")
	{
		//Arrange
		MyString s("Hello");
		MyString t("olleH");

		//Act
		s += t;

		//Assert
		REQUIRE(s[s.size() - 1] == 'H');
	}

	SECTION("operator+=_EmptyString_ShouldDoNothing")
	{
		//Arrange
		MyString s("Hello");
		MyString t("");

		//Act
		s += t;

		//Assert
		REQUIRE(s[s.size() - 1] == 'o');
	}

	SECTION("operator+=_NonEmptyString_HaveItsSizeIncremented")
	{
		//Arrange
		MyString s("Hello");
		MyString t("olleH");
		unsigned sSize = s.size();
		unsigned tSize = t.size();

		//Act
		s += t;

		//Assert
		REQUIRE(s.size() == tSize + sSize);
	}

	SECTION("operator+=_EmptyString_ShouldntChangeItsSize")
	{
		//Arrange
		MyString s("Hello");
		MyString t("");
		unsigned sSize = s.size();
		unsigned tSize = t.size();

		//Act
		s += t;

		//Assert
		REQUIRE(s.size() == sSize + tSize);
	}

	SECTION("operator+=_SingleChar_IncrementSizeByOne")
	{
		//Arrange
		MyString s("Hello");
		unsigned sSize = s.size();

		//Act
		s += 'a';

		//Assert
		REQUIRE(s.size() == sSize + 1);
	}
}

TEST_CASE("MyString operator+", "[operator+]")
{
	SECTION("operator+_ValidChar_IncrementSizeByOne")
	{
		//Arrange
		MyString s("Hello");

		//Act
		MyString t(s + '!');

		//Assert
		REQUIRE(t.size() == s.size() + 1);
	}

	SECTION("operator+_ValidChar_LastElementShouldEqualTheConcatenatedElement")
	{
		//Arrange
		MyString s("Hello");

		//Act
		MyString t(s + '!');

		//Assert
		REQUIRE(t[t.size() - 1] == '!');
	}

	SECTION("operator+_MyStringObject_LastElementShouldEqualLastElementOfAddedString")
	{
		//Arrange
		MyString s("Hello");

		//Act
		MyString t(s + s);

		//Assert
		REQUIRE(t[t.size() - 1] == 'o');
	}

	SECTION("operator+_MyStringObject_ShouldHaveIncrementedSize")
	{
		//Arrange
		MyString s("Hello");
		unsigned sSize = s.size();

		//Act
		MyString t(s + s);

		//Assert
		REQUIRE(t.size() == 2 * sSize);
	}

	SECTION("operator+_ChainingMultipleObjects_ConcatenateThemProperly")
	{
		//Arrange
		MyString s("Hello");
		MyString z("Hi");

		//Act
		MyString t(s + s + z);

		//Assert
		REQUIRE(t.size() == (2 * s.size()) + z.size());
	}
}

TEST_CASE("MyString c_str class method", "[c_str+]")
{
	SECTION("c_str_OfNonEmptyString_ShouldReturnProperString")
	{
		//Arrange
		MyString s("Hello");
		bool areEqual = true;
		unsigned sSize = s.size();

		//Act
		const char* copy = s.c_str();
		for (size_t i = 0; i < sSize; i++)
		{
			if (copy[i] != s[i])
			{
				areEqual = false;
			}
		}

		//Assert
		REQUIRE(areEqual == true);
	}

	SECTION("c_str_OfNonEmptyString_ShouldHaveTheSameSizeAsTheSource")
	{
		//Arrange
		MyString s("Hello");
		unsigned srcSize = s.size();

		//Act
		const char* copy = s.c_str();
		unsigned copyLen = strlen(copy);

		//Assert
		REQUIRE(copyLen == srcSize);
	}
}

TEST_CASE("MyString operator==", "[operator==]")
{
	SECTION("operator==_SameStrings_True")
	{
		//Arrange
		MyString s("Hello");
		MyString t("Hello");

		//Act
		bool areEqual = s == t;

		//Assert
		REQUIRE(areEqual == true);
	}

	SECTION("operator==_DifferentStrings_False")
	{
		//Arrange
		MyString s("Hello");
		MyString t("Hey");

		//Act
		bool areEqual = s == t;

		//Assert
		REQUIRE(areEqual == false);
	}

	SECTION("operator==_EmptyStrings_True")
	{
		//Arrange
		MyString s("");
		MyString t("");

		//Act
		bool areEqual = s == t;

		//Assert
		REQUIRE(areEqual == true);
	}

	SECTION("operator==_AddOneCharThenRemoveIt_True")
	{
		//Arrange
		MyString s("a");
		MyString t("a");

		//Act
		s.push_back('!');
		s.pop_back();
		bool areEqual = s == t;

		//Assert
		REQUIRE(areEqual == true);
	}
}

TEST_CASE("MyString operator<", "[operator<]")
{
	SECTION("operator<_StringThatPrecedesIt_False")
	{
		//Arrange
		MyString s("Ring");
		MyString t("Group");

		//Act
		bool s_precedes_t = s < t;

		//Assert
		REQUIRE(s_precedes_t == false);
	}

	SECTION("operator<_StringThatDoesntPrecedeIt_True")
	{
		//Arrange
		MyString s("Group");
		MyString t("Ring");

		//Act
		bool s_precedes_t = s < t;

		//Assert
		REQUIRE(s_precedes_t == true);
	}

	SECTION("operator<_EqualStrings_False")
	{
		//Arrange
		MyString s("Hi");
		MyString t("Hi");

		//Act
		bool s_precedes_t = s < t;

		//Assert
		REQUIRE(s_precedes_t == false);
	}

	SECTION("operator<_AddingThenRemovingSingleChar_True")
	{
		//Arrange
		MyString s("Hi");
		MyString t("Ih");

		//Act
		s.push_back('1');
		s.pop_back();
		t.pop_back();
		t.push_back('h');
		bool s_precedes_t = s < t;

		//Assert
		REQUIRE(s_precedes_t == true);
	}
}