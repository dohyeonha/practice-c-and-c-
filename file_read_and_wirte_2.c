// /* 파일에서 문자를 하나씩 입력 받는다.*/
// #include <stdio.h>

// int main(){
//     FILE *fp = fopen("some_data.txt", "r");
//     char c;

//     if (fp == NULL)
//     {
//         printf("file open error ! \n");
//         return 0;
//     }

//     while((c = fgetc(fp)) != EOF){
//         printf("%c", c);
//     }
// }

// /* fseek 함수 예제*/
// #include <stdio.h>
// int main(){
//     FILE *fp = fopen("some_data.txt", "r");
//     char data[10];
//     char c;

//     if (fp == NULL){
//         printf("file open error ! \n");
//         return 0;
//     }

//     fgets(data, 5, fp);
//     printf("입력 받은 데이터 : %s \n", data);
// /*입력을 받을 때 \n 이 나올 때 까지 입력을 받거나 (두번째 인자의 크기 - 1) 만큼
//   입력을 받을 때 까지 입력을 받게 됩니다.
//   왜 1 만큼 뺀 크기로 입력을 받냐면, data 에 문자열을 구성하기 위해 
//   맨 뒤에는 언제나 NULL 문자를 위한 자리를 만들어주어야 하기 때문이죠.*/
//     c = fgetc(fp);
//     printf("그 다음에 입력 받은 문자 : %c \n", c);

//     fseek(fp, -1, SEEK_CUR);

//     c = fgetc(fp);
//     printf("그렇다면 무슨 문자가? : %c \n", c);

//     fclose(fp);
// }

// /* 파일의 마지막 문자를 보기 */
// #include <stdio.h>
// int main(){
//     FILE *fp = fopen("some_data.txt", "r");
//     char data[10];
//     char c;

//     if (fp == NULL){
//         printf("file open error ! \n");
//         return 0;
//     }

//     fseek(fp, -1, SEEK_END);
//     c = fgetc(fp);
//     printf("The last character of the file : %c \n", c);
// /* 왜 한 칸 왼쪽으로 옮기냐면, 맨 끝으로 옮기게 되면 그 부분에는 EOF (파일의 끝) 을
//    나타내는 것이 들어 있기 때문에 우리가 원하는 결과가 아니게 되지요.*/
//     fclose(fp);
// }

// /* fopen 의  "r+" 인자 이용해보기*/
// #include <stdio.h>
// int main(){
//     FILE *fp = fopen("some_data.txt", "r+");
//     char data[100];
// /*
//  읽기 및 쓰기형식으로 열겠다 라는 뜻인데, 파일이 존재하지 않는다면 열지를 않겠다는 의미 입니다.
//  만일 파일이 존재한다면 파일의 내용을 지우지 않지요. 
//  반면에 뒤에서 배울 "w+" 도 "읽기 및 쓰기 형식으로 열겠다" 이지만, 이 경우 파일이 존재하지 않는다면
//  파일을 새로 만들고 파일이 존재한다면 파일의 내용을 싹 지워버리게 됩니다.*/
//     fgets(data, 100, fp);
//     printf("현재 파일에 있는 내용 : %s \n", data);

//     fseek(fp, 5, SEEK_SET);

//     fputs("is nothing on this file", fp);

//     fclose(fp);
// }


// /*특정한 파일을 입력 받아서 소문자를 대문자로, 대문자를 소문자로 바꾸는 프로그램.*/
// #include <stdio.h>
// int main(){
//     FILE *fp = fopen("some_data.txt", "r+");
//     char c;

//     if (fp == NULL){
//         printf("파일 열기를 실패하셨습니다! \n");
//         return 0;
//     }
// /* 스트림 작업에서 읽기/쓰기 를 변환할 때 에는 
// 반드시 fflush 함수를 호출하거나 fseek 이나 rewind 와 같은 함수를 호출하여 파일 위치 지정자를 
// 다시 설정해주어야 하기 때문(자세한 내용은 fopen 함수 레퍼런스를 참조)입니다. */
//     while((c = fgetc(fp)) != EOF) {
//         /* c가 대문자일 경우 */
//         if ( 65 <= c && c <= 98){
//             /*한 칸 뒤로 가서*/
//             fseek(fp, -1, SEEK_CUR);
//             /*소문자로 바뀐 c를 출력한다.*/
//             fputc( c + 32, fp);
//             /*

//             쓰기 - 읽기 모드 전환을 위해서는 무조건
//             fseek 함수와 같은 파일 위치 지정자 설정 함수들을
//             호출해야 한다.
//             fseek or fflush
//             */
//             fseek(fp, 0, SEEK_CUR);
//         }

//         /* c가 소문자일 경우*/
//         else if(97 <= c && c <= 122){
//             fseek(fp, -1, SEEK_CUR);
//             fputc( c - 32, fp);
//             fflush(fp);
//         }
//     }

//     fclose(fp);
// }

// /* fopen 의 'append' 기능 사용*/
// /*덧붙이기 형식에서는 파일의 맨 끝부분 부터 내용이 쓰여지고 앞 부분은 전혀 건들여지지 않습니다. 
// 즉, 이전에 파일에 들어가 있었던 내용들은 아주 소중하게 보호가 됩니다.*/
// #include <stdio.h>
// int main(){
//     FILE *fp = fopen("some_data.txt", "a");
//     char c;
//     if ( fp == NULL){
//         printf("파일 열기를 실패하였습니다! \n");
//         return 0;
//     }

//     /* 아래 내용이 파일 뒤에 덧붙여진다*/
//     fputs("IS ADDED HAHAHAHAHA", fp);

//     fclose(fp);
// }

// /*fscanf 이용하기*/
// #include <stdio.h>
// int main(){
//     FILE *fp = fopen("some_data.txt", "r");
//     char data[100];

//     if (fp == NULL){
//         printf("파일 열기 오류 ! \n");
//         return 0;
//     }
//     printf("---- 입력 받은 단어들 ---- \n");

//     while(fscanf(fp, "%s", data) != EOF){
//         printf("%s \n", data);
//     }
//     /*fscanf(stdin, "%s", data);
//     scanf("%s", data);                 <- 같은 내용이다.
    
//     fgets 는 \n 전까지 전부 불러오지만 fscanf는 \n 뿐만아니라 \t(tap)과 띄어쓰기 전까지 불러온다.*/

//     fclose(fp);
// }

/* 파일에서 'this' 를 'that' 으로 바꾸기*/
#include <stdio.h>
#include <string.h>

int main(){
    FILE *fp = fopen("some_data.txt", "r+");
    char data[100];

    if (fp == NULL){
        printf("파일 열기 오류! \n");
        return 0;
    }

    while (fscanf(fp, "%s", data) != EOF){
        if (strcmp(data, "this") == 0){
            fseek(fp, -(long)strlen("this"), SEEK_CUR);
            fputs("that", fp);

            fflush(fp);
        }
    }

    fclose(fp);
}