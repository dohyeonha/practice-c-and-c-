// /*전역변수 global variable*/
// #include <stdio.h>
// int global = 0;

// int function(){
//     global++;
//     return 0;
// }
// int main(){
//     global = 10;
//     function();
//     printf("%d \n", global);
//     return 0;
// }

// /* 전역 변수의 초기화 ? */
// #include <stdio.h>

// int global;
// int function() {
//   global++;
//   return 0;
// }
// int main() {
//   function();
//   printf("%d \n", global);
//   return 0;
// }

// /*함수 호출 횟수 세기*/
// #include <stdio.h>

// int how_many_called = 0;
// int function(){
//     how_many_called++;
//     printf("called : %d \n", how_many_called);

//     return 0;
// }
// int main(){
//     function();
//     function();
//     function();
//     function();
//     function();
//     return 0;
// }

// /*statoc varoable, 정적변수: 지역을 빠져나가도 파괴되지 않는 변수*/
// #include <stdio.h>
// int* function(){
//     static int a = 2;
//     return &a;
// }

// int main(){
//     int* pa = function();
//     printf("%d \n", *pa);
// }

// /* static variable의 활용*/
// #include <stdio.h>

// int function(){
//     static int how_many_called = 0;

//     how_many_called++;
//     printf("function called : %d \n", how_many_called);

//     return 0;
// }

// int function2(){
//     static int how_many_calle = 0;
//     how_many_calle++;
//     printf("function 2 called : %d \n", how_many_calle);

//     return 0;
// }
// int main(){
//     function();
//     function2();
//     function();
//     function2();
//     function2();
//     function2();
//     function();
//     function();
//     function2();
//     return 0;
// }

/*메모리의 배치 모습*/
#include <stdio.h>
int global = 3;
int main(){
    int i;
    char *str = "Hello, Baby";
    char arr[20] = "WHATTHEHECK";

    printf("global : %p \n", &global);
    printf("i : %p \n", &i);
    printf("str : %p \n", str);
    printf("arr : %p \n", arr);
}