/*2 차원 배열의 각 원소에 1 을 더하는 함수의 인자는 어떤 모양일까요?*/
#include <stdio.h>
int add_number(int *parr);
int main(){ 
    int arr[3][3];
    int i, j;
    printf("Enter the elemenet of the 3 by 3 matrix : ");
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    add_number(arr[0]);
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}

int add_number(int *parr){
    for(int i = 0; i < 9; i++){
        (*(parr+i))++; // parr + i 는 주소를 한칸씩 뒤로 밀 수 있게 하기 위해서. 괄호 중요
    }
    return 0;
}