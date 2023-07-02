#include <stio.h>
/*문자열 길이 측정*/
int str_length(char *str){
    int i = 0;
    while(str[i]) i++;
    
    return i;
}