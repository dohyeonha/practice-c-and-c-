#include <stdio.h>
int main(){
    /*위 입력받는 학생들의 성적을 높은 순으로 정렬하는 프로그램을 만들어 보세요.*/
    int students = 30;  // 넉넉하게 잡는다.
    int arr[students];
    int sort_score[students] = {0};  /*첫 칸 0으로 채우고 뒤에 빈자리도 0으로 채우게 된다.*/
    int i, j;
    int temp = 0;
    printf("Enter how many students there are : ");
    scanf("%d", &students);

    for (i = 0; i < students; i++){
        
        if ( i >= 2){
            printf("Enter the %dth student's score : ", i + 1);
            scanf("%d", &arr[i]);
        }
        else if (i == 0){
            printf("Enter the %dst student's score : ", i + 1);
            scanf("%d", &arr[i]);
        }
        else if (i == 1)
        {
            printf("Enter the %dnd student's score : ", i + 1);
            scanf("%d", &arr[i]);
        }

    }
    for (i = 0; i < students; i++){
        sort_score[i] = arr[i];
    }
    for (i = 0; i < students; i++){ /*sorting the array.*/
        for (j = i; j < students - 1; j++){
            if (sort_score[i] < sort_score[j+1]){
                temp = sort_score[i];
                sort_score[i] = sort_score[j+1];
                sort_score[j+1] = temp;
            }
        }
    }
    printf("The order of the larger number : ");
    for (i = 0; i < students; i++){  /*checking the array*/
        printf("%d ", sort_score[i]);
    }

    return 0;
}