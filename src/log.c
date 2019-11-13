#include "log.h"

#include <stdarg.h>
#include <stdio.h>


void magi_log(const char * format, ...)
{
#ifdef ERRLOG
    va_list args;
    va_start(args, format);
    fputs("MAGI ERROR: ", stderr);
    vfprintf(stderr, format, args);
    fputc('\n', stderr);
    va_end(args);
#endif
}
