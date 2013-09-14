#ifndef TUT_HELPERS_H
#define TUT_HELPERS_H

#include <tut/tut.hpp>

#include <string>

class TutHelpers
{
public:
    // Strip a full file path to just the file name and extension.
    static const char* stripFileName(const char* fullFileName);
    
    // Formatted error messages.
    static std::string errorMessage(int lineNumber, const std::string& what = 0);
};

// Macro to define the basic stuff to make TUT tests.
#define DEFINE_TEST_TYPES(TEST_DATA)                                       \
    namespace tut                                                          \
    {                                                                      \
        typedef test_group<TEST_DATA> TestFactory;                         \
        typedef TestFactory::object TestRegistry;                          \
    }                                                                      \
    namespace                                                              \
    {                                                                      \
        tut::TestFactory testFactory(TutHelpers::stripFileName(__FILE__)); \
    }

// Shortcut to TutHelpers::errorMessage that tacks on the line number.
#define ERR_MSG(MSG) (TutHelpers::errorMessage(__LINE__, MSG))

// TUT wrapper macros for more descriptive output.
#define ENSURE(COND) (ensure(ERR_MSG(#COND), COND))
#define ENSURE_NOT(COND) (ensure_not(ERR_MSG("!("#COND")"), COND))
#define VALUES_EQUAL(A, B) (ensure_equals(ERR_MSG("Values not equal"), A, B))
#define DOUBLES_EQUAL(A, B, EPSILON) \
    (ensure_equals(ERR_MSG("Doubles not equal"), A, B, EPSILON))

#endif
