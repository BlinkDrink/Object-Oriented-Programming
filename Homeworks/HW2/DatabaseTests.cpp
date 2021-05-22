#include "catch2.hpp"
#include<cassert>
#include "Database.h"

using db = Database;

TEST_CASE("database", "[Database]") {
	db::getInstance().addPersonRecord("name", 10);

	REQUIRE(db::getInstance().findPersonById(10) != nullptr);
}