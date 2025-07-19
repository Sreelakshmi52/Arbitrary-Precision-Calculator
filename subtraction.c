#include "apc.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int subtraction(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, Dlist **headR, Dlist **tailR, char *argv[])
{
	/* Definition goes here */
	// eg : ./a.out 44 - 11 ;
	int flag = 0, borrow = 0;
	if (argv != NULL)
	{
		if (strlen(argv[1]) < strlen(argv[3])) // We need to swap
		{
			digit_to_list(head1, tail1, head2, tail2, argv[3], argv[1]);
			flag = 1;
		}
		else if (strlen(argv[1]) > strlen(argv[3])) // dont need to swap
		{
			digit_to_list(head1, tail1, head2, tail2, argv[1], argv[3]);
			flag = 0;
		}
		else
		{
			if (strcmp(argv[1], argv[3]) < 0)
			{
				digit_to_list(head1, tail1, head2, tail2, argv[3], argv[1]); // we need to swap
				flag = 1;
			}
			else
			{
				digit_to_list(head1, tail1, head2, tail2, argv[1], argv[3]); // dont need to swap
				flag = 0;
			}
		}
	}

	Dlist *temp1 = *tail1;
	Dlist *temp2 = *tail2;
	while (temp1 || temp2)
	{
		if (temp1 && temp2)
		{
			if (borrow == 1)
			{
				if (temp1->data - 1 < 0)
				{
					temp1->data = 9;
					borrow = 1;
				}
				else
				{
					temp1->data = temp1->data - 1;
				}
			}
			if ((temp1->data) < (temp2->data))
			{
				borrow = 1; // borrow from next digit
				if (temp1 == *head1 && temp2 == *head2 && (temp1->data + 10) - temp2->data == 0)
				{
					borrow = 0;
					break;
				}
				// printf("current numbers: %d and %d\n",temp1->data,temp2->data);
				insert_first(headR, tailR, (temp1->data + 10) - temp2->data);
				// printf("%d",(temp1->data + 10) - temp2->data);
			}
			else
			{
				if (temp1 == *head1 && temp2 == *head2 && temp1->data - temp2->data == 0)
				{
					borrow = 0;
					break;
				}
				// printf("Next numbers: %d and %d\n",temp1->data,temp2->data);
				insert_first(headR, tailR, temp1->data - temp2->data);
				if (borrow == 1 && temp1->data == 9)
				{
					borrow = 1;
				}
				else
				{
					borrow = 0;
				}
			}
			temp1 = temp1->prev;
			temp2 = temp2->prev;
		}
		else if (temp2 == NULL && temp1 != NULL)
		{

			if (borrow == 1)
			{

				if (temp1->data - 1 < 0)
				{
					insert_first(headR, tailR, 9);
					borrow = 1;
				}
				else
				{
					if (temp1 == *head1 && (temp1->data - 1) == 0)
					{
						borrow = 0;
						break;
					}
					insert_first(headR, tailR, temp1->data - 1);
					borrow = 0;
				}
			}
			else
			{
				if (temp1 == *head1 && (temp1->data) == 0)
				{
					borrow = 0;
					break;
				}
				insert_first(headR, tailR, temp1->data);
			}
			temp1 = temp1->prev;
		}
		else
		{
			break;
		}
	}
	remove_zeros(headR, tailR);

	if (flag == 1)
	{
		(*headR)->data *= -1;
	}
	

	return SUCCESS;
}
