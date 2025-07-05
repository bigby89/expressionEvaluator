/*
 * File: expressionEvaluator_tests.cpp
 * Author: Alex Turner
 * Description: This file contains the functional unit tests for the expression evaluator.
 */

 // Include necessary headers
#include "../expressionEvaluator.hpp"
#include "../constants.hpp"
#include "testData.hpp"
#include <iostream>
using namespace std;

// Function pointer types for the isValidExpression test function
typedef int (*IsValidExpressionFunction)(const char*);
typedef int (*ParseFunction)(const char*&, int&);
typedef void (*SkipSpacesFunction)(const char*&);
typedef int (*EvaluateFunction)(const char*, int&);

// Overloaded runTests function for isValidExpression function
int runTests(IsValidExpressionFunction func, char* title, int iter, bool isValidTest) {
    cout << endl << "----------------------------------------" << endl;
    cout << "Running test: " << title << endl;
    cout << "----------------------------------------" << endl;
    for (size_t i = 0; i < iter; ++i) {
        if (isValidTest) {
            const char* expression = testData::getValidExpressions(i);
            // Check if the function evaluates the expression successfully
            if (func(expression) == ERROR::SUCCESS) {
                cout << "Test " << i + 1 << ": '" << expression << "' is valid." << endl;
            }
            else {
                cout << "Test " << i + 1 << ": '" << expression << "' is invalid." << endl;
                return ERROR::PARSE_ERROR;
            }
        }
        else {
            const char* expression = testData::getInvalidExpressions(i);
            // Check if the function evaluates the expression successfully
            if (func(expression) != ERROR::SUCCESS) {
                cout << "Test " << i + 1 << ": '" << expression << "' is invalid as expected." << endl;
            }
            else {
                cout << "Test " << i + 1 << ": '" << expression << "' is valid, but it should be invalid." << endl;
                return ERROR::PARSE_ERROR;
            }
        }
    }
    return ERROR::SUCCESS;
}

// Overloaded runTests function for parse function
int runTests(ParseFunction func, char* title, int iter) {
    cout << endl << "----------------------------------------" << endl;
    cout << "Running test: " << title << endl;
    cout << "----------------------------------------" << endl;
    for (size_t i = 0; i < iter; ++i) {
        const char* expression = testData::getValidExpressions(i);
        int expectedResult = testData::getExpectedResults(i);
        const char* currentChar = expression;
        int result = 0;

        // Check if the function parses the expression successfully
        if (func(currentChar, result) == ERROR::SUCCESS && result == expectedResult && *currentChar == '\0') {
            cout << "Test " << i + 1 << ": '" << expression << "' parsed successfully with result: "
                << result << endl;
        }
        else {
            cout << "Test " << i + 1 << ": '" << expression << "' failed. Expected: "
                << expectedResult << ", Got: " << result << endl;
            return ERROR::PARSE_ERROR;
        }
    }
    return ERROR::SUCCESS;
}

// Overloaded runTests function for skipSpaces function
int runTests(SkipSpacesFunction func, char* title, int iter) {
    cout << endl << "----------------------------------------" << endl;
    cout << "Running test: " << title << endl;
    cout << "----------------------------------------" << endl;
    for (size_t i = 0; i < iter; ++i) {
        const char* spaces = testData::getTestSpaces(i);
        int expectedSpaces = testData::getExpectedSpaces(i);

        const char* currentChar = spaces;
        func(currentChar);
        int spacesSkipped = currentChar - spaces;
        // Check if the function skips the expected number of spaces
        if (spacesSkipped == expectedSpaces) {
            cout << "Test " << i + 1 << ": '" << spaces << "' skipped successfully with count: "
                << spacesSkipped << endl;
        }
        else {
            cout << "Test " << i + 1 << ": '" << spaces << "' failed. Expected: "
                << expectedSpaces << ", Got: " << spacesSkipped << endl;
            return ERROR::PARSE_ERROR;
        }
    }
    return ERROR::SUCCESS;
}

// Overloaded runTests function for evaluate function
int runTests(EvaluateFunction func, char* title, int iter) {
    cout << endl << "----------------------------------------" << endl;
    cout << "Running test: " << title << endl;
    cout << "----------------------------------------" << endl;
    for (size_t i = 0; i < iter; ++i) {
        const char* expression = testData::getValidExpressions(i);
        int expectedResult = testData::getExpectedResults(i);
        int result = 0;
        // Check if the function evaluates the expression successfully
        if (func(expression, result) == ERROR::SUCCESS && result == expectedResult) {
            cout << "Test " << i + 1 << ": '" << expression << "' passed with result: " << result << endl;
        }
        else {
            cout << "Test " << i + 1 << ": '" << expression << "' failed. Expected: "
                << expectedResult << ", Got: " << result << endl;
            return ERROR::PARSE_ERROR;
        }
    }
    return ERROR::SUCCESS;
}

// This is the main function that runs all the tests
int main(int, char**) {  

    // Print a message indicating the start of the tests
    cout << endl;
	cout << "----------------------------------------" << endl;
	cout << "Running Expression Evaluator Tests..." << endl;
    cout << "----------------------------------------" << endl;

    // Tests for valid expressions
    if (runTests(isValidExpression, "Test Valid Expressions", testData::NUM_TEST_EXPRESSIONS, 1) == ERROR::SUCCESS) {
        cout << "All valid expression tests passed successfully!" << endl;
    }
    else {
        cout << "Some valid expression tests failed." << endl;
        return ERROR::PARSE_ERROR;
    }
    // Tests for invalid expressions
    if (runTests(isValidExpression, "Test Invalid Expressions", testData::NUM_TEST_EXPRESSIONS, 0) == ERROR::SUCCESS) {
        cout << "All invalid expression tests passed successfully!" << endl;
    }
    else {
        cout << "Some invalid expression tests failed." << endl;
        return ERROR::PARSE_ERROR;
    }

    // Tests for parse
    if (runTests(parse, "Test Parse Expressions", testData::NUM_TEST_EXPRESSIONS) == ERROR::SUCCESS) {
        cout << "All parse tests passed successfully!" << endl;
    }
    else {
        cout << "Some parse tests failed." << endl;
        return ERROR::PARSE_ERROR;
    }

    // Tests for skipSpaces
    if (runTests(skipSpaces, "Test Skip Spaces", testData::NUM_TEST_SPACES) == ERROR::SUCCESS) {
        cout << "All skip spaces tests passed successfully!" << endl;
    }
    else {
        cout << "Some skip spaces tests failed." << endl;
        return ERROR::PARSE_ERROR;
    }

    // Tests for evaluate with valid expressions
    if (runTests(evaluate, "Test Evaluate Valid Expressions", testData::NUM_TEST_EXPRESSIONS) == ERROR::SUCCESS) {
        cout << "All evaluate valid expressions tests passed successfully!" << endl;
    }
    else {
        cout << "Some evaluate valid expressions tests failed." << endl;
        return ERROR::PARSE_ERROR;
    }
    
    // Final message indicating all tests passed successfully
	cout << endl;
	cout << "All tests passed successfully!" << endl;
	
    // Return success code. We Win!
    return 0;  
}