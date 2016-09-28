#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int flag;
	char data;
	struct node *next,*level;
}node;
node *space() {
	return (node *)malloc(sizeof(node));
}
node *create(node *head) {
	head = space();
	node *p = head,*q[5];
	char c;
	int temp = -1;
	do {
		scanf(" %c",&c);
		if(c == '(') {
			if(temp != -1) {
				p->flag = 1;
				q[temp] = p;
				p->level = space();
				p = p->level;
			}
			temp++;
		}
		else if(c == ')') {
			temp-- ;
			if(temp != -1) {
				p = q[temp];
				p->next = space();
				p = p->next;
			}
		}
		else {
			p->flag = 0;
			p->level = NULL;
			p->data = c;
			p->next = space();
			p = p->next;
			p->next = NULL;
			p->level = NULL;
		}
	}while(temp != -1);
	return head;
}
void display(node *head) {
	node *p = head,*q[5];
	int temp = 0;
	printf("(\t");
	do {
		if(p->flag == 0) {
			printf("%c\t",p->data);
			if(p->level == NULL && p->next == NULL && temp !=0) {
				p = q[--temp];
				p = p->next;
				printf(")\t");
			}
		}
		else {
			q[temp++] = p;
			p = p->level;
			printf("(\t");
		}
	}while(temp != 0);
	printf(")\n");
}
int main() {
	node *head = NULL;
	int temp;
	do {
		printf("1. Generate Generalized Linked List\n"
				"2. Display the List\n"
				"3. Exit\n");
		scanf("%d",&temp);
		switch(temp) {
		case 1 : {
			head = create(head);
			break;
		}
		case 2 : {
			display(head);
			break;
		}
		case 3 : {
			exit(0);
		}
		}
	}while(1);
}
