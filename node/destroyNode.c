/* 선택된 노드를 파괴하는 함수 */
/*첫 번째 node를 head로 하고 destroy 노드 함수는 head를 인자로 받는다, 파괴하고자 하는 노드도 마찬가지.*/
void DestroyNode(struct Node *destroy, struct Node *head) {
  /* 다음 노드를 가리킬 포인터*/
  struct Node *next = head;

  /* head 를 파괴하려 한다면 */
  if (destroy == head) {
    free(destroy);
    return;
  }

  /* 만일 next 가 NULL 이면 종료 */
  while (next) {
    /* 만일 next 다음 노드가 destroy 라면 next 가 destory 앞 노드*/
    if (next->nextNode == destroy) {
      /* 따라서 next 의 다음 노드는 destory 가 아니라 destroy 의 다음 노드가
       * 된다. */
      next->nextNode = destroy->nextNode;
    }
    /* next 는 다음 노드를 가리킨다. */
    next = next->nextNode;
  }
  free(destroy);
}