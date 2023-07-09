#ifndef STR_H
#define STR_H

int compare(char *a, char *b){
    
    while(*a){
        if(*a != *b){
            return 0;
        }
        a++;
        b++;
    }
    if(*b == 0) return 1;  // 0대신 '\0' 또는 (char)NULL을 쓸 수도 있다.

    return 0;
}
int similar(char *a, char *b){ // a 찾고 싶은 단어, b 검색대상.  //있으면 1 없으면 0
    while(*a){
        if(*a != *b){
            return 0;
        }
        a++;
        b++;
    }
    return 1;
}
#endif