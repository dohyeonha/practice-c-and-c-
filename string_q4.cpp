/*두 개의 문자열을 입력 받아서 같다면 "같다",
 다르면 "다르다" 라고 출력하는 함수를 만들어보세요. (난이도 : 下)*/
 #include <stdio.h>
 int compare(char *a, char *b);
 int main(){
    char a[100];
    char b[100];
    
    printf("문자열을 입력하시오 : ");
    scanf("%s", a);
    printf("비교하고 싶은 문자열을 입력하시오 : ");
    scanf("%s", b);
    printf("(같으면 1 다르면 0) 결과는 : %d", compare(a,b));

    return 0;
 }

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