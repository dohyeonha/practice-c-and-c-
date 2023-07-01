/*길이가 최대 100 인 문자열을 하나 입력 받아서 문자열을 역순으로 출력하는 함수를 만들어보세요.
 (난이도 : 下) 예를 들어서 "abcde" 입력 --> "edcba" 출력*/
 #include <stdio.h>
 int reverse_print (char *p);
 int main(){
    char str[100];
    printf("Enter the literal that maximum length is 100. : ");
    scanf("%s", str);
    reverse_print(str);
    printf("The result of the reverse_printing is : %s", str);

    return 0;
 }

 int reverse_print(char *p){
    char str[100];  // 빈 문자열
    int i = 0;
    while(*p){
        str[i] = *p;
        p++;
        i++;  // 입력된 문자열 크기 파악 완료.
    }
    p = p - i;  // 주소값 올린거 다시 내리기.
    i -=1;      // i번째에는 '\0'이 입력되어 있음.
    while(*p){
        *p = str[i];
        p++;
        i--;
    }
    return 0;
 }