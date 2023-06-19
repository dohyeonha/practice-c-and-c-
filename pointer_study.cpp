// /*Find address*/
// #include <stdio.h>
// int main(){
//     int a;
//     a = 2;

//     printf("%p \n", &a);
//     return 0;
// }


// #include <stdio.h>
// int main(){
//     int *p;
//     int a;

//     p = &a;

//     printf("포인터 p에 들어 있는 값 : %p \n", p);
//     printf("int 변수 a가 저장된 주소 : %p \n", &a);
//     return 0;
// }

// /*연산자의 이용*/
// #include <stdio.h>
// int main(){
//     int *p;
//     int a;

//     p = &a;
//     a = 2;

//     printf("The value of a : %d \n", a);
//     printf("THe value of p : %d \n", *p);   //p에 들어 있는 주소를 가리켜 2가 아웃풋으로 나온다.

//     return 0;
// }

// /* *연산자 */
// #include <stdio.h>
// int main(){
//     int *p;
//     int a;

//     p = &a;
//     *p = 3;

//     printf("The value of a : %d \n", a);
//     printf("The value of *p : %d \n", *p);

//     return 0;
// }

// /* 포인터도 변수이다.*/
// #include <stdio.h>
// int main(){
//     int a;
//     int b;
//     int *p;

//     p = &a;
//     *p = 2;
//     p = &b;
//     *p = 4;

//     printf("a : %d \n", a);
//     printf("b : %d \n", b);
//     return 0;
// }

// #include <stdio.h>
// int main(){
//     int a;
//     int* pa;
//     pa = &a;

//     printf("The value of pa : %p \n", pa); 
//     printf("The value of (pa + 1) : %p \n", pa + 1); // int형 크기인 4바이트 만큼 밀린 주소로 나온다.
    
//     return 0;
// }

// /*배열의 주소 확인*/
// #include <stdio.h>
// int main(){
//     int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int i;

//     for (i = 0; i < 10; i++){
//         printf("arr[%d]의 주소값 %p \n", i, &arr[i]);
//     }
//     return 0;
// }

// /*배열의 원소를 가리키는 포인터*/
// #include <stdio.h>
// int main(){
//     int arr[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int* parr;
//     int i;
//     parr = &arr[0];
    
//     for(i = 0; i < 10; i++){
//         printf("arr[%d] 의 주소값 : %p ", i, &arr[i]);
//         printf("(parr + %d) 의 값 : %p ", i, (parr + i));

//         if (&arr[i] == (parr + i)){
//             /*만일 parr + i 가 성공적으로 arr[i]를 가리킨다면*/
//             printf("--> 일치 \n");
//         } else {
//             printf("--> 불일치\n");
//         }
//     }
//     return 0;
// }


// /*우왕*/
// #include <stdio.h>
// int main(){
//     int arr[10] ={1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//     int* parr;
    
//     parr = &arr[0];
//     printf("arr[3] = %d, *(parr + 3) = %d \n", arr[3], *(parr + 3));
//     return 0;
// }

// /*1차원 배열 가리키기*/
// #include <stdio.h>
// int main() {
//     int arr[3] = {1,2,3};
//     int *parr;

//     parr = arr;
//     /* parr = &arr0]; 도 동일하다! */

//     printf("arr[1] : %d \n", arr[1]);
//     printf("arr[1] : %d \n", parr[1]);

//     return 0;
// }


/*포인터 이용하기*/
#include <stdio.h>
int main(){
    int arr[10] = {100,98,97,95,89,76,92,96,100,99};

    int* parr = arr;
    int sum = 0;

    while (parr - arr <= 9){ // 주소 계산을 고려해서 arr[10]을 넘지 않게 계산하려는 의도이다.
        sum += (*parr);
        parr++;
    }

    printf("내 시험 점수 평균 : %d \n", sum/10);
    return 0;
}