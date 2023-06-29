// /*split null*/
// #include <stdio.h>
// int main(){
//     char null_1 = '\0'; // 이 3개는 모두 동일하다.
//     char null_2 = 0;
//     char null_3 = (char)NULL; // 모두 대문자로 작성한다.
    
//     char not_null = '0';  //문자(숫자) 0
    
//     printf("NULL의 정수(아스키)값 : %d, %d, %d \n", null_1, null_2, null_3);
//     printf("'0'의 정수(아스키)값 : %d ", not_null);

//     return 0;   
// }

// /* 문자열의 시작 */
// #include <stdio.h>
// int main(){
//     char sentence_1[4] = {'P', 's', 'i', '\0'};
//     char sentence_2[4] = {'P', 's', 'i', 0};
//     char sentence_3[4] = {'P', 's', 'i', (char)NULL};
//     char sentence_4[4] = {"Psi"};

//     printf("sentence_1 : %s \n", sentence_1);
//     printf("sentence_2 : %s \n", sentence_2);
//     printf("sentence_3 : %s \n", sentence_3);
//     printf("sentence_4 : %s \n", sentence_4);

//     return 0;
// }

// /*포인터 간단 복습*/
// #include <stdio.h>
// int main(){
//     char word[30] = {"long sentence"};
//     char *str = word;

//     printf("%s \n", str);

//     return 0;
// }


// /* 문자열 바꾸기*/
// #include <stdio.h>
// int main(){
//     char word[] = {"long sentence"}; // 크기 알아서 설정? : 컴파일러가 알아서 원소의 수를 세어서 빈칸을 채워 넣으라는 뜻

//     printf("조작 이전 : %s \n", word);
    
//     word[0] = 'a';
//     word[1] = 'b';
//     word[2] = 'c';
//     word[3] = 'd';

//     printf("조작 이후 : %s \n", word);

//     return 0;
// }   

// /*문자열 개수 세기*/
// #include <stdio.h>
// int length_str(char *pstr);
// int str_length(char *str);
// int main(){
//     char str[] = {"What is your name?"};
//     printf("이 문자열의 길이 : %d \n", length_str(str));
//     printf("이 문자열의 길이 : %d \n", str_length(str));

//     return 0;
// }

// int length_str(char *pstr){
//     int i = 0, length = 0;
//     while(*(pstr+i) != 0/*\0, (char)NULL*/){
//         length++;
//         i++;
//     }
//     return length;
// }
// /*강의에서 제공되는 함수*/
// int str_length(char *str){
//     int i = 0;
//     while(str[i]) i++;
    
//     return i;
// }


/*문자열 입력하기*/
#include <stdio.h>
int main(){
    char words[30];
    printf("30 자 이내의 문자열을 입력해주세요! : ");
    scanf("%s", words);  // &words 라고 쓰지 않는다 배열의 이름이 이미 주소값을 가리키기 때문!

    printf("문자열 : %s \n", words);  

    return 0;
}