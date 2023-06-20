/*재산을 계산하는 노예*/
#include <stdio.h>

int slave(int master_money, int income){
    printf("%d , %d\n", master_money, income);
    master_money += income;
    
    return master_money;
}

int main(){
    int my_money, income; // 어차피 노예에게 값만 입력해주고 배출되는 결과가 master_money로 main에 없는 변수여서 상관없을 듯.. 다만 income은 좋은 변수는 아닌듯.
    printf("master의 재산과 수입을 순서대로 입력하시오 : ");
    scanf("%d %d", &my_money, &income);
    //scanf("%d", &income);
    printf("내 재산은 : %d",slave(my_money, income));

    return 0;

}