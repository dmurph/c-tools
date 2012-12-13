#include "log.h"
#include "checks.h"

int called_times = 0;

int test_call() {
  called_times++;
  return 1;
}

int main() {
  logd("debug! %s", "str");
  logi("info! %s", "str");
  logw("warning! %s", "str");
  loge("error! %s", "str");
  
  CHECK_EQ(test_call(), 1, "error");
  CHECK_EQ(called_times, 1, "function called more than once!");
  
  int b = 2;
  CHECK_GT(b, 2, "This should fail.  %s test.", "format");
}