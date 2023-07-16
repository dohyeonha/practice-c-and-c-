// //구조체의 동적할당
// #include <stdio.h>
// #include <stdlib.h>
// struct Something{
//     int a, b;
// };
// int main(){
//     struct Something *arr;
//     int size, i;

//     printf("원하시는 구조체 배열의 크기: ");
//     scanf("%d", &size);

//     arr = (struct Something *)malloc(sizeof(struct Something) * size);

//     for(i = 0; i < size; i++){
//         printf("arr[%d].a : ", i);
//         scanf("%d", &arr[i].a);
//         printf("arr[%d].b : ", i);
//         scanf("%d", &arr[i].b);
//     }
//     for(i = 0; i < size; i++){
//         printf("arr[%d].a : %d, arr[%d].b : %d \n", i, arr[i].a, i, arr[i].b);
//     }

//     free(arr);

//     return 0;
// }

// // 노드
// /* 새 노드를 만드는 함수 */
// struct Node* CreateNode(int data) {
//   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

//   newNode->data = data;
//   newNode->nextNode = NULL;

//   return newNode;
// }

// /* current 라는 노드 뒤에 노드를 새로 만들어 넣는 함수 */
// struct Node* InsertNode(struct Node* current, int data) {
//   /* current 노드가 가리키고 있던 다음 노드가 after 이다 */
//   struct Node* after = current->nextNode;

//   /* 새로운 노드를 생성한다 */
//   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

//   /* 새 노드에 값을 넣어준다. */
//   newNode->data = data;
//   newNode->nextNode = after;

//   /* current 는 이제 newNode 를 가리키게 된다 */
//   current->nextNode = newNode;

//   return newNode;
// }

// /* 선택된 노드를 파괴하는 함수 */
// void DestroyNode(struct Node *destroy, struct Node *head) {
//   /* 다음 노드를 가리킬 포인터*/
//   struct Node *next = head;

//   /* head 를 파괴하려 한다면 */
//   if (destroy == head) {
//     free(destroy);
//     return;
//   }

//   /* 만일 next 가 NULL 이면 종료 */
//   while (next) {
//     /* 만일 next 다음 노드가 destroy 라면 next 가 destory 앞 노드*/
//     if (next->nextNode == destroy) {
//       /* 따라서 next 의 다음 노드는 destory 가 아니라 destroy 의 다음 노드가
//        * 된다. */
//       next->nextNode = destroy->nextNode;
//     }
//     /* next 는 다음 노드를 가리킨다. */
//     next = next->nextNode;
//   }
//   free(destroy);
// }

// //위 노드를 한 소스에 정리하면.
// #include <stdio.h>
// #include <stdlib.h>
// struct Node* InsertNode(struct Node* current, int data);
// void DestroyNode(struct Node* destroy, struct Node* head);
// struct Node* CreateNode(int data);
// void PrintNodeFrom(struct Node* from);

// struct Node{
//   int data;               /* 데이터 */
//   struct Node* nextNode;  /* 다음 노드를 가리키는 부분 */
// };
// int main(){
//   struct Node* Node1 = CreateNode(100);
//   struct Node* Node2 = InsertNode(Node1, 200);
//   struct Node* Node3 = InsertNode(Node2, 300);
//   /* Node 2 뒤에 Node4 넣기 */
//   struct Node* Node4 = InsertNode(Node2, 400);

//   PrintNodeFrom(Node1);
//   return 0;
// }
// void PrintNodeFrom(struct Node* from){
//   /* from 이 NULL이 될 떄 까지,
//     즉 끝 부분에 도달할 때 까지 출력*/
//   while(from){
//     printf("노드의 데이터 : %d \n", from->data);
//     from = from->nextNode;
//   }
// }
// /* current 라는 노드 뒤에 노드를 새로 만들어 넣는 함수*/
// struct Node* InsertNode(struct Node* current, int data){
//   /* current 노드가 가리키고 있던 다음 노드가 after 이다.*/
//   struct Node* after = current->nextNode;

//   /* 새로운 노드를 생성한다. Generation New Node*/
//   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//   /* 새 노드에 값을 넣어준다. */
//   newNode->data = data;
//   newNode->nextNode = after;

//   /* current는 이제 newNode를 가리키게 된다.*/
//   current->nextNode = newNode;
  
//   return newNode;
// }
// /* 선택된 노드를 파괴하는 함수 */
// void DestroyNode(struct Node* destroy,
//                  struct Node* head){/* 다음 노드를 가리킬 포인터*/
//   struct Node* next = head;
//   if(destroy == head){
//     free(destroy);
//     return;
//   }           /* 만일 next가 NULL이면 바로 종료*/
//   while(next) {/* 만일 next 다음 노드가 destroy라면 next가 destroy 앞 노드*/
//     if (next->nextNode == destroy){/*따라서 next의 다음 노드는 destroy가 아니라 destroy의 다음 노드가 된다.*/
//       next->nextNode = destroy->nextNode;
//     }
//     /* next는 다음 노드를 가리킨다.*/
//     next = next->nextNode;
//   }
//   free(destroy);
// }
// /* 새 노드를 만드는 함수*/
// struct Node* CreateNode(int data){
//   struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

//   newNode->data = data;
//   newNode->nextNode = NULL;

//   return newNode;
// }


/* 메모리 관련 함수 memmove, memcpy, memcmp, memset 일단 memset 빼고 알아보자.*/

// /*memcpy 함수*/
// #include <stdio.h>
// #include <string.h>

// int main(){
//   char str[50] = "I love Chewing C haha";
//   char str2[50];
//   char str3[50];

//   memcpy(str2, str, strlen(str) + 1); // 'str 로 부터 strlen(str) + 1 만큼의 문자를 str2 로 복사해라'
//   memcpy(str3, "hello", 6); // 마지막 문자인 NULL은 세지 않으므로 복사할때는 1만큼 더 더해서 복사해오는 것임.

//   printf("%s \n", str);
//   printf("%s \n", str2);
//   printf("%s \n", str3);
  
//   return 0;
// }


// /* memmove 함수에 대해 살펴봅시다.
//  이 함수는 메모리의 특정한 부분의 내용을 다른 부분으로 옮겨주는 역할을 합니다.
//   이 때 '옮긴다' 고 해서 이전 공간에 있던 데이터가 사라지지는 않습니다.*/
// //memmove 함수의 장점은 memcpy 와 하는 일이 많이 비슷해보이지만 사실 memcpy 와는 달리 메모리 공간이 겹쳐도 됩니다.
// #include <stdio.h>
// #include <string.h>

// int main() {
//   char str[50] = "I love Chewing C hahaha";

//   printf("%s \n", str);
//   printf("memmove 이후 \n");
//   memmove(str + 23, str + 17, 6); //str+17 에서 6 개의 문자를 str+23 에 옮겼습니다.
//   printf("%s", str);

//   return 0;
// }

// /* memcmp 함수 */
// //같다면 0, 다르다면 결과에 따라 0 이 아닌 값을 리턴
// #include <stdio.h>
// #include <string.h>

// int main() {
//   int arr[10] = {1, 2, 3, 4, 5};
//   int arr2[10] = {1, 2, 3, 4, 5};

//   if (memcmp(arr, arr2, 5) == 0)
//     printf("arr 과 arr2 는 일치! \n");
//   else
//     printf("arr 과 arr2 는 일치 안함 \n");

//   return 0;
// }