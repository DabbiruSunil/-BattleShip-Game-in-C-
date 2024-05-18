/*
 * AllTests.h
 *
 * Created on: 08-Jan-2024
 * Author: Dabbiru Sunil
 */

#ifndef PART1TESTS_H_
#define PART1TESTS_H_

#include "Board.h"
#include <string>
#include "ConsoleView.h"

/**
 * @brief Custom assertion function to check the given condition.
 *
 * @param condition The condition to check.
 * @param failedMessage The message to display if the condition is false.
 */
void assertTrue(bool condition, std::string failedMessage);

/**
 * @brief Function to execute Part 1 tests.
 */
void part1tests();

/**
 * @brief Function to execute Part 2 tests.
 */
void part2tests();

/**
 * @brief Function to execute Part 3 tests.
 */
void part3tests();

#endif /* PART1TESTS_H_ */
