// #include <stdio.h>
// int print_hello(){
//     printf("Hello! \n");
//     return 0;
// }
// int main(){
//     printf("함수를 불러보자 : ");
//     print_hello();

//     printf("또 부를까? ");
//     print_hello();
//     return 0;
// }

// /*반환값*/
// #include <stdio.h>
// int ret(){ return 1000;}
// int main(){
//     int a = ret();
//     printf("ret() 함수의 반환값 : %d \n", a);

//     return 0;
// }

/*함수의 인자*/
#include <stdio.h>
int slave(int master_money){
    master_money += 10000;
    return master_money;
}
int main(){
    int my_money = 100000;
    printf("2009.12.12 재산 : %d \n",slave(my_money));

    return 0;
}