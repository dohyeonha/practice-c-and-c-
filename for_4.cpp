#include <stdio.h>
int main(){
    int a_n, a_n_1, sum;
    a_n = a_n_1 = 1;
    sum = 0;
    printf("%d %d ", a_n_1, a_n);
    while(a_n <= 1000000){
        a_n_1 = a_n_1 + a_n;
        a_n = a_n + a_n_1;
        printf("%d %d ", a_n_1, a_n);
        sum = sum + a_n;
    }
    printf("\n The sum of the all even part is : %d", sum);
    return 0;
}