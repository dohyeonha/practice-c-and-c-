/*자기 자신을 호출하는 함수를 이용해서 1 부터 특정한 수까지의 곱을 구하는 프로그램을 만들어보세요. (난이도 : 下)*/
#include <stdio.h>
int call_me(int *p, int N);
int main(){
    int num; // 어떤 수 까지의 곱을 구하고 싶나요.
    int result = 1;
    printf("What do you want to multiply untill something number : ");
    scanf("%d",&num);
    
    call_me(&result, num);
    printf("The result is : %d", result);
    return 0;
}
int call_me(int *p, int N){
    if(N == 0) return 0;
    *p *= N;
    // *p = *p * N;
    call_me(p, N-1); // *p = &result로 p에는 result의 주소값이 들어있음.
    return 0;
}