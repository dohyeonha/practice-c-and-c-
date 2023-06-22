/* 10개의 원소들 중 최대값을 구하는 함수를 사용하여.
10개의 원소를 입력받고 그 원소를 큰 순으로 출력하시오.*/
#include <stdio.h>
int max_number(int *parr);
int arrange(int *parr);
int main(){
    int arr[10];
    int i;

    printf("Enter the 10 numbers : ");
    for(i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    printf("The biggest nnuber of the entered array : %d \n", max_number(arr));
    printf("arrange them in order of size : ");
    arrange(arr);
    return 0;
}
int max_number(int *parr){
    int max = parr[0];
    int i;
    for (i = 1; i < 10; i++){
        if(parr[i] > max){
            max = parr[i];
        }
    }
    return max;
}
int arrange(int *parr){
    int i, j, temp = 0;

    for(i = 0; i < 10; i++){
        for(j = i; j < 9; j++){
            if(parr[i] < parr[j+1]){
                temp = parr[i];
                parr[i] = parr[j+1];
                parr[j+1] = temp;
            }
        }
        printf("%d ", parr[i]);
    }
    
    return 0;
}