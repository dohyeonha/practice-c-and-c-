// /*구조체 안의 구조체*/
// #include <stdio.h>
// struct employee{
//     int age;
//     int salary;
// };
// struct company{
//     struct employee data;
//     char name[10];
// };
// int main(){
//     struct company Kim;

//     Kim.data.age = 31;
//     Kim.data.salary = 3000000;

//     printf("Kim's age : %d \n", Kim.data.age);
//     printf("Kim's salary : %d$/year \n", Kim.data.salary);

//     return 0;
// }

// /*구조체를 리턴하는 함수*/
// #include <stdio.h>
// struct AA function (int j);
// struct AA{
//     int i;
// };
// int main(){
//     struct AA a;

//     a = function(10);
//     printf("a.i : %d \n", a.i);

//     return 0;
// }

// struct AA function(int j){
//     struct AA A:
//     A.i = j;

//     return A;
// }

// /*

// 구조체 변수를 정의하는 색다른 방법.
// 예제를 이렇게 길게 만든 이유는 소스를 읽으면서 구조체와 조금 더 친해지기 바래서
// 입니다. 소스를 찬찬히 분석해보세요 ^^

// */
// #include <stdio.h>
// char copy_str(char *dest, char *src);
// int Print_Obj_Status(struct obj OBJ);
// struct obj {
//   char name[20];
//   int x, y;
// } Ball;

// int main() {
//   Ball.x = 3;
//   Ball.y = 4;
//   copy_str(Ball.name, "RED BALL");

//   Print_Obj_Status(Ball);

//   return 0;
// }
// int Print_Obj_Status(struct obj OBJ) {
//   printf("Location of %s \n", OBJ.name);
//   printf("( %d , %d ) \n", OBJ.x, OBJ.y);

//   return 0;
// }
// char copy_str(char *dest, char *src) {
//   while (*src) {
//     *dest = *src;
//     src++;
//     dest++;
//   }

//   *dest = '\0';

//   return 1;
// }


// struct HUMAN {
//   int age;
//   int height;
//   int weight;
//   int gender;
// };

// int main() {
//   struct HUMAN Adam = {31, 182, 75, 0};
//   struct HUMAN Eve = {27, 166, 48, 1};

//   Print_Status(Adam);
//   Print_Status(Eve);
// }

// int Print_Status(struct HUMAN human) {
//   if (human.gender == 0) {
//     printf("MALE \n");
//   } else {
//     printf("FEMALE \n");
//   }

//   printf("AGE : %d / Height : %d / Weight : %d \n", human.age, human.height,
//          human.weight);

//   if (human.gender == 0 && human.height >= 180) {
//     printf("HE IS A WINNER!! \n");
//   } else if (human.gender == 0 && human.height < 180) {
//     printf("HE IS A LOSER!! \n");
//   }

//   printf("------------------------------------------- \n");

//   return 0;
// }

/*열거형의 도임 ENUM*/
#include <stdio.h>
enum {RED, BLUE, WHITE, BLACK};  // By the order 0,1,2,3
// if {RED = 3, BLUE, WHITE, BLACK}; // 3,4,5,6
int main(){
    int palette = RED;
    switch (palette)
    {
    case RED:
        printf("palette : RED \n");
        break;
    case BLUE:
        printf("palette : BLUE \n");
        break;
    case WHITE:
        printf("palette : WHITE \n");
        break;
    case BLACK:
        printf("palette : WHITE \n");
        break;
    }
}