#include "log.h"

#include <stdio.h>
#include "stdarg.h"

void force_log_console(int priority, const char* file, int line, const char* function, const char *format, ...) {
  va_list arglist;
  va_list size_check;
  const char *loglevel;
  va_start(arglist, format);

  switch(priority) {
    case LOG_DEBUG:
      loglevel = "D ";
      break;
    case LOG_ERROR:
      loglevel = "*E ";
      break;
    case LOG_INFO:
      loglevel = "I ";
      break;
    case LOG_WARN:
      loglevel = "*W ";
      break;
    default:
      loglevel = "U ";
      break;
  }
  fprintf(LOG_OUT_STREAM, "%s", loglevel);
  if (FILE_IN_LOG) {
    fprintf(LOG_OUT_STREAM, "%s", file);
  }
  if (FUNCTION_IN_LOG) {
    fprintf(LOG_OUT_STREAM, ":%s", function);
  }
  if (LINE_IN_LOG) {
    fprintf(LOG_OUT_STREAM, ":%d", line);
  }
  fprintf(LOG_OUT_STREAM, ": ");
  vfprintf(LOG_OUT_STREAM, format, arglist);
  fprintf(LOG_OUT_STREAM, "\n");
  va_end(arglist);
}