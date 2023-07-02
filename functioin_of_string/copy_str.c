#include <stdio.h>

char copy_str(char *dest, char *src){ //  src를 dest에 붙여넣기.
    while(*src){
        *dest = *src;
        src++;
        dest++;
    }

    *dest = '\0';

    return 1;
}