/*
OVERVIEW: Merge two sorted linked lists.
E.g.: 1->3->5 and 2->4, output is 1->2->3->4->5.

INPUTS: Two sorted linked lists.

OUTPUT: Return merged sorted linked list.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include<malloc.h>
struct node {
	int num;
	struct node *next;
};
void insertnode(struct node** end, struct node** start)
{
	struct node* newNode = *start;
	if (newNode != NULL){ ; }
	*start = newNode->next;
	newNode->next = *end;
	*end = newNode;
}

struct node * merge2LinkedLists(struct node *head1, struct node *head2) {
	
		struct node* result = NULL;
		struct node** res = &result;

		while (true)
		{
			if (head1 == NULL)
			{
				*res = head2;
				break;
			}
			else if (head2 == NULL)
			{
				*res = head1;
				break;
			}
			if (head1->num <= head2->num)
			{
				insertnode(res, &head1);
			}
			else
			{
				insertnode(res, &head2);
			}
			//again pointing result to first
			res = &((*res)->next);
		}
		return(result);
}

