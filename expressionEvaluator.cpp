/* 
 * File: expressionEvaluator.cpp
 * Author: Alex Turner
 * Description: This file contains the implementation of the expression evaluator.
 * It provides functions to evaluate mathematical expressions represented as strings.
 * The expressions can include integers, basic arithmetic operations (+, -, *, /), and parentheses.
 */

// Include necessary headers
#include "expressionEvaluator.hpp"
#include "constants.hpp"


// This function checks if the expression is valid.
// It should return true if the expression is valid and false otherwise.
int isValidExpression(const char* expression)
{
    if (expression == 0 || *expression == '\0')
    {
        return false; // Empty expression is not valid
    }

    // We need to count the components as we parse the expression
    int openParenCount = 0;      // Count of open parentheses
    int closeParenCount = 0;     // Count of close parentheses
    int numCount = 0;          // Count of numbers (digits)
    int operatorCount = 0;       // Count of operators (arithmetic symbols)
    const char* ch = expression; // Use const pointer for iteration

    // Check for valid characters and balanced parentheses
    // We will iterate through the expression and check for valid characters
    while (*ch && *ch != '\0')
    {
        // Check for valid numbers first
        if (*ch >= '0' && *ch <= '9')
        {
            numCount++; // Increment count for digits
            ch++;     // Move to next character
            continue; // Valid digit, continue checking
        }

        // If we reach here, the character is not a digit, so we check for operators and parentheses
        switch (*ch)
        {

            // Check for valid operators
        case '+':
        case '-':
        case '*':
        case '/':
            operatorCount++; // Increment count for operators
            // allow fallthrough to check next character

        // Check for whitespaces
        case ' ':
            ch++;     // Move to next character
            continue; // Valid character, continue checking

            // Check for parentheses
        case '(':
            openParenCount++; // Increment count for open parentheses
            ch++;             // Move to next character
            continue;         // Valid character, continue checking
        case ')':
            closeParenCount++; // Increment count for close parentheses
            if (closeParenCount > openParenCount)
            {
                return ERROR::UNMATCHED_PAREN; // More closing parentheses than opening ones
            }
            ch++;     // Move to next character
            continue; // Valid character, continue checking

            // If we encounter any other character, we return an error code
        default:
            return ERROR::INVALID_CHARACTER; // Invalid character found
        }
    }
}


// This function evaluates the expression and returns the result in 'result'.
// It returns true if the expression is valid and false otherwise.
int evaluate(const char* expression, int& result)
{
	// Initialize the result to 0
	result = 0;

    // First, lets check if the expression is valid
	// If the expression is invalid, we will return an error code
	int errorCode = isValidExpression(expression);
	if (errorCode != ERROR::SUCCESS) return errorCode;

    // Here, we set a local pointer for parsing and space skipping
    const char* exprPtr = expression;

    // Skip any leading spaces
    while (*exprPtr == ' ') {
        ++exprPtr; // Move to the next character
    }
	// We now have a non-space character to start with

	// TO DO: Implement the actual evaluation logic

	// If we reach here, the expression was successfully evaluated
	return ERROR::SUCCESS;
}