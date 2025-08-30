#ifndef LOGGER_H
#define LOGGER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

enum {INFO = 0, DEBUG, WARNING, ERROR};

const char* verdict_strings[] = {"INFO", "DEBUG", "WARN", "ERROR"};

void log_message(int verdict, const char* file, int line, const char* message);

#define LOG_INFO(message) log_message(INFO,  __FILE__, __LINE__, message)
#define LOG_DEBUG(message) log_message(DEBUG,  __FILE__, __LINE__, message)
#define LOG_WARNING(message) log_message(WARNING,  __FILE__, __LINE__, message)
#define LOG_ERROR(message) log_message(ERROR,  __FILE__, __LINE__, message)

#endif