#include "log.h"

Log& Log::Instance()
{
    static Log instance;
    return instance;
}