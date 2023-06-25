/*사용자로 부터 5 명의 학생의 수학, 국어, 영어 점수를 입력 받아서
 평균이 가장 높은 사람 부터 평균이 가장 낮은 사람까지 정렬되어 출력하도록 하세요.
 특히, 평균을 기준으로 평균 이상인 사람 옆에는 '합격', 아닌 사람은 '불합격' 을 출력하게 해보세요 */        // 주석처리된 코드는 지워도 된다.
 #include <stdio.h>
 float average(float a, float b, float c);
 int sort(int (*psort)[2], int row);
 int main(){
    int arr[5][3];
    int student_sort[5][2];  //[i][0] : 학생 번호, [i][1] 학생 평균점수. // 언제 빈 괄호로 둘 수 있는지 찾아보기[]
    int i, j;

    for(i = 0; i < 5; i++){ //Enter the student's scores and enter the each average value.
        printf("Enter the student_%d's Math, Korean and English scores \n", (i+1));
        for(j = 0; j < 3; j++){
            if(j==0){
                printf("Math : ");
                scanf("%d", &arr[i][j]);
            }
            else if(j==1){
                printf("Korean : ");
                scanf("%d", &arr[i][j]);
            }else{
                printf("English : ");
                scanf("%d", &arr[i][j]);
            }
        }
        student_sort[i][0] = i+1; // 학생에 따른
        student_sort[i][1] = average(arr[i][0], arr[i][1], arr[i][2]); // 점수 입력
    }
    sort(student_sort, 5); // 배열 이름만

    return 0;
 }
 int sort(int(*psort)[2], int row){
    int i, j;
    int temp;
    float total_average = 0; // 값을 초기화 하고 사용하자.
    for(i = 0; i < row; i++){
        for (j = i; j < row -1; j++){
            if (psort[i][1] < psort[j+1][1]){
                /*change the vlaue.*/
                temp = psort[i][1];
                psort[i][1] = psort[j+1][1];
                psort[j+1][1] = temp;  
                /*change the student number.*/
                temp = psort[i][0];
                psort[i][0] = psort[j+1][0];
                psort[j+1][0] = temp;
            }
        }
    }
    for(i = 0; i < row; i++){
        total_average += psort[i][1];
    }
    // printf("\n sum of the average : %f \n",total_average);
    total_average = total_average / 5.0;
    // printf("\n total_average :  %f \n",total_average);
    for(i = 0; i < row; i++){
        if (psort[i][1] > total_average)
            printf("The student_%d is pass \n", psort[i][0]);
        else
            printf("The student_%d is fail \n", psort[i][0]);
    }

    //     for( i = 0; i < 5; i++){
    //     printf("%d_student average : %d \n",psort[i][0], psort[i][1]);
    // }
    // printf("------------------------\n");

    // printf("%d, %d, %d, %d, %d,total_average : %f \n", psort[0][1],psort[1][1],psort[2][1],psort[3][1],psort[4][1],total_average);

    return 0;
 }
 float average(float a, float b, float c){
    return (a+b+c)/3.0;
 }
