// #define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <catch2/matchers/catch_matchers_exception.hpp>
#include <catch2/matchers/catch_matchers_string.hpp>
#include <catch2/matchers/catch_matchers_contains.hpp>
#include "parser.hh"

TEST_CASE("Test double linked list", "[methods]")
{
    ini_parser::Parser parser("test.ini");
    SECTION("Test simple types") {
        REQUIRE(parser.get_value<int>("Section1.var4") == 123);
        REQUIRE(parser.get_value<std::string>("Section1.var3") == "значение");
        REQUIRE(parser.get_value<std::string>("Section4.Mode").empty());
        REQUIRE(parser.get_value<double>("Section1.var1") == 1.2);
        REQUIRE(parser.get_value<bool>("Section1.var99") == false);
    }

    SECTION("Test wrong return types") {

        // return string; request number
        REQUIRE_THROWS(
            parser.get_value<std::string>("Section1.var4"),
            Catch::Matchers::Contains("wrong return types")
        );

        // return double; request string
        REQUIRE_THROWS(
            parser.get_value<double>("Section1.var3"),
            Catch::Matchers::Contains("wrong return types")
        );

        // return bool; request string
        REQUIRE_THROWS(
            parser.get_value<bool>("Section1.var3"),
            Catch::Matchers::Contains("wrong return types")
        );

    }

    // Тестирование подсказки
    SECTION("Test clues for user") {
        REQUIRE_THROWS_WITH(
            parser.get_value<std::string>("Section2.Mode"),
            Catch::Matchers::ContainsSubstring("var1") &&
            Catch::Matchers::ContainsSubstring("var2")
        );
    }
    
    SECTION("Test exceptions") {
        REQUIRE_THROWS_WITH(
            new ini_parser::Parser("test_exceptions.ini"),
            Catch::Matchers::ContainsSubstring("Not consistent section"));
    }
}