#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <stdio.h>
#include <time.h>


struct LogFileName_t
{
    const char *fname;
    FILE       *stream;
};

extern LogFileName_t *x;
extern const char* verdict_strings[];

enum log_verdict_t
{
    LOG_INFO  = 0x00,
    LOG_DEBUG = 0x01,
    LOG_WARN  = 0x02, 
    LOG_ERROR = 0x03
};

int LogFileOpener(const char *fname);
int LogFileCloser(const char *fname);


#endif