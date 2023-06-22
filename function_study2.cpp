// #include <stdio.h>
// int change_val(int *pi){
//     printf("----- change_val 함수 안에서 -----\n");
//     printf("pi 의 값 : %p \n", pi);
//     printf("pi 가 가리키는 것의 값 : %d \n", *pi);

//     *pi = 3;

//     printf("----- change_val 함수 끝~~ -----\n");
//     return 0;
// }

// int main(){
//     int i = 0;

//     printf("i 변수의 주소값 : %p \n", &i);
//     printf("호출 이전 i의 값 : %d \n", i);
//     change_val(&i);
//     printf("호출 이후 i의 값 : %d \n", i);

//     return 0;
// }

// /* 두 변수의 값을 교환하는 함수*/
// #include <stdio.h>
// int swap(int *a, int *b) {
//     int temp = *a;

//     *a = *b;
//     *b = temp;

//     return 0;
// }

// int main(){
//     int i, j;

//     i = 3;
//     j = 5;

//     printf("Swap 이전 : i : %d, j : %d \n", i, j);

//     swap(&i,&j); // swap 함수 호출

//     printf("Swap 이후 : i : %d, j : %d \n", i, j);

//     return 0;
// }

// /*배열을 인자로 받아서 그 배열의 각 원소의 값을 1씩 더한다.*/
// #include <stdio.h>
// int add_number(int *parr);
// int main(){
//     int arr[3];
//     int i;

//     /* 사용자로 부터 3개의 원소를 입력 받는다.*/
//     for(i = 0; i < 3; i++){
//         scanf("%d", &arr[i]);
//     }
//     add_number(arr);

//     printf("Each element of the array : %d, %d, %d", arr[0], arr[1], arr[2]);

//     return 0;
// }
// int add_number(int *parr){
//     int i;
//     for (i = 0; i < 3; i++){
//         parr[i]++;
//     }
//     return 0;
// }

/* 입력 받은 배열의 10개의 원소들 중 최대값을 출력*/
#include <stdio.h>
/* max_number : 인자로 전달받은 크기 10인 배열로 부터 최대값을 구하는 함수*/
int max_number(int *parr);
int main(){
    int arr[10];
    int i;

    /*Get the element from the user*/
    for (i = 0; i< 10; i++){
        scanf("%d", &arr[i]);
    }

    printf("The biggest nnuber of the entered array : %d \n", max_number(arr));

    return 0;
}

int max_number(int *parr){
    int i;
    int max = parr[0];
    
    for (i = 1; i < 10; i++){
        if (parr[i] > max){
            max = parr[i];
        }
    }
    return max;
}