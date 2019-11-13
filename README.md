# C Linked List library
A simple library written in C for managing linked lists.

To understand well the operation of the data structure it is convenient to consolidate the notions concerning pointers in C.
## Table of Contents

- [Linked list in a nutshell](#linked-list-in-a-nutshell)
- [Definition of the struct](#definition-of-the-struct)
- [Inserting operations](#inserting-operations)
	* [Create a new node](#create-a-new-node)
	* [Pre-Insertion](#pre-insertion)
	* [Post-Insertion](#post-insertion)
	* [Sorted insertion](#sorted-insertion)
- [Managing operations](#managing-operations)
	* [Linear search](#linear-search)
	* [Merge of two sorted lists](#merge-of-two-sorted-lists)
	* [Splitting a list](#splitting-a-list)
	* [Print list](#print-list)
	* [Counting nodes](#counting-nodes)
- [Deleting operations](#deleting-operations)
	* [Deleting a node](#deleting-a-node)
	* [Erasing the list](#erasing-the-list)
- [Sorting the list](#sorting-the-list)

## Linked list in a nutshell
It's a dynamic data structure with a linear collection of items. It consists of a sequence of nodes, each containing arbitrary data fields and one reference pointing to the next node. A linked list is a self-referring data type, as it contains a pointer to another data of the same type.

## Definition of the struct
```c
typedef struct node {
	int n;
	/* float b;
	 * char c;
	 * ... etc.
	 */
	struct node *next;
}Node;
```
Node struct contains the information of the single node. In this example there is a dummy variable of integers but it can be shaped according to your needs. The `struct node *next` variable points to his next item (which is NULL if it is the last node in the list).

## Inserting operations

### Create a new node
`Node *newNode(int x)`

Creates physically a new node. It is not used directly into main block, but only from other functions, like inserting ones.

**Parameter:**
- `int x`: value to insert in the node

![newNode](https://github.com/Leyxargon/c-linked-list/blob/master/figures/newNode.png "newNode()")

### Pre-Insertion
`Node *preInsert(Node *top, int x)`

Inserts a new item at the top of the list. If the list is not empty then the new node will be the new top item, which will points to the list.

**Parameters:**
- `Node *top`: pointer to the first element of the list
- `int x`: value to insert in the node

![preInsert](https://github.com/Leyxargon/c-linked-list/blob/master/figures/preInsert.png "preInsert()")

### Post-Insertion
`Node *postInsert(Node *top, int x)`

Inserts a new item at the end of the list. If the list is not empty then the new node will be the last one, pointed by the previous last node.

**Parameters:**
- `Node *top`: pointer to the first element of the list
- `int x`: value to insert in the node

![postInsert](https://github.com/Leyxargon/c-linked-list/blob/master/figures/postInsert.png "postInsert()")

### Sorted insertion
`Node *orderInsert(Node *top, int x)`

Inserts a new item in the list following an order, according to a key field. For example if you want to have an increasingly ordered list, this function is the solution.
This insertion function cannot be combined with Pre and Post insertions, the result is the loss of meaning of the eventual order applied by the sorted insertion.

**Parameters:**
- `Node *top`: pointer to the first element of the list
- `int x`: value to insert in the node

![orderInsert](https://github.com/Leyxargon/c-linked-list/blob/master/figures/orderInsert.png "orderInsert()")

## Managing operations

### Linear search
`Node *findNode(Node *top, int k)`

Finds the node that contains the k value. It scans all the list while the item is not found, or the list is ended. If the node with k value is not in the list, it will return NULL.

**Parameters:**
- `Node *top`: pointer to the first element of the list
- `int k`: value to find in the list

### Merge of two sorted lists
`Node* Merge(Node *top1, Node *top2)`

Returns a single linked list made by merge of two given sorted linked lists.
This function has ad undefined behavior if used with unsorted linked lists.

### Splitting a list
`void Split(Node *top, Node **front, Node **back)`

Splits a given list in two lists.

### Print list
`void printList(Node *top)`

Prints all the items in the list.

**Parameter:**
- `Node *top`: pointer to the first element of the list

### Counting nodes
`int countNodes(Node *top)`

Returns the number of the nodes in the list.

**Parameter:**
- `Node *top`: pointer to the first element of the list

## Deleting operations

### Deleting a node
`Node *deleteNode(Node *top, int k)`

This function applies the linear search to remove the element that contains the k value.

**Parameters:**
- `Node *top`: pointer to the first element of the list
- `int k`: value to delete in the list

![deleteNode](https://github.com/Leyxargon/c-linked-list/blob/master/figures/deleteNode.png "deleteNode()")

### Erasing the list
`Node *deleteList(Node *top)`

**Parameter:**
- `Node *top`: pointer to the first element of the list

Destroy the list deallocating every nodes. At the end it will return a NULL pointer.

## Sorting the list
`void MergeSort(Node **top)`

Sort a non-empty list. This algorithm works with pointers, so there is not the variables swapping, but simply redefines the order of the pointers that make up the list.

**Parameter:**
- `Node **top`: address of the pointer to the first element of the list

![MergeSort](https://github.com/Leyxargon/c-linked-list/blob/master/figures/MergeSort.png "MergeSort()")

## Example of usage
```c
#include ...

int main(...) {
	Node *list = NULL;
	
	list = postInsert(list, 7);
	list = postInsert(list, 18);
	list = postInsert(list, 1);
	list = preInsert(list, 20);
	
	printList(list);
	
	if (findNode(list, 2) != NULL)
		printf("Found 2 in the list\n");
	else
		printf("Not found 2 in the list\n");
		
	printf("Sorted list:\n");
	MergeSort(&list);
	printList(list);
		
	if ((list = deleteList(list)) == NULL)
		printf("List erased correctly\n");
	else
		printf("Error\n");
		
	return 0;
}
```
