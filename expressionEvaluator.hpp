/*
* ExpressionEvaluator.hpp
* Author: Alex Turner
* Description: This file contains the declarations of the expression evaluator.
* It provides functions to evaluate mathematical expressions represented as strings.
* The expressions can include integers, basic arithmetic operations (+, -, *, /), and parentheses.
*/

#ifndef EXPRESSION_EVALUATOR_HPP
#define EXPRESSION_EVALUATOR_HPP
#endif

// This function checks if the expression is valid.
// It should return true if the expression is valid and false otherwise.
int isValidExpression(const char* expression);

// Parses a parenthesis in the expression.
// This function takes a sign (1 for positive, -1 for negative), a reference to a character pointer, 
// and an integer reference to store the result.
int parseParen(int sign, const char*& cur, int& result);

// Parses the entire expression and returns the result as an integer.
// This function takes a reference to a character pointer and returns the result of the expression.
int parse(const char*& cur, int& result);

// This function evaluates the expression and returns the result in 'result'.
// It returns true if the expression is valid and false otherwise.
int evaluate(const char* expression, int& result);
