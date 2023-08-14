/* 파일에 출력하기 */

// /* a.txt에 내용을 기록한다.*/
// #include <stdio.h>

// int main(){
//     FILE *fp;
//     fp = fopen("a.txt", "w");
//     /*
//     예를 들어 C 드라이브의 BBB 라는 폴더의 a.txt 를 원한다면 다음과 같이 하면 됩니다.
//     fp = fopen("C:\\BBB\\a.txt", "w");
//     이 때 \\ 를 쓰는 이유는 \ 하나만 쓰면
//     escape character 라고 해서 이상한 문자가 되므로 \\ 를 두개 붙여 써서 \ 로 나타내야 합니다.
//     */
//     if ( fp == NULL ){
//         printf("Write Error!!\n");
//         return 0;
//     }

//     fputs("Hello World!!! \n", fp);

//     fclose(fp);

//     return 0;
// }

// /* fgets로 a.txt에서 내용을 입력 받는다.*/
// #include <stdio.h>
// int main(){
//     FILE *fp = fopen("a.txt", "r");
//     char buf[20]; // 내용을 입력받을 곳
//     if (fp == NULL){
//         printf("Read ERROR !! \n");
//         return 0;
//     }
//     fgets(buf, 20, fp);
//     printf("입력받는 내용 : %s \n", buf);
//     fclose(fp);

//     return 0;
// }

// /* 한 글자씩 입력받기 */
// #include <stdio.h>
// int main(){
//     FILE *fp = fopen("a.txt", "r");
//     char c;
// /*문자열 맨 마지막이 NULL 문자로 종료를
//  나타내는 것 처럼,파일의 맨 마지막에는 EOF 라고
//   End Of File 을 나타내는 값인 -1 이 들어가 있습니다.
  
//   #define EOF (-1)
//   */
//     while ((c = fgetc(fp)) != EOF){
//         printf("%c", c);
//     }
//     fclose(fp);

//     return 0;
// }

// /*파일의 크기를 알아내는 프로그램*/
// #include <stdio.h>

// int main(){
//     FILE *fp = fopen("a.txt", "r");
//     int size = 0;

//     while(fgetc(fp) != EOF){
//         size++;
//     }

//     printf("The size of this FILE : %d bytes \n", size);
//     fclose(fp);
//     return 0;
// }

/* 파일 위치 지정자 file position indicator*/
// fseek(가리키는 파일 ex. fp, 얼만큼 떨어져 있나 ex. 0, 상태 SEEK_SET);
// 처음 SEEK_SET, 현재 SEEK_CUR, 맨 끝 SEEK_END 상수로 존재
// #include <stdio.h>
// int main() {
//   /* 현재 fp 에 abcdef 가 들어있는 상태*/
//   FILE *fp = fopen("a.txt", "r");
//   fgetc(fp);
//   fgetc(fp);
//   fgetc(fp);
//   fgetc(fp);
//   /* d 까지 입력받았으니 파일 위치지정자는 이제 e 를 가리키고 있다 */
//   fseek(fp, 0, SEEK_SET);
//   printf("다시 파일 처음에서 입력 받는다면 : %c \n", fgetc(fp));
//   fclose(fp);
//   return 0;
// }

// /* 출력 스트림도 마찬가지*/
// #include <stdio.h>
// int main() {
//   FILE *fp = fopen("a.txt", "w");
//   fputs("Psi is an excellent C programmer", fp);
//   fseek(fp, 0, SEEK_SET);
//   fputs("is Psi", fp);
//   fclose(fp);
//   return 0;
// }