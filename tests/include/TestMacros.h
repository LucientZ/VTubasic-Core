#ifndef TEST_MACROS_H
#define TEST_MACROS_H

#include <iostream>
#include <cstdlib>
#include <vector>

#define ASSERT(condition)\
do {\
    if(!(condition)) {\
        std::cerr << "Assertion False\n"\
                  << "Location: " << __FILE__ << ':' << __LINE__ << '\n'\
                  << "Condition: " << #condition << '\n';\
        throw std::runtime_error(__func__);\
    }\
} while(0)

#define ASSERT_THROWS(expression)\
do {\
    bool caught = false;\
    try {\
        expression;\
    }\
    catch (...) {\
        caught = true;\
    }\
    if(!caught) {\
        std::cerr << "Did not throw.\n"\
                  << "Location: " << __FILE__ << ':' << __LINE__ << '\n'\
                  << "Expression: " << #expression << '\n';\
        throw std::runtime_error(__func__);\
    }\
} while(0)

#define ASSERT_THROWS_EXCEPTION(expression, ExceptionType)\
do {\
    bool caught = false;\
    try {\
        expression;\
    }\
    catch (const ExceptionType&) {\
        caught = true;\
    }\
    if(!caught) {\
        std::cerr << "Did not throw.\n"\
                  << "Location: " << __FILE__ << ':' << __LINE__ << '\n'\
                  << "Expression: " << #expression << '\n';\
        throw std::runtime_error(__func__);\
    }\
} while(0)


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

inline static void runAllTests() {
    unsigned int failures = 0;
    for (auto test: getTestFunctions()) {
        try {
            test();
        }
        catch(const std::runtime_error& e) {
            std::cerr << "Failed Test Function: " << e.what() << '\n';
            std::cerr << "\n======================\n\n";
            failures++;
        }
    }
    if (failures != 0) {
        std::cerr << "Failed " << failures << " test functions!" << std::endl;
        std::abort();
    }
}

#endif
