#ifndef CHECKS_H
#define CHECKS_H

#define CHECK_PRINT_STREAM stdout

// hook debugger to this
void print_check_result(const char* file,
                        int line,
                        const char* function,
                        const char* expression,
                        const char* op,
                        const char* value,
                        double eval,
                        double vval,
                        const char* msg,
                        ...);
// hook debugger to this
void exit_from_check();

// turn expressions into doubles to allow finest granularity (need to store so we don't evaluate twice)
#define CHECK_OP(expression, op, value, msg, args...) {\
  __typeof__(expression) evaluated = (expression);\
  __typeof__(value) expected = (value);\
  if (!(evaluated op expected)) {\
    print_check_result(__FILE__, __LINE__, __FUNCTION__, #expression, #op, #value, (double)evaluated, (double)expected, msg, ## args);\
	  exit_from_check();\
  }\
}

#define CHECK(condition, msg, args...) CHECK_OP(condition, ==, 1, msg, ## args)

#define CHECK_LT(expression, value, msg, args...) CHECK_OP(expression, <, value, msg, ## args)
#define CHECK_GT(expression, value, msg, args...) CHECK_OP(expression, >, value, msg, ## args)
#define CHECK_LTE(expression, value, msg, args...) CHECK_OP(expression, <=, value, msg, ## args)
#define CHECK_GTE(expression, value, msg, args...) CHECK_OP(expression, >=, value, msg, ## args)
#define CHECK_EQ(expression, value, msg, args...) CHECK_OP(expression, ==, value, msg, ## args)
#define CHECK_NE(expression, value, msg, args...) CHECK_OP(expression, !=, value, msg, ## args)

// only prints if condition is false
#define DEXPECT(condition) if (!(condition)) { kprintf("Unexpected condition at %s:%d: \"%s\"\n", __FILE__, __LINE__, #condition); }

#define EXPECT(condition) if (!(condition)) { kprintf("Unexpected condition at %s:%d: \"%s\"\n", __FILE__, __LINE__, #condition); }

#if DEBUG_CHECKS
#define DCHECK(condition) CHECK(condition, #condition)
#define DCHECK_OP(expression, op, value) CHECK_OP(expression, op, value, "Debug Assertion")
#define DCHECK_LT(expression, value) DCHECK_OP(expression, <, value)
#define DCHECK_GT(expression, value) DCHECK_OP(expression, >, value)
#define DCHECK_LTE(expression, value) DCHECK_OP(expression, <=, value)
#define DCHECK_GTE(expression, value) DCHECK_OP(expression, >=, value)
#define DCHECK_EQ(expression, value) DCHECK_OP(expression, ==, value)
#define DCHECK_NE(expression, value) DCHECK_OP(expression, !=, value)
#else // no DEBUG_CHECKS, just stub out
#define DCHECK(condition)
#define DCHECK_OP(expression, op, value)
#define DCHECK_LT(expression, value)
#define DCHECK_GT(expression, value)
#define DCHECK_LTE(expression, value)
#define DCHECK_GTE(expression, value)
#define DCHECK_EQ(expression, value)
#define DCHECK_NE(expression, value)
#endif // DEBUG_CHECKS

#endif