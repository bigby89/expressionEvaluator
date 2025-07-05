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

// Parses a parenthesis in the expression.
// This function takes a sign (1 for positive, -1 for negative), a reference to a character pointer, 
// and an integer reference to store the result.
int parseParen(const char*& expression, int& result) {

    // Move past the opening parenthesis
    ++expression;

    int parenValue = 0;

    // Parse the expression inside the parentheses
    int err = parse(expression, parenValue);

    // If there was an error, return it
    if (err) return err;

    // Skip any spaces after the expression inside parentheses
    while (*expression == ' ') {
        ++expression; // Move to the next character
    }

    // Ensure the next character is a closing parenthesis
    if (*expression != ')') return ERROR::MISSING_PAREN; // Missing closing parenthesis

    // Move past the closing parenthesis
    ++expression;

    // Set the result to the parsed value with the correct sign
    result = parenValue;

    // If we reach here, we successfully parsed a parenthesis
    return ERROR::SUCCESS;
}


// Parses the entire expression and returns the result as an integer.
// This function takes a reference to a character pointer and returns the result of the expression.
int parse(const char*& expression, int& result) {

	// Initialize the leftValue to 0
    int leftValue = 0;

    // Skip any leading spaces
    while (*expression == ' ') {
        ++expression; // Move to the next character
    }

    // If the current character is an opening parenthesis, we need to parse the expression inside it.
    if (*expression == '(') parseParen(expression, result); // Parse the expression inside parentheses
    // If we encounter a closing parenthesis without a matching opening one, it's an error
    else if (*expression == ')') return ERROR::UNMATCHED_PAREN; // Closing parenthesis without matching opening
    // If the current character is not a digit or a parethesis, it must be an invalid operator or character
    else if (*expression < '0' || *expression > '9') return ERROR::INVALID_CHARACTER; // Invalid character in expression
    else {
        // Parse the number
        int val = 0;

        // This loop will parse the digits of the number, ensuring we handle multi-digit numbers correctly
        while (*expression >= '0' && *expression <= '9') val = val * 10 + (*expression++ - '0');

        // After parsing the number, we set the leftValue to the value with the correct sign
        leftValue = val;
    }

    // Now we will parse the rest of the expression
    while (true) {

        // Skip spaces before the operator
        while (*expression == ' ') {
            ++expression; // Move to the next character
        }
        char operation = *expression;

        // If the next operation is not a valid operator, we break out of the loop
        if (operation != '*' && operation != '/' && operation != '+' && operation != '-') break;

        // If we reach here, we have a valid operator, so we move to the next character
        ++expression;

        // We now need to parse the right-hand side of the expression
        int rightValue = 0;

        // Skip any leading spaces
        while (*expression == ' ') {
            ++expression; // Move to the next character
        }

        // If the current character is an opening parenthesis, we need to parse the expression inside it.
        if (*expression == '(') parseParen(expression, result); // Parse the expression inside parentheses
        // If we encounter a closing parenthesis without a matching opening one, it's an error
        else if (*expression == ')') return ERROR::UNMATCHED_PAREN; // Closing parenthesis without matching opening
        // If the current character is not a digit or a parethesis, it must be an invalid operator or character
        else if (*expression < '0' || *expression > '9') return ERROR::INVALID_CHARACTER; // Invalid character in expression
        else {
            // Parse the number
            int val = 0;

            // This loop will parse the digits of the number, ensuring we handle multi-digit numbers correctly
            while (*expression >= '0' && *expression <= '9') val = val * 10 + (*expression++ - '0');

            // After parsing the number, we set the leftValue to the value with the correct sign
            rightValue = val;
        }

        // Now we can perform the operation on the left and right values
        // We will handle multiplication and division first, as they have higher precedence
        while (operation == '*' || operation == '/') {
            if (operation == '*') leftValue *= rightValue;
            else {
                if (rightValue == 0) return ERROR::DIV_BY_ZERO; // Division by zero error
                leftValue /= rightValue;
            }

            // After handling multiplication or division, we need to check for the next operator
            while (*expression == ' ') {
                ++expression; // Move to the next character
            }
            operation = *expression;

            // If the next operation is not a valid operator, we break out of the loop
            if (operation != '*' && operation != '/') break;

            // If we reach here, we have a valid operator, so we move to the next character
            ++expression;

            // Skip any leading spaces
            while (*expression == ' ') {
                ++expression; // Move to the next character
            }

            // If the current character is an opening parenthesis, we need to parse the expression inside it.
            if (*expression == '(') parseParen(expression, result); // Parse the expression inside parentheses
            // If we encounter a closing parenthesis without a matching opening one, it's an error
            else if (*expression == ')') return ERROR::UNMATCHED_PAREN; // Closing parenthesis without matching opening
            // If the current character is not a digit or a parethesis, it must be an invalid operator or character
            else if (*expression < '0' || *expression > '9') return ERROR::INVALID_CHARACTER; // Invalid character in expression
            else {
                // Parse the number
                int val = 0;

                // This loop will parse the digits of the number, ensuring we handle multi-digit numbers correctly
                while (*expression >= '0' && *expression <= '9') val = val * 10 + (*expression++ - '0');

                // After parsing the number, we set the leftValue to the value with the correct sign
                rightValue = val;
            }
        }

        // Now we handle addition and subtraction, which have lower precedence
        if (operation == '+') leftValue += rightValue;
        else if (operation == '-') leftValue -= rightValue;
    }

    // If we reach here, the expression was successfully parsed
    result = leftValue;
    return ERROR::SUCCESS;
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