#include <stdio.h>
#include <stdlib.h>
typedef struct {
	int rollno;
	float marks;
	char name[101];
	struct node *previous, *next;
}node;
node *create(node *head) {
	node *p,*q;
	p = head; q = head;
	char another;
	do {
		printf("Enter the Name, Roll Number and Marks of Student\n");
		scanf("%s%d%f",p->name,&p->rollno,&p->marks);
		printf("Do you want to add another record\n");
		scanf(" %c",&another);
		if(another == 'Y' || another == 'y') {
			q->next = (node *)malloc(sizeof(node));
			p = q->next;
			p->previous = q;
			q = q->next;
			p->next = NULL;
		}
	}while(another == 'Y' || another == 'y');
	return head;
}
node *insert(node *head) {
	int opt;
	node *p;
	p = (node *)malloc(sizeof(node));
	printf("Where do you want to insert\n"
			"1. Head\n"
			"2. Tail\n"
			"3. Somewhere else\n");
	scanf("%d",&opt);
	switch(opt) {
	case 1 : {
		head->previous = p;
		printf("Enter the Name, Roll Number and Marks of Student\n");
		scanf("%s%d%f",p->name,&p->rollno,&p->marks);
		head = p;
		head->previous = NULL;
		break;
	}
	case 2 : {
		p = head;
		while(p->next != NULL) {
			p = p->next;
		}
		node *q = p;
		p->next = (node *)malloc(sizeof(node));
		p->previous = q;
		printf("Enter the Name, Roll Number and Marks of Student\n");
		scanf("%s%d%f",p->name,&p->rollno,&p->marks);
		break;
	}
	case 3 : {
		p = head;
		int n,i = 1;
		printf("Enter the Location \n");
		scanf("%d",&n);
		while(i<=n) {
			p = p->next;
			i++;
		}
		node *q = p;
		printf("Enter the Name, Roll Number and Marks of Student\n");
		scanf("%s%d%f",p->name,&p->rollno,&p->marks);
		p->next = q->next;
		q->next = p->next;
		break;
	}
	}
	return head;
}
node *del(node *head) {
	int n,i = 1;
	node *p = head,*q;
	printf("Enter the Location\n");
	scanf("%d",&n);
	while(p != NULL || i<=n) {
		p = p->next;
		i++;
	}
	q = p;
	node *r;
	r = p->next;
	q->next = r;
	r->previous = q;
	return head;
}
node *mod(node *head) {
	int n,i = 1;
	node *p;
	p = head;
	while(i<=n || p!=NULL) {
		p = p->next;
		i++;
	}
	printf("Enter the Name, Roll Number and Marks of Student\n");
	scanf("%s%d%f",p->name,&p->rollno,&p->marks);
	return head;
}
void displayf(node *head) {
	if(head!=NULL) {
		printf("Roll Number : %d\n"
				"Name : %s\n"
				"Marks : %f\n",head->rollno,head->name,head->marks
		);
		displayf(head->next);
	}
}
void displayb(node *head) {
		node *p;
		p = head;
		while(p != NULL) {
			p = p->next;
		}
		printf("Name : %s\n"
				"Roll Number : %d\n"
				"Marks : %f\n",
				p->name,p->rollno,p->marks);
		displayb(p->previous);
}
int main() {
	int opt;
	node *head;
	head = (node *)malloc(sizeof(node));
	head->previous = NULL;
	head->next = NULL;
	do  {
		printf("1. Create a List\n"
				"2. Insert a Node\n"
				"3. Display Forward\n"
				"4. Display Backwards\n"
				"5. Modify Data\n"
				"6. Exit\n");
		scanf("%d",&opt);
		switch(opt) {
		case 1 : {
			head = create(head);
			break;
		}
		case 3 : {
			displayf(head);
		}
		}
	}while(1);
}
