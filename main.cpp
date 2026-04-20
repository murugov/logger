<<<<<<< HEAD
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
=======
#include "my_logger.h"

int main()
{
    LOG_INFO("INFO");
    LOG_DEBUG("DEBUG");
    LOG_WARNING("WARNING");
    LOG_ERROR("ERROR");
    
>>>>>>> 358babc6800b8f32bf080720032f27682e7f739f
    return 0;
}