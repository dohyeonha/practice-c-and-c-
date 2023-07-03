// /*구조체의 도입*/
// #include <stdio.h>
// struct Human
// {
//     int age;
//     int height;
//     int weight;
// };

// int main(){
//     struct Human Psi;
//     Psi.age = 99;
//     Psi.height = 185;
//     Psi.weight = 80;

//     printf("Psi에 대한 정보 \n");
//     printf("나이    : %d \n", Psi.age);
//     printf("키      : %d \n", Psi.height);
//     printf("몸무게  : %d \n", Psi.weight);
//     return 0;
// }

// /*구조체 예제 2*/
// #include <stdio.h>
// char copy_str(char *dest, const char *src);
// struct Books{
//     char name[30]; /*책 이름*/
//     char auth[30]; /*저자 이름*/
//     char publ[20]; /*출판사 이름*/
//     int borrowed; /*빌려졌나요?*/
// };

// int main(){
//     struct Books Harry_Potter;

//     copy_str(Harry_Potter.name, "Harry Potter");
//     copy_str(Harry_Potter.auth, "J.K. Rolling");
//     copy_str(Harry_Potter.publ, "Scholastic");
//     Harry_Potter.borrowed = 0;

//     printf("책 이름 : %s \n", Harry_Potter.name);
//     printf("저자 이름 : %s \n", Harry_Potter.auth);
//     printf("출판사 이름 : %s \n", Harry_Potter.publ);

//     return 0;
// }

// char copy_str(char *dest, const char *src){
//     while(*src){
//         *dest = *src;
//         src++;
//         dest++;
//     }

//     *dest = '\0';

//     return 1;
// }

// /* 구조체 예제*/
// #include <stdio.h>
// struct Books {
//   /* 책 이름 */
//   char name[30];
//   /* 저자 이름 */
//   char auth[30];
//   /* 출판사 이름 */
//   char publ[30];
//   /* 빌려 졌나요? */
//   int borrowed;
// };
// int main() {
//   struct Books book_list[3];
//   int i;

//   for (i = 0; i < 3; i++) {
//     printf("책 %d 정보 입력 : ", i);
//     scanf("%s%s%s", book_list[i].name, book_list[i].auth, book_list[i].publ);
//     book_list[i].borrowed = 0;
//   }

//   for (i = 0; i < 3; i++) {
//     printf("------------------------------- \n");
//     printf("책 %s 의 정보\n", book_list[i].name);
//     printf("저자 : %s \n", book_list[i].auth);
//     printf("출판사 : %s \n", book_list[i].publ);

//     if (book_list[i].borrowed == 0) {
//       printf("안 빌려짐\n");
//     } else {
//       printf("빌려짐 \n");
//     }
//   }
//   return 0;
// }

// /*구조체 포인터*/
// #include <stdio.h>
// struct test
// {
//     int a, b;
// };

// int main(){
//     struct test st;
//     struct test *ptr;

//     ptr = &st;
  /* ptr 가 가리키는 구조체 변수의 a 멤버의 값을 1 로 한다*/
//     (*ptr).a = 1;
//     (*ptr).b = 2;

//     printf("st의 a 멤버 : %d \n", st.a);
//     printf("st의 b 멤버 : %d \n", st.b);

  /* ptr 가 가리키는 구조체 변수의 a 멤버의 값을 2 로 한다*/
//     ptr->a = 2;
//     ptr->b = 3;
//     printf("st의 a 멤버 : %d \n", st.a);
//     printf("st의 b 멤버 : %d \n", st.b);

//     return 0;
// }

// /*포인터 갖고 놀기*/
// #include <stdio.h>
// struct TEST {
//   int c;
// };
// int main(){
//   struct TEST t;
//   struct TEST *pt = &t;
//   /*pt가 가리키는 구조체 변수의 c 멤버의 값을 0으로 한다.*/
//   (*pt).c = 0;

//   printf("t.c : %d \n", t.c);

//   /*pt가 가리키는 구조체 변수의 c 멤버의 값을 0으로 한다.*/
//   pt->c = 1;

//   printf("t.c : %d \n", t.c);

//   return 0;
// }

// /*헷갈릴만한 예제*/
//  #include <stdio.h>
//  struct TEST
//  {
//   int c;
//   int *pointer;
//  };
 
//  int main(){
//   struct TEST t;
//   struct TEST *pt = &t;
//   int i = 0;

//   /*t의 멤버 pointer 는  i를 가리키게 된다*/
//   *t.pointer = &i;
//   /* t 의 멤버 pointer 가 가리키는 변수의 값을 3 으로 만든다*/
//   *t.pointer = 3;

//   printf("i : %d \n", i);

//   /*

//   -> 가 * 보다 우선순위가 높으므로 먼저 해석하게 된다.
//   즉,
//   (pt 가 가리키는 구조체 변수의 pointer 멤버) 가 가리키는 변수의 값을 4 로
//   바꾼다. 라는 뜻이다/

//   */

//   *pt->pointer = 4;

//   printf("i : %d \n", i);

//   return 0;

//  }

// /*구조체 포인터 연습*/
// #include <stdio.h>
// int add_one(int *a);
// struct TEST{
//   int c;
// };
// int main(){
//   struct TEST t;
//   struct TEST *pt = &t;

//   /* pt 가 가리키는 구조체 변수의 c 멤버의 값을 0 으로 한다*/
//   pt->c = 0;
//   /*
//   add_one 함수의 인자에 t 구조체 변수의 멤버 c 의 주소값을
//   전달하고 있다.
//   */
//   add_one(&t.c);
//   printf("t.c : %d \n", t.c);
//   /*
//   add_one 함수의 인자에 pt 가 가리키는 구조체 변수의 멤버 c
//   의 주소값을 전달하고 있다.

//   */
//   add_one(&pt->c);

//   printf("t.c : %d \n", t.c);

//   return 0;
// }

// int add_one(int *a){
//   *a += 1;
//   return 0;
// }

// /*구조체의 대입*/
// #include <stdio.h>
// struct TEST
// {
//   int i;
//   char c;
// };

// int main(){
//   struct TEST st, st2;

//   st.i = 1;
//   st.c = 'c';

//   st2 = st;

//   printf("st2.i : %d \n", st2.i);
//   printf("st2.c : %c \n", st2.c);

//   return 0;
// }

// #include <stdio.h>
// char copy_str(char *dest, char *src);
// struct TEST{
//   int i;
//   char str[20];
// };
// int main(){
//   struct TEST a, b;

//   b.i = 3;
//   copy_str(b.str, "hello, world"); // "hello, world" 자체로 주소를 가지고 있음을 생각하자.
  
//   a = b;

//   printf("a.str : %s \n", a.str);
//   printf("a.i : %d \n", a.i);
//   return 0;
// }
// char copy_str(char *dest, char *src){
//   while (*src){
//     *dest = *src;
//     src++;
//     dest++;
//   }
//   *dest = '\0';
//   return 1;
// }

// /*구조체를 인자로 전달하기*/ // ERROR human이 초기화 되지 않은 상황에서 함수로 인해 값을 전달 할 수 없다.
// // human이 아니라 human과는 별개인 a의 age나 gender 값이 초기화 되었던 것이다. human은 초기화되지 않았음.
// // 따라서 human 구조체 변수의 주소값을 전달해주어야 한다. 
// #include <stdio.h>
// struct TEST{
//   int age;
//   int gender;
// };
// int set_human(struct TEST a, int age, int gender);
// int main(){
//   struct TEST human;
//   set_human(human, 10, 1);
//   printf("AGE : %d // Gender : %d ", human.age, human.gender);
//   return 0;\
// }

// int set_human(struct TEST a, int age, int gender){
//   a.age = age;
//   a.gender = gender;

//   return 0;
// }

// /*구조체를 인자로 전달하기*/
// #include <stdio.h>
// struct TEST{
//   int age;
//   int gender;
// };
// int set_human(struct TEST *a, int age, int gender);
// int main(){
//   struct TEST human;
//   set_human(&human, 10, 1);
//   printf("AGE : %d // Gender : %d ", human.age, human.gender);
//   return 0;\
// }

// int set_human(struct TEST *a, int age, int gender){
//   a->age = age;
//   a->gender = gender;

//   return 0;
// }

/*살짝 업그레이드*/
#include <stdio.h>
struct TEST{
  int age;
  int gender;
  char name[20];
};
int set_human(struct TEST *a, int age, int gender, const char *name);
char copy_str(char *dest, const char *src);

int main(){
  struct TEST human;

  set_human(&human, 10, 1, "Lee");
  printf("AGE : %d // Gender : %d // Name : %s \n", human.age, human.gender, human.name);
  return 0;
}

int set_human(struct TEST *a, int age, int gender, const char *name){
  a->age = age;
  a->gender = gender;
  copy_str(a->name, name);

  return 0;
}
char copy_str(char *dest, const char *src) {
  while (*src) {
    *dest = *src;
    src++;
    dest++;
  }

  *dest = '\0';

  return 1;
}