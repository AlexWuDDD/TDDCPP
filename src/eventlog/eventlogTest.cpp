#include "Eventlog.h"
#include "Common.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
    for(int i = 0; i < 10; ++i){
        LOG_DEBUG("DEBUG");
        LOG_INFO("MY ags is %d", 30);
        LOG_WARNING("MY ags is %d", 30);
        LOG_ERROR("MY ags is %d", 30);
        sleep(1);
    }
    return 0;
}
