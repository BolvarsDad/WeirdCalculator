#include <stdio.h>
#include <string.h>

#include "util.h"

void
putsv(char const **lines)
{
    for(int i = 0; lines[i] != NULL; ++i)
        puts(lines[i]);
}

size_t
str_write(char *dest, char const *src)
{
    size_t nwritten = strlen(src);

    strcat(dest, src);
    return nwritten;
}