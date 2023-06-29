/*두 개의 문자열을 비교하는 함수를 만들어서 같으면 1, 다르면 0 을 리턴하게 해보세요.*/
#include <stdio.h>
int compare(char *a, char *b);
int main(){
    char a[30], b[30];
    
    printf("30자 이내의 문자열을 입력하시오. : ");
    scanf("%s", a); // 문자열 이기 때문에 &a 쓰지 않는다 a만으로도 주소를 가지고 있음
    printf("\n비교하고 싶은 문자열을 30자 이내로 쓰시오. : ");
    scanf("%s", b);
    printf("\n(같으면 1, 다르면 0) 결과는 : %d ",compare(a, b));
    
}
int compare(char *a, char *b){
    int i = 0;
    while (a[i] || b[i]){
        if(a[i] != b[i]) return 0;
        i++;
    }
    return 1;
}