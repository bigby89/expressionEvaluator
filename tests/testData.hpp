/*
 * File: testData.hpp
 * Author: Alex Turner
 * Description: This file contains the test data used for the expression evaluator tests.
 */

#ifndef TEST_DATA_HPP  
#define TEST_DATA_HPP  
#endif  

// Constants for test data used in the expression evaluator tests
namespace testData {  

	// Constants for the number of test expressions and spaces
    static const size_t NUM_TEST_EXPRESSIONS = 8;
	static const size_t NUM_TEST_SPACES = 20;

	// Function to get a valid expression by index
    static const char* getValidExpressions(size_t index) {  
        static const char* expressions[] = {  
            "1 + 2",  
            "3 - 4",  
            "5 *     6",  
            "7",  
            "9 + (10 - 11)      ",  
            "\t(12 * 13) + (14 / 15)",  
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

	// Function to get an invalid expression by index
    static const char* getInvalidExpressions(size_t index) {
        static const char* expressions[] = {
			"1  2",                         // Missing operator between numbers
			"(3 - 4",                       // Missing closing parenthesis
			"5 * 6)",                       // Missing opening parenthesis
			"   ",                          // Empty expression
			"9 + (10 % 11)      ",          // Invalid operator (%)
            "20 x (21 + 22)",               // Invalid operator (x)
			"-16 + &17",                    // Invalid character (&)
			"£18 - -19)",                   // Invalid character (£) and unmatched parenthesis
            "    (12 * 13) + [14 / 15]",    // Invalid brackets ([ ])
			"(31 / {2 - 33)  ) + 34"        // Invalid brackets ({ }) and unmatched parenthesis
        };
        return expressions[index];
    }

	// Function to get the expected result for an invalid expression by index
    static const char* getTestSpaces(size_t index) {
       
        static const char* spaces[] = {
			" ", "  ", "   ", "    ", "     ",  // 1 to 5 spaces
			"\t", "\n", "\r", "\f", "\v",       // 1 space with different whitespace characters
			" \t", " \n", " \r", " \f", " \v",  // 2 spaces with leading space and different whitespace characters
			"\t ", "\n ", "\r ", "\f ", "\v "   // 2 spaces with trailing space and different whitespace characters
        };
		return spaces[index];
    }  

	// Function to get the expected number of spaces for a given index
    static const int getExpectedSpaces(size_t index) {
        static const int expectedSpaces[] = {
            1, 2, 3, 4, 5,
            1, 1, 1, 1, 1, 
            2, 2, 2, 2, 2, 
            2, 2, 2, 2, 2
        };
        return expectedSpaces[index];
	}
}