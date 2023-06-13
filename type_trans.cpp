#include <stdio.h>
int main(){
    int i;
    float f;
    
    printf("실수를 입력하시오. : ");
    scanf("%f", &f);
    i = (int)(100 * (f - (int)f));
    printf("i = %d\n", i);
    return 0;
}
