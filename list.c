#include "list.h"

Node *newNode(int x) {
	Node *pnt = (Node *) malloc (sizeof(Node)); /* allocates physical memory for the node */
	pnt -> n = x;                               /* inserts the information received as input in the field(s) in the list */
	/* entering additional information if necessary...
	 * pnt -> b = y;
	 * pnt -> c = z;
	 * ... and so on
	 */
	pnt -> next = NULL;                         /* initialize the pointer */
	/* an insert function will take care of properly setting the next variable */
	return pnt;
}

Node *preInsert(Node *top, int x) {
	Node *tmp = newNode(x);						/* create a node with input information */
	tmp -> next = top;							/* top corresponds to the first element of the list BEFORE this operation,
												 * which provides to put "tmp" at the top of the list,
												 * thus becoming the new "top" */
	return tmp;									/* returns the new first element of the list */
}

Node *orderInsert(Node *top, int x) {
	if (top == NULL || top -> n > x) {
		/* if top == NULL is true then the element will be positioned at the bottom of the list,
		 * if top -> n > x then the element will be positioned in the middle of the list.
		 * OBSERVATION: the first condition is fundamental to the function of the function
		 * while the second one can be modeled according to the needs, in this case the condition
		 * top -> n > x imposes an increasing order of the elements of the list, but it could well
		 * be top -> n < x if you wanted to insert elements in descending order. */
		Node *tmp = newNode(x);						/* creates a node with the information entered as input */
		tmp -> next = top;							/* points to the next node in the list */
		top = tmp;									/* inserts the node in the list */
		return top;
	}
	else
		top -> next = orderInsert(top -> next, x);	/* "scrolls" the list, examining the next node */
	return top;
}

Node *postInsert(Node *top, int x) {
	if (top == NULL)
		return newNode(x);							/* inserts the item at the bottom of the list */
	else
		top -> next = postInsert(top -> next, x);	/* if it is not at the bottom, move on */
	return top;
}

Node *findNode(Node *top, int k) {
	if (top == NULL || top -> n == k)
		return top;							/* returns the found node (NULL if it was not found) */
	else
		return findNode(top -> next, k);	/* scrolls the list to search for the item */
}

Node *deleteNode(Node *top, int k) {
	Node *tmp;					/* temporary node */
	if (top != NULL) {
		if (top -> n == k) {	/* if the element was found, it is deleted */
			tmp = top -> next;	/* set the temporary node to the next element (in order not to "lose" the list) */
			free(top);			/* frees the physical memory associated with the node to be deleted */
			top = tmp;			/* set the pointer to the next node */
		}
		else
			top -> next = deleteNode(top -> next, k);	/* scrolls the list in order to search the item to be deleted */
	}
	return top;
}

Node *deleteList(Node *top) {
	if (top != NULL) {				/* if not reached end of the list... */
		deleteList(top -> next);	/* ...move on */
		free(top);					/* delete the node */
	}
	else
		return NULL;
}

void printList(Node *top) {
	if (top != NULL) {
		printf("%d -> ", top -> n);
		printList(top -> next);
	}
	else
		printf("NULL\n");
}

void MergeSort(Node **top) {
	Node *tmp = *top, *a, *b;

    if (tmp != NULL && tmp -> next != NULL) {
		Split(tmp, &a, &b);				/* (divide) split head into "a" and "b" sublists */
	  
		/* (conquer) sort the sublists */
		MergeSort(&a); 
		MergeSort(&b); 
	  
		*top = Merge(a, b);				/* (combine) merge the two sorted lists together */
	}
} 

Node* Merge(Node *top1, Node *top2) {
    if (top1 == NULL) 
		return top2; 
    else
		if (top2 == NULL) 
			return top1;   

    Node* pnt = NULL;
    /* pick either top1 or top2, and merge them */
    if (top1 -> n <= top2 -> n) { 
		pnt = top1;
		pnt -> next = Merge(top1 -> next, top2); 
    } 
    else {
        pnt = top2; 
        pnt -> next = Merge(top1, top2 -> next); 
    }
    return pnt; 
} 

void Split(Node *top, Node **front, Node **back) {
	Node* fast = top -> next;
	Node* slow = top;

    /* fast pointer advances two nodes, slow pointer advances one node */
	while (fast != NULL) {
		fast = fast -> next;		/* "fast" moves on first time */
		if (fast != NULL) { 
			slow = slow -> next;	/* "slow" moves on first time */
			fast = fast -> next;	/* "fast" moves on second time */
        }
    }
	
    /* "slow" is before the middle in the list, so split it in two at that point */
	*front = top;
	*back = slow -> next;
	slow -> next = NULL;			/* end of the input list */
}

int countNodes(Node *top) {
    if (top == NULL)
        return 0;
    else
        return 1 + countNodes(top -> next);
}
