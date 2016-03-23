/*
OVERVIEW: Given a single sorted linked list find the median element of the single linked list.
Median is the middle element.
E.g.: 1->2->3->4->5, output is 3.

INPUTS: A sorted linked list.

OUTPUT: Return median of the linked list elements.

ERROR CASES: Return -1 for error cases.

NOTES: If length is even, return average of middle pair of numbers.
*/

#include <stdio.h>

struct node {
	int num;
	struct node *next;
};

int linkedListMedian(struct node *head) {
	if (head == NULL)
		return -1;
	int median;
	int length = 0;
	struct node *temp = head;

	while (temp != NULL)
	{
		temp = temp->next;
		length++;
	}
	temp = head;
	int dummy = (length / 2), j = 1;
	int i = 1;
	//to check if list consists of single element only
	if (length == 1)
		return temp->num;
	//checking for odd length
	if (length % 2 != 0)
	{
		while (i < dummy)
		{
			temp = temp->next;
			i++;
		}
		return (temp->next->num);
	}
	else
	{
		//checking for even length
		while (j < dummy)
		{
			temp = temp->next;
			j++;
		}
		return ((temp->num + temp->next->num) / 2);
	}

	return -1;
}
