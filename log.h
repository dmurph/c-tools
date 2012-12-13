#ifndef __LOG_H__
#define __LOG_H__

#define LOG_ERROR (0x01)
#define LOG_WARN (0x02)
#define LOG_INFO (0x04)
#define LOG_DEBUG (0x08)

#define FILE_IN_LOG 1
#define FUNCTION_IN_LOG 1
#define LINE_IN_LOG 1

// change to change logging
#define LOG_MASK (LOG_DEBUG | LOG_INFO | LOG_WARN | LOG_ERROR)

#define log_level(priority, format, args...) if (priority & LOG_MASK) { force_log_console(priority, __FILE__, __LINE__, __FUNCTION__, format, ## args); }

#define logd(format, args...) log_level(LOG_DEBUG, format, ## args);
#define logi(format, args...) log_level(LOG_INFO, format, ## args);
#define logw(format, args...) log_level(LOG_WARN, format, ## args);
#define loge(format, args...) log_level(LOG_ERROR, format, ## args);

#define LOG_OUT_STREAM stdout

void force_log_console(int priority, const char* file, int line, const char* function, const char *format, ...);

#endif // __LOG_H__
