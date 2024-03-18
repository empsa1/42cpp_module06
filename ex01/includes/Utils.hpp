#ifndef UTILS_HPP
#define UTILS_HPP

/// Define macro to control debug mode
#ifndef DEBUG_MODE
#define DEBUG_MODE 0 // Set to 1 to enable debug mode by default
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
#define INTEGER_IMPOSSIBLE      "int: impossible\n"
#define CHAR_IMPOSSIBLE         "char: impossible\n"
#define FLOAT_IMPOSSIBLE        "float: impossible\n"
#define DOUBLE_IMPOSSIBLE       "double: impossible\n"
#define FLOAT_NEG_INFF          "float: -inff\n"
#define DOUBLE_NEG_INF          "double: -inf\n"
#define FLOAT_NANF              "float: nanf\n"
#define DOUBLE_NAN              "double: +inf\n"
#define FLOAT_POS_INFF          "float: +inff\n"
#define DOUBLE_POS_INF          "double: +inf\n"
/// DEBUG MESSAGES
#if DEBUG_MODE == 1
#define DEFAULT_CONSTRUCTOR     "[Default Constructor called]       "
#define PARAMTER_CONSTRUCTOR    "[Parameter Constructor called]     "
#define COPY_CONSTRUCTOR        "[Copy Constructor called]          "
#define DESTRUCTOR              "[Destructor called]                "
#define ASSIGMENT_OPERATOR      "[Assigment Operator called]        "
#else
#define DEFAULT_CONSTRUCTOR     ""
#define PARAMTER_CONSTRUCTOR    ""
#define COPY_CONSTRUCTOR        ""
#define DESTRUCTOR              ""
#define ASSIGMENT_OPERATOR      ""
#endif

#endif