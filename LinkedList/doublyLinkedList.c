#include<stdio.h>
#include<stdlib.h>

struct DLLNode {
   int data;
   struct DLLNode *next;
   struct DLLNode *prev;
};


//traverse the linked list
void traverse(struct DLLNode *head) {

   if (head == NULL) {
     printf("Linked list is empty\n");
     return;
   }
    
   struct DLLNode *current = head;
   
   while (current != NULL) {
     printf("%d\t", current->data);
     current = current->next;
   }
   printf("\n");
}


//insert a node before the head
void insertAtFirst(struct DLLNode **head, int data) {

   struct DLLNode *node = (struct DLLNode*)malloc(sizeof(struct DLLNode));
   node->data = data;
   node->next = *head;
   node->prev = NULL;
   //check if linked list is empty or not
   if (*head != NULL)
     (*head)->prev = node;
   *head = node;
}


//insert a node at the end
void insertAtEnd(struct DLLNode **head, int data) {

   struct DLLNode *node = (struct DLLNode*)malloc(sizeof(struct DLLNode));
   node->data = data;
   node->next = NULL;
   if (*head == NULL) {
     node->prev = NULL;
     *head = node;
     return;
   }
   struct DLLNode *temp = *head;
   while (temp->next != NULL) {
	temp = temp->next;
   }
   temp->next = node;
   node->prev = temp;
}


//insert a node at a specific position
void insertAtPos(struct DLLNode **head, int pos, int data) {

   struct DLLNode *node = (struct DLLNode*)malloc(sizeof(struct DLLNode));
   node->data = data;

   if (pos == 0) {
     node->next = *head;
     node->prev = NULL;
     *head = node;
     return;
   }
   struct DLLNode *temp = *head;
   int i=0;
   for (i=0;i<pos&&temp->next!=NULL;i++) {
      temp = temp->next;
   }
   if (i != pos) {
     printf("position doesn't exist\n");
     return;
   }
   node->next = temp;
   node->prev = temp->prev;
   temp->prev->next = node;
   temp->prev = node; 
}


//delete the head node
void deleteHead(struct DLLNode **head) {

   if (*head == NULL) {
     printf("cannot delete it, the list is empty\n");
     return;
   }
   struct DLLNode *temp = *head;
   *head = (*head)->next;
   //if more than one element is present in the list
   if (*head != NULL)
     (*head)->prev = NULL;
   free(temp);
}


//delete the last node
void deleteLast(struct DLLNode **head) {

   if (*head == NULL) {
     printf("cannot delete it, the list is empty\n");
     return;
   }
   struct DLLNode *temp = *head;
   //if there is only one element in the list
   if (temp->next == NULL) {
     *head = NULL;
     free(temp);
     return;
   }
   while (temp->next != NULL) {
     temp = temp->next;
   }
   temp->prev->next = NULL;
   temp->prev = NULL;
   free(temp);
}


//delete a node at a specific position
void deleteAtPos(struct DLLNode **head, int pos) {

   if (*head == NULL) {
     printf("cannot delete it, the list is empty\n");
     return;
   }
   struct DLLNode *temp = *head;
   //if the node to be deleted is the head node
   if (pos == 0) {
     *head = (*head)->next;
     if (*head != NULL)
       (*head)->prev = NULL;
     free(temp);
     return;
   }
   int i=0;
   for (i=0;i<pos&&temp!=NULL;i++) {
      temp = temp->next;
   }
   if (temp == NULL) {
    printf("the given position doesn't exist\n");
    return;
   }
   //if the node to be deleted is the last node
   if (temp->next == NULL) {
     temp->prev->next = NULL;
     temp->prev = NULL;
   } 
   //if the node to be deleted is the intermediate node
   else {
     temp->prev->next = temp->next;
     temp->next->prev = temp->prev;
   }
   free(temp);
}


int main() {

   struct DLLNode *head = (struct DLLNode*)malloc(sizeof(struct DLLNode)); 
   struct DLLNode *second = (struct DLLNode*)malloc(sizeof(struct DLLNode)); 
   struct DLLNode *third = (struct DLLNode*)malloc(sizeof(struct DLLNode)); 

   printf("%lu\n", sizeof(head));
   printf("%lu\n", sizeof(*head));

   head->data = 1;
   head->next = second;
   head->prev = NULL;

   second->data = 2;
   second->next = third;
   second->prev = head;

   third->data = 3;
   third->next = NULL;
   third->prev = second;

   traverse(head);

   insertAtFirst(&head, 4);

   traverse(head);

   insertAtEnd(&head, 5);

   traverse(head);

   insertAtPos(&head, 5, 6);

   insertAtPos(&head, 4, 6);

   traverse(head);

   insertAtPos(&head, 3, 7);

   traverse(head);

   insertAtPos(&head, 0, 8);

   traverse(head);

   deleteHead(&head);

   traverse(head);

   deleteLast(&head);

   traverse(head);

   deleteAtPos(&head, 6);

   deleteAtPos(&head, 5);
 
   traverse(head);

   deleteAtPos(&head, 0);

   traverse(head);

   deleteAtPos(&head, 2);

   traverse(head);
}
