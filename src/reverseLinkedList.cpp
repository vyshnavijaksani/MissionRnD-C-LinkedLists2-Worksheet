/*
OVERVIEW: Given a single linked list, reverse the linked list.
E.g.: 1->2->3->4->5, output is 5->4->3->2->1.

INPUTS: A linked list.

OUTPUT: Reverse the linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

struct node * reverseLinkedList(struct node *head) {
	//checking for empty list
	if (head == NULL)
		return NULL;
	//curr will store current node ,prev will store previous node to curr,next will store next node to curr
	struct node *curr, *next, *prev;
	prev = NULL;
	next = NULL;
	curr = head;
	while (curr != NULL)
	{
		//tracking next node as we will lose the link to remaining list
		next = curr->next;
		//reversing link
		curr->next = prev;
		//updating prev to next node so as to traverse the whole list
		prev = curr;
		//updating previous curr so as to traverse the whole list
		curr = next;
	}
	//updating head with last node address field which is stored in prev
	head = prev;

	return head;
}
