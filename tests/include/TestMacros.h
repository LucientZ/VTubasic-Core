#ifndef TEST_MACROS_H
#define TEST_MACROS_H

#include <iostream>
#include <cstdlib>
#include <vector>

#define ASSERT(condition) do {\
    if(!(condition)) {\
        std::cerr << "Assertion False\n"\
                  << "File: "      << __FILE__   << '\n'\
                  << "Line: "      << __LINE__   << '\n'\
                  << "Condition: " << #condition << '\n'\
                  << "\n";\
        std::abort();\
    }\
} while(0)\


using TestFunction = void (*)();

inline std::vector<TestFunction>& getTestFunctions() {
    static std::vector<TestFunction> tests;
    return tests;
}

inline void registerTest(TestFunction fn) {
    getTestFunctions().push_back(fn);
}

#define TEST_CASE(function)\
    namespace {                              \
        const bool registered_##function = [] { \
            registerTest(&function);         \
            return true;                     \
        }();                                 \
    }

#endif
