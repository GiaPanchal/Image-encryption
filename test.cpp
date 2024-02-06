// Copyright 2022
// By Dr. Rykalova
// Editted by Dr. Daly
// test.cpp for PS1a
// updated 1/8/2024

#include <iostream>
#include <string>

#include "FibLFSR.hpp"
#include "PhotoMagic.hpp"

#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Main
#include <boost/test/unit_test.hpp>

using PhotoMagic::FibLFSR;

BOOST_AUTO_TEST_CASE(testStepInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
}

BOOST_AUTO_TEST_CASE(testGenerateInstr) {
  FibLFSR l("1011011000110110");
  BOOST_REQUIRE_EQUAL(l.generate(9), 51);
}

BOOST_AUTO_TEST_CASE(testOutputOperator) {
  FibLFSR l("1010101010101010");
  std::ostringstream before;
  std::ostringstream after;
  before << l;
  BOOST_REQUIRE_EQUAL(before.str(), "1010101010101010");
  l.step();
  after << l;
  BOOST_REQUIRE_EQUAL(after.str(), "0101010101010100");
}

BOOST_AUTO_TEST_CASE(testMultipleStepsAndGenerate) {
  FibLFSR l("1111000011110000");
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.step(), 0);
  BOOST_REQUIRE_EQUAL(l.step(), 1);
  BOOST_REQUIRE_EQUAL(l.generate(6), 21);
}

BOOST_AUTO_TEST_CASE(testLargeNumberOfSteps) {
  FibLFSR l("1101100111001101");
  for (int i = 0; i < 50; ++i) {
    l.step();
  }
  BOOST_REQUIRE_EQUAL(l.generate(9), 157);
}

BOOST_AUTO_TEST_CASE(testLargeGenerate) {
  FibLFSR l("0000000000000001");
  BOOST_REQUIRE_EQUAL(l.generate(23), 5762);
}

BOOST_AUTO_TEST_CASE(transform) {
  sf::Image wee;
  wee.create(1, 1);
  FibLFSR l("1100110011001100");
  PhotoMagic::transform(wee, &l);
  BOOST_REQUIRE_EQUAL(l.getReg(), "0001110000000011");
}
