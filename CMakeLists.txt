# CMakeList.txt : CMake project for expressionEvaluator, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

# Set the C++ standard to C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set the project name and version
project ("expressionEvaluator" VERSION 1.0)

# Set the output directories for the build
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# Set the output directories for the build configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${CMAKE_BINARY_DIR}/bin/Debug)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${CMAKE_BINARY_DIR}/bin/Release)
# Set the output directories for the build configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CMAKE_BUILD_TYPE} ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE})
# Set the output directories for the build configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CMAKE_CONFIGURATION_TYPES} ${CMAKE_BINARY_DIR}/bin/${CMAKE_CONFIGURATION_TYPES})
# Set the output directories for the build configurations
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY_${CMAKE_BUILD_TYPE}_${CMAKE_CONFIGURATION_TYPES} ${CMAKE_BINARY_DIR}/bin/${CMAKE_BUILD_TYPE}_${CMAKE_CONFIGURATION_TYPES})