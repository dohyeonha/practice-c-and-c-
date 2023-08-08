// typedef, volatile, #pragma에 대해 알아보자
// /* typedef의 이용*/
// #include <stdio.h>
// struct HUMAN{
//     int age;
//     int height;
//     int weight;
//     int gender;
// };

// typedef struct HUMAN Human;
// int Print_Status(Human human);
// int main(){
//     Human Adam = {31, 182, 75, 0};
//     Human Eve = {27, 166, 48, 1};

//     Print_Status(Adam);
//     Print_Status(Eve);
// }

// int Print_Status(Human human){
//     if (human.gender == 0){
//         printf("MALE \n");
//     } else {
//         printf("FEMALE \n");
//     }

//     printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height, human.weight);

//     if (human.gender == 0 && human.height >= 180){
//         printf("He Is A Winner!! \n");
//     } else if (human.gender == 0 && human.height < 180){
//         printf("HE IS A LOSER!! \n");
//     }

//     printf("------------------------------------------------------ \n");

//     return 0;
// }

// typedef 의 활용 . 한번에 type을 전부 바꿔줄 수 있음 short나 char 형만 쓸 수 있는 계산기와 int도 되는 계산기 등 타입을 바꿀때
// /* 향상된 소스 코드 */
// #include <stdio.h>
// typedef int CAL_TYPE;
// int main() {
//   CAL_TYPE input;
//   CAL_TYPE a, b;

//   while (1) {
//     printf("--- 계산기 --- \n");
//     printf("1. 덧셈 \n");
//     printf("2. 뺄셈 \n");
//     printf("3. 종료 \n");

//     scanf("%d", &input);

//     if (input == 1) {
//       printf("두 수 : ");
//       scanf("%d%d", &a, &b);
//       printf("%d 와 %d 의 합 : %d \n", a, b, a + b);
//     } else if (input == 2) {
//       printf("두 수 : ");
//       scanf("%d%d", &a, &b);
//       printf("%d 와 %d 의 차 : %d \n", a, b, a - b);
//     } else
//       break;
//   }

//   return 0;
// }

// /* 여러가지 typedef 예제들 */

// #include <stdio.h>
// int add(int a, int b) { return a + b; }
// typedef int CAL_TYPE;
// typedef int (*Padd)(int, int); // Padd 라는 이름을 붙여주신다고 생각
// typedef int Arrays[10];
// int main() {
//   CAL_TYPE a = 10;
//   Arrays arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
//   Padd ptr = add;
//   printf("a : %d \n", a);
//   printf("arr[3] : %d \n", arr[3]);
//   printf("add(3, 5) : %d \n", ptr(3, 5));
//   return 0;
// }

// /* volatile 키워드 */
// //컴파일러의 최적화 옵션을 빼버리는 것입니다.
// #include <stdio.h>
// typedef struct SENSOR {
//   /* 감지 안되면 0, 감지되면 1 이다.*/
//   int sensor_flag;
//   int data;
// } SENSOR;

// int main() {
//   volatile SENSOR *sensor;
//   /* 값이 감지되지 않는 동안 계속 무한 루프를 돈다*/
//   while (!(sensor->sensor_flag)) {
//   }
//   printf("Data : %d \n", sensor->data);
// }

/* #pragma 키워드 : 컴파일러에게 말하는 전처리기 명령*/

// // pragma pack
// // https://modoocode.com/103#:~:text=%EC%99%9C%EB%83%90%ED%95%98%EB%A9%B4%20%EC%8B%A4%EC%A0%9C%EB%A1%9C%20%EB%A9%94%EB%AA%A8%EB%A6%AC%20%EC%83%81%EC%97%90%EC%84%9C%20%EC%9C%84%20%EA%B5%AC%EC%A1%B0%EC%B2%B4%EC%9D%98%20%ED%81%AC%EA%B8%B0%EB%A5%BC%208%20%EB%B0%94%EC%9D%B4%ED%8A%B8%EB%A1%9C%20%EC%BB%B4%ED%8C%8C%EC%9D%BC%EB%9F%AC%EA%B0%80%20%EC%A7%80%EC%A0%95%ED%95%98%EC%98%80%EA%B8%B0%20%EB%95%8C%EB%AC%B8%EC%9E%85%EB%8B%88%EB%8B%A4.%20%ED%98%84%EC%9E%AC%20%EC%9A%B0%EB%A6%AC%EA%B0%80%20%EC%82%AC%EC%9A%A9%ED%95%98%EB%8A%94%20%EC%BB%B4%ED%93%A8%ED%84%B0%EC%97%90%EC%84%9C%EB%8A%94%20%EC%96%B8%EC%A0%9C%EB%82%98%204%20%EB%B0%94%EC%9D%B4%ED%8A%B8%20%EB%8B%A8%EC%9C%84%EB%A1%9C%20%EB%AA%A8%EB%93%A0%20%EA%B2%83%EC%9D%84%20%EC%B2%98%EB%A6%AC%ED%95%98%EB%8A%94%20%EA%B2%83%EC%9D%B4%20%EB%B9%A0%EB%A6%85%EB%8B%88%EB%8B%A4.%20%EB%94%B0%EB%9D%BC%EC%84%9C%20%EC%96%B8%EC%A0%9C%EB%82%98%20%EC%BB%B4%ED%93%A8%ED%84%B0%EC%97%90%EC%84%9C%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%A5%BC%20%EB%B3%B4%EA%B4%80%ED%95%A0%20%EB%95%8C%20%EC%97%90%EB%8A%94%204%EC%9D%98%20%EB%B0%B0%EC%88%98%EB%A1%9C%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EB%A5%BC%20%EB%B3%B4%EA%B4%80%ED%95%98%EB%8A%94%20%EA%B2%83%EC%9D%B4%20%EC%B2%98%EB%A6%AC%EC%8B%9C%20%EC%9A%A9%EC%9D%B4%ED%95%98%EA%B2%8C%20%EB%90%A9%EB%8B%88%EB%8B%A4.%20%EC%9D%B4%EB%A0%87%EA%B2%8C%20%EB%8D%B0%EC%9D%B4%ED%84%B0%EA%B0%80%204%20%EC%9D%98%20%EB%B0%B0%EC%88%98%20%EA%B2%BD%EA%B3%84%EC%97%90%20%EB%86%93%EC%9D%B8%20%EA%B2%83%EC%9D%84%20%EB%8D%94%EB%B8%94%20%EC%9B%8C%EB%93%9C%20%EA%B2%BD%EA%B3%84%EC%97%90%20%EB%86%93%EC%97%AC%20%EC%9E%88%EB%8B%A4%20%EB%9D%BC%EA%B3%A0%20%ED%95%A9%EB%8B%88%EB%8B%A4.
// #include <stdio.h>
// /* 전처리기 명령에는 ; 를 붙이지 않는다! */
// #pragma pack(1)
// struct Weird{
//     char arr[2];
//     int i;
// };
// int main(){
//     struct Weird a;
//     printf("size of a : %d \n", sizeof(a));
//     return 0;
// }

// #pragma once 헤더파일이 두번 언급되어 중복실행되는 것을 막아줌.

// /* #pragma 의 위엄 – weird.h*/
// #pragma once
// struct Weird {
//   char arr[2];
//   int i;
// };

// /* test.c*/
// #include <stdio.h>
// #include "weird.h"
// int main() {
//   struct Weird a;
//   a.i = 3;
//   printf("Weird 구조체의 a.i : %d \n", a.i);
//   return 0;
// }

// 헤더파일을 사용하는 경우는 다음과 같다.
// 한번 .h 가 실행되면 define 된걸로 되기 때문에 ifndef 가 거짓이 됌!

// /* 수정된 weird.h*/
// #ifndef WEIRD_H
// #define WEIRD_H
// struct Weird {
//   char arr[2];
//   int i;
// };
// #endif

// /* 이상한 test.c*/
// #include <stdio.h>
// #include "weird.h"
// int main() {
//   struct Weird a;
//   a.i = 3;
//   printf("Weird 구조체의 a.i : %d \n", a.i);
//   return 0;
// }

