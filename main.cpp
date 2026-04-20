#include "logger.hpp"

#define PATH_TO_LOGFILE "message.log"

int main()
{
    if (!LogFileOpener()) {
        return 1;
    }

    LOG(INFO, "Program started");
    LOG(DEBUG, "User %s connected from %s", "John", "192.168.1.1");
    LOG(WARN, "Memory usage: %d%%", 85);
    LOG(ERROR, "Data overlow");

    LogFileCloser();
    return 0;
}