#include "logger.hpp"


LogFileName_t *LogFileNames = NULL;                                                 // improve, I want to process a lot of files
const char* verdict_strings[] = {"INFO", "DEBUG", "WARN", "ERROR"};

int LogFileOpener(const char *fname)
{
    FILE *LogFile = fopen(fname, "w");
    if (LogFile == NULL)
    {
        perror("Failed to open log file");
        return 0;
    }
    
    return 1;
}

int LogFileCloser()
{
    if (LogFile)
    {
        fclose(LogFile);
        LogFile = NULL;
        return 1;
    }
    return 0;
}

void $(FILE *stream, const char *verdict, ...)
{
    if (stream)
    {
        time_t now = time(NULL);
        struct tm *timeinfo = localtime(&now);
        char time_str[20] = {0};
        strftime(time_str, sizeof(time_str), "%Y-%m-%d %H:%M:%S", timeinfo); /*TODO: parts of second*/
        fprintf(stream, "[%s] %-5s %s:%d: ",
                time_str, verdict_strings[verdict], __FILE__, __LINE__);
        fprintf(stream, __VA_ARGS__);
        fprintf(stream, "\n"); \
        fflush(stream); \
    } \
}