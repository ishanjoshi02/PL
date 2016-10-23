#include <stdio.h>
#include <string.h>
typedef struct Database {
	char name[101],rollNumber[16],marks[5];
}Database;
int main(int argc, char const *argv[]) {
  FILE  *fp;
  Database dat;
  int option,numberOfRecords;
  long int recsize = sizeof(dat);
  do {
    printf("1. Create a File Database\n2. Display Database\n3. Add a Record\n"
    		"4. Delete a Record\n5. Modify a Record\n6. Exit\n");
    scanf("%d",&option);
    switch(option) {
    case 1 : {
    	fp = fopen("Database.dat","wb");
    	if(fp==NULL) {
    		printf("File couldn't be created\n");
    	}
    	else {
    		printf("Enter the Number of Records\n");
    		scanf("%d",&numberOfRecords);
    		for(int i=0;i<numberOfRecords;i++) {
    			printf("Enter Name, Roll Number and Marks of Student %d\n",i+1);
    			scanf("%s%s%s",dat.name,dat.rollNumber,dat.marks);
    			fwrite(&dat,recsize,1,fp);
    		}
    	}
    	fclose(fp);
    	break;
    }
    case 2 : {
    	fp = fopen("Database.dat","rb");
    	if(fp==NULL) {
    		printf("File doesn't exist\n");
    	}
    	else {
    		while(fread(&dat,recsize,1,fp)==1) {
    			printf("Name : %s\n"
    					"Roll Number : %s\nMarks : %s\n"
    					,dat.name,dat.rollNumber,dat.marks);
    		}
    	}
    	fclose(fp);
    	break;
    }
    case 3 : {
    	fp = fopen("Database.dat","ab");
		printf("Enter Name, Roll Number and Marks of Student\n");
		scanf("%s%s%s",dat.name,dat.rollNumber,dat.marks);
		fwrite(&dat,recsize,1,fp);
		fclose(fp);
		break;
    }
    case 4 : {
    	FILE *temp;
    	temp = fopen("temp.dat","wb+");
    	char key[101];
    	printf("Enter the Name/Roll Number of Student\n");
    	scanf("%s",key);
    	fp = fopen("Database.dat","wb+");
    	while(fread(&dat,recsize,1,fp)==1) {
    		if((strcmp(key,dat.name)==0 ||	strcmp(key,dat.rollNumber)==0 || strcmp(key,dat.marks)==0))
    		{

    		}
    		else {
    			fwrite(&dat,recsize,1,temp);
    		}
    	}
    	remove("Database.dat");
    	rename("temp.dat","Database.dat");
    	fclose(temp);
    	fclose(fp);
    	break;
    }
    case 5 : {
    	FILE *temp;
    	temp = fopen("temp.dat","wb+");
    	char key[101];
    	printf("Enter the Name/Roll Number of Student\n");
    	scanf("%s",key);
    	fp = fopen("Database.dat","wb+");
    	while(fread(&dat,recsize,1,fp)==1) {
    		if(!(strcmp(key,dat.name)==0 ||	strcmp(key,dat.rollNumber)==0 || strcmp(key,dat.marks)==0))
    		{
    			fwrite(&dat,recsize,1,temp);
    		}
    		else {
    			printf("Enter Name, Roll Number and Marks of Student %d",++numberOfRecords);
    			scanf("%[^\n]s%s%s",dat.name,dat.rollNumber,dat.marks);
    			fwrite(&dat,recsize,1,temp);
    		}
    	}
    	remove("Database.dat");
    	rename("temp.dat","Database.dat");
    	fclose(temp);
    	fclose(fp);
    	break;
    }
    case 6 : {
    	printf("Do you want to save the File\n1.Yes\n2.No");
    	scanf("%d",&option);
    	if(option==2) {
    		remove("Database.dat");
    	}
    	return 0;
    }
    }
  } while(1);
  return 0;
}
