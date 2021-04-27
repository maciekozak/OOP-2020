//
// Created by Dominik on 25/01/2021.
//

#include <boost/test/unit_test.hpp>


BOOST_AUTO_TEST_SUITE(TestSuiteCorrect)

    BOOST_AUTO_TEST_CASE(CorrectCase) {
        std::string a = "a";
        std::string b = "a";
        BOOST_REQUIRE_EQUAL(a, b);
    }

BOOST_AUTO_TEST_SUITE_END()