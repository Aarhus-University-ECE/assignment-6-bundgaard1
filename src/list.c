#include <assert.h> /*assert*/
#include <stdio.h>  /*printf*/
#include <stdlib.h> /*malloc*/

typedef struct node {
  int data;
  struct node *next;
} node;

void add(node *head, int x) {
  /*  pre: Head points to the first element. The last element's next is
      NULL post: a new node containing x is added to the end of the list*/
  assert(head != NULL);  // Assertion
  node *p = head;
  while (p->next != NULL) {
    p = p->next;
  } /*p points to the last element*/
  // Make the new element, with correct values
  node *element = (node *)malloc(sizeof(node));
  element->next = NULL;
  element->data = x;
  p->next = element;  // Make last element in list the new element
}

int size(node *head) {
  // Exercise 3b:
  assert(head != NULL);  // Assertion
  int n = 0;             // Counter for size.
  node *p = head;
  while (p->next != NULL) {
    p = p->next;
    n++;
  }
  // Runs untill the end of the list

  return n;
}

void printout(node *head) {
  /*Excercise 3d) Implement your changes..
    pre: head points to the first, empty element. The last element's next is
    NULL post: the values of the list are printed out*/
  node *p = head->next;
  while (p != NULL) {
    printf("%d, ", p->data);
    p = p->next;  // Select next element
  }
  printf("\n");
}

int largest(node *head) {
  /*Excercise 3e
    pre: 1. head points to the first element. 2. The last element’s next is
    NULL. 3. size(l>0)
    post: returns the largest value of the list*/
  assert(head != NULL);    // pre 1
  assert(size(head) > 0);  // pre 3
  int maxValue = head->next->data;

  node *p = head;

  while (p->next != NULL) {
    if (p->data > maxValue) {
      maxValue = p->data;
    }
    p = p->next;
  }

  assert(p->next == NULL);  // pre 2

  return maxValue;
}
