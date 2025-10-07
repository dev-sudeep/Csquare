#pragma once

#ifndef CS_MCRS_H
#define CS_MCRS_H

// Data type macros
#define string char*
#define character char
#define integer int
#define decimal double
#define boolean bool
#define pointer *

// Operators
#define and &&
#define or ||
#define not !
#define B_and &
#define B_or |
#define B_xor ^

// Comparison operators
#define equals ==
#define not_equals !=
#define greater_than >
#define less_than <
#define greater_equals >=
#define less_equals <=

// Logical macro
#define eval(expression, if_true, if_false) ((expression) ? (if_true) : (if_false))

// Stringize
#define str(x) #x

#endif // CS_MCRS_H