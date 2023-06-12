#include <stdio.h>
int main(){
    int num;
    int result = 1;
    // double result = 1; 사이즈가 너무 크다면.
    printf("Enter any number you want to multiply 1 to num : ");
    scanf("%d", &num);
    for (int i = 1; i <= num; i++){
        result *= i;
        // printf("%f ",result);  사이즈가 너무 크다면.
    }
    printf("\nThe result is : %d", result);
    // printf("\nThe result is : %lf", result);  사이즈가 너무 크다면
    return 0;
}