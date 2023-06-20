/* 1부터 n까지 더하는 함수*/
#include <stdio.h>

int add_to_n (int number){
    int sum = 0;
    for (int i = 0; i < number; i++){
        sum += i + 1;
    }
    return sum;
}

int main(){
    int num;
    printf("1부터 어떤 숫자까지 더하고 싶습니까? : ");
    scanf("%d", &num);
    printf("결과는 %d 입니다.", add_to_n(num));

    return 0;
}