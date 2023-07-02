#include <stdio.h>
int change_size(char *str){
    while(*str){
        if(*str >= 65 && *str <= 90){ /*대문자 => 소문자*/
            *str += 32; 
        }else if(*str >= 97 && *str <= 122){ /*소문자 => 대문자*/
            *str -= 32;
        }
        str++;
    }
    return 0;
}