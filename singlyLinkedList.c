//This is an extremely Crude Program. Little changes required\n. Please make those changes
//Changes needed in addNode(),display().
#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int data;
	struct node *next;
}node;
node *addNode(node *p) {
	p = (node *)malloc(sizeof(node));
	printf("Enter Element\n");
	scanf("%d",&p->data);
	return p;
}
node *create(node *head) {
	node *p;
	char another;
	head = addNode(head);
	printf("Do you want to add another node\n");
	scanf(" %c",&another);
	p = head->next;
	while (another=='y'||another=='Y') {
		p = addNode(p);
		p = p->next;
		printf("Do you want to add another node\n");
		scanf(" %c",&another);
	}
	return head;
}
void display(node *p,int n) {
	if(p!=NULL) {
		if(n==1) {
			printf("%d\n",p->data);
			display(p->next,n);
		}
		else {
			display(p->next,n);
			printf("%d\n",p->data);
		}
	}
}
node *addatLocation(node *head) {
	int location;
	node *p = head,*q=NULL;
	printf("Enter Location\n");
	scanf("%d",&location);
	if(location == 0) {
		q = addNode(q);
		q->next = head;
		return q;
	}
	for(int i=0;i<location;i++,p=p->next){}
	q = p->next;
	p->next = addNode(p->next);
	p = p->next;
	p->next = q;
	return head;
}
node *delete(node *head) {
	int location;
	node *p = head,*q;
	printf("Enter Location\n");
	scanf("%d",&location);
	if(location!=0) {
		for(int i=0;i<location;i++,p=p->next){}
		q = p->next;
		p->next = p->next->next;
	}
	else {
		q = head;
		free(q);
		return head->next;
	}
	free(q);
	return head;
}
node *reverseList(node *head) {
	node *p = head,*q = NULL,*r = NULL;
	while(p!=NULL) {
		q = p->next;
		p->next = r;
		r = p;
		p = q;
	}
	return r;
}
int main(int argc, char **argv) {
	int option;
	node *head;
	do {
		printf("1. Create List\n"
				"2. Display List\n"
				"3. Add a Node\n"
				"4. Delete a Node\n"
				"5. Display Reverse List\n"
				"6. Reverse List\n"
				"7. Exit \n");
		scanf("%d",&option);
		switch(option) {
		case 1 : {
			head = create(head);
			break;
		}
		case 2 : {
			display(head,1);
			break;
		}
		case 3 : {
			head = addatLocation(head);
			break;
		}
		case 4 : {
			head = delete(head);
			break;
		}
		case 5 : {
			display(head,12);
			break;
		}
		case 6 : {
			head = reverseList(head);
			break;
		}
		case 7 : {
			return 0;
		}
		}
	} while (1);
}
