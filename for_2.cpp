#include <stdio.h>

int main(){
    int num;
    int i, j, k;
    printf("N줄의 삼각형을 출력할 것입니다. 원하는 숫자를 입력해주세요 : ");
    scanf("%d", &num);
    for (i = 0; i < num; i++){
        for (k = 0; k < i; k++){
            printf(" ");
        }
        for (j = 0; j < 2*(num - i) - 1; j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}