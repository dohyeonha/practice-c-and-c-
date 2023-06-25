// /*눈돌아가는 예제*/
// #include <stdio.h>

// int pswap(int **pa, int **pb);
// int main(){
//     int a, b;
//     int *pa, *pb;

//     pa = &a;
//     pb = &b;

//     printf("pa가 가리키는 변수의 주소값 : %p \n", pa);
//     printf("pa의 주소값 : %p \n \n", &pa);
//     printf("pb가 가리키는 변수의 주소값 : %p \n", pb);
//     printf("pb의 주소값 : %p \n", &pb);

//     printf("---------- 호출 ---------- \n");
//     pswap(&pa, &pb);
//     printf("---------- 호출끝 --------- \n");
    
//     printf("pa가 가리키는 변수의 주소값 : %p \n", pa);
//     printf("pa의 주소값 : %p \n \n", &pa);
//     printf("pb가 가리키는 변수의 주소값 : %p \n", pb);
//     printf("pb의 주소값 : %p \n", &pb);
//     return 0;
// }

// int pswap (int **ppa, int **ppb){
//     int *temp = *ppa;

//     printf("ppa가 가리키는 변수의 주소값 : %p \n", ppa);
//     printf("ppb가 가리키는 변수의 주소값 : %p \n", ppb);

//     *ppa = *ppb;
//     *ppb = temp;

//     return 0;
// }


/* 2차원 배열의 각 원소를 1씩 증가시키는 함수*/
#include <stdio.h>
/* 열의 개수가 2개인 이차원 배열과, 총 행의 수를 인자로 받는다.*/
int add1_element(int (*arr)[2], int row);
int main(){
    int arr[3][2];
    int i, j;

    for (i = 0; i < 3; i++){
        for (j = 0; j < 2; j++){
            scanf("%d", &arr[i][j]);
        }
    }

    add1_element(arr, 3);

    for (i = 0; i < 3; i++){
        for (j = 0; j < 2; j++){
            printf("arr[%d][%d] : %d \n", i, j, arr[i][j]);
        }
    }
    return 0;
}

int add1_element( int (*arr)[2], int row){ /*함수의 인자에서'만' 허용
int add1_element( int (*arr)[][2], int row)*/
    int i, j;
    for (i = 0; i < row; i++){
        for (j = 0; j < 2; j++){
            arr[i][j]++;
        }
    }

    return 0;
}

/*함수 포인터*/
#include <stdio.h>

int max(int a, int b);
int main(){
    int a, b;
    int (*pmax)(int, int);
    pmax = max;

    scanf("%d %d", &a, &b);
    printf("%d \n", a);    
    printf("%d \n", b);   
    printf("max(a,b) : %d \n", max(a,b));
    printf("pmax(a,b) : %d \n", pmax(a,b));

    return 0;
}

int max(int a, int b){
    if ( a > b )
        return a;
    else    
        return b;
    return 0;
}