/*계산기를 만들어보세요. 사용자가 1 을 누르면 +, 2 를 누르면 - 와 같은 방식으로 해서 만들면 됩니다.
 물론 이전의 계산 결과는 계속 누적되어야 하고, 지우기 기능도 있어야 합니다.
  (물론 하나의 함수에 구현하는 것이 아니라 여러개의 함수로 분할해서 만들어야겠죠?)*/

#include <stdio.h>
int add(int a, int b);
int minus(int a, int b);
int multi(int a, int b);
int divide(int a, int b);
int main(){
    int op;
    int a, b;
    int result = 0;
    printf(" 계산 하고 싶은 숫자를 입력하시오: ");
    scanf("%d", &a);
    printf("\n 원하는 연산을 입력하시오(종료 0, 더하기 1, 빼기 2, 곱하기 3, 나누기 4): ");
    scanf("%d", &op);
    printf("\n 계산 하고 싶은 숫자를 입력하시오: ");
    scanf("%d", &b);
    while(op != 0){ // op = 1 이면 종료
        
        if(op == 1){
            result = add(a, b);
        }else if(op == 2){
            result = minus(a, b);
        }else if(op == 3){
            result = multi(a, b);
        }else if(op == 4){
            result = divide(a, b);
        }
        printf("결과는 : %d \n", result);
        a = result;
        printf("\n 원하는 연산을 입력하시오(종료 0, 더하기 1, 빼기 2, 곱하기 3, 나누기 4): ");
        scanf("%d", &op);
        if(op == 0) break;
        printf("\n 계산 하고 싶은 숫자를 입력하시오: ");
        scanf("%d", &b);
    }
    printf("최종 결과는 : %d", result);
    return 0;
}
int add(int a, int b){
    return a+b;
}
int minus(int a, int b){
    return a-b;
}
int multi(int a, int b){
    return a*b;
}
int divide(int a, int b){
    return a/b;
}