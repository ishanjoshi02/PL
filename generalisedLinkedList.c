#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int flag;
	char data;
	struct node *next,*level,*plevel;
}node;
node *create(node *head) {
	int temp = 0;
	char c;
	node *p,*q;
	head = (node *)malloc(sizeof(node));
	p = head;
	printf("Enter the Book Index now\n");
	do {
		scanf(" %c",&c);
		if(c == '(') {
			if(temp != 0) {
				p->level = (node *)malloc(sizeof(node));
				q = p;
				p->flag = 1;
				p = p->level;
				p->plevel = q;
			}
			temp ++;
		}
		else if(c == ')') {
			p = q;
			temp--;
		}
		else {
			p->next = (node *)malloc(sizeof(node));
			p->flag = 0;
			p = p->next;
			p->next = NULL;
			p->level = NULL;
			p->data = c;
		}
	}while(temp > 0);
	p->plevel = NULL;
	p->level = NULL;
	p->next = NULL;
	return head;
}
void display(node *head) {
	node *p;
	p = head;
	printf("(\t");
	do {
		if(p->flag == 0) {
				printf("%c\t",p->data);
				p = p->next;
		}
		else {
			p = p->level;
			printf("(\t");
		}

	}while(p != NULL);
	printf(")\n");
}
int main() {
	node *head;
	head->plevel = NULL;
	int opt;
	do {
		printf("1. Create Generalized Linked List\n"
				"2. Display Generalized Linked List\n");
		scanf("%d",&opt);
		switch(opt) {
		case 1 : {
			head = create(head);
			break;
		}
		case 2 : {
			display(head);
		}
		}
	}while(1);
	return 0;
}
