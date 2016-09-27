#include <stdio.h>
#include <stdlib.h>
typedef struct {
	char data;
	int flag;
	struct node *next,*nextlevel;
}node;

node *create(node *head) {
	node *p,*q[5];
	head = (node *)malloc(sizeof(node));
	p = head;
	char something;
	int temp = -1;
	printf("Enter the Data now\n");
	do {
		scanf(" %c",&something);
		if(something == '(') {
			if(temp != -1) {
				p->flag = 1;
				q[temp] = p;
				p->nextlevel = (node *)malloc(sizeof(node));
				p = p->nextlevel;
			}
			temp ++;
		}
		else if(something == ')') {
			if(temp != -1) {
				p = q[temp];
				p = p->next;
			}
			temp --;
		}
		else {
			p->flag = 0;
			p->data = something;
			p->next = (node *)malloc(sizeof(node));
			p = p->next;
			p->nextlevel = NULL;
			p->next = NULL;
		}
	}while(temp != -1);
	return head;
}
void display(node *head) {
	node *p,*q[5];
	int temp = 0;
	p = head;
	printf("(\t");
	do {
		if(p->flag == 0) {
			printf("%c\t",p->data);
			if(p->next == NULL && temp > 0) {
				p = q[temp--];
				printf(")\t");
			}
			else {
				p = p->next;
			}
		}
		else {
			q[temp++] = p;
			p = p->nextlevel;
			printf("(\t");
		}
	}while(p->next != NULL && p->nextlevel != NULL && temp > 0);
	printf(")\n");
}
int main() {
	node *head = NULL;
	int temp;
	do {
		printf("1. Create a Generalized Linked List\n"
				"2. Display the list \n"
				"3. Exit \n");
		scanf("%d",&temp);
		switch(temp) {
		case 1 : {
			head = create(head);
			break;
		}
		case 2 : {
			if(head != NULL) {
				display(head);
			}
			else {
				printf("No list exists\n");
			}
			break;
		}
		case 3 : {
			return 0;
		}
		}
	}while(1);
}
