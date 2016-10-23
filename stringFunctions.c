#include <stdio.h>
#include <stdlib.h>

int length(char *a) {
	int i;
	for(i=1;*a!='\0';i++,a++) {
	}
	return i-1;
}
void reverse(char *a) {
	char *temp;
	int i;
	temp = (char *)malloc(sizeof(char)*length(a));
	for(i=0;i<length(a);i++) {
		temp++;
	}
	while(*a!='\0') {
		*temp = *a;
		temp--;a++;
	}
	*(temp+length(a)+1) = '\0';
	a = temp;
	printf("%s",*a);
}
char *copy(char *destination,char *source) {
	for(;*source!='\0';source++,destination++) {
		*destination = *source;
	}
	return destination;
}
void concatenate(char *string1,char *string2) {
	char *temp = string1;
	while(*string1!='\0') {
		string1++;
	}
	copy(string1,string2);
	string1 = temp;
	printf("%s\n",string1);
}
char *compare(char *s1,char *s2) {
	while(*s1!='\0' && *s2!='\0' && *s1==*s2) {
		s1++;s2++;
	}
	if(s1>s2) {
		return "First String is greater than Second String";
	}
	else if(s1<s2) {
		return "First String is less than Second String";
	}
	else {
		return "Both String are equal";
	}
}
void copyn(char *destination,char *source,int n) {
	for(int i =0;i<n && *source!='\0';i++,source++,destination++) {
		*destination = *source;
	}
}
int main(int argc, char **argv) {
	int option;
	char *a,*b,*oa,*ob;
	do {
		printf("1. Accept String 1\n"
				"2. Accept String 2\n"
				"3. Concatenate the Two Strings\n"
				"4. Compare the Two Strings\n"
				"5. Length of First String\n"
				"6. Length of Second String\n"
				"7. Reverse First String\n"
				"8. Reverse Second String\n"
				);
		scanf("%d",&option);
		switch(option) {
		case 1 : {
			a = (char *)malloc(sizeof(char)*51);
			oa = a;
			scanf(" %[^\n]s",a);
			printf("%s\n",a);
			break;
		}
		case 2 : {
			b = (char *)malloc(sizeof(char)*51);
			ob = b;
			scanf(" %[^\n]s",b);
			printf("%s\n",b);
			break;
		}
		case 3 : {
			a = oa; b = ob;
			concatenate(a,b);
			break;
		}
		case 4 : {
			a = oa; b = ob;
			printf("%s\n",compare(a,b));
			break;
		}
		case 5 : {
			a = oa;
			printf("Length of %s is %d\n",a,length(a));
			break;
		}
		case 6 : {
			b = ob;
			printf("Length of %s is %d\n",b,length(b));
			break;
		}
		case 7 : {
			a = oa;
			reverse(a);
			break;
		}
		case 8 : {
			b = ob;
			reverse(b);
			break;
		}
		}
	} while (1);
}
