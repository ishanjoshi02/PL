#include <stdio.h>
#include <stdlib.h>
typedef struct node {
	int flag;
	char data;
	struct node *next,*level;
}node;
node *getData(char string[],node *p) {
	static int index = 0;
	p = (node *)malloc(sizeof(node));
	if(string[index++]=='(') {
		p->flag = 1;
		p->level = getData(string,p->level);
	}
	else if(string[index++]==')') {
		return p;
	}
	else {
		p->flag = 0;
		p->data = string[index++];
		p->next = getData(string,p->next);
	}
}
void displayData(node *p) {
	if(p==NULL) {
		return;
	}
	if(p->flag == 0) {
		printf("%c ",p->data);
		displayData(p->next);
		printf(")");
	}
	else {
		printf("( ");
		displayData(p->level);
	}
}
int main(int argc, char **argv) {
	char string[101];
	node *head;
	printf("Enter the Data now\n");
	scanf("%s",string);
	displayData(getData(string,head));
}

