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

//find loop in a linked list if it exists, using Floyd's Cycle Finding Algorithm
int findLoop(struct Node *head) {
   struct Node *slow = head;
   struct Node *fast = head;
   
   while (slow != NULL && fast != NULL && fast->next != NULL) {
     slow = slow->next;
     fast = fast->next->next;
     if (slow == fast) {
       return 1;
     }
   }
   return 0;
}

//find the starting node of a linked list in a loop
int findStartNode(struct Node *head) {
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
        return temp->data;
      }
    }
    size++;
    visit[size] = temp;
   }
   return -1; 
}

int findStartNodeInCycle(struct Node *head) {
   struct Node *slow = head;
   struct Node *fast = head;

   while (slow != NULL && fast != NULL && fast->next != NULL) {
     slow = slow->next;
     fast = fast->next->next;
     if (slow == fast) {
        break; 
     }      
   }
   if (slow != fast) {
     return -1;
   }
   
   slow = head;
   while (slow != fast) {
     slow = slow->next;
     fast = fast->next;
   }
   return slow->data;
}

//find the length of a loop in the linked list, return 0 if no loop is there
int findLoopLength(struct Node *head) {
   struct Node *slow = head;
   struct Node *fast = head;

   while (slow != NULL && fast != NULL && fast->next != NULL) {
     slow = slow->next;
     fast = fast->next->next;
     if (slow == fast) {
        break; 
     }      
   }
   //loop is not present
   if (slow != fast) {
      return 0;
   }
     
   int count = 1;
   fast = fast->next;
   while (slow != fast) {
     count++;
     fast = fast->next;
   }
   return count;
}

//insert a node in a sorted linked list
void insertInSortedList(struct Node **head, int data) {
   struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
   newNode->data = data;
   newNode->next = NULL;
   if (*head == NULL || (*head)->data >= newNode->data) {
      newNode->next = *head;
      *head = newNode;
      return;
   }
   struct Node *prev = NULL, *current = *head;
   while (current != NULL && current->data < newNode->data) {
      prev = current;
      current = current->next;
   }
   prev->next = newNode;
   newNode->next = current;
}

void reverseList(struct Node **head) {
   struct Node *current = *head;
   struct Node *prev = NULL, *next = NULL;
   while (current != NULL) {
     next = current->next;
     current->next = prev;
     prev = current;
     current = next;
   }
   *head = prev;
}

void reverseListRecursive(struct Node **head) {
   if (*head == NULL) {
      return;
   }
   struct Node *first = *head;
   struct Node *rest = (*head)->next;
   if (rest == NULL) {
     return;
   }
   reverseListRecursive(&rest);
   first->next->next = first;
   first->next = NULL;	//to avoid loop
   *head = rest; 
}

//brute force approach
int findIntersection(struct Node *head1, struct Node *head2) {
   struct Node *temp1 = head1;
   struct Node *temp2 = head2;
   while (temp1 != NULL) {
     temp2 = head2;
     while (temp2 != NULL) {
       if (temp1 == temp2) {
          return temp1->data;
       }
       temp2 = temp2->next;
     }
     temp1 = temp1->next;
   }
   return -1;   // if there is no merge point
}

//using hashing
int findMergePoint(struct Node *head1, struct Node *head2) {
   if (head1 == NULL || head2 == NULL) {
     return -1;
   }
   struct Node *address[MAXSIZE];
   struct Node *temp1 = head1;
   struct Node *temp2 = head2;
   int i=0;
   while (temp1!=NULL) {
      address[i] = temp1;
      temp1 = temp1->next;
      i++;
   }
   while (temp2!=NULL) {
      for (int j=0;j<i;j++) {
        if (address[j] == temp2) {
           return temp2->data;
        }    
      }
      temp2 = temp2->next;
   }
   return -1;
}

//using node difference
int getMergePoint(struct Node *head1, struct Node *head2) {
   int m = length(head1);
   int n = length(head2);
   struct Node *temp1 = head1, *temp2 = head2;
   int d=0;
   if (m<n) {
     d = n-m;
     temp1 = head2;
     temp2 = head1;
   } else {
     d = m-n;
     temp1 = head1;
     temp2 = head2;
   }
   for (int i=0;i<d && temp1!=NULL;i++) {
     temp1 = temp1->next;
   }
   while (temp1 != NULL && temp2 != NULL) {
     if (temp1 == temp2) {
       return temp1->data;
     }
     temp1 = temp1->next;
     temp2 = temp2->next;
   }
   return -1;
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
 
  fifth->data = 6;
  fifth->next = NULL;

  struct Node *head1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *second1 = (struct Node*)malloc(sizeof(struct Node));

  head1->data = 5;
  head1->next = second1;
 
  second1->data = 7;
  second1->next = fourth;

  printf("Length is : %d\n", length(head));

  printList(head);

  printNthFromLast(head,1);
  
  printNthFromLast(head,2);

  printNthFromLast(head,3);

  printNthFromLast(head,4);
  
  printNthFromLast(head,-2);

  printf(detectLoop(head) == 1 ? "Loop is there\n" : "Loop is not there\n");
  
  printf(findLoop(head) == 1 ? "Loop is there\n" : "Loop is not there\n");

  printf("%d\n", findStartNode(head));

  printf("%d\n", findStartNodeInCycle(head));
  
  printf("%d\n", findLoopLength(head));

  insertInSortedList(&head, 5);

  printList(head);

  reverseList(&head);

  printList(head);

  reverseListRecursive(&head);

  printList(head);

  printf("%d\n", findIntersection(head,head1));

  printList(head);

  printList(head1);

  printf("%d\n", findMergePoint(head,head1));

  printf("%d\n", getMergePoint(head,head1));

}
