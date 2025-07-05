/*
 * File: constants.hpp
 * Author: Alex Turner
 * Description: This file contains the constants used in the expression evaluator.
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H
#endif

 // Constants for error codes used in the expression evaluator
namespace ERROR
{
	static const int SUCCESS = 0; // Success code for successful evaluation or parsing
	static const int PARSE_ERROR = 1; // Error code for parsing error
	static const int UNMATCHED_PAREN = 2; // Error code for unmatched closing parenthesis at the end
	static const int INVALID_CHARACTER = 3; // Error code for invalid character in the expression
}