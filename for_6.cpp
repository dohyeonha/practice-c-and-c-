#include <stdio.h>
int main(){
    // a + b + c = 2000 , a > b > c > 0모두 자연수
    // 마지막 a = 1997 b = 2 c = 1
    // 시작 if a, b, c => a, a-1, a-2 => sum = 3a -3 =2000 a= 667.6666
    // 667 + 666 + 665 = 1998
    // a는 최소 668부터 시작을 해야 불필요한 계산을 줄일 수 있다.
    int a, b, c;
    int num = 0;
    for (a = 668; a <= 1997; a++){
        for(b = 1; b < a && b < 2000 - a; b++){
            c = 2000 - a - b;
            if ( b > c && c > 0){
                num += 1;
            }
            // for(c = 1; c < b; c++){
            //     if(a+b+c == 2000){
            //         //printf("a : %d, b : %d, c : %d \n", a, b, c);
            //         num += 1;
            //     }
            // }
        }
    }
    printf("The number is : %d", num);
    return 0;
}