//
// Created by student on 2/1/21.
//

#include <boost/test/unit_test.hpp>
#include "Entity.h"
#include "Spike.h"
#include "Fruit.h"
#include "Apple.h"
#include "Banana.h"
#include <string>

BOOST_AUTO_TEST_SUITE(EntityTestSuite)

BOOST_AUTO_TEST_CASE(testAllEntitySpawnCheck) {
//      base "good" entity
//        Fruit fruit(10, 10, "Fruit", 10);
//        BOOST_CHECK_EQUAL(fruit.getX(), 10);
//        BOOST_CHECK_EQUAL(fruit.getY(), 10);
//        BOOST_CHECK_EQUAL(fruit.getName(), "Fruit");
//        BOOST_CHECK_EQUAL(fruit.getPointsGained(), 10);
//        BOOST_CHECK_EQUAL(fruit.isEnemy(), false);

        Spike spike (10,10, "Cactus");
        BOOST_CHECK_EQUAL(spike.getX(), 10);
        BOOST_CHECK_EQUAL(spike.getY(), 10);
        BOOST_CHECK_EQUAL(spike.getName(), "Cactus");
        BOOST_CHECK_EQUAL(spike.getPointsGained(), 0);
        BOOST_CHECK_EQUAL(spike.isEnemy(), true);

//      fruit -> apple
        Apple apple (10, 10, "apple", 10);
        BOOST_CHECK_EQUAL(apple.getX(), 10);
        BOOST_CHECK_EQUAL(apple.getY(), 10);
        BOOST_CHECK_EQUAL(apple.getName(), "apple");
        BOOST_CHECK_EQUAL(apple.getPointsGained(), 10);
        BOOST_CHECK_EQUAL(apple.isEnemy(), false);
//        BOOST_CHECK_EQUAL(apple.doesSnakeGrow(), true);

//      fruit -> banana
        Banana banana (10, 10, "banana", 10);
        BOOST_CHECK_EQUAL(banana.getX(), 10);
        BOOST_CHECK_EQUAL(banana.getY(), 10);
        BOOST_CHECK_EQUAL(banana.getName(), "banana");
        BOOST_CHECK_EQUAL(banana.getPointsGained(), 10);
        BOOST_CHECK_EQUAL(banana.isEnemy(), false);
//        BOOST_CHECK_EQUAL(banana.doesSnakeGrow(), false);
}

BOOST_AUTO_TEST_CASE(testSpikeWork) {
    // for lifetime = 10
        Spike spike (10,10, "Cactus");
        BOOST_CHECK_EQUAL(spike.isDead(), false);
        for (int i=0; i<20;i++){
            spike.increaseAgeBy1();
        }
        BOOST_CHECK_EQUAL(spike.isDead(), true);
}

BOOST_AUTO_TEST_SUITE_END()
