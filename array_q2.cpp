#include <stdio.h>
int main(){
    /*입력받은 학생들의 성적을 막대 그래프로 나타내는 프로그램을 만들어 보세요..*/
    int students = 30;  // 넉넉하게 잡는다.
    int arr[students];

    int i, j;
 
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
    for (i = 0; i < students; i++){ /*막대 그래프.*/
        printf("Student_%2d : ", i+1);
        for (j = 0; j < arr[i]; j++){
            printf("*");
        }
        printf("\n");
    }

    return 0;
}