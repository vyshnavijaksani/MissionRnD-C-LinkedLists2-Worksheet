/*
OVERVIEW: Given a single linked list insert a new node at every Kth node with value K.
E.g.: 1->2->3->4->5, k = 2, 1->2->2->3->4->2->5

INPUTS: A linked list and Value of K.

OUTPUT: Insert a new node at every Kth node with value K.

ERROR CASES: Return NULL for error cases.

NOTES:
*/

#include <stdio.h>
#include <malloc.h>

struct node {
	int num;
	struct node *next;
};

struct node * insertAtEveryKthNode(struct node *head, int K) {
	//invalid K value check
	if (K <= 0 || head == NULL)
		return NULL;
	struct node *temp = head;
	int count = 0;
	//calculating length of the linked list given
	while (temp != NULL)
	{
		temp = temp->next;
		count++;
	}
	//checking for K value greater than length of the linked list
	if (K > count)
	{
		return head;
	}
	int res = K + 1;
	//initialising how many values to be inserted in the list
	int looprun = count / K;
	int i;
	int num1 = K;
	int t = 0;
	for (t = 0; t < looprun; t++)
	{
		struct node *temp2 = head;
		//allocating space for new node
		struct node *temp1 = (struct node *)malloc(sizeof(struct node));
		temp1->next = NULL;
		temp1->num = num1;
		//traversing to n-1th node
		for (int i = 0; i < K - 1; i++)
		{
			temp2 = temp2->next;
		}
		temp1->next = temp2->next;
		temp2->next = temp1;
		K = K + res;
	}
	return head;
}