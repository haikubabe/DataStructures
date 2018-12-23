#include<stdio.h>
#include<stdlib.h>

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

int printNthFromLast(struct Node *head, int pos) {
   if (head == NULL) {
    printf("linked list is empty\n");
    return -1;
   }
   int len = length(head);
   if (len<pos) {
    printf("position cannot be greater than the length of the linked list\n");
    return -1;
   }
   struct Node *last = head;
   int i = len-pos;
   while (last->next != NULL && i>0) {
     last = last->next;
     i--;
   }
   return last->data;
}
 
  
int main() {
  struct Node *head = (struct Node*)malloc(sizeof(struct Node));
  struct Node *second = (struct Node*)malloc(sizeof(struct Node));
  struct Node *third = (struct Node*)malloc(sizeof(struct Node));

  head->data = 1;
  head->next = second;

  second->data = 2;
  second->next = third;

  third->data = 3;
  third->next = NULL;

  printf("Length is : %d\n", length(head));

  printList(head);

  printf("%d\n", printNthFromLast(head,1));
  
  printf("%d\n", printNthFromLast(head,2));

  printf("%d\n", printNthFromLast(head,3));

  printf("%d\n", printNthFromLast(head,4));

}
