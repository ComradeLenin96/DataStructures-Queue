#include  <stdio.h>
#include  <stdlib.h>

typedef struct node {
  int data;
  struct node*  next;
}Node;

typedef struct queue{
  Node* front;
  Node* tail;
}Queue;

Node* createNode(int  data);
Queue*  emptyQueue();
void  enQueue(int data, Queue*  Myqueue);
void  deQueue(Queue*  Myqueue);
void  display(Queue*  Myqueue);
int   countElem(Queue*  Myqueue);

int main()  {
  Queue*  queuee  = emptyQueue();
  enQueue(5,  queuee);
  enQueue(6,  queuee);
  enQueue(7,  queuee);
  enQueue(9,  queuee);
  enQueue(8,  queuee);
  int count = countElem(queuee);
  printf("COUNT:%d\n", count);
  display(queuee);
  deQueue(queuee);
  deQueue(queuee);
  deQueue(queuee);
  deQueue(queuee);
  deQueue(queuee);
  display(queuee);
  count = countElem(queuee);
  printf("COUNT:%d\n", count);
  if (count ==  0) 
    queuee  = NULL;
  return  0;
}

Queue*  emptyQueue()  {
  Queue*  queuee  = malloc(sizeof(Queue));
  queuee->front = NULL;
  queuee->tail  = NULL;
  return  queuee;
}

int countElem(Queue*  Myqueue)  {
  int count = 0;
  if (Myqueue->front  ==  NULL) return  count;
  Node* curr = Myqueue->front;
  while (curr)  {
    ++count;
    curr  = curr->next;
  }
  return  count;
}

void  display(Queue*  Myqueue)  {
  if (Myqueue->front == NULL) printf("Empty\n");
  Node* curr  = Myqueue->front;
  while(curr) {
    printf("queue->data:={%d}\n", curr->data);
    curr  = curr->next;
  }
}

void  deQueue(Queue*  Myqueue)  {
  if (Myqueue->front  ==  NULL) printf("Queue is  empty\n");
  Node* temp  = Myqueue->front;
  Myqueue->front  = Myqueue->front->next;
  if (Myqueue->front  ==  temp) {
    Myqueue->front  = NULL;
    Myqueue->tail = NULL;
  }
  printf("Deleted from the Queue:=%d\n",  temp->data);
  free(temp);
}

void  enQueue(int data, Queue* Myqueue) {
  Node* myNode  = createNode(data);
  if (Myqueue->tail ==  NULL) {
    Myqueue->front  = myNode;
    Myqueue->tail = myNode;
  } else  {
    Myqueue->tail->next = myNode;
    Myqueue->tail = myNode;
  }
}

Node* createNode(int  data) {
  Node* new_node  = malloc(sizeof(Node));
  new_node->data  = data;
  new_node->next  = NULL;
  return  new_node;
}
