// /*2-dimensional array*/
// #include <stdio.h>
// int main(){
//     int arr[3][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//     /*              {1, 2, 3,
//                      4, 5, 6,
//                      7, 8, 9}
//     */
//     int arr[3][3] = {{1,2,3},{4,5,6},{7,8,9}}; // arr 배열의 앞의 3은 지워도 정상동작한다. 다만 뒤에 3은 지우명 에러를 띄운다.
//     printf("arr 배열의 2행 3열의 수를 출력 : %d \n", arr[1][2]);
//     printf("arr 배열의 1행 2열의 수를 출력 : %d \n", arr[0][1]);
//     return 0;
// }

/*Enter the student's score.*/
#include <stdio.h>
int main(){
    int score[3][2];
    int i, j;

    for(i = 0; i < 3; i++){ // Get 3 student's score
        for( j = 0; j < 2; j++){
            if (j == 0) {
                printf("%d 번째 학생의 국어 점수 : ", i + 1);
                scanf("%d", &score[i][j]);
            }else if(j == 1) { 
                printf("%d 번째 학생의 수학 점수 : ", i + 1);
                scanf("%d", &score[i][j]);
            }
        }
    }
    for(i = 0; i < 3; i++){
        printf("%d 번째 학생의 국어 점수 : %d, 수학 점수 : %d \n", i + 1, score[i][0], score[i][1]);
    }
    return 0;
}