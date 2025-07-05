# tests/CMakeList.txt : CMake list for expressionEvaluator tests, include source and define

# Create a test executable for expressionEvaluator
add_executable(expressionEvaluator_tests
	"expressionEvaluator_tests.cpp"
	"../expressionEvaluator.hpp"
	"../expressionEvaluator.cpp")

# Link the test executable with the necessary libraries
add_test(NAME expressionEvaluator_tests COMMAND expressionEvaluator_tests expressionEvaluator_tests.cpp)
