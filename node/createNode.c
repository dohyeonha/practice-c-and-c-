/* 새 노드를 만드는 함수 */
struct Node* CreateNode(int data) {
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  newNode->data = data;
  newNode->nextNode = NULL;

  return newNode;
}