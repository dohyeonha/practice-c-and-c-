// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char **argv){
//     int sizeOfArray;
//     int *arr;

//     printf("만들고 싶은 배열의 수  : ");
//     scanf("%d", &sizeOfArray);
//     arr = (int *)malloc( sizeof(int)* sizeOfArray);
// // int arr[SizeOfArray] 와 동일한 작업을 한 크기의 배열 생성
//     free(arr);
//     return 0;
// }

//  /* 동적 할당의 활용*/
//  #include <stdio.h>
//  #include <stdlib.h>

//  int main(int argc, char **argv){
//     int student; // 입력 받고자 하는 학생 수,
//     int i, input;
//     int *score; // 학생들의 수학점수 변수
//     int sum = 0; // 총점

//     printf("학생의 수는? : ");
//     scanf("%d", &student);

//     score = (int *)malloc(student * sizeof(int));
//     // score[student];
//     for (i = 0; i < student; i++){
//         printf("학생 %d 의 점수: ", i);
//         scanf("%d", &input);
        
//         score[i] = input;
//     }
    
//     for(i = 0; i < student; i++){
//         sum += score[i];
//     }

//     printf("전체 학생 평균 점수 : %d \n", sum / student);
//     free(score);
//     return 0;
//  }
 

//  /* 2차원 배열의 동적 할당 ( 포인터 배열을 이용해서 2 차원 배열 할당하기 )*/
//  #include <stdio.h>
//  #include <stdlib.h>

//  int main(int argc, char **argv){
//     int i;
//     int x, y;
//     int **arr; // 우리는 arr[x][y] 를 만들 것이다. 

//     printf("arr[x][y]를 만들 것입니다ㅏ. \n");
//     scanf("%d %d",&x, &y);

//     arr = (int **)malloc(sizeof(int *) * x);
//     // int* 형의 원소를 x 개 가지는 1 차원 배열 생성

//     for (i = 0; i < x; i++){
//         arr[i] = (int*)malloc(sizeof(int) * y);
//     }
//     printf("생성 완료! \n");

//     for (i = 0; i < x; i++){
//         free(arr[i]);
//     }
//     free(arr);
//     return 0;
//  }
//  //ㄴ'2 차원 배열 처럼 생긴' 포인터 배열은 2 차원 배열과는 달리 함수의 인자로 손쉽게 넘길 수 있습니다.

//  /*2차원 동적 할당의 활용*/

// #include <stdio.h>
// #include <stdlib.h>

// void get_average(int **arr, int numStudent, int numSubject);

// int main(int argc, char **argv){
//     int i, j, input, sum = 0;
//     int subject, students;
//     int **arr;
//     // 우리는 arr[subject][students] 배열을 만들 것이다.
//     printf("과목 수 : ");
//     scanf("%d", &subject);

//     printf("학생의 수 : ");
//     scanf("%d", &students);

//     arr = (int **)malloc(sizeof(int *) * subject);

//     for (i = 0; i < subject; i++){
//         arr[i] = (int *)malloc(sizeof(int) * students);
//     }
//     for (i = 0; i < subject; i++){
//         printf("과목 %d 점수 -------- \n", i);

//         for(j = 0; j < students; j++){
//             printf("학생 %d 점수 입력 : ", j);
//             scanf("%d", &input);

//             arr[i][j] = input;
//         }
//     }
//     get_average(arr, students, subject);

//     for (i = 0; i < subject; i++){
//         free(arr[i]);
//     }
//     free(arr);

//     return 0;
// }

// void get_average(int **arr, int numStudent, int numSubject){
//     int i, j, sum;

//     for (i = 0; i < numSubject; i++){
//         sum = 0;
//         for (j = 0; j < numStudent; j++){
//             sum += arr[i][j];
//         }
//         printf("과목 %d 평균 점수 : %d \n", i, sum / numStudent);
//     }
// }



// // 진짜 2차원 배열 할당하기
// //int arr[height][width]  
// // int (*arr)[width] =(int(*)[width])malloc(height * width * sizeof(int));
// #include <stdio.h>
// #include <stdlib.h>

// int main() {
//   int width, height;
//   printf("배열 행 크기 : ");
//   scanf("%d", &width);
//   printf("배열 열 크기 : ");
//   scanf("%d", &height);

//   int(*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));
//   for (int i = 0; i < height; i++) {
//     for (int j = 0; j < width; j++) {
//       int data;
//       scanf("%d", &data);
//       arr[i][j] = data;
//     }
//   }
//   for (int i = 0; i < height; i++) {
//     for (int j = 0; j < width; j++) {
//       printf("%d ", arr[i][j]);
//     }
//     printf("\n");
//   }

//   free(arr);
// }


// 아래 두개의 코드의 경우 다음을 참고하자
/*만일 컴파일 오류가 발생한다면 C 컴파일러로 컴파일 되고 있는지 확인해보세요. 
비주얼 스튜디오의 경우 파일 확장자를 .c 로 지정해야하고, 
GCC 를 사용하시는 분들은 g++ 이 아니라 gcc 로 컴파일 해야 합니다.*/
// #include <stdio.h>
// #include <stdlib.h>

// void add_one(int width, int (*arr)[width], int height) {
//   for (int i = 0; i < height; i++) {
//     for (int j = 0; j < width; j++) {
//       arr[i][j]++;
//     }
//   }
// }

// void print_array(int width, int (*arr)[width], int height) {
//   for (int i = 0; i < height; i++) {
//     for (int j = 0; j < width; j++) {
//       printf("%d ", arr[i][j]);
//     }
//     printf("\n");
//   }
// }

// int main() {
//   int width, height;
//   printf("배열 행 크기 : ");
//   scanf("%d", &width);
//   printf("배열 열 크기 : ");
//   scanf("%d", &height);

//   int(*arr)[width] = (int(*)[width])malloc(height * width * sizeof(int));
//   for (int i = 0; i < height; i++) {
//     for (int j = 0; j < width; j++) {
//       int data;
//       scanf("%d", &data);
//       arr[i][j] = data;
//     }
//   }

//   printf("----- Array ----- \n");
//   print_array(width, arr, height);
//   printf("----- Add one ----- \n");
//   add_one(width, arr, height);
//   print_array(width, arr, height);

//   free(arr);
// }


// #include <stdio.h>
// #include <stdlib.h>

// void get_average(int num_student, int num_subject, int (*scores)[num_student]);

// int main(int argc, char **argv) {
//   int subject, students;

//   printf("과목 수 : ");
//   scanf("%d", &subject);

//   printf("학생의 수 : ");
//   scanf("%d", &students);

//   // students 의 값이 정해진 후에 scores 을 정의해야 한다.
//   int(*scores)[students];
//   scores = (int(*)[students])malloc(sizeof(int) * subject * students);

//   for (int i = 0; i < subject; i++) {
//     printf("과목 %d 점수 --------- \n", i);

//     for (int j = 0; j < students; j++) {
//       printf("학생 %d 점수 입력 : ", j);
//       scanf("%d", &scores[i][j]);
//     }
//   }

//   get_average(students, subject, scores);
//   free(scores);

//   return 0;
// }

// void get_average(int num_student, int num_subject, int (*scores)[num_student]) {
//   int i, j, sum;

//   for (i = 0; i < num_subject; i++) {
//     sum = 0;
//     for (j = 0; j < num_student; j++) {
//       sum += arr[i][j];
//     }
//     printf("과목 %d 평균 점수 : %d \n", i, sum / num_student);
//   }
// }