// /* test.c */
// #include <stdio.h>
// #include "str.h"
// int main() {
//   char str1[20];
//   char str2[20];

//   scanf("%s", str1);
//   scanf("%s", str2);

//   if (compare(str1, str2)) {
//     printf("%s 와 %s 는 같은 문장 입니다. \n", str1, str2);
//   } else {
//     printf("%s 와 %s 는 다른 문장 입니다. \n", str1, str2);
//   }
//   return 0;
// }

/*도서관리 test*/
/* test.c */
#include <stdio.h>
#include "function.h"
int main() {
  int user_choice;        /* 유저가 선택한 메뉴 */
  int num_total_book = 0; /* 현재 책의 수 */
  /* 각각 책, 저자, 출판사를 저장할 배열 생성. 책의 최대 개수는 100 권*/
  char book_name[100][30], auth_name[100][30], publ_name[100][30];
  /* 빌렸는지 상태를 표시 */
  int borrowed[100];
  while (1) {
    printf("도서 관리 프로그램 \n");
    printf("메뉴를 선택하세요 \n");
    printf("1. 책을 새로 추가하기 \n");
    printf("2. 책을 검색하기 \n");
    printf("3. 책을 빌리기 \n");
    printf("4. 책을 반납하기 \n");
    printf("5. 프로그램 종료 \n");
    printf("당신의 선택은 : ");
    scanf("%d", &user_choice);
    if (user_choice == 1) {
      /* 책을 새로 추가하는 함수 호출 */
      add_book(book_name, auth_name, publ_name, borrowed, &num_total_book);
    } else if (user_choice == 2) {
      /* 책을 검색하는 함수 호출 */
      search_book(book_name, auth_name, publ_name, num_total_book);
    } else if (user_choice == 3) {
      /* 책을 빌리는 함수 호출 */
      borrow_book(borrowed);
    } else if (user_choice == 4) {
      /* 책을 반납하는 함수 호출 */
      return_book(borrowed);
    } else if (user_choice == 5) {
      /* 프로그램을 종료한다. */
      break;
    }
  }
  return 0;
}