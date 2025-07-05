# expressionEvaluator
### Author: Alex Turner
#### Date : 2025-07-05

# Description
Project that includes a function that evaluates the results of simple arithmetic expressions, produced in C++

*DISCLAIMER* 
All code written in this repository is my own.
No code has been written by AI or any other development automation tool.

# Requirements
- Expressions should be parsed left to right (e.g., 1 + 3 * 4 = 16).
- Ignore whitespace between tokens.
- Handle error cases.
- Include tests that verify your implementation.
- Comment your code so that the interviewer may understand decisions you have
taken.

### Valid tokens
| Number | Only signed decimal integers (0-9). | 
| --- | --- |
| ( ) | Nested expressions should be evaluated first. | 
| +, -, *, / | Basic operators: addition, subtraction, multiplication and division. | 

### Function prototype
```c++
bool evaluate(const char *expression, int &result);
// Returns true on success and stores the result in result.
// Returns false on error.
```

### Example test cases
|Input               | Expected result | Return value |
|       ---          |       ---       |    ---       |
|1 + 3               | 4               | true         |
|(1 + 3) * 2         | 8               | true         |
|(4 / 2) + 6         | 8               | true         |
|4 + (12 / (1 * 2))  | 10              | true         |
|(1 + (12 * 2)       | N/A             | false        |
