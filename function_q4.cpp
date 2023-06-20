/* N 값을 입력받아서 1부터 N까지의 소수 출력하기*/
#include <stdio.h>

int prime (int N){
    int p = 2; // 2는 소수이다. // p = prime
    printf("%d ", p);
    int i, a;
    int total = 0;

    for( p = 3; p <= N; p++){
        a = 0;
        for ( i = 2; i < p; i++){
            if(p%2 == 0){
                a++;
                break;
            }
            if(p%i == 0){
                a++;
            }
        }
        if (a == 0){
            printf("%d ",p);
            total++;
        }
    }
    printf("\nThe number of the prime number is : %d ", total);
    return 0;
}

int main(){
    int number;
    printf("1부터 어떤 숫자까지의 소수를 출력하고 싶습니까? : ");
    scanf("%d", &number);
    printf("결과는 다음과 같습니다. : ");
    prime(number);

    return 0;
}