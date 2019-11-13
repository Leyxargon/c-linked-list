#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int n;              /* data field(s) */
	/* float b;
	 * char c;
	 * ... etc.
	 */
	struct node *next;  /* pointer to next element */
}Node;

Node *newNode(int ); /* physically creates a new node */
/* N.B. this function is called by other functions because does not take care
 * of inserting the Node in the list, but delegates this operation to other
 * functions, such as *Insert functions */

Node *preInsert(Node *, int ); /* inserts a new item at the top of the list */

Node *orderInsert(Node *, int ); /* inserts a new element in order, according to a key field */

Node *postInsert(Node *, int ); /* inserts a new item at the end of the list */

Node *findNode(Node *, int ); /* find a node in the list */

Node *deleteNode(Node *, int ); /* deletes a node corresponding to the inserted key */

Node *deleteList(Node *); /* deletes a list */

void printList(Node *); /* prints all the nodes in the list */

void MergeSort(Node **); /* sorting algorithm */

Node *Merge(Node *, Node *); /* merges two sorted linked lists */

void Split(Node *, Node **, Node **); /* split the nodes of the list into two sublists */

int countNodes(Node *); /* returns the number of nodes in the list */
