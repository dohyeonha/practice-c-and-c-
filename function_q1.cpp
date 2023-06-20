/* Magic box that plus 4 at input digit*/
#include <stdio.h>
int magic_box(int output){
    output += 4;
    return output;
}
int main(){
    int input;
    printf("마술 상자에 넣고 싶은 숫자를 입력하시오 : ");
    scanf("%d", &input);
    printf("결과는 %d 입니다.", magic_box(input));

    return 0;
}