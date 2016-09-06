/*
Implement singly linked list with following opt
1 ins of a node at any location
2 deletion of a node from any location
3 display a list
4 reverting a list without using additional data structure
 */


#include <stdio.h>
#include <stdlib.h>

typedef struct
{
	int data;
	struct node *next;

}node;

typedef struct {
	int data;
	struct n *previous;
}n;

node *create(int n);
void display(node *head);
node *insert(node *, int , int );
node *del(node *, int);
void displayrev(node *);
void displayreverse(node *);

int main()
{
	node *head;
	int n, loc;
	int opt, dt;
	while(1)
	{
		printf("Choose your option\n1: Input data\n2: Display the linked list\n3: Insert a node at a location\n4:: Display reverse\n5: Delete node\n6: Exit\n");
		scanf("%d", &opt);

		switch(opt)
		{
		case 1:
			printf("Enter no. of elements:\n");
			scanf("%d", &n);
			head = create(n);
			break;

		case 2:
			display(head);
			break;

		case 3:
			printf("In which position do you want to enter node?\n");
			scanf("%d", &loc);
			printf("Enter data for new node\n");
			scanf("%d", &dt);
			head = insert(head, loc, dt);
			break;

		case 5:
			printf("Which node do you want to delete?\n");
			scanf("%d", &loc);
			head = del(head,loc);
			break;

		case 4:
			displayrev(head);
			break;

		case 6:
			exit(1);

		}
	}
	return 0;
}

node *create(int n)
{
	int i=1, x;
	node *head=NULL, *p;
	head=(node*)malloc(sizeof(node));
	printf("Enter data for node %d :\n", i);
	scanf("%d", &x);
	head->data=x;
	head->next=NULL;
	p=head;
	for(i=2; i<=n; i++)
	{
		p->next=(node*)malloc(sizeof(node));
		p=p->next;
		printf("Enter data for node %d:\n", i);
		scanf("%d", &x);
		p->data=x;
		p->next=NULL;
	}
	return head;
}

void display(node *head)
{
	int i;
	node *p=head;
	if(p==NULL)
	{
		printf("No data man! Enter data!\n");
	}
	else
	{
		while(p!=NULL)
		{
			printf("Data at node %d is :", ++i);
			printf("%d\n", p->data);
			p=p->next;
		}
	}
}

node *insert(node *head, int loc, int dt)
{
	int i;
	node *p, *q;
	p=(node *)malloc(sizeof(node));
	p->data=dt;
	if(loc==1)
	{
		p->next=head;
		head=p;
	}

	else
	{
		q=head;
		for(i=1; i<(loc-1); i++)
		{
			q=q->next;
		}
		if(q!=NULL)
		{
			p->next=q->next;
			q->next=p;
		}
		else
		{
			printf("Overflow\n");
		}
	}
	return head;
}

node *del(node *head, int loc)
{
	int i;
	node *p, *q;
	p=head;
	if(loc==1)
	{
		head=head->next;
		free(p);
	}

	else
		q=head;
	{
		for(i=1; i<(loc-1); i++)
		{
			q=q->next;
		}

		if(q!=NULL)
		{
			p=q->next;
			q->next=p->next;
			free(p);
		}
	}
	return head;
}

void  displayrev(node *head)
{
	if(head!=NULL)
	{
		displayrev(head->next);
		printf("%d\n", head->data);
	}
}
void displayreverse(node *head) {
	n *p;
	node *pf;
	pf = head;
	while(pf != NULL) {
		pf = pf->next;
	}
	p = pf;
	pf = head;
	while(pf != NULL) {
		p->data = pf->data;
		p->previous = pf->next;
		pf = pf->next;
	}
	while(p!=NULL) {
		printf("%d",p->data);
		p = p->previous;
	}
}
