#ifndef __CONTRACTS_ENABLED__

#ifndef STRINGIFY_HELPER
#define STRINGIFY_HELPER(x) #x
#elif
#error "'STRINGIFY_HELPER' is already defined - cannot use EnableHeaders.h"
#endif

#ifndef TOSTRING
#define TOSTRING(x) STRINGIFY_HELPER(x)
#else
#error "'TOSTRING' is already defined - cannot use EnableHeaders.h"
#endif

#ifndef Expects
#define Expects(cond)                                                                              \
    if (!(cond))                                                                                   \
        throw std::runtime_error{                                                                  \
            "Contract violation: precondition failed\n  Expression : " TOSTRING(                   \
                cond) "\n  Location   : " __FILE__ ":" TOSTRING(__LINE__)};

#else
#error "'Expects' is already defined - cannot use EnableHeaders.h"
#endif

#ifndef Ensures
#define Ensures(cond)                                                                              \
    if (!(cond))                                                                                   \
        throw std::runtime_error{                                                                  \
            "Contract violation: postcondition failed\n  Expression : " TOSTRING(                  \
                cond) "\n  Location   : " __FILE__ ":" TOSTRING(__LINE__)};
#else
#error "'Ensures' is already defined - cannot use EnableHeaders.h"
#endif

#ifndef Assert
#define Assert(cond)                                                                               \
    if (!(cond))                                                                                   \
        throw std::runtime_error{"Contract violation: assertion failed\n  Expression : " TOSTRING( \
            cond) "\n  Location   : " __FILE__ ":" TOSTRING(__LINE__)};
#else
#error "'Assert' is already defined - cannot use EnableHeaders.h"
#endif

#ifndef AssertWithMessage
#define AssertWithMessage(cond, message)                                                           \
    if (!(cond))                                                                                   \
        throw std::runtime_error{"Contract violation: assertion failed\n  Expression : " TOSTRING( \
                                     cond) "\n  Location   : " __FILE__                            \
                                           ":" TOSTRING(__LINE__) "\n  Message    : " +            \
                                 (message)};
#else
#error "'AssertWithMessage' is already defined - cannot use EnableHeaders.h"
#endif

#ifndef InvalidCase
#define InvalidCase(value)                                                                         \
    throw std::runtime_error{"Invalid value (" +                                                   \
                             std::to_string(static_cast<unsigned int>(value)) +                    \
                             ") in switch statement at " __FILE__ ":" TOSTRING(__LINE__)};
#else
#error "'InvalidCase' is already defined - cannot use EnableHeaders.h"
#endif

#define __CONTRACTS_ENABLED__
#endif