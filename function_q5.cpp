/* N 소인수분해 출력하기*/
#include <stdio.h>

int prime_factorization (int N){
    while(N != 1){
        for (int i = 2; i <= N; i++){
            if (N%i == 0){
                printf("%d ", i);
                N = N/i;
                for(;;){
                    if (N%i == 0){
                        printf("%d ", i);
                        N = N/i;
                    } else{break;}
                }
            }
        }
    }
    return 0;
}

int main(){
    int number;
    printf("어떤 수를 소인수 분해하고 싶습니까? : ");
    scanf("%d", &number);
    printf("결과는 다음과 같습니다. : ");
    prime_factorization(number);

    return 0;
}
