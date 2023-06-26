/*유클리도 호제법을 이용해서 N 개의 수들의 최대공약수를 구하는 함수를 만들어보세요. 유클리드 호제법이 무엇인지 모르신다면, 인터넷 검색을 활용하는 것을 추천합니다.*/
/*https://ko.wikipedia.org/wiki/%EC%9C%A0%ED%81%B4%EB%A6%AC%EB%93%9C_%ED%98%B8%EC%A0%9C%EB%B2%95*/
#include <stdio.h>
/*1071, 1029 => r = 42 // 1029, 42 => r = 21 // 42, 21 => r = 0 21이 최대공약수*/
int euclidean_algorithm(int *parr, int N);/*유클리드 호제법.*/

int main(){
    // int a, b;
    int i, N;
    printf("What do you want to find GCD of Nth number : ");  //gcd : gratest common deivisor 최대공약수
    scanf("%d", &N);
    int arr[N];

    for (i = 0; i < N; i++){
        printf("Enter the #%d : ", i+1);
        scanf("%d", &arr[i]);
        printf("\n");
    }
    euclidean_algorithm(arr, N);

    return 0;
}
int euclidean_algorithm(int *parr, int N){
    int gcd;
    int a, b, r;
    int i;

    for (i = 0; i < N - 1; i++){/*N개의 수들을 최대공약수 계산하기.*/
        a = parr[i];
        b = parr[i+1];
        for(;;){
            if(a % b == 0 || b % a == 0) break;
            if (a > b){
                r = a % b;
                a = r; //이제 a는 필요 없으므로.
            }
            else{
                r = b % a;
                b = r;
            }
        }
        parr[i+1] = r;
    }
    gcd = parr[N-1];
    
    printf("GCD is  : %d", gcd);
    return 0;
}

// #include <stdio.h>
// /*1071, 1029 => r = 42 // 1029, 42 => r = 21 // 42, 21 => r = 0 21이 최대공약수*/
// int euclidean_algorithm(int a, int b);/*유클리드 호제법.*/
// int main(){

//     int i, N;
//     printf("What do you want to find GCD of Nth number : ");  //gcd : gratest common deivisor 최대공약수
//     scanf("%d", &N);
//     int arr[N];

//     for (i = 0; i < N; i++){
//         printf("Enter the #%d : ", i+1);
//         scanf("%d", &arr[i]);
//         printf("\n");
//     }
//     for( i = 0; i < N - 1; i++){/*N개의 수들을 최대공약수 계산하기.*/
//         arr[i+1] = euclidean_algorithm(arr[i], arr[i+1]);
//     }
//     printf("GCD is : %d", arr[N-1]);
//     return 0;
// }
// int euclidean_algorithm(int a, int b){
//     int r;

//     for(;;){
//         if(a%b == 0 || b%a == 0) break;
//         if (a > b){
//             r = a % b;
//             a = r; //이제 a는 필요 없으므로.
//         }
//         else{
//             r = b % a;
//             b = r;
//         }
//     }
//     return r;
// }