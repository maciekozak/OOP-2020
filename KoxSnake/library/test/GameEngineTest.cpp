//
// Created by Dominik on 25/01/2021.
//

#include <boost/test/unit_test.hpp>
#include "GameEngine.h"

BOOST_AUTO_TEST_SUITE(GameEngineTestSuite)

    BOOST_AUTO_TEST_CASE(testGameEnginetesttesting) {
    GameEngine g;
        BOOST_CHECK_NO_THROW(g.startGame(1,10,10));
    }

BOOST_AUTO_TEST_SUITE_END()
