//
// Created by Dominik on 30/01/2021.
//

#include <boost/test/unit_test.hpp>
#include "Snake.h"

BOOST_AUTO_TEST_SUITE(SnakeTestSuite)

    BOOST_AUTO_TEST_CASE(testSnakeBodyCreationSimple) {
        Snake noodle;
        BOOST_CHECK_EQUAL(noodle.getSegment(0).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(0).y, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(1).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(1).y, 1);
    }
    BOOST_AUTO_TEST_CASE(testSnakeBodyCreationComplex) {
        Snake noodle(3,8,3,Direction(up));
        // 0 - Noodle's head
        BOOST_CHECK_EQUAL(noodle.getSegment(0).x, 3);
        BOOST_CHECK_EQUAL(noodle.getSegment(0).y, 8);
        // 1
        BOOST_CHECK_EQUAL(noodle.getSegment(1).x, 3);
        BOOST_CHECK_EQUAL(noodle.getSegment(1).y, 7);
        // 2
        BOOST_CHECK_EQUAL(noodle.getSegment(2).x, 3);
        BOOST_CHECK_EQUAL(noodle.getSegment(2).y, 6);

        Snake noodleFriend(30,35,3,Direction(left));
        // 0 - NoodleFriend's head
        BOOST_CHECK_EQUAL(noodleFriend.getSegment(0).x, 30);
        BOOST_CHECK_EQUAL(noodleFriend.getSegment(0).y, 35);
        // 1
        BOOST_CHECK_EQUAL(noodleFriend.getSegment(1).x, 29);
        BOOST_CHECK_EQUAL(noodleFriend.getSegment(1).y, 35);
        // 2
        BOOST_CHECK_EQUAL(noodleFriend.getSegment(2).x, 28);
        BOOST_CHECK_EQUAL(noodleFriend.getSegment(2).y, 35);
    }
    BOOST_AUTO_TEST_CASE(testSnakeMovement) {
        Snake noodle(0,0,3,Direction(right));
        noodle.move(Direction(down));
        // 0 - Noodle's head
        BOOST_CHECK_EQUAL(noodle.getSegment(0).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(0).y, 1);
        // 1
        BOOST_CHECK_EQUAL(noodle.getSegment(1).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(1).y, 0);
        // 2
        BOOST_CHECK_EQUAL(noodle.getSegment(2).x, 1);
        BOOST_CHECK_EQUAL(noodle.getSegment(2).y, 0);
    }
    BOOST_AUTO_TEST_CASE(testSnakeMovement2) {
        Snake noodle(4,4,3,Direction(down));
        noodle.move(Direction(right));
        // 0 - Noodle's head
        BOOST_CHECK_EQUAL(noodle.getSegment(0).x, 5);
        BOOST_CHECK_EQUAL(noodle.getSegment(0).y, 4);
        // 1
        BOOST_CHECK_EQUAL(noodle.getSegment(1).x, 4);
        BOOST_CHECK_EQUAL(noodle.getSegment(1).y, 4);
        // 2
        BOOST_CHECK_EQUAL(noodle.getSegment(2).x, 4);
        BOOST_CHECK_EQUAL(noodle.getSegment(2).y, 5);
    }
    BOOST_AUTO_TEST_CASE(testSnakeExtending) {
        Snake noodle(0,0,3,Direction(right));
        noodle.extend(2);
        // 0 - Noodle's head
        BOOST_CHECK_EQUAL(noodle.getSegment(0).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(0).y, 0);
        // 1
        BOOST_CHECK_EQUAL(noodle.getSegment(1).x, 1);
        BOOST_CHECK_EQUAL(noodle.getSegment(1).y, 0);
        // 2
        BOOST_CHECK_EQUAL(noodle.getSegment(2).x, 2);
        BOOST_CHECK_EQUAL(noodle.getSegment(2).y, 0);
        // 3
        BOOST_CHECK_EQUAL(noodle.getSegment(3).x, 3);
        BOOST_CHECK_EQUAL(noodle.getSegment(3).y, 0);
        // 4
        BOOST_CHECK_EQUAL(noodle.getSegment(4).x, 4);
        BOOST_CHECK_EQUAL(noodle.getSegment(4).y, 0);
    }
    BOOST_AUTO_TEST_CASE(testSnakeExtending2) {
        Snake noodle(0,0,3,Direction(down));
        noodle.extend(2);
        // 0 - Noodle's head
        BOOST_CHECK_EQUAL(noodle.getSegment(0).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(0).y, 0);
        // 1
        BOOST_CHECK_EQUAL(noodle.getSegment(1).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(1).y, 1);
        // 2
        BOOST_CHECK_EQUAL(noodle.getSegment(2).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(2).y, 2);
        // 3
        BOOST_CHECK_EQUAL(noodle.getSegment(3).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(3).y, 3);
        // 4
        BOOST_CHECK_EQUAL(noodle.getSegment(4).x, 0);
        BOOST_CHECK_EQUAL(noodle.getSegment(4).y, 4);
    }
    BOOST_AUTO_TEST_CASE(testSnakeBodyCreationExceptions) {
        // snake must be at least of length 2
        BOOST_CHECK_THROW(Snake badNoodle(0,0,1,Direction(down)),SnakeException);
    }

BOOST_AUTO_TEST_SUITE_END()