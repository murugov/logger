#include "my_logger.h"

// static FILE *log_file = NULL;

void log_message(int verdict, const char* file, int line, const char* message)
{
    FILE *log_file = fopen("message.log", "a");
    
    if (log_file == NULL) {
        perror("ERROR: Cannot open log file\n");
        exit(1);
    }

    time_t now = time(NULL);
    struct tm *timeinfo = localtime(&now);
    char time[20];
    strftime(time, sizeof(time), "%Y-%m-%d %H:%M:%S", timeinfo);

    if (log_file != NULL) {
        fprintf(log_file, "[%s] %-5s %s:%d: %s\n", time, verdict_strings[verdict], file, line, message);
    }

    fclose(log_file);
}