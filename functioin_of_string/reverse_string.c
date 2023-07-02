#include <stdio.h>

int reverse_print(char *pstr){
    char str[100];  // 빈 문자열
    int i = 0;
    while(*pstr){
       str[i] = *pstr;
       pstr++;
       i++;  // 입력된 문자열 크기 파악 완료.
    }
    pstr = pstr - i;  // 주소값 올린거 다시 내리기.
    i -=1;      // i번째에는 '\0'이 입력되어 있음.
    while(*pstr){
        *pstr = str[i];
        pstr++;
        i--;
    }
    return 0;
}