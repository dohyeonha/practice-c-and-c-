/*문자열을 두 개 입력 받아서 먼저 입력받은 문자열에서 나중에 입력받은 문자열의 위치를 검색하는 함수를 만들어보세요.
 만일 없다면 -1 을 리턴하고 있다면 그 위치를 리턴합니다. (난이도 : 中)

예를 들어먼저 처음 입력한 것이 I_am_a_boy 이고, 나중에 입력한 것이 am 이였다면 컴퓨터는 I_am_a_boy 에서 am 의 위치를 찾는다.
 이 경우에는 am 의 위치는 2 (처음에서 세번째) 이므로 2 를 리턴한다. 만일 am 이라는 문자열이 없다면 -1 을 리턴한다.*/
 #include <stdio.h>
 int find_location(char *p1, char *p2);
 int compare(char *a, char *b);
 int main(){
    char a[100];
    char b[100];

    printf("피문자열을 입력하시오 : ");
    scanf("%s", a);
    printf("찾고 싶은 단어를 입력하시오 : ");
    scanf("%s", b);
    printf("찾고자하는 단어의 위치는(없으면 -1) : %d ", find_location(a, b));

    return 0;
 }

 int find_location(char *p1, char *p2){
    int location = 0;
    // int ok = 0; // 같은 위치 찾음.
    while(*p1){
        if(*p1 == '_') location++;

        if(*p1 == *p2){
            if(compare(p1, p2) == 1){//같으면 1, 다르면 0
                // ok++;
                return (location+1);
            }
        }
        p1++;
    }
    // if(ok == 0) return -1;
    return -1;
 }
 
 int compare(char *a, char *b){

    while(*a!=0 && *a != '_'){
        // if(*a == '_') break; // 위에 while 문에 엮으면 해결이 안됨.
        if(*a != *b){
            return 0;  // 다르면 0;
        }
        a++;
        b++;
    }
    if(*b == 0) return 1;  // 종결 위치거나 띄어쓰기 사이면... 같으면 1.
    return 0;
 }