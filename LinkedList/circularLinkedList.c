#include<stdio.h>
#include<stdlib.h>

struct CLLNode {
    int data;
    struct CLLNode *next;
};


//print the list
void traverseList(struct CLLNode *head) {

    struct CLLNode *current = head;
    do {
      printf("%d\t",current->data);
      current = current->next;
    }while(current !=head);
    printf("\n");
}

//insertion of a node at the front of the list
void insertAtFront(struct CLLNode **head, int data) {

   struct CLLNode *node = (struct CLLNode*)malloc(sizeof(struct CLLNode));
   node->data = data;
   node->next = node;

   if (*head == NULL) {
     *head = node;
     return;
   }
   struct CLLNode *temp = *head;
   while (temp->next != *head) {
      temp = temp->next;
   }
   node->next = temp->next;
   temp->next = node;
   *head = node;
}


//insert a node at the end
void insertAtEnd(struct CLLNode **head, int data) {

   struct CLLNode *node = (struct CLLNode*)malloc(sizeof(struct CLLNode));
   node->data = data;
   node->next = node;

   if (*head == NULL) {
     *head = node;
     return;
   }
   struct CLLNode *temp = *head;
   while (temp->next != *head) {
      temp = temp->next;
   }
   node->next = temp->next;
   temp->next = node;
}


//insert a node after a given node
void insertAfterNode(struct CLLNode *givenNode, int data) {

   struct CLLNode *node = (struct CLLNode*)malloc(sizeof(struct CLLNode));
   node->data = data;
   node->next = node;

   node->next = givenNode->next;
   givenNode->next = node;
}


//delete the last node
void deleteLast(struct CLLNode **head) {

   if (*head == NULL) {
     printf("List is empty, cannot delete it\n");
     return;
   }
   struct CLLNode *prev;
   struct CLLNode *last = *head;
   while (last->next != *head) {
     prev = last;
     last = last->next;
   }
   prev->next = last->next;
   free(last);
}


//delete the first node
void deleteFirst(struct CLLNode **head) {

   if (*head == NULL) {
     printf("List is empty, cannot delete it\n");
     return;
   }
   struct CLLNode *temp = *head;
   struct CLLNode *last = *head;
   while (last->next != *head) {
     last = last->next;
   }
   last->next = (*head)->next;
   *head = (*head)->next;
   free(temp);
}


int main() {

   struct CLLNode *head = (struct CLLNode*)malloc(sizeof(struct CLLNode));
   struct CLLNode *second = (struct CLLNode*)malloc(sizeof(struct CLLNode));
   struct CLLNode *third = (struct CLLNode*)malloc(sizeof(struct CLLNode));

   head->data = 1;
   head->next = second;

   second->data = 2;
   second->next = third;
 
   third->data = 3;
   third->next = head;

   traverseList(head);

   insertAtFront(&head, 4);

   traverseList(head);

   insertAtEnd(&head, 5);

   traverseList(head); 

   insertAfterNode(third, 6);

   traverseList(head);

   deleteLast(&head);

   traverseList(head);

   deleteFirst(&head);

   traverseList(head);
}
