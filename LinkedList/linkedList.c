#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 999

struct Node {
  int data;
  struct Node *next;
};

int length(struct Node *head) {
  int len = 0;
  struct Node *temp = head;
  while (temp != NULL) {
   len++;
   temp = temp->next;
  }
  return len;
}

int detectLoop(struct Node *head) {

   if (head == NULL) {
    printf("linked list is empty\n");
    return -1;
   }
   struct Node *visit[MAXSIZE];
   struct Node *temp = head;
   visit[0] = temp;
   int size = 0;
   while (temp->next != NULL) {
    temp = temp->next;
    for (int i=0;i<=size;i++) {
      if (visit[i] == temp) {
        return 1;
      }
    }
    size++;
    visit[size] = temp;
   }
   return 0; 
}

void printList(struct Node *head) {
 
  if (head == NULL) {
    printf("linked list is empty, cannot print it\n");
    return;
  }
  struct Node *temp = head;
  while (temp != NULL) {
   printf("%d\t",temp->data);
   temp = temp->next;
  }
  printf("\n");
}

void printNthFromLast(struct Node *head, int pos) {
   if (head == NULL) {
    printf("linked list is empty\n");
    return;   
   }
   if (pos<=0) {
    printf("not a valid position\n");
    return;
   }
   int len = length(head);
   if (len<pos) {
    printf("position cannot be greater than the length of the linked list\n");
    return;
   }
   struct Node *temp = head;
   for (int i=1;i<len-pos+1;i++) {
     temp = temp->next;
   }
   printf("%d\n", temp->data);
}
 
  
int main() {
  struct Node *head = (struct Node*)malloc(sizeof(struct Node));
  struct Node *second = (struct Node*)malloc(sizeof(struct Node));
  struct Node *third = (struct Node*)malloc(sizeof(struct Node));
  struct Node *fourth = (struct Node*)malloc(sizeof(struct Node));
  struct Node *fifth = (struct Node*)malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = fourth;

  fourth->data = 4;
  fourth->next = fifth;
 
  fifth->data = 5;
  fifth->next = NULL;

  printf("Length is : %d\n", length(head));

  printList(head);

  printNthFromLast(head,1);
  
  printNthFromLast(head,2);

  printNthFromLast(head,3);

  printNthFromLast(head,4);
  
  printNthFromLast(head,-2);

  printf(detectLoop(head) == 1 ? "Loop is there\n" : "Loop is not there\n");
}
