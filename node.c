/*
 * Author : Ishan Joshi
 * Roll Number : 3154166
 * SE IT C
 * Implement a Single Linki List with the following options :
 * 1. Insertion of a node at any location
 * 2. Deleting of a node at any Location
 * 3. Display a List
 * 4. Revert a list without using additional data structure.
 */
#include<stdio.h>
typedef struct linkedList{
	int data;
	struct linkedList *next;
}node;
node *create(int n) {
	int i=1,x;
	node *head=NULL;
	node *p;
	head = (node *)malloc(sizeof(node));
	printf("Data of node %d :\n",i);
	scanf("%d",&x);
	head->data = x;
	head->next = NULL;
	p = head;
	for(i=2;i<n+1;i++) {
		p->next = (node *)malloc(sizeof(node));
		p = p->next;
		printf("Data of node %d :\n",i);
		scanf("%d",&p->data);
		p->next = NULL;
	}
	return head;
}
void display(node *head) {
	node *d;
	int i= 1;
	d = head;
	if(d == NULL) {
		printf("NO LIST EXISTS!\n");
	}
	else {
		do {
			printf("Data at %d node is %d\n",i,d->data);
			d = d->next;
			i++;
		}while(d!=NULL);
	}
}
void insert(node *head,int i) {
	int count=1;
	node *p = head;
	do {
		p = p->next;
		count++;
	}while(count!=i);
	node *d,*cpy;
	cpy = p->next;
	d = (node *)malloc(sizeof(node));
	printf("Enter the data\n");
	scanf("%d",&d->data);
	p->next = d;
	d->next = cpy;
}
int main() {
	int opt;
	node *head;
	do {
		printf("1.Create a List\n2.Display the List\n3.Insert the List\n4.Delete a Node\n5.Exit\n");
		scanf("%d",&opt);
		switch(opt) {
		case 1 : {
			printf("Enter the Number of Lists\n");
			scanf("%d",&opt);
			head = create(opt);
			break;
		}
		case 2 : {
			display(head);
			break;
		}
		case 3 : {
			printf("Where do you want to insert\n");
			scanf("%d",&opt);
			insert(head,opt);
			break;
		}
		case 4 : {
			break;
		}
		case 5 : {
			return 0;
		}
		}
	}while(1);
}
