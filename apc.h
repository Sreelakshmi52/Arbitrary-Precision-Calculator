#ifndef APC_H
#define APC_H


#define SUCCESS 0
#define FAILURE -1

//Double Linked List
typedef struct node
{
	struct node *prev;
	int data;
	struct node *next;
}Dlist;



/*store the operands into the list */
int digit_to_list(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,char *oper1,char *oper2);

/*Addition */
int addition(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);

/*subtraction*/
int subtraction(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *argv[]);

/*Multiplication*/
int multiplication(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR,char *argv[]);

/*Division */
int division(Dlist **head1,Dlist **tail1,Dlist **head2,Dlist **tail2,Dlist **headR,Dlist **tailR);



int insert_last(Dlist **head, Dlist **tail, int data);
int insert_first(Dlist **head, Dlist **tail, int data);
void print_list(Dlist *head);
int remove_zeros(Dlist **head, Dlist **tail);
int dl_delete_list(Dlist **head, Dlist **tail);
int is_valid_number(const char *str);
int process_operand(char *oper,Dlist **head,Dlist **tail);

#endif
