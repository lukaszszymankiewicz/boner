#ifndef MACRO_H
#define MACRO_H

#define MAX(a, b) ((a) > (b) ? (a) : (b))
#define MIN(a, b) ((a) > (b) ? (b) : (a))
#define ASSERT_RANGE(min, val, max) assert(min <= val); assert(max >= val);
#define PIX_COEF             0.5 

#endif
