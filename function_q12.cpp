/*에라토스테네스의 체를 이용해서 1 부터 N 까지의 소수를 구하는 프로그램을 만들어보세요. 알고리즘*/
#include <stdio.h>
int sieve(int *p, int N, int num1);
int main(){
    int N;
    int i;
    printf("어떤 숫자까지 소수를 구하고 싶습니까? : ");
    scanf("%d", &N);
    int arr[N];
    for(i = 0; i < N; i++){
        arr[i] = i+1;
    }
    arr[0] = 0;
    sieve(arr, N, 2);
    for(i = 0; i < N; i++){
        if(arr[i] == 0 ) continue;
        printf("%d ", arr[i]);
    }
    return 0;
}

int sieve(int *p, int N, int num1){
    if(num1 > N) return 0;                   //Segmentation fault  맨 앞줄에 쓰지 않고 중간이나 뒷줄에 쓰면 오류뜸.
    for (int i = num1+1; i < N; i++){ // 체크할 수가 지워지면 안되므로 체크 다음 숫자부터 확인
        if((*(p+i)) % num1 == 0){
            (*(p+i)) = 0;
        }
    }
    num1 += 1;                   // 체크할 수 증가.
    if(num1 % 2 == 0) num1 += 1; // 2를 제외한 짝수는 체크할 필요가 없음

    sieve(p, N, num1);  // p는 arr주소가 담겨있음.

    return 0;
}