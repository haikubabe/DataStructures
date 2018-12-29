#include<stdio.h>
#include<stdlib.h>
#define MAXSIZE 999

struct Node {
  int data;
  struct Node *next;
};

//find the length of a linked list
int length(struct Node *head) {
  int len = 0;
  struct Node *temp = head;
  while (temp != NULL) {
   len++;
   temp = temp->next;
  }
  return len;
}

//find loop in a linked list using Hashing
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

//find the starting node of a linked list in a loop using hashing technique
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

//find the starting node of a cycle in a linked list using Floyd's Cycle Finding Algorithm
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

//find the length of the loop in a linked list, return 0 if no loop is there
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

//iterative way of reversing a linked list
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

//recursive way of reversing a linked list
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

//brute force approach to find the merge point of two singly linked list
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

//using hashing technique to find the merge point of two singly linked list
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

//using node difference approach to find the merge point of two singly linked list
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

//find the middle of a linked list
int findMiddle(struct Node *head) {
   struct Node *slow = head;
   struct Node *fast = head;
   if (head == NULL) {
     return -1;
   }
   while (fast != NULL && fast->next != NULL) {
      slow = slow->next;
      fast = fast->next->next;
   }
   return slow->data;
}

//find if a given linked list is even or odd, return true(1) if even else return false(0)
int findEvenOrOdd(struct Node *head) {
   struct Node *fast = head;
   while (fast != NULL && fast->next != NULL) {
      fast = fast->next->next;
   }
   if (fast != NULL) {
     return 0;
   }
   return 1;
}

//print the elements of a linked list
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

//print Nth Node from the end of a linked list
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
 
//merge two sorted linked list in iterative way
struct Node *mergeSortedList(struct Node *head1, struct Node *head2) {
   if (head1 == NULL) {
      return head2;
   }
   if (head2 == NULL) {
      return head1;
   }
   struct Node *newNode = NULL;
   struct Node *temp1 = head1, *temp2 = head2;
   if (head1->data <= head2->data) {
     newNode = head1;
     temp1 = temp1->next;
   } else {
      newNode = head2;
      temp2 = temp2->next;
   }
   struct Node *temp3 = newNode;
   while (temp1 != NULL && temp2 != NULL) {
     if (temp1->data <= temp2->data) {
       temp3->next = temp1;
       temp3 = temp1;
       temp1 = temp1->next;
     } else {
       temp3->next = temp2;
       temp3 = temp2;
       temp2 = temp2->next;
     }
   }
   if (temp1 != NULL) {
       temp3->next = temp1;
   }
   if (temp2 != NULL) {
     temp3->next = temp2;
   }
   return newNode;
}

//split a circular linked list into two halves, if the list is odd then make the first list one node more than the second list
void splitCircularList(struct Node *head, struct Node **head1, struct Node **head2) {
  
   struct Node *slow = head;
   struct Node *fast = head;

   //in case of odd fast->next becomes head and in case of even fast->next->next becomes head
   while (fast->next != head && fast->next->next != head) {
	slow = slow->next;	 // will give the mid node
	fast = fast->next->next; //in case of odd fast is the last node and in case of even fast is the last node's previous node
   }
   //find the last node for even elements
   if (fast->next->next == head) {
       fast = fast->next;
   }
   *head1 = head;
   //if there is only one node then there will be only one list
   if (head->next != head) {
     *head2 = slow->next;
   }
   fast->next = slow->next; //make the second list circular
   slow->next = head;	    //make the first list circular
}					

//split a singly linked list into two halves, if the list is odd then make the first list one node more than the second list
void splitList(struct Node *head, struct Node **head1, struct Node **head2) {
  
   struct Node *slow = head;
   struct Node *fast = head;

   //in case of odd fast->next becomes null and in case of even fast->next->next becomes null
   while (fast->next != NULL && fast->next->next != NULL) {
	slow = slow->next;	 // will give the mid node
	fast = fast->next->next; //in case of odd fast is the last node and in case of even fast is the last node's previous node
   }
   *head1 = head;
   //if there is only one node then there will be only one list
   if (head->next != NULL) {
     *head2 = slow->next;
   }
   slow->next = NULL;
}	

//print the elements of a circular linked list
void printCircularList(struct Node *head) {
  if (head == NULL) {
   printf("list is empty\n");
   return;
  }
  struct Node *temp = head;
  do {
   printf("%d\t", temp->data);
   temp = temp->next;
  } while(temp!=head);
  printf("\n");
}

//check if two lists are same or not
int checkListSame(struct Node *head1, struct Node *head2) {
   struct Node *temp1 = head1;
   struct Node *temp2 = head2;
   while (temp1 != NULL && temp2 != NULL) {
      if (temp1->data == temp2->data) {
	   temp1 = temp1->next;
	   temp2 = temp2->next;
      }
      else {
	   return 0;
      }
   }
   if (temp1 == NULL && temp2 == NULL) {
	return 1;
   }
   return 0;
}

//check if a list is palindrome or not
int checkPalindrome(struct Node *head) {
   struct Node *slow = head;
   struct Node *fast = head;
   struct Node *prev_slow = NULL, *secondHalf = NULL;
   int res = 1;

   if (head != NULL && head->next != NULL) {
     while(fast != NULL && fast->next != NULL) {
      	prev_slow = slow;
      	slow = slow->next;
      	fast = fast->next->next;
     }  
     struct Node *midNode = NULL;
     //to handle the odd case, in case of odd the mid node will not be included in the second half
     //in case of even there will be no mid node and the mid node i.e. slow will be included in the second half
     if (fast != NULL) {
      	midNode = slow;
      	slow = slow->next;
     }
     secondHalf = slow;
     prev_slow->next = NULL;
     reverseList(&secondHalf);
     res = checkListSame(head, secondHalf);
     reverseList(&secondHalf);
     if (midNode != NULL) {
        prev_slow->next = midNode;
        midNode->next = secondHalf;
     } else {
        prev_slow->next = secondHalf;
     }
  }
  return res;
}

//reverse the two sorted merged linked list
struct Node *reverseSortedMerge(struct Node *head1, struct Node *head2) {
   struct Node *current1 = head1;
   struct Node *current2 = head2;
   struct Node *res = NULL, *next = NULL;
   if (head1 == NULL && head2 == NULL) {
	return NULL;
   }
   while (current1 != NULL && current2 != NULL) {
      if (current1->data <= current2->data) {
        next = current1->next;
        current1->next = res;
        res = current1;
        current1 = next;
      } else {
        next = current2->next;
        current2->next = res;
	res = current2;
	current2 = next;
      }
   }
   while (current1 != NULL) {
      next = current1->next;
      current1->next = res;
      res = current1;
      current1 = next;
   }
   while (current2 != NULL) {
     next = current2->next;
     current2->next = res;
     res = current2;
     current2 = next;
   }
   return res;
}

int main() {
  struct Node *head = (struct Node*)malloc(sizeof(struct Node));
  struct Node *second = (struct Node*)malloc(sizeof(struct Node));
  struct Node *third = (struct Node*)malloc(sizeof(struct Node));

  head->data = 10;
  head->next = second;

  second->data = 40;
  second->next = third;

  third->data = 70;
  third->next = NULL;

  struct Node *head1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *second1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *third1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *fourth1 = (struct Node*)malloc(sizeof(struct Node));

  head1->data = 20;
  head1->next = second1;
 
  second1->data = 50;
  second1->next = third1;

  third1->data = 80;
  third1->next = fourth1;

  fourth1->data = 100;
  fourth1->next = NULL;

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

  printf("%d\n", findMiddle(head));

  printf(findEvenOrOdd(head) == 1 ? "Even\n" : "Odd\n");

  printf("Merge two sorted linked lists\n");
  printList(head);
  printList(head1);
  printList(mergeSortedList(head, head1));

//  printf("Reverse Sorted Merge\n");
//  printList(head);
//  printList(head1);
//  printList(reverseSortedMerge(head, head1));

  struct Node *one = (struct Node*)malloc(sizeof(struct Node));
  struct Node *two = (struct Node*)malloc(sizeof(struct Node));
  struct Node *three = (struct Node*)malloc(sizeof(struct Node));
  struct Node *four = (struct Node*)malloc(sizeof(struct Node));
  struct Node *five = (struct Node*)malloc(sizeof(struct Node));

  one->data = 10;
  one->next = two;

  two->data = 70;
  two->next = three;

  three->data = 40;
  three->next = four;

  four->data = 60;
  four->next = five;

  five->data = 80;
  five->next = one;

  struct Node *head2 = NULL;
  struct Node *head3 = NULL;

  printCircularList(one);
  
  splitCircularList(one, &head2, &head3);

  printCircularList(head2);

  printCircularList(head3);

  struct Node *one1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *two1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *three1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *four1 = (struct Node*)malloc(sizeof(struct Node));
  struct Node *five1 = (struct Node*)malloc(sizeof(struct Node));

  one1->data = 10;
  one1->next = two1;

  two1->data = 20;
  two1->next = three1;

  three1->data = 30;
  three1->next = four1;

  four1->data = 20;
  four1->next = five1;

  five1->data = 50;
  five1->next = NULL;

  printf(checkPalindrome(one1) == 1 ? "Palindrome\n" : "Not Palindrome\n");

}


