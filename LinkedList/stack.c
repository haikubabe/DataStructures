/**
  In Linked List implementation of stack there is not concept of overflow of stack
  as the size of a linked list is not fixed
*/

#include<stdio.h>
#include<stdlib.h>

struct Stack {
  int data;
  struct Stack *next;
};

void push(struct Stack **top, int data) {
   struct Stack *temp = (struct Stack *)malloc(sizeof(struct Stack));
   temp->data = data;
   temp->next = *top;
   *top = temp;
}

int isEmpty(struct Stack *top) {
  return top == NULL;
}

int pop(struct Stack **top) {
  if (isEmpty(*top)) {
    printf("cannot remove from an empty stack\n");
    return -1;
  }
  struct Stack *temp = *top;
  *top = (*top)->next;
  temp->next = NULL;
  int data = temp->data;
  free(temp);
  return data;
}

int findTop(struct Stack *top) {
  if (isEmpty(top)) {
    printf("stack is empty, cannot find the element\n");
    return -1;
  }
  return top->data;
}

void printStack(struct Stack *top) {
   if (isEmpty(top)) {
     printf("Stack is empty\n");
     return;
   }

   struct Stack *temp = top;
   while (temp != NULL) {
     printf("%d\t", temp->data);
     temp = temp->next;
   }
   printf("\n");
}

int size(struct Stack *top) {
   int size=0;
   if (isEmpty(top)) {
     return size;
   }

   struct Stack *temp = top;
   while (temp != NULL) {
     size++;
     temp = temp->next;
   }
   return size;
}

void deleteStack(struct Stack **top) {

   struct Stack *prev = NULL;
   struct Stack *temp = *top;
   if (isEmpty(*top)) {
     printf("Stack is empty, cannot delete it\n");
     return;
   }
   while (temp != NULL) {
      prev = temp;
      free(prev);
      temp = temp->next;
      *top = temp;
   }
}


int main() {
  
   struct Stack *top = NULL;
   push(&top, 1);
   push(&top, 2);
   push(&top, 3);
   printStack(top);
   
/*   pop(&top);
   printStack(top);
   pop(&top);
   printStack(top);
   pop(&top);
   printStack(top);
   pop(&top);*/

   printf("Top element is %d\n", findTop(top));
   
   printf(isEmpty(top) == 1 ? "Stack is empty\n" : "Stack is not empty\n");

   printf("Size of stack is %d\n", size(top));
 
   deleteStack(&top);
   
   printf("Size of stack is %d\n", size(top));
}
