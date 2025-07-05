/*
 * File: expressionEvaluator_tests.cpp
 * Author: Alex Turner
 * Description: This file contains the functional unit tests for the expression evaluator.
 */

 // Include necessary headers
#include "../expressionEvaluator.hpp"
#include "../constants.hpp"
#include <iostream>
using namespace std;

// Function pointer types for the isValidExpression test function
typedef int (*IsValidExpressionFunction)(const char*);

// Constants for test data used in the expression evaluator tests
namespace testData {

    // Constants for the number of test expressions and spaces
    static const size_t NUM_TEST_EXPRESSIONS = 8;

    // Function to get a valid expression by index
    static const char* getValidExpressions(size_t index) {
        static const char* expressions[] = {
            "1 + 2",
            "3 - 4",
            "5 *     6",
            "7",
            "9 + (10 - 11)      ",
            "(12 * 13) + (14 / 15)",
            "- 16 + 17",
            "(18 - -19)"
        };
        return expressions[index];
    }

    // Function to get the expected result for a valid expression by index
    static const int getExpectedResults(size_t index) {
        static const int expectedResults[] = { 3, -1, 30, 7, 8, 156, 1, 37 };
        return expectedResults[index];
    }
}

// Overloaded runTests function for isValidExpression function
int runTests(IsValidExpressionFunction func, char* title, int iter) {
    cout << endl << "----------------------------------------" << endl;
    cout << "Running test: " << title << endl;
    cout << "----------------------------------------" << endl;
    for (size_t i = 0; i < iter; ++i) {
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
    if (runTests(isValidExpression, "Test isValidExpression()", testData::NUM_TEST_EXPRESSIONS) == ERROR::SUCCESS) {
        cout << "All tests passed successfully!" << endl;
    }
    else {
        cout << "Some tests failed." << endl;
        return ERROR::PARSE_ERROR;
    }

    
    // Final message indicating all tests passed successfully
	cout << endl;
	cout << "All tests passed successfully!" << endl;
	
    // Return success code. We Win!
    return 0;  
}