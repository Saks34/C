#include <stdio.h>
#include <string.h>
int main()
{
	FILE *fp;
	char data[50]="I am in kocbk";
	fp=fopen("Gfg.txt","w");
	if (fp==NULL)
	{
		printf("Gfg.txt file failed to open");
		
	}
	else 
	{printf("The file is now opened.\n");
	if (strlen (data)>0)
	{
		fputs(data,fp);
		fputs("\n",fp);
		
	}
	fclose(fp);
	printf("Data successfully written in file Gfg.txt\n");
	printf("The file is now closed.");
	}
}
