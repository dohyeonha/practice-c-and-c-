// /* 매크로 함수 */
// #include <stdio.h>
// #define square(x) x *x   // 아래 주석 문제를 해결하고 싶다면, #define squrae(x) (x)*(x)

// int main(int argc, char **argv){
//     printf("square(3) : %d \n", square(3)); // 만약 (3+1)을 괄호 안에 넣으면 3 + 1 * 3 + 1로 계산

//     return 0;
// }


// /* 라디안에서 도로 바꾸기*/
// #include <stdio.h>
// #define RADTODEG(x) (x) * 57.295

// int main(int argc, char **argv){
//     printf("5 rad 는 : %f 도 ", RADTODEG(5));

//     return 0;
// }

// // 문제 1/RADTODEC(5)를 하고 싶다면 제대로 print 될까?  1 / 5 * 57295 로 계산되는 문제 발생
// // 해결  #define RADTODEG(x) ((x) * 57.295)

// /* 변수의 이름 출력하기 */
// #include <stdio.h>
// #define PrintVariableName(var) printf(#var "\n");
// //#define 과 같은 전처리기 문에서만 사용되는 것 중 # 이 있는데, 어떠한 인자 앞에 # 을 붙이게 되면 이 인자를 문자열로 바꾸어 버립니다. 
// int main(){
//     int a;
//     PrintVariableName(a);

//     return 0;
// }


// /* ## 의 사용*/
// #include <stdio.h>
// #define AddName(x,y) x##y
// /*
// # 나 ## 모두 '전처리기 문' 에서만 사용할 수 있다는 것입니다. 
// 즉 #define 에서만 사용할 수 있다는 정도로만 알아두세요. 
// ## 문은 아마 짐작했지만 입력된 것을 하나로 '합쳐주는' 역할을 합니다.
// */
// int main(){
//     int AddName(a,b);

//     ab = 3;

//     printf("%d \n", ab);

//     return 0;
// }

// /* 인라인 함수*/
// // 간단한 함수는 따로 만들어 호출 시간을 늘리지 말고 인라인함수를 사용하자.
// // "똑똑한 컴파일러"가 인라인 함수를 사용한 문장 내부에서 적절하게 '우리가 보통 함수를 사용하는 것처럼' 바꿔 줍니다.
// #include <stdio.h>
// __inline int square(int a) {return a*a;}
// int main(){
//     printf("%d", square(3));

//     return 0;
// }

/* 인라인 함수 다른 예제*/
#include <stdio.h>
__inline int max(int a, int b){
    if ( a > b)
        return a;
    else
        return b;
}

int main(){
    printf("3 과 2 중 최대값은 : %d \n", max(3,2));
    printf("%d 과 %d 중 최대값은 : %d \n",3, 2, 3 > 2 ? 3 : 2 );
    return 0;
}