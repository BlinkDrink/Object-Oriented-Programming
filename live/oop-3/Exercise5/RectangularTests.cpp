#define CATCH_CONFIG_MAIN // This tells Catch to provide a main() - only do this in one cpp file
#include "Rectangular.h"
#include "catch.hpp"
#include <cassert>

TEST_CASE("initRectangular() should assign propreties properly", "[initRectangular]")
{
    Rectangular r;
    Point p1 = { 3, 3 };
    Point p2 = { 15, 15 };
    initRectangular(&r, &p1, &p2);

    REQUIRE(r.p1.x == 3);
    REQUIRE(r.p1.y == 3);
    REQUIRE(r.p2.x == 15);
    REQUIRE(r.p2.y == 15);
}

TEST_CASE("checkIfPointLiesInsideRect should indicate if point lies inside", "[checkIfPointLiesInsideRect]")
{
    Rectangular r;
    Point p1 = { 3, 3 };
    Point p2 = { 15, 15 };
    initRectangular(&r, &p1, &p2);

    SECTION("should return true when point lies inside of rect")
    {
        Point inside = { 6, 7 };
        REQUIRE(liesInsideRect(&r, &inside) == true);
    }

    SECTION("should return false when point lies outside of rect")
    {
        Point inside = { -4, 2 };
        REQUIRE(liesInsideRect(&r, &inside) == false);
    }

    SECTION("should return false when point lies on the border of rect")
    {
        Point inside = { 15, 15 };
        REQUIRE(liesInsideRect(&r, &inside) == false);
    }
}

TEST_CASE("rectsOverlap should indicate if rectangles overlap", "[rectsOverlap]")
{
    SECTION("should return true when a r1's point lies inside r2")
    {
        Rectangular r1, r2;
        Point p1 = { 3, 3 };
        Point p2 = { 6, 6 };
        Point p3 = { 4, 4 };
        Point p4 = { 7, 7 };
        initRectangular(&r1, &p1, &p2);
        initRectangular(&r2, &p3, &p4);

        REQUIRE(rectsOverlap(&r1, &r2) == true);
    }

    SECTION("should return true when a r2's point lies inside r1")
    {
        Rectangular r1, r2;
        Point p1 = { 2, 8 };
        Point p2 = { 7, 5 };
        Point p3 = { 6, 10 };
        Point p4 = { 9, 7 };
        initRectangular(&r1, &p1, &p2);
        initRectangular(&r2, &p3, &p4);

        REQUIRE(rectsOverlap(&r1, &r2) == true);
    }

    SECTION("should return false when rects dont overlap")
    {
        Rectangular r1, r2;
        Point p1 = { 2, 8 };
        Point p2 = { 7, 5 };
        Point p3 = { 8, 10 };
        Point p4 = { 9, 7 };
        initRectangular(&r1, &p1, &p2);
        initRectangular(&r2, &p3, &p4);

        REQUIRE(rectsOverlap(&r1, &r2) == false);
    }

    SECTION("should return false when rects are tangent to each other but do not overlap")
    {
        Rectangular r1, r2;
        Point p1 = { 2, 8 };
        Point p2 = { 7, 5 };
        Point p3 = { 7, 10 };
        Point p4 = { 9, 7 };
        initRectangular(&r1, &p1, &p2);
        initRectangular(&r2, &p3, &p4);

        REQUIRE(rectsOverlap(&r1, &r2) == false);
    }
}