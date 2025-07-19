#include "apc.h"
#include <stdio.h>
#include <stdlib.h>

int digit_to_list(Dlist **head1, Dlist **tail1, Dlist **head2, Dlist **tail2, char *oper1, char *oper2)
{
    // Initialize pointers to NULL
    *head1 = *tail1 = NULL;
    *head2 = *tail2 = NULL;

    // Validate input parameters
    if (oper1 == NULL || oper2 == NULL)
    {
        return FAILURE;
    }

    // Process first operand
    process_operand(oper1, head1, tail1);
    // Process second operand
    process_operand(oper2, head2, tail2);
    return SUCCESS;
}