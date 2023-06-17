// #include <stdio.h>
// int main(){
//     int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

//     printf("Array 3th compliment : %d \n ", arr[2]);
//     return 0;
// }

// 소수 찾는 프로그램
#include <stdio.h>
int main(){
    /*우리가 소수인지 판별하고 있는 수*/
    int guess = 5; //소수의 배열
    int prime[1000]; /*현재까지 찾은 (소수의 개수 -1 ) 아래 두개의
                        소수를 미리 찾았음으로 초기값은 1이 된다.*/
    int index = 1; /* for문 변수 */
    int i;         /* 소수인지 판별하기 위해 쓰이는 변쉬*/
    int ok;        /* 처음 두 소수는 특별한 경우로 친다.*/
    prime[0] = 2;
    prime[1] = 3;
    for(;;){
        ok = 0;
        for (i = 0; i <= index; i++){
            if (guess % prime[i] != 0){
                ok++;
            } else {break;}
        }
        if (ok == (index + 1)){
            index++;
            prime[index] = guess;
            printf("소수 : %d \n", prime[index]);
            if (index == 999) break;
        }
        guess += 2; // 짝수는 고려할 필요없기 떄문에 홀수 5에서 2씩 추가한다.
    }
    return 0;
}

