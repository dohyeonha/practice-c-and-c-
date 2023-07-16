/* current 라는 노드 뒤에 노드를 새로 만들어 넣는 함수 */
struct Node* InsertNode(struct Node* current, int data) {
  /* current 노드가 가리키고 있던 다음 노드가 after 이다 */
  struct Node* after = current->nextNode;

  /* 새로운 노드를 생성한다 */
  struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

  /* 새 노드에 값을 넣어준다. */
  newNode->data = data;
  newNode->nextNode = after;

  /* current 는 이제 newNode 를 가리키게 된다 */
  current->nextNode = newNode;

  return newNode;
}