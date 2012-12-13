#include "checks.h"

#include <stdlib.h>
#include <stdio.h>
#include "stdarg.h"

void exit_from_check() {
  exit(EXIT_FAILURE);
}

void print_check_result(const char* file,
                        int line,
                        const char* function,
                        const char* expression,
                        const char* op,
                        const char* value,
                        double eval,
                        double vval,
                        const char* msg,
                        ...) {
  va_list arglist;
  va_start(arglist, msg);
  fprintf(CHECK_PRINT_STREAM, "Abort: %s:%d in %s, Cause: \"%s %s %s\": %f %s %f,  Msg: ",
	        file, line, function, expression, op, value, eval, op, vval);
  vfprintf(CHECK_PRINT_STREAM, msg, arglist);
  fprintf(CHECK_PRINT_STREAM, "\n");
  va_end(arglist);
}