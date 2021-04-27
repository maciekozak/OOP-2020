//
// Created by Dominik on 25/01/2021.
//

#define BOOST_AUTO_TEST_MAIN//root of all tests suites and cases
#if defined(__GNUC__) || defined(__GNUG__)
#define BOOST_TEST_DYN_LINK //use shared boost library
#endif
#include <boost/test/unit_test.hpp>

using namespace boost::unit_test;

struct MyConfig {

    MyConfig() {
    }

    ~MyConfig() {
    }
};

BOOST_GLOBAL_FIXTURE(MyConfig);