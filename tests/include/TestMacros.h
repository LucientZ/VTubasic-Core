#ifndef TEST_MACROS_H
#define TEST_MACROS_H

#include <iostream>
#include <cstdlib>

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


#endif
