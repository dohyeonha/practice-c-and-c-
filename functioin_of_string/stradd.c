#include <stdio.h>
int stradd(char *dest, char *src) {
  /* dest 의 끝 부분을 찾는다.*/
  while (*dest) {
    dest++;
  }

  /*
  while 문을 지나고 나면 dest 는 dest 문자열의 NULL 문자를 가리키고 있게 된다.
  이제 src 의 문자열들을 dest 의 NULL 문자 있는 곳 부터 복사해넣는다.
  */
  while (*src) {
    *dest = *src;
    src++;
    dest++;
  }

  /* 마지막으로 dest 에 NULL 추가 (왜냐하면 src 에서 NULL 이 추가 되지
   * 않았으므로) */
  *dest = '\0';

  return 1;
}