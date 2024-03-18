#ifndef UTILS_HPP
#define UTILS_HPP

/// Define macro to control debug mode
#ifndef DEBUG_MODE
#define DEBUG_MODE 0    // Set to 1 to enable debug mode by default
#endif

///MACROS FOR FUNC RETURN VALUES MORE READABLE
#define EXITED_FUNC_WITH_SUCESS 0
#define EXITED_FUNC_WITH_ERROR 1

// /Define ANSI escape codes for text colors
#define RESET   "\033[0m"
#define RED     "\033[31m"      /* Red */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define WHITE   "\033[37m"      /* White */

/// EXCEPTIONS
#define IMPOSSIBLE_CONVERSION "Impossible"

/// CONSTANTS
#define IMPOSSIBLE              "impossible\n"
#define NEG_INFF                "float: -inff\n"
#define NEG_INF                 "-inf\n"
#define _NAN                    "nan\n"
#define POS_INFF                "+inff\n"
#define NANF                    "nanf\n"
#define NON_DISPLAYABLE         "Non displayable\n"
#define POS_INF                 "+inf\n"
#define OUT_OF_BOUNDS           "Out of bounds"
#define P_CHAR                   "char: "
#define P_FLOAT                  "float: "
#define P_INTEGER                "int: "
#define P_DOUBLE                 "double: "
#define FLOAT_ARRAY              "0123456789.f-"
#define INT_ARRAY                "0123456789.-"
#define DOUBLE_ARRAY             "0123456789.-"
#define USAGE                    "[USAGE]: ./convert <string_literal-to-convert>\n"


/// DEBUG MESSAGES
#if DEBUG_MODE == 1
#define DEFAULT_CONSTRUCTOR     "[Default Constructor called]       "
#define PARAMTER_CONSTRUCTOR    "[Parameter Constructor called]     "
#define COPY_CONSTRUCTOR        "[Copy Constructor called]          "
#define DESTRUCTOR              "[Destructor called]                "
#define ASSIGMENT_OPERATOR      "[Assigment Operator called]        "
#define INTEGER_CASE            "Inside integer case solver         "
#define DOUBLE_CASE             "Inside double case solver          "
#define SPECIAL_CASE            "Inside special case solver         "
#define FLOAT_CASE              "Inside float case solver           "
#define CHAR_CASE               "Inside char case solver            "
#else
#define CHAR_CASE               ""
#define INTEGER_CASE            ""
#define DOUBLE_CASE             ""
#define SPECIAL_CASE            ""
#define FLOAT_CASE              ""
#define DEFAULT_CONSTRUCTOR     ""
#define PARAMTER_CONSTRUCTOR    ""
#define COPY_CONSTRUCTOR        ""
#define DESTRUCTOR              ""
#define ASSIGMENT_OPERATOR      ""
#endif

#endif